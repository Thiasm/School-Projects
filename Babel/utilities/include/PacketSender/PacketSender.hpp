/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** PacketSender
*/

#ifndef PACKETSENDER_HPP_
#define PACKETSENDER_HPP_

#include "IPacketSender.hpp"

class PacketSender
    :public IPacketSender {
    public:
        PacketSender();
        ~PacketSender();
        virtual void sendPacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket, Message &message, const char *content, RequestType type) = 0;
    protected:
    private:
};

#endif /* !PACKETSENDER_HPP_ */
