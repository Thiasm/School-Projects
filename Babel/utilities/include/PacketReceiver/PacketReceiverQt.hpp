/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** PacketReceiverQt
*/

#ifndef PACKETRECEIVERQT_HPP_
#define PACKETRECEIVERQT_HPP_

#include <QObject>
#include <QTcpSocket>
#include <iostream>
#include "../Message.hpp"

class PacketReceiverQt {
    public:
        PacketReceiverQt(QTcpSocket *);
        ~PacketReceiverQt();
        gate_t *receive();
    protected:
    private:
        QTcpSocket *socket;
        Message message;
};

#endif /* !PACKETRECEIVERQT_HPP_ */
