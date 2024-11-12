/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** UdpSocket
*/

#include "../include/UdpSocket.hpp"

UdpSocket::UdpSocket()
    : socket(new QUdpSocket(this))
{
    socket->bind(QHostAddress::LocalHost, 0, QUdpSocket::DontShareAddress);
}

UdpSocket::~UdpSocket()
{
    socket->close();
}

std::string const UdpSocket::getPort()
{
    return std::to_string(socket->localPort());
}

std::string const UdpSocket::getAddress()
{
    return socket->localAddress().toString().toStdString();
}
