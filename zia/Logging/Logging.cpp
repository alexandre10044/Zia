/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Log
*/

#include "Logging.hpp"

/**                         
* \file Logging.cpp
* \author Thomas CHEZAUD (thomas1.chezaud@epitech.eu)
* \date 13/01/2020
* \brief Using to log things in console (colored).
*/
                         
Log::Log() {};                         
Log::~Log() {};                         

/*!
*   Printing with color.
    \param startColor The color for the text to be printed.
    \param message The message to be printed
    \return Nothing.
*/

void Log::Console(std::string startColor, std::string message)
{
    std::cout << startColor << message << RESET << std::endl;
}
                         
/*!
*   Printing with given color.
    \param head The head of the message ([head]message)
    \param startColor The color for the text to be printed.
    \param message The message to be printed
    \return Nothing.
*/

void Log::Console(std::string startColor, std::string head, std::string message)
{
    std::cout  << startColor << "[" << head << "] "<< message << RESET << std::endl;
}

/*!
*    Printing with red color.
    \param startColor The color for the text to be printed.
    \param head The head of the message ([head]message)
    \param message The message to be printed
    \return Nothing.
*/
void Log::Error(std::string startColor, std::string head ,std::string message)
{
    std::cerr << startColor << "[" << head << "] " << message << RESET << std::endl;
}

/*!
*    Printing with red color.
    \param startColor The color for the text to be printed.
    \param message The message to be printed
    \return Nothing.
*/
























                         


void Log::Error(std::string startColor, std::string message)
{
    std::cerr << "[" << startColor << message << RESET << std::endl;
}






































































    
                         


