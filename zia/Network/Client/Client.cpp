/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Client
*/

#include "Client.hpp"
#include <unistd.h>

Client::Client(int fd)
{
    _fd = fd;
}

Client::~Client()
{
}

std::string Client::popMessage()
{
   
}

void    Client::pushMessage(std::string s)
{
}

int Client::getFd()
{
    return (_fd);
}