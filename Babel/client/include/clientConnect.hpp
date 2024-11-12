/*
** EPITECH PROJECT, 2020
** clientConnect
** File description:
** clientConnect
*/

#ifndef CLIENTCONNECT_HPP_
#define CLIENTCONNECT_HPP_

#include <QObject>
#include <QTcpSocket>
#include <QDialog>
#include <iostream>
#include "../include/Audio/PAudio.hpp"
#include "../include/UdpSocket.hpp"
#include "../../utilities/include/Message.hpp"
#include "../../utilities/include/PacketReceiver/PacketReceiverQt.hpp"
#include "../../utilities/include/PacketSender/PacketSenderQt.hpp"


/**
 * Here a snapshot of the Communication Protocol:
 * \image html Communication_Protocol.png
 */

class clientSocket : public QObject
{
    Q_OBJECT

public:
    clientSocket(int const&, std::string const&);

    void sendConnect();
    void sendServer(std::string const&, RequestType const&);
    
    void sendHangUp();
    void launchCall(std::string const&);
    void launchReceiveCall(std::string const&);
    void launchHangUp(std::string const&);
    void launchUpdate(std::string const&);
    void launchDisconnection(std::string const&);
    
    bool const getResponse(std::string);
    int const getPort(std::string);
    std::string const getName(std::string);
    void handleRead();
    std::vector<std::string> const getContactList();

private:
    QTcpSocket *TCPsocket;
    my_PAudio *_client;


    const std::string username;
    std::vector<std::string> contactList;

    // Current TCP data 
    const std::string serverAdress;
    const int serverPort;
    
    // current UDP port
    int UDPport;

    // other UDP port
    int otherUDPport;

    std::unique_ptr<PacketSenderQt> sender;
    std::unique_ptr<PacketReceiverQt> receiver;
    std::unique_ptr<UdpSocket> CallSocket;
    bool connected; // is connected ?
    bool calling; // is calling ?
    std::string currentCall; //Current contact in call
};
#endif /* !CLIENTCONNECT_HPP_ */
