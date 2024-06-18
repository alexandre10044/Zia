/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_
/**
 * @class Client
 * @brief Class for the NetworkManager to store clients (TCP)
 */
#include <string>
#include <queue>
#include <sys/socket.h>
#include "Pipeline.hpp"
class Client {
	public:
        /**
         * @brief Construct a new Client object
         *
         * @param fd
         */
        Client(int fd);
        /**
         * @brief Destroy the Client object
         *
         */
		~Client();
        /**
         * @brief Get the client Fd
         *
         * @return int
         */
        int             getFd();
        /**
         * @brief pops a new message from clients messages
         *
         * @return std::string
         */
        std::string     popMessage();
        /**
         * @brief Pushes a new message to the client queue
         *
         * @param message Message tu be pushed
         */
        void            pushMessage(std::string message);
        oZ::Context                 _ctx;
	protected:
	private:
        /**
         * @brief The fd of the client
         *
         */
        int                         _fd;
};

#endif /* !CLIENT_HPP_ */
