/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** babelClient
*/

#include "../include/client.hpp"
#include "../include/mainwindow.h"

babelClient::babelClient(int port)
    : isConnected(false)
    , isCalling(false)
    , clientName(getUsername())
{
    clientConnect = std::unique_ptr<clientSocket> (new clientSocket(port, this->clientName));
}

babelClient::~babelClient()
{
}

void babelClient::launch()
{
    clientConnect->sendConnect();
}

const std::string babelClient::getUsername()
{
    std::string name;

    std::cout << "Please, enter your Username:" << std::endl;
    std::getline(std::cin, name);

    return name;
}