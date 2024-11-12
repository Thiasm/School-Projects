/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** PacketSenderBoost
*/

#include "PacketSenderBoost.hpp"

PacketSenderBoost::PacketSenderBoost()
{
}

PacketSenderBoost::~PacketSenderBoost()
{
}

void PacketSenderBoost::sendPacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket, Message &message, const char *content, RequestType type)
{
    size_t size = strlen(content);
    char code[sizeof(gate_t) + size];

    message.encode(code, content, type);
    socket->send(boost::asio::buffer(code, sizeof(gate_t) + size));
}
