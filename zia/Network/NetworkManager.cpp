/*
** EPITECH PROJECT, 2019
** Code Workspace Epitech (Workspace)
** File description:
** NetworkManager
*/

#include "NetworkManager.hpp"
/**
* @file NetworkManager.cpp
* @author Thomas CHEZAUD (thomas1.chezaud@epitech.eu)
* @date 13/01/2020
* @brief Used to init network, send or receive data
*/

NetworkManager::NetworkManager(int port, int protocol) : _pipeline("modules", ".")
{
    _started = 0;
    if (port < 0 || port > 25565)
        port = 80;
    if (this->init(port, protocol) == 0)
        _started = 1;
    else
        _started = 0;
    _pipeline.loadModules();
}

NetworkManager::~NetworkManager()
{
    close(_fd);
}

int NetworkManager::init(int port, int ip_protocol)
{
    if (_started)
    {
        close(_fd);
        return (-1);
    }
    _started = 0;
    int error;
    if (ip_protocol != IPPROTO_UDP && ip_protocol != IPPROTO_TCP)
    {
        std::cerr << "Protocol not avalaible" << std::endl;
        return (-1);
    }
    _protocol = ip_protocol;
    _fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_fd < 0)
    {
        perror("Socket ");
        return (-1);
    }
    memset(&_other, 0, sizeof(_other));
    _other.sin_family = AF_INET;
    _other.sin_addr.s_addr = htonl(INADDR_ANY);
    _other.sin_port = htons(port);

    error = bind(_fd, (SOCKADDR *)&_other, sizeof(struct sockaddr_in));
    if (error < 0)
    {
        perror("Bind ");
        return (-1);
    }
    _port = port;
    if (0 != listen(_fd, 5))
    {
        perror(RED BOLD "Listen ");
        std::cout << RESET;
        return (false);
    }

    _started = 1;
    return (0);
}

int NetworkManager::TCP_Loop(std::future<void> futureObj)
{
    int error = 0;

    if (_protocol == IPPROTO_UDP)
        return (-1);
    fcntl(_fd, F_SETFL, O_NONBLOCK, 0);
    while (error == 0 && futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
    {
        // Accept
        SOCKADDR client = {0};
        int newfd = 0;
        unsigned int len = sizeof(&client);

        newfd = accept(_fd, (sockaddr *)&client, &len);
        if (newfd > 0)
        {
            _clients.push_back(Client(newfd));
            Log::Console(GREEN, "NetworkManager", "New client accepted");
            fcntl(newfd, F_SETFL, O_NONBLOCK, 0);
            oZ::ByteArray   buffer;
            oZ::Endpoint    end;
            end.setPort(_port);
            end.setAddress(getClientIP(_clients[_clients.size() - 1]));
            oZ::Context ctx(oZ::Packet(std::move(buffer), end,(oZ::FileDescriptor)newfd));
            ctx.setMetadata("fd", newfd);
            _clients[_clients.size() - 1]._ctx = std::move(ctx);
            onClientConnected(_clients[_clients.size() - 1]._ctx);
        }
        // Read/write
        for (auto it = _clients.begin(); it < _clients.end(); it++)
        {
            auto _c = *it;
            oZ::ByteArray byteArray;
            fd_set  fdset;
            struct timeval timeout;
            oZ::Endpoint end(getClientIP(_c), _port);
            timeout.tv_usec = 100000;
            FD_ZERO(&fdset);
            FD_SET(_c.getFd(), &fdset);
            if (int i = select(_c.getFd() + 1, &fdset, NULL, NULL, &timeout) > 0) {
                std::cout << "Packet received." << std::endl;
                onPacketReceived(std::move(byteArray), end, _c);
                close(_c.getFd());
                _clients.erase(it);
            }
            /*
                while ((ret = recv(_c.getFd(), buffer, sizeof(buffer), 0)) == sizeof(buffer))
                {
                    for (int i = 0; i < ret; i++)
                        byteArray.push_back((int8_t)buffer[i]);
                    memset(buffer, 0, 1024);
                }
                if (ret > 0)
                {
                    oZ::Endpoint end(getClientIP(_c), _port);
                    message += buffer;
                    for (int i = 0; i < ret; i++)
                        byteArray.push_back((int8_t)buffer[i]);
                    //_c.pushMessage(message);
                    std::cout << "Packet received (" << getClientIP(_c) << "): " << byteArray.size() << std::endl;
                    onPacketReceived(std::move(byteArray), end, _c);
                }
            */
        }
    }
    close(_fd);
    for (auto i = _clients.begin(); i < _clients.end(); i++)
    {
        try
        {
            close(i->getFd());
        }
        catch(const std::exception& e)
        {
            // Fd already closed ?
            std::cerr << e.what() << '\n';
        } 
    }
    std::cout << "Server terminated" << std::endl;
    //*terminate = true;
    return (error);
}

std::string NetworkManager::getClientIP(Client client)
{
    std::string clientIP = "";
    struct sockaddr_in addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    int res = getpeername(client.getFd(), (struct sockaddr *)&addr, &addr_size);
    char *clientip = new char[20];

    memset(clientip, 0, 20);
    strcpy(clientip, inet_ntoa(addr.sin_addr));
    clientIP += std::string(clientip);

    return (clientIP);
}

int NetworkManager::started()
{
    return (_started);
}

void NetworkManager::setOther(SOCKADDR_IN other)
{
    if (_protocol == IPPROTO_UDP)
        _other = other;
}

SOCKADDR_IN NetworkManager::getOther()
{
    if (_protocol == IPPROTO_UDP)
        return (_other);
    return {0};
}

int NetworkManager::getFd()
{
    if (_protocol == IPPROTO_UDP)
        return (_fd);
    return (-1);
}

void NetworkManager::setFd(int fd)
{
    if (_protocol == IPPROTO_UDP)
        _fd = fd;
}