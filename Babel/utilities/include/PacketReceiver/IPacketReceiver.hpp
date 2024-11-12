/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** IPacketReceiver
*/

#ifndef IPACKETRECEIVER_HPP_
#define IPACKETRECEIVER_HPP_

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <string>
#include "Message.hpp"

class IPacketReceiver {
    public:
        virtual ~IPacketReceiver() = default;
        virtual gate_t *receivePacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket) = 0; //template à mettre
    protected:
    private:
};

#endif /* !IPACKETRECEIVER_HPP_ */
