/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** PacketSenderQt
*/

#ifndef PACKETSENDERQT_HPP_
#define PACKETSENDERQT_HPP_

#include <QObject>
#include <QTcpSocket>
#include <iostream>
#include "../Message.hpp"

class PacketSenderQt {
    public:
        PacketSenderQt(QTcpSocket *);
        ~PacketSenderQt();
        const bool sendConnection(std::string const&, std::string const&, int const&);
        void send(std::string const&, RequestType const&);
    protected:
    private:
        QTcpSocket *socket;
        std::unique_ptr<Message> message;
};

#endif /* !PACKETSENDERQT_HPP_ */
