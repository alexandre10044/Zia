/*
** EPITECH PROJECT, 2020
** PHP
** File description:
** zia
*/

#include "Php.hpp"
#include <openZia/Log.hpp>

PhpCgiModule::PhpCgiModule()
{
}

PhpCgiModule::~PhpCgiModule()
{
}


bool PhpCgiModule::exeCgi(oZ::Context &context)
{
    std::string     cgi_path = conf.get("php-cgi");
    std::string     base_path = conf.get("cgi_directory");

    std::cout << "Php" << std::endl;
    if (context.getResponse().getCode() == oZ::HTTP::Code::Undefined && context.getRequest().getMethod() == oZ::HTTP::Method::Get) {
        if (cgi_path == "null" || base_path == "null") 
                return true;
        int link[2];
        pid_t pid;
        char foo[409600];
        std::string uri = context.getRequest().getURI();
        if (uri.length() > 4) {
            std::string end = &uri[uri.length() - 4];
            if (!(uri.length() > 4 && end == ".php"))
                return (true);
        }
        else
            return (true);
        

        // Pipe for php output
        if (pipe(link)==-1)
            return (true);
        // Forking process
        if ((pid = fork()) == -1)
            return (true);

        if(pid == 0) {
            dup2 (link[1], STDOUT_FILENO);
            close(link[0]);
            close(link[1]);
            execl(cgi_path.c_str(), "php-cgi", (base_path + uri).c_str(), (char *)0);
            return (true);

        } else {

            close(link[1]);
            int nbytes = read(link[0], foo, sizeof(foo));
            context.getPacket().getByteArray().clear();
            std::string data = "";
            char    data2[nbytes];
            std::strncpy(data2, foo, (uint)nbytes);
            data = data2;
            // TODO more checks here, maybe 404 ?
            data = "HTTP/1.1 200 OK\r\n" + data;
            for (int i = 0; i < nbytes; i++)
            {
                context.getPacket().getByteArray().push_back(data[i]);
            }
            wait(NULL);
            // Here we return false to end the process and send response to client.
            return (false);
        }
    }
            
    
    return true;
}



OPEN_ZIA_MAKE_ENTRY_POINT(PhpCgiModule);