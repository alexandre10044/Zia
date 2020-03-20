/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Log
*/


/**
* \file Config.cpp
* \author Thomas CHEZAUD (thomas1.chezaud@epitech.eu)
* \date 13/01/2020
* \brief Using to log things in console (colored).
*/

#ifndef LOG_HPP_
#define LOG_HPP_
#include <map>
#include <string>
#include <iostream>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[93m"
#define BG_YELLOW "\033[103m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

/**
 * \class Log
 *
 * Class used to log things in console
 */


class Log {
	public:
        static void Console(std::string startColor, std::string message);
        static void Error(std::string startColor, std::string message);
        static void Console(std::string startColor, std::string head,std::string message);
        static void Error(std::string startColor, std::string head,std::string message);
    protected:
	private:
		Log();
		~Log();
};

#endif /* !LOG_HPP_ */

































































































