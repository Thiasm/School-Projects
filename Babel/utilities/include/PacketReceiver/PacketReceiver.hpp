/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** PacketReceiver
*/

#ifndef PACKETRECEIVER_HPP_
#define PACKETRECEIVER_HPP_

#include "IPacketReceiver.hpp"

class PacketReceiver
    :public IPacketReceiver {
    public:
        PacketReceiver();
        ~PacketReceiver();
        virtual gate_t *receivePacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket) = 0;

    protected:
    private:
};

#endif /* !PACKETRECEIVER_HPP_ */
