/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "ConnectionToClientManager.hpp"
#include "ClientID.hpp"
#include "Message.hpp"
#include <vector>
#include <utility>
#include <string>
#include <thread>
#include <chrono>

/**
 * Here a snapshot of the Communication Protocol:
 * \image html Communication_Protocol.png
 */

class Server {
    public:
        Server();
        ~Server();
        void launch(std::string ip, std::string port);

    protected:
    private:
        void removeOldSocket();
        void getConnection();
        void getRequest(unsigned int i);
        ConnectionToClientManager _connectionManager;
        std::vector<std::unique_ptr<ClientID>> _client;
        std::string _ip;
        unsigned short _port;
};

#endif /* !SERVER_HPP_ */
