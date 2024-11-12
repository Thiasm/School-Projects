/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** ConnectionToClientManager
*/

#include "ConnectionToClientManager.hpp"
#include <boost/lexical_cast.hpp>

ConnectionToClientManager::ConnectionToClientManager()
{
}

ConnectionToClientManager::~ConnectionToClientManager()
{
}

void ConnectionToClientManager::launch(std::string &ip, unsigned short &portnum)
{
    _acceptor = std::unique_ptr<boost::asio::ip::tcp::acceptor> (new boost::asio::ip::tcp::acceptor(_io_context,
                                                    boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), portnum)));
}

void ConnectionToClientManager::createSocket(std::unique_ptr<boost::asio::ip::tcp::socket> &sock)
{
    sock = std::unique_ptr<boost::asio::ip::tcp::socket> (new boost::asio::ip::tcp::socket(_io_context));
}

void ConnectionToClientManager::searchConnection(std::unique_ptr<boost::asio::ip::tcp::socket> &client) // cherche si un client veux se connecter
{
    RequestType messageRCV;
    boost::system::error_code error;

    _acceptor->accept(*client, error);
    std::cout << "Connection to client accepted" << std::endl;
    if (client->is_open() == false) {
        return;
    }
    messageRCV = _packetReceiver.receivePacketTCP(client);
    if (messageRCV == RequestType::UNKNOWN)
        return;
    if (messageRCV != RequestType::CONNECTION) {
        return;
    }
}

RequestType ConnectionToClientManager::getRequest(std::unique_ptr<boost::asio::ip::tcp::socket> &client) // cherche si un client connecté envoie une requete
{
    return _packetReceiver.receivePacketTCP(client);
}

RequestType ConnectionToClientManager::getRequestNoResponse(std::unique_ptr<boost::asio::ip::tcp::socket> &client) // cherche si un client connecté envoie une requete
{
    return _packetReceiver.receivePacketTCPNoResponse(client);
}

gate_t *ConnectionToClientManager::getRequestGame(std::shared_ptr<boost::asio::ip::udp::socket> &client, std::shared_ptr<boost::asio::ip::udp::endpoint> &_endpoint, bool getEndpoint) // cherche si un client connecté envoie une requete
{
    return _packetReceiver.receivePacketUDP(client, _endpoint, getEndpoint);
}

void ConnectionToClientManager::joinRoom(std::unique_ptr<boost::asio::ip::tcp::socket> &sock, bool roomExist)
{
    if (roomExist == false) {
        _packetSender.sendPacketTCPNoResponse(sock, RequestType::PLAYER1);
    }
    else {
        _packetSender.sendPacketTCPNoResponse(sock, RequestType::PLAYER2);
    }
}

bool ConnectionToClientManager::gameIsStarted(std::unique_ptr<boost::asio::ip::tcp::socket> &sock, RequestType nbrPlayerInRoom)
{
    if (_packetSender.sendPacketTCP(sock, nbrPlayerInRoom) == RequestType::LAUNCH_GAME)
        return true;
    else
        return false;
}

void ConnectionToClientManager::gameStart(std::unique_ptr<boost::asio::ip::tcp::socket> &sock)
{
    std::cout << "gameStarted" << std::endl;
    _packetSender.sendPacketTCPNoResponse(sock, RequestType::LAUNCH_GAME);
}

void ConnectionToClientManager::sendGameInfo(std::shared_ptr<boost::asio::ip::udp::socket> &sock, boost::asio::ip::udp::endpoint &_endpoint, gate_t &gameinfo)
{
    _packetSender.sendPacketUDP(sock, _endpoint, gameinfo);
}

void ConnectionToClientManager::sendGameInfo(std::shared_ptr<boost::asio::ip::udp::socket> &sock, boost::asio::ip::udp::endpoint &_endpoint, gate_t *gameinfo)
{
    _packetSender.sendPacketUDP(sock, _endpoint, gameinfo);
}

void ConnectionToClientManager::deco(std::unique_ptr<boost::asio::ip::tcp::socket> &client) // s'occupe de deco
{
    client->close();
}
