/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** PacketReceiverBoost
*/

#include "PacketReceiverBoost.hpp"
#include <iostream>
#include <unistd.h> 

static std::size_t _bytes_transferred = 0;
PacketReceiverBoost::PacketReceiverBoost()
{
}

PacketReceiverBoost::~PacketReceiverBoost()
{
}

void print_status(
  const boost::system::error_code& error,
  std::size_t bytes_transferred)
{
}

gate_t *PacketReceiverBoost::receivePacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket)
{
    Message *message;
    char str_size[4];
    uint32_t size;
    boost::system::error_code error;
  
    if (socket->is_open() == true) {
      _bytes_transferred = socket->receive(boost::asio::buffer(&str_size, 4), 0, error);
      print_status(error, _bytes_transferred);
      if (_bytes_transferred < 4)
        return nullptr;
    } else
      return nullptr;
    size = message->getSize(str_size);
    
    char str[size + 4];
    _bytes_transferred = socket->receive(boost::asio::buffer(&str, size + 4), 0, error);
    print_status(error, _bytes_transferred);

    gate_t *result = message->decode(str, size + 4);
    

    return result;
}