/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** PacketSenderBoost
*/

#ifndef PACKETSENDERBOOST_HPP_
#define PACKETSENDERBOOST_HPP_

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <string>
#include "MessageComp.hpp"

class PacketSenderBoost {
    public:
        PacketSenderBoost();
        ~PacketSenderBoost();
        void sendPacketUDP(std::shared_ptr<boost::asio::ip::udp::socket> &socket,
                           boost::asio::ip::udp::endpoint &endpoint, gate_t &gameInfo);
        void sendPacketUDP(std::shared_ptr<boost::asio::ip::udp::socket> &socket,
                           boost::asio::ip::udp::endpoint &endpoint, gate_t *gameInfo);
        RequestType sendPacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket,
                           RequestType type);
        void sendPacketTCPNoResponse(std::unique_ptr<boost::asio::ip::tcp::socket> &socket,
                           RequestType type);
    protected:
    private:
        MessageComp _messageComp;
};

#endif /* !PACKETSENDERBOOST_HPP_ */
