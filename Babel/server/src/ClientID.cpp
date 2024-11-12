/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** ClientID
*/

#include "ClientID.hpp"

ClientID::ClientID(std::string &name, std::unique_ptr<boost::asio::ip::tcp::socket> &socket)
{
    _name = name;
    _socket = std::move(socket);
}

ClientID::~ClientID()
{
}

void ClientID::setName(std::string name)
{
    _name = name;
}
std::string &ClientID::getName()
{
    return _name;
}
std::unique_ptr<boost::asio::ip::tcp::socket> &ClientID::getSocket()
{
    return _socket;
}