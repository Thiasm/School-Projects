/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** ConnectionToServerManager
*/

#include "ConnectionToServerManager.hpp"

ConnectionToServerManager::ConnectionToServerManager()
{
    _socket = std::unique_ptr<boost::asio::ip::tcp::socket> (new boost::asio::ip::tcp::socket(_io_context));
    _udpSocket = std::shared_ptr<boost::asio::ip::udp::socket> (new boost::asio::ip::udp::socket(_io_context));
}

ConnectionToServerManager::~ConnectionToServerManager()
{
}

void ConnectionToServerManager::connect(std::string ip, unsigned short portnum)
{
    _ip = ip;
    _portnum = portnum;
    _udpSocket->open(boost::asio::ip::udp::v4());
    _socket->connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), portnum));
    std::cout << _socket->local_endpoint() << std::endl;
    if (_packetSender.sendPacketTCP(_socket, RequestType::CONNECTION) == RequestType::OK)
        std::cout << "Connected to " << ip << " " << portnum << std::endl;
    else
        std::cout << "Connection failed ip : " << ip << " port : " << portnum << std::endl;
}
RequestType ConnectionToServerManager::joinRoom()
{
    RequestType ret;
    _packetSender.sendPacketTCP(_socket, RequestType::JOIN_ROOM);
    ret = _packetReceiver.receivePacketTCPNoResponse(_socket);
    if (ret == RequestType::PLAYER1) {
        _endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::make_address(_ip), _portnum + 1);
    }
    else if (ret == RequestType::PLAYER2) {
        _endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::make_address(_ip), _portnum + 2);
    }
    return ret;
}

void ConnectionToServerManager::sendGameInfo(gate_t *gameinfo)
{
    _packetSender.sendPacketUDP(_udpSocket, _endpoint, *gameinfo);
}

gate_t *ConnectionToServerManager::receiveGameInfo()
{
    return _packetReceiver.receivePacketUDP(_udpSocket, _endpoint);
}

bool ConnectionToServerManager::getRoomInfo(bool &gameLaunched)
{
    RequestType resp = RequestType::OK;
    RequestType recv = _packetReceiver.receivePacketTCPNoResponse(_socket);
    if (gameLaunched == true)
        resp = RequestType::LAUNCH_GAME;
    _packetSender.sendPacketTCPNoResponse(_socket, resp);

    if (recv == RequestType::LAUNCH_GAME)
        gameLaunched = true;
    else if (recv == RequestType::PLAYER2) {
        return true;
    }
    return false; // else
    
}

void ConnectionToServerManager::disconnect()
{
    _packetSender.sendPacketTCP(_socket, RequestType::DISCONNECTION);
}