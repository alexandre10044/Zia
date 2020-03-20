/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main
*/

/**
* @file main.cpp
* @author Thomas CHEZAUD (thomas1.chezaud@epitech.eu)
* @date 13/01/2020
* @brief ZIA main
*/

#include "NetworkManager.hpp"
#include "Config.hpp"
#include "Log.hpp"


bool    run_server(std::future<void> futureObj)
{
    Config          conf;
    int             port = 80;
    
    conf.read("./config.conf");
    conf.print();

    Log::Console(GREEN, BOLD BLUE "Network" RESET GREEN, "Initiating network...");
    if (conf.get("port") != "null")
        port = std::atoi(conf.get("port").c_str());
    NetworkManager  server(port, IPPROTO_TCP);
    if (server.started() != 1)
        return (84);
    Log::Console(GREEN, BOLD BLUE "Network" RESET GREEN, "Server has been initiated");
    server.TCP_Loop(std::move(futureObj));
    return (true);
}

/*!
    @param ac Argument count.
    @param av Arguments value.
    @return An int (0 if error)
*/
int     main(int ac, char **av)
{
    std::promise<void>  exitSignal;
    std::future<void> futureObj = exitSignal.get_future();
    std::thread     threadServer;

    bool    server = true;

    threadServer = std::thread(run_server, std::move(futureObj));
    while (server == true)
    {
        std::string     message;
        getline(std::cin, message);
        if (message == "RELOAD") {
            exitSignal.set_value();
            threadServer.join();
            exitSignal = std::promise<void>();
            futureObj = exitSignal.get_future();
            threadServer = std::thread(run_server, std::move(futureObj));
        }
        else if (message == "EXIT")
        {
            exitSignal.set_value();
            threadServer.join();
            return (0);
        }
        else
            std::cout << "Unknown message : " << message << std::endl;
    }
    return (0);
}
