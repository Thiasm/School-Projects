/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** ConnectionToClientManager
*/

#ifndef CONNECTIONTOCLIENTMANAGER_HPP_
#define CONNECTIONTOCLIENTMANAGER_HPP_

#include "PacketReceiverBoost.hpp"
#include "PacketSenderBoost.hpp"
#include "MessageComp.hpp"
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
        void searchConnection(std::unique_ptr<boost::asio::ip::tcp::socket> &client); // cherche si un client se connecte
        RequestType getRequest(std::unique_ptr<boost::asio::ip::tcp::socket> &client); // cherche si un client connecté envoie une requete
        RequestType getRequestNoResponse(std::unique_ptr<boost::asio::ip::tcp::socket> &client);
        gate_t *getRequestGame(std::shared_ptr<boost::asio::ip::udp::socket> &client, std::shared_ptr<boost::asio::ip::udp::endpoint> &_endpoint, bool getEndpoint);
        void joinRoom(std::unique_ptr<boost::asio::ip::tcp::socket> &sock, bool roomExist);
        bool gameIsStarted(std::unique_ptr<boost::asio::ip::tcp::socket> &sock, RequestType nbrPlayerInRoom);
        void gameStart(std::unique_ptr<boost::asio::ip::tcp::socket> &sock);
        void sendGameInfo(std::shared_ptr<boost::asio::ip::udp::socket> &sock, boost::asio::ip::udp::endpoint &_endpoint, gate_t &gameinfo);
        void sendGameInfo(std::shared_ptr<boost::asio::ip::udp::socket> &sock, boost::asio::ip::udp::endpoint &_endpoint, gate_t *gameinfo);
        void deco(std::unique_ptr<boost::asio::ip::tcp::socket> &client); // s'occupe de deco
    protected:
    private:
        boost::asio::io_context _io_context;
        std::unique_ptr<boost::asio::ip::tcp::acceptor> _acceptor;
        PacketReceiverBoost _packetReceiver;
        PacketSenderBoost _packetSender;
};

#endif /* !CONNECTIONTOCLIENTMANAGER_HPP_ */
