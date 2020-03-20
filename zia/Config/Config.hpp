/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Config
*/

/**
* \file Config.cpp
* \author Thomas CHEZAUD (thomas1.chezaud@epitech.eu)
* \date 13/01/2020
* \brief Parsing configuration
*/

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <map>
#include "Logging.hpp"

/**
 * \class Config
 *
 * Class used to parse config
 * Comment : ##
 * Value : key=value
 */
class Config {
	public:
		Config();
		~Config();
        /*!
        *   Reading the config.
            \param file The config to parse
            \return 0 : success, -1 : error
        */
        int     read(std::string file);
        /*!
        *   Printing all or specific config key
            \param key The key to be printed
            \return Nothing.
        */
        void    print(std::string key = "");
        /**
         * @brief Get the selected key value in config read
         *
         * @param key
         * @return std::string
         */
        std::string     get(std::string key);
	protected:
	private:
        std::map<std::string, std::string> config;
};

#endif /* !CONFIG_HPP_ */



























