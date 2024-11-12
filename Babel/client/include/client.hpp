/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** babelClient
*/

#ifndef BABELCLIENT_HPP_
#define BABELCLIENT_HPP_

#include "Iclient.hpp"

class babelClient
{
private:
    bool isConnected;
    bool isCalling;
    std::string clientName;
    std::vector<std::string> contactList;

public:
    babelClient(int);
    ~babelClient();
    std::unique_ptr<clientSocket> clientConnect;
    void launch();
    const std::string getUsername();
};

#endif /* !BABELCLIENT_HPP_ */
