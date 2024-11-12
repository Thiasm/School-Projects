/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** PacketSenderBoost
*/

#ifndef PACKETSENDERBOOST_HPP_
#define PACKETSENDERBOOST_HPP_

#include "PacketSender.hpp"

class PacketSenderBoost
    :public PacketSender {
    public:
        PacketSenderBoost();
        ~PacketSenderBoost();
        void sendPacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket, Message &message, const char *content, RequestType type);
    protected:
    private:
};

#endif /* !PACKETSENDERBOOST_HPP_ */
