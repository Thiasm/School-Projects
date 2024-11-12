/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** clientConnect
*/

#include "../include/clientConnect.hpp"
#include <QByteArray>
#include "../include/Audio/PAudio.hpp"
#include <unistd.h> 
#include <sstream>
#include <QApplication>

clientSocket::clientSocket(int const& port, std::string const& username)
    : serverAdress("127.0.0.1")
    , serverPort(port)
    , username(username)
    , connected(false)
    , calling(false)
    , TCPsocket(new QTcpSocket(this))
{
    receiver = std::unique_ptr<PacketReceiverQt> (new PacketReceiverQt(TCPsocket));
    sender = std::unique_ptr<PacketSenderQt> (new PacketSenderQt(TCPsocket));
    QDialog::connect(this->TCPsocket, &QIODevice::readyRead, this, &clientSocket::handleRead);
}

void clientSocket::handleRead()
{
    gate_t *message = receiver->receive();

    switch (message->type)
    {
    case RequestType::CONNECTION:
        this->connected = true;
        std::cout << "Connected" << std::endl;
        break;
    case RequestType::DISCONNECTION:
        this->connected = false;
        launchDisconnection(message->content);
        break;
    case RequestType::CALL:
        launchCall(message->content);
        break;
    case RequestType::RECEIVE_CALL:
        launchReceiveCall(message->content);
        break;
    case RequestType::UPDATE:
        launchUpdate(message->content);
        break;
    case RequestType::HANG_UP:
        launchHangUp(message->content);
        break;
    }
    std::free(message);
    return;
}

void clientSocket::sendConnect()
{   
    sender->sendConnection(this->username, this->serverAdress, this->serverPort);
}

void clientSocket::sendServer(std::string const& content, RequestType const& type)
{
    if (this->connected == false) {
        std::cout << "Not Connected: Try Again" << std::endl;
        sender->sendConnection(this->username, this->serverAdress, this->serverPort);
    }
    if (type == RequestType::CALL) {
        std::unique_ptr<UdpSocket> CallSocket = std::unique_ptr<UdpSocket> (new UdpSocket());
        
        this->UDPport = std::stoi(CallSocket->getPort());
        this->currentCall = content;
        std::string data = content + "|" + std::to_string(UDPport);
        sender->send(data, type);
    }
    else
        sender->send(content, type);
}

void clientSocket::launchCall(std::string const& content)
{
    if (content == "ko") {
        std::cout << "call failed" << std::endl;
        return;
    }
    std::cout << "Call is succes:" << std::endl;
    this->calling = true;

    this->otherUDPport = getPort(content);
    _client = new my_PAudio("127.0.0.1", UDPport, std::to_string(otherUDPport));
    _client->LaunchVoip();
}

void clientSocket::launchReceiveCall(std::string const& content)
{
    std::unique_ptr<UdpSocket> CallSocket = std::unique_ptr<UdpSocket> (new UdpSocket());
    
    if (content == "ko") {
        std::cout << "call failed" << std::endl;
        return;
    }
    this->calling = true;
    this->otherUDPport = getPort(content);
    this->currentCall = getName(content);

    std::cout << "Receive Call from : " << currentCall << std::endl;
    this->_client = new my_PAudio("127.0.0.1", std::stoi(CallSocket->getPort()), std::to_string(otherUDPport));
    std::string _data = CallSocket->getPort() + "|" + CallSocket->getPort() + "|" + "true";
    
    sender->send(_data, RequestType::RECEIVE_CALL);
    _client->LaunchVoip();
}

void clientSocket::launchHangUp(std::string const& content)
{
    if (this->calling == true) {
        _client->StopCall();
        this->calling = false;
    }
    else
        std::cout << "Not In Call !" << std::endl;
}

void clientSocket::sendHangUp()
{
    if (this->calling == true) {
        this->calling = false;
        _client->StopCall();
        std::cout << "currentCall :" << currentCall << std::endl;
        sender->send(this->currentCall, RequestType::HANG_UP);
        this->currentCall.clear();
    }
    else
        std::cout << "Not In Call !" << std::endl;

}

void clientSocket::launchUpdate(std::string const& content)
{
    std::string result = content;
    std::string token = "";
    size_t pos = 0;

    this->contactList.clear();
    while ((pos = result.find("|")) != std::string::npos) {
        token = result.substr(0, pos);
        result.erase(0, pos + 1);
        this->contactList.push_back(token);
    }
}

void clientSocket::launchDisconnection(std::string const& content)
{
    std::cout << "Disconnected" << std::endl;
    qApp->exit();
}

std::vector<std::string> const clientSocket::getContactList()
{
    return this->contactList;
}

int const clientSocket::getPort(std::string str)
{
    std::string token = str.substr(0, str.find("|"));

    return std::stoi(token);
}

std::string const clientSocket::getName(std::string str)
{
    std::string token = str.substr(str.find("|") + 1, str.size());

    return token;
}

bool const clientSocket::getResponse(std::string str)
{
    return true;
}