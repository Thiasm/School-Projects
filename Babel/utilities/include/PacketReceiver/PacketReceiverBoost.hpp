/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** PacketReceiverBoost
*/

#ifndef PACKETRECEIVERBOOST_HPP_
#define PACKETRECEIVERBOOST_HPP_

#include "PacketReceiver.hpp"

class PacketReceiverBoost
    :public PacketReceiver {
    public:
        PacketReceiverBoost();
        ~PacketReceiverBoost();
        gate_t *receivePacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket);
    protected:
    private:
};

#endif /* !PACKETRECEIVERBOOST_HPP_ */
