/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
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

void send_status(
  const boost::system::error_code& error,
  std::size_t bytes_transferred)
{
}

void PacketSenderBoost::sendPacketUDP(std::shared_ptr<boost::asio::ip::udp::socket> &socket, boost::asio::ip::udp::endpoint &endpoint, gate_t &gameInfo)
{

    size_t size = gameInfo.size + 8;
    char code[size];
    char *ptr;
    ptr = _messageComp.encode(code, gameInfo);
    socket->send_to(boost::asio::buffer(ptr, size), endpoint);

}
void PacketSenderBoost::sendPacketUDP(std::shared_ptr<boost::asio::ip::udp::socket> &socket, boost::asio::ip::udp::endpoint &endpoint, gate_t *gameInfo)
{

    size_t size = gameInfo->size + 8;
    char code[size];
    char *ptr;
    ptr = _messageComp.encode(code, *gameInfo);
    if (socket->is_open())
        socket->send_to(boost::asio::buffer(ptr, size), endpoint);
    else
        std::cout << "socket not open" << std::endl;

}

RequestType PacketSenderBoost::sendPacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket,
                           RequestType type)
{
    std::size_t ret;
    RequestType recv;

    socket->send(boost::asio::buffer(&type, sizeof(RequestType)));
    ret = socket->receive(boost::asio::buffer(&recv, sizeof(RequestType)));
    if (ret < sizeof(RequestType))
        return RequestType::KO;
    return recv;
}

void PacketSenderBoost::sendPacketTCPNoResponse(std::unique_ptr<boost::asio::ip::tcp::socket> &socket,
                           RequestType type)
{
    socket->send(boost::asio::buffer(&type, sizeof(RequestType)));
}