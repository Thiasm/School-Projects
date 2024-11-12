/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** Server
*/

#include "Server.hpp"

Server::Server()
{
}

Server::~Server()
{
}

void Server::launch(std::string ip, std::string port)
{
    _ip = ip;
    _port = std::stoi(port);
    _connectionManager.launch(_ip, _port);
    for (;;) {
            removeOldSocket();
            getConnection();
        for (unsigned int i = 0; i < _client.size(); i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            getRequest(i);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Server::removeOldSocket()
{
    if (_client.size() == 0)
        return;
    for (unsigned int i = 0; i < _client.size(); i++)
        if (_client[i]->getName() == "")
            _client.erase(_client.begin() + i);
}

void Server::getConnection()
{
    std::unique_ptr<boost::asio::ip::tcp::socket> sock;
    _connectionManager.createSocket(sock);
    std::string name = "";
    std::unique_ptr<ClientID> new_client (new ClientID(name, sock));
    _connectionManager.searchConnection(new_client);
    _client.push_back(std::move(new_client));
}

void Server::getRequest(unsigned int i)
{
    gate_t *message;
    
    message = _connectionManager.getRequest(_client[i]);
    if (message == nullptr)
        return;

    switch (message->type)
    {
    case RequestType::CONNECTION:
        if (_client[i]->getName() == "")
            _connectionManager.searchConnection(_client[i]);
    case RequestType::DISCONNECTION:
        _connectionManager.deco(_client[i]);
        _client.erase(_client.begin() + i);
        break;
    case RequestType::CALL:
        _connectionManager.call(_client[i], _client, message);
        break;
    case RequestType::UPDATE:
        _connectionManager.update(_client[i], _client);
        break;
    case RequestType::HANG_UP:
        _connectionManager.hangUp(_client[i], _client, message);
        break;
    }
    std::free(message);
    return;
}
