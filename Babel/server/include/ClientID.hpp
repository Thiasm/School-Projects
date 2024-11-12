/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** ClientID
*/

#ifndef CLIENTID_HPP_
#define CLIENTID_HPP_

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <string>
#include <utility>

class ClientID {
    public:
        ClientID(std::string &name, std::unique_ptr<boost::asio::ip::tcp::socket> &socket);
        ~ClientID();
        void setName(std::string name);
        std::string &getName();
        std::unique_ptr<boost::asio::ip::tcp::socket> &getSocket();

    protected:
    private:
        std::string _name;
        std::unique_ptr<boost::asio::ip::tcp::socket> _socket;

};

#endif /* !CLIENTID_HPP_ */
