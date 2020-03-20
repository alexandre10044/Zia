/*
** EPITECH PROJECT, 2019
** Code Workspace Epitech (Workspace)
** File description:
** NetworkManager
*/

#ifndef NETWORKMANAGER_HPP_
#define NETWORKMANAGER_HPP_

#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <tuple>
#include <iostream>
#include <fcntl.h>
#include <vector>
#include <thread>
#include <future>
#include "Client.hpp"
#include "Logging.hpp"
#include "Pipeline.hpp"

/**
* @file NetworkManager.cpp
* @author Thomas CHEZAUD (thomas1.chezaud@epitech.eu)
* @date 13/01/2020
* @brief Used to init network, send or receive data.
*/

/**
 * @def BUFF_LEN
 * @brief Buffer length
 */
#define BUFF_LEN 4096

/**
 * @typedef SOCKADDR_IN
 * @brief Easier to write "struct sockaddr_in"
 */
typedef struct sockaddr_in SOCKADDR_IN;
/**
 * @typedef SOCKADDR
 * @brief Easier to write "struct sockaddr"
 */
typedef struct sockaddr SOCKADDR;
/**
 * @class NetworkManager
 *
 * Class used init and manage network
 */
class NetworkManager
{
public:
    /*!
        *   Constructor of the NetworkManager
            \param port The port of the network manager
            \param protocol Either IPPROTO_TCP | IPPROTO_UDP
        */
    NetworkManager(int port, int protocol);

    /*!
        *   Destructor of the NetworkManager
        */
    ~NetworkManager();
    /*!
        *   Set the sockaddr (not used ?)
            \param other Sets the sockaddr* _other
            \return 0 = done, -1 = error
        */
    void setOther(SOCKADDR_IN other);

    /*!
        *   Initiating socket
            \param _port The port of the server
            \param ip_protocol Either IPPROTO_TCP | IPPROTO_UDP
            \return 0 = done, -1 = error
        */
    int init(int _port, int ip_protocol);
    /*!
            \return server
        */
    SOCKADDR_IN getOther();
    /*!
            * The fd of server.
            \return the fd.
        */
    int getFd();
    /*!
            * Returns the fs
            \return the client(s)
        */
    void setFd(int fd);
    /*!
        *   UDP send data
            \param buff De taille BUFF_LEN
            \param n size_t the size of the message
            \return the client(s)
        */
    int sendTo(char buff[BUFF_LEN], std::size_t n);
    /*!
        *   UDP receive data
            \return std::tuple<struct sockaddr *,char*, int>
        */
    std::tuple<struct sockaddr *, char *, int> receiveFrom();
    /**
         * @brief This function contains the main loop.<BR>
         * Is used to accept new Client.<BR>
         * It also stores them in the Client class.<BR>
         * And also reads/stores there messages in there.<BR>
         * (It is doing I/O but nothing else)<BR>
         * @return 0 if ok, -1 if not ok
         */
    int TCP_Loop(std::future<void> obj);
    /**
         * @brief Returns the state of the server
         *
         * @return int
         */
    int started();
    /**
         * @brief Get the Client IP string
         *
         * @param c
         * @return std::string
         */
    std::string getClientIP(Client c);
    /**
         * @brief When a packet is received, follow it thrue pipeline
         *
         * @param buffer
         * @param endpoint
         */
    void onPacketReceived(oZ::ByteArray &&buffer, const oZ::Endpoint endpoint, Client client)
    {
        oZ::Context context(oZ::Packet(std::move(buffer), endpoint));
        _pipeline.runPipeline(client._ctx);
        //sendResponseToClient(client._ctx, client);
    }
    // Callback when server receive disconnection
    void onClientDisconnected(oZ::Context &context) {
        _pipeline.onDisconnection(context);
    }
     // Callback when server accept a new client
    void onClientConnected(oZ::Context &context) {
        _pipeline.onConnection(context);
    }
    /**
     * @brief Used to send the response to the client
     *
     * @param context
     */
    void sendResponseToClient(oZ::Context &context, Client client)
    {
        std::string response = "";

        for (int i = 0; i < context.getPacket().getByteArray().size(); i++)
            response += context.getPacket().getByteArray()[i];
        send(client.getFd(), response.c_str(), response.length(), 0);
        oZ::Endpoint    end;
        end.setPort(_port);
        end.setAddress(getClientIP(client));
        oZ::ByteArray buffer;
        onClientDisconnected(context);
        close(client.getFd());
    }

protected:
private:
    /**
     * @brief Used in UDP
     */
    SOCKADDR_IN         _other;
    /**
     * @brief Used in UDP
     */
    int                 _fd;
    /**
     * @brief Used to determine which protocol the server is in
     */
    int                 _protocol;
    /**
     * @brief The pipeline for the API
     */
    oZ::Pipeline        _pipeline;
    int                 _started;
    std::vector<Client> _clients;
    int                 _port;
};

#endif /* !NETWORKMANAGER_HPP_ */
