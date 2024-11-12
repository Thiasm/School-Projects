/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
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

void accept_handler(const boost::system::error_code& error)
{
  if (!error)
  {
    std::cout << "accepted" << std::endl;// Accept succeeded.
  } else {
      std::cout << "not accepted" << std::endl;
  }
}

void ConnectionToClientManager::createSocket(std::unique_ptr<boost::asio::ip::tcp::socket> &sock)
{
    sock = std::unique_ptr<boost::asio::ip::tcp::socket> (new boost::asio::ip::tcp::socket(_io_context));
}

void ConnectionToClientManager::searchConnection(std::unique_ptr<ClientID> &new_client) // cherche si un client veux se connecter
{
    gate_t *messageRCV;
    Message messageSend;
    std::string response = "connected";
    boost::system::error_code error;

    _acceptor->non_blocking(true);
    _acceptor->accept(*(new_client->getSocket()), error);
    if (new_client->getSocket()->is_open() == false) {
        return;
    }
    new_client->getSocket()->non_blocking(true);
    messageRCV = _packetReceiver.receivePacketTCP(new_client->getSocket());
    if (messageRCV == nullptr)
        return;
    if (messageRCV->type != RequestType::CONNECTION) {
        return;
    }
    new_client->setName(std::string(messageRCV->content));
    std::free(messageRCV);
    _packetSender.sendPacketTCP(new_client->getSocket(), messageSend, "ok", RequestType::CONNECTION);
}

gate_t *ConnectionToClientManager::getRequest(std::unique_ptr<ClientID> &client) // cherche si un client connecté envoie une requete
{
    return _packetReceiver.receivePacketTCP(client->getSocket());
}

void ConnectionToClientManager::deco(std::unique_ptr<ClientID> &client) // s'occupe de deco
{
    Message messageSend;
    
    _packetSender.sendPacketTCP(client->getSocket(), messageSend, "ok", RequestType::DISCONNECTION);
    client->getSocket()->close();
}

std::string ConnectionToClientManager::getNameInCallBuff(const std::string content)
{
    if (content.find("|") == content.size())
        return std::string("");

    return content.substr(0, content.find("|"));
}

std::string ConnectionToClientManager::getPortInCallBuff(const std::string content)
{
    std::string take = content;
    std::string delimiter = "|";

    size_t pos = 0;
    std::string token;
    while ((pos = take.find(delimiter)) != std::string::npos) {
        token = take.substr(0, pos);
        take.erase(0, pos + delimiter.length());
    }
    return take;
}

void ConnectionToClientManager::getPortInReceiveCallBuff(const std::string content, std::string &port1, std::string &portnbool)
{
    if (content.find("|") == content.size())
        return;
    
    port1 = content.substr(0, content.find("|"));
    portnbool = content.substr(content.find("|") + 1, content.find("|") + 1 - content.find("e"));
}

void ConnectionToClientManager::call(std::unique_ptr<ClientID> &client, std::vector<std::unique_ptr<ClientID>> &clientList,
                                     gate_t *message) // s'occupe de l'appel
{
    Message messageSend;
    gate_t *clientTwoResponse;
    std::string name;
    std::string port;
    std::string portTemp = "";
    std::string port1 = "";
    std::string portnbool = "";

    name = getNameInCallBuff(message->content);
    port = getPortInCallBuff(message->content);

    std::cout << "Calling: " << name << " Port : " << port << std::endl;
    if (name == "" || port == "") {
        std::cout << "wrong call message sent by client" << std::endl;
        return;
    }
    for (int i = 0; i < clientList.size(); i++)
        if (clientList[i]->getName() == name) {
            port = port + "|" + client->getName();

            _packetSender.sendPacketTCP(clientList[i]->getSocket(), messageSend, port.c_str(), RequestType::RECEIVE_CALL);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            clientTwoResponse = _packetReceiver.receivePacketTCP(clientList[i]->getSocket());
            if (clientTwoResponse == nullptr) {
                std::cout << "Call failed" << std::endl;
                return;
            }
            std::string clientTwoResponseContent = clientTwoResponse->content;
            getPortInReceiveCallBuff(clientTwoResponseContent, port1, portnbool);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            _packetSender.sendPacketTCP(client->getSocket(), messageSend, portnbool.c_str(), RequestType::CALL);
            std::free(clientTwoResponse);
            return;
        }
    _packetSender.sendPacketTCP(client->getSocket(), messageSend, "ko", RequestType::CALL);
}

void ConnectionToClientManager::hangUp(std::unique_ptr<ClientID> &client, std::vector<std::unique_ptr<ClientID>> &clientList,
                                     gate_t *message) // s'occupe de l'appel
{
    Message messageSend;
    gate_t *clientTwoResponse;

    for (int i = 0; i < clientList.size(); i++)
        if (clientList[i]->getName() == message->content) {
            _packetSender.sendPacketTCP(clientList[i]->getSocket(), messageSend, "", RequestType::HANG_UP);
            return;
        }
    _packetSender.sendPacketTCP(client->getSocket(), messageSend, "ko", RequestType::HANG_UP);
}

void ConnectionToClientManager::update(std::unique_ptr<ClientID> &client, std::vector<std::unique_ptr<ClientID>> &clientList) // se connecte à l'utilisateur qui est appelé
{
    Message messageSend;
    std::string clientName = client->getName();
    std::string nameList("");
    
    if (clientList.size() == 1 || clientList.size() == 0) {
        _packetSender.sendPacketTCP(client->getSocket(), messageSend, nameList.c_str(), RequestType::UPDATE);
        return;
    }
    for (unsigned int i = 0; i < clientList.size(); i++)
        if (clientList[i]->getName() != clientName) {
            if (nameList != "")
                nameList += "|";
            nameList += clientList[i]->getName();
            }
    _packetSender.sendPacketTCP(client->getSocket(), messageSend, nameList.c_str(), RequestType::UPDATE);
}
