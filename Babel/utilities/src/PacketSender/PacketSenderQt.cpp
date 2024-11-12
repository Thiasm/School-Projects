/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** PacketSenderQt
*/

#include "PacketSenderQt.hpp"
#include "unistd.h"

PacketSenderQt::PacketSenderQt(QTcpSocket *socket)
    : socket(socket)
{
    message = std::unique_ptr<Message>(new Message());
}

PacketSenderQt::~PacketSenderQt()
{
}

const bool PacketSenderQt::sendConnection(std::string const& user, std::string const& adress, int const& port)
{
    int userSize = user.size() + 1;
    char data[sizeof(gate_t) + userSize];
    
    message->encode(data, user.c_str(), RequestType::CONNECTION);
    std::cout << "Try to connect to " << adress << " : " << port << std::endl; 
    socket->connectToHost(adress.c_str(), port);
    if (socket->waitForConnected() == false) {
        std::cout << "Connection Error" << std::endl;
        socket->close();
        return false;
    }
    else {
        socket->write(data, sizeof(gate_t) + userSize);
        return true;
    }
}

void PacketSenderQt::send(std::string const& str, RequestType const& type)
{
    int strSize = str.size() + 1;
    char data[sizeof(gate_t) + strSize];

    message->encode(data, str.c_str(), type);
    socket->write(data, sizeof(gate_t) + strSize);
}