/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** ConnectionToClientManager
*/

#ifndef CONNECTIONTOCLIENTMANAGER_HPP_
#define CONNECTIONTOCLIENTMANAGER_HPP_

#include "PacketReceiverBoost.hpp"
#include "PacketSenderBoost.hpp"
#include "Message.hpp"
#include "ClientID.hpp"
#include <utility>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <string>
#include <vector>
#include <iostream>

class ConnectionToClientManager {
    public:
        ConnectionToClientManager();
        ~ConnectionToClientManager();
        void launch(std::string &ip, unsigned short &portnum);
        unsigned int peopleConnected();
        void createSocket(std::unique_ptr<boost::asio::ip::tcp::socket> &sock);
        void searchConnection(std::unique_ptr<ClientID> &); // cherche si un client se connecte
        gate_t *getRequest(std::unique_ptr<ClientID> &client); // cherche si un client connecté envoie une requete
        void deco(std::unique_ptr<ClientID> &client); // s'occupe de deco
        std::string getNameInCallBuff(const std::string content);
        std::string getPortInCallBuff(const std::string content);
        void getPortInReceiveCallBuff(const std::string content, std::string &port1, std::string &portnbool);
        void call(std::unique_ptr<ClientID> &client,
                  std::vector<std::unique_ptr<ClientID>> &clientList,
                  gate_t *message); // s'occupe de l'appel
        void hangUp(std::unique_ptr<ClientID> &client,
                    std::vector<std::unique_ptr<ClientID>> &clientList,
                    gate_t *message); // s'occupe de raccrocher
        void update(std::unique_ptr<ClientID> &client, std::vector<std::unique_ptr<ClientID>> &clientList);

    protected:
    private:
        boost::asio::io_context _io_context;
        std::unique_ptr<boost::asio::ip::tcp::acceptor> _acceptor;
        PacketReceiverBoost _packetReceiver;
        PacketSenderBoost _packetSender;
};

#endif /* !CONNECTIONTOCLIENTMANAGER_HPP_ */
