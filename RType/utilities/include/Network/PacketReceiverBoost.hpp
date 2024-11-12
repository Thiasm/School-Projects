/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** PacketReceiverBoost
*/

#ifndef PACKETRECEIVERBOOST_HPP_
#define PACKETRECEIVERBOOST_HPP_

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <string>
#include "MessageComp.hpp"

class PacketReceiverBoost {
    public:
        PacketReceiverBoost();
        ~PacketReceiverBoost();
        gate_t *receivePacketUDP(std::shared_ptr<boost::asio::ip::udp::socket> &socket, boost::asio::ip::udp::endpoint &endpoint);
        gate_t *receivePacketUDP(std::shared_ptr<boost::asio::ip::udp::socket> &socket, std::shared_ptr<boost::asio::ip::udp::endpoint> &endpoint, bool getEndpoint);
        RequestType receivePacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket);
        RequestType receivePacketTCPNoResponse(std::unique_ptr<boost::asio::ip::tcp::socket> &socket);
    protected:
    private:
        MessageComp _messageComp;
};

#endif /* !PACKETRECEIVERBOOST_HPP_ */
