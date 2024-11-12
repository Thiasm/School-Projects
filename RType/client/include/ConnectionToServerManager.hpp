/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** ConnectionToServerManager
*/

#ifndef CONNECTIONTOSERVERMANAGER_HPP_
#define CONNECTIONTOSERVERMANAGER_HPP_

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

class ConnectionToServerManager {
    public:
        ConnectionToServerManager();
        ~ConnectionToServerManager();
        void connect(std::string ip, unsigned short portnum);
        RequestType joinRoom();
        void sendGameInfo(gate_t *gameinfo);
        gate_t *receiveGameInfo();
        bool getRoomInfo(bool &gameLaunched);
        void disconnect();
        RequestType player;
    protected:
    private:
        boost::asio::io_context _io_context;
        std::unique_ptr<boost::asio::ip::tcp::socket> _socket;
        std::shared_ptr<boost::asio::ip::udp::socket> _udpSocket;
        PacketReceiverBoost _packetReceiver;
        PacketSenderBoost _packetSender;
        boost::asio::ip::udp::endpoint _endpoint;
        std::string _ip;
        unsigned int _portnum;
};

#endif /* !CONNECTIONTOSERVERMANAGER_HPP_ */
