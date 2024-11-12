/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** PacketReceiverBoost
*/

#include "PacketReceiverBoost.hpp"
#include <iostream>
#include <unistd.h>

PacketReceiverBoost::PacketReceiverBoost()
{
}

PacketReceiverBoost::~PacketReceiverBoost()
{
}

void print_status(
  const boost::system::error_code& error,
  std::size_t bytes_transferred)
{
}

gate_t *PacketReceiverBoost::receivePacketUDP(std::shared_ptr<boost::asio::ip::udp::socket> &socket, std::shared_ptr<boost::asio::ip::udp::endpoint> &endpoint, bool getEndpoint)
{
    std::size_t bytes_transferred = 0;
    char str_type[4];
    RequestType type;
    char str_size[4];
    uint32_t size;
    boost::system::error_code error;
    char *str = (char *)std::malloc(1024);
    boost::asio::ip::udp::endpoint temp;
    
    if (socket->is_open() == true) {
        bytes_transferred = socket->receive_from(boost::asio::buffer(str, 1024), temp);

        if (bytes_transferred < 4) {
            return nullptr;
        }
        if (getEndpoint == true)
            endpoint->operator=(temp);
        memcpy(&type, str, 4);
        if (type == RequestType::DISCONNECTION) {
            exit(0);
        }
        str += 4;
        memcpy(&size, str, 4);
        str += 4;
        gate_t *result = _messageComp.decode(str, size);
        return result;
    } else {
        return nullptr;
    }
}
gate_t *PacketReceiverBoost::receivePacketUDP(std::shared_ptr<boost::asio::ip::udp::socket> &socket, boost::asio::ip::udp::endpoint &endpoint)
{
    std::size_t bytes_transferred = 0;
    char str_type[4];
    RequestType type;
    char str_size[4];
    uint32_t size;
    boost::system::error_code error;
    char *str = (char *)std::malloc(1024);
    
    if (socket->is_open() == true) {
        bytes_transferred = socket->receive_from(boost::asio::buffer(str, 1024), endpoint);

        if (bytes_transferred < 4) {
            return nullptr;
        }
        memcpy(&type, str, 4);
        if (type == RequestType::DISCONNECTION) {
            std::cout << "Client deconnects" << std::endl;
            exit(0);
        }
        str += 4;
        memcpy(&size, str, 4);
        str += 4;
        gate_t *result = _messageComp.decode(str, size);
        return result;
    } else {
        return nullptr;
    }
}

RequestType PacketReceiverBoost::receivePacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket)
{
    RequestType recv = RequestType::UNKNOWN;
    RequestType resp = RequestType::UNKNOWN;
    std::size_t bytes_transferred = 0;

    if (socket->is_open() == true) {
        bytes_transferred = socket->receive(boost::asio::buffer(&recv, sizeof(RequestType)));
    } else
        return RequestType::UNKNOWN;
    if (bytes_transferred < sizeof(RequestType))
        return RequestType::UNKNOWN;
    if (recv == RequestType::UNKNOWN)
        return RequestType::UNKNOWN;
    resp = RequestType::OK;
    socket->send(boost::asio::buffer(&resp, sizeof(RequestType)));
    return recv;
}


RequestType PacketReceiverBoost::receivePacketTCPNoResponse(std::unique_ptr<boost::asio::ip::tcp::socket> &socket)
{
    RequestType recv = RequestType::UNKNOWN;
    std::size_t bytes_transferred = 0;

    if (socket->is_open() == true) {
        bytes_transferred = socket->receive(boost::asio::buffer(&recv, sizeof(RequestType)));
    } else
        return RequestType::UNKNOWN;
    if (bytes_transferred < sizeof(RequestType))
        return RequestType::UNKNOWN;
    return recv;
}