/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** UdpSocket
*/

#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_

#include <QUdpSocket>
#include <QObject>
#include <iostream>

class UdpSocket : public QObject
{
    Q_OBJECT
 
    public:
        UdpSocket();
        ~UdpSocket();
        std::string const getPort();
        std::string const getAddress();

    protected:
    private:
        QUdpSocket *socket;
};

#endif /* !UdDSOCKET_HPP_ */
