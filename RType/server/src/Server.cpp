/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(std::string ip, std::string port)
{
    _ip = ip;
    _port = std::stoi(port);
    _connectionManager.launch(_ip, _port);

    _game_infoFirst = (gate_t *)std::malloc(sizeof(gate_t));
    _game_infoSecond = (gate_t *)std::malloc(sizeof(gate_t));
    _game_infoFirst->size = 0;
    _game_infoSecond->size = 0;
    _game_infoNull.type = RequestType::GAME_UPDATE;
    _game_infoNull.size = sizeof(gate_t);
    _game_infoNull.size_1 = 0;
    _game_infoNull.size_2 = 0;
    _game_infoNull.size_3 = 0;
}

Server::~Server()
{
}

void Server::launch()
{
    std::cout << "thread launched" << std::endl;
    std::mutex locker;
    locker.lock();
    unsigned int current_id = _client_id++;
    locker.unlock();
    std::unique_ptr<boost::asio::ip::tcp::socket> sock;

    std::shared_ptr<boost::asio::ip::udp::socket> _udpsock = std::unique_ptr<boost::asio::ip::udp::socket> (new boost::asio::ip::udp::socket(_io_context,
                                                    boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(_ip), _port + current_id + 1)));
    std::shared_ptr<boost::asio::ip::udp::endpoint> endpoint = std::make_shared<boost::asio::ip::udp::endpoint>();
    std::cout << _udpsock->local_endpoint() << std::endl;
    getConnection(sock, current_id);
    for (;;) {
        locker.lock();
        if (_gameLaunched == true)
            break;
        else
            getRequest(sock, current_id);
        locker.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    for (;;) {
        gameUpdate(_udpsock, endpoint, current_id);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void Server::getConnection(std::unique_ptr<boost::asio::ip::tcp::socket> &sock, const unsigned int &current_id)
{
    std::mutex locker;
    _connectionManager.createSocket(sock);
    _connectionManager.searchConnection(sock);
    createThread();
}

void Server::createThread()
{
    std::thread{&Server::launch, this}.detach();
}

void Server::getRequest(std::unique_ptr<boost::asio::ip::tcp::socket> &sock, const unsigned int &current_id)
{
    RequestType type;
    type = _connectionManager.getRequest(sock);
    if (type == RequestType::UNKNOWN)
        return;

    switch (type)
    {
    case RequestType::JOIN_ROOM:
        joinRoom(sock);
        break;
    case RequestType::DISCONNECTION:
        _connectionManager.deco(sock);
        break;
    }
    return;
}

void Server::gameUpdate(std::shared_ptr<boost::asio::ip::udp::socket> &udpsock, std::shared_ptr<boost::asio::ip::udp::endpoint> &endpoint, const unsigned int &current_id)
{
    if (_count < 10)
        _count++;
    else
        _getEndpoint = false;
    gate_t *gameinfo;
    std::mutex locker;
    gameinfo = _connectionManager.getRequestGame(udpsock, endpoint, _getEndpoint);

    if (gameinfo == nullptr)
        return;
    locker.lock();
    if (current_id == 0) {
        _messageComp.fulfillStruct(gameinfo, _game_infoFirst);
        if (_game_infoSecond->size != 0 && _game_infoFirst->size != 0)
            _connectionManager.sendGameInfo(udpsock, *endpoint, _game_infoSecond);
        else
            _connectionManager.sendGameInfo(udpsock, *endpoint, _game_infoNull);
    }
    else {
        _messageComp.fulfillStruct(gameinfo, _game_infoSecond);
        if (_game_infoFirst->size != 0 && _game_infoSecond->size != 0)
            _connectionManager.sendGameInfo(udpsock, *endpoint, _game_infoFirst);
        else
            _connectionManager.sendGameInfo(udpsock, *endpoint, _game_infoNull);
    }
    locker.unlock();
    free(gameinfo);
    return;
}

void Server::joinRoom(std::unique_ptr<boost::asio::ip::tcp::socket> &sock)
{
    std::mutex locker;
    _connectionManager.joinRoom(sock, _roomExist);
    RequestType nbrPlayerInRoom = RequestType::PLAYER1;
    _playerInRoom++;
    do {
        locker.lock();
        if (_gameLaunched == true) {
            _connectionManager.gameStart(sock);
            locker.unlock();
            break;
        }
        if (_playerInRoom > 1)
            nbrPlayerInRoom = RequestType::PLAYER2;
        if (_roomExist == false)
            _roomExist = true;
        locker.unlock();
    } while (_connectionManager.gameIsStarted(sock, nbrPlayerInRoom) == false);
    _connectionManager.gameStart(sock);
    locker.lock();
    _gameLaunched = true;
    locker.unlock();
}