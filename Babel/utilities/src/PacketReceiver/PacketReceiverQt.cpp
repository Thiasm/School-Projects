/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** PacketReceiverQt
*/

#include "PacketReceiverQt.hpp"
#include <unistd.h> 

PacketReceiverQt::PacketReceiverQt(QTcpSocket *socket)
    : socket(socket)
    , message()
{
}

PacketReceiverQt::~PacketReceiverQt()
{
}

gate_t *PacketReceiverQt::receive()
{
    uint32_t size;
    char str_size[4];
    
    socket->read(str_size, 4);
    size = message.getSize(str_size);
    char str[size + 4];
    socket->read(str, size + 4);
    str[size + 3] = '\0';
    return message.decode(str, size + 4);
}
