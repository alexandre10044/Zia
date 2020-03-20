/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Config
*/

/**
* @file Config.cpp
* @author Thomas CHEZAUD (thomas1.chezaud@epitech.eu)
* @date 13/01/2020
* @brief Utilisé pour parser la configuration.
*/

#include "Config.hpp"

Config::Config()
{
}

int Config::read(std::string file)
{
    std::ifstream stream(file);

    if (!stream)
    {
        Log::Error(BOLD RED, "Config", "Coult not read config.");
        return (-1);
    }
    while (stream)
    {
        std::string line;
        std::string elem;
        std::string key;
        std::string value;
        std::getline(stream, line);
        if (line[0] == '#')
            continue;
        std::stringstream stream_s(line);
        if (std::getline(stream_s, elem, '='))
            key = elem;
        if (std::getline(stream_s, elem, '='))
            value = elem;
        if (key != "")
        {
            config[key] = elem;
        }
    }
    return (0);
}

void Config::print(std::string key)
{
    size_t lenKey = 0;
    size_t lenVal = 0;
    for (auto const &x : config)
    {
        lenKey = std::max(lenKey, x.first.length());
        lenVal = std::max(lenVal, x.second.length());
    }
    lenKey = lenKey % 8 + 16;
    if (key == "")
    {
        for (auto const &x : config)
        {
            if (x.first != "")
            {
                //std::cout << lenKey - x.first.length() << std::endl;
                std::cout << x.first;
                for (int i = 0; i < (lenKey - x.first.length()) / 8; i++)
                    std::cout << '\t';
                std::cout << " -> \t" << x.second << std::endl;
            }
        }
    }
    else
    {
        for (auto const &element : config)
            if (element.first == key)
            {
                 std::cout << element.first;
                 for (int i = 0; i < (lenKey - element.first.length()) / 8; i++)
                     std::cout << '\t';
                 std::cout << " -> \t" << element.second << std::endl;
            }
    }
}

std::string Config::get(std::string key)
{
    for (auto const& x : config)
    {
        if (x.first == key)
            return (x.second);
    }
    return "null";
}

Config::~Config()
{
}











































































































