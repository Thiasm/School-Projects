/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** IPacketSender
*/

#ifndef IPACKETSENDER_HPP_
#define IPACKETSENDER_HPP_

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include "Message.hpp"

class IPacketSender {
    public:
        virtual ~IPacketSender() = default;
        virtual void sendPacketTCP(std::unique_ptr<boost::asio::ip::tcp::socket> &socket, Message &message, const char *content, RequestType type) = 0; //mettre template
    protected:
    private:
};

#endif /* !IPACKETSENDER_HPP_ */
