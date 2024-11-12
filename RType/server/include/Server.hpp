/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "ConnectionToClientManager.hpp"
#include "MessageComp.hpp"
#include <vector>
#include <utility>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>


class Server {
    public:
        Server(std::string ip, std::string port);
        ~Server();
        void launch();

    protected:
    private:
        void getConnection(std::unique_ptr<boost::asio::ip::tcp::socket> &sock, const unsigned int &current_id);
        void createThread();
        void getRequest(std::unique_ptr<boost::asio::ip::tcp::socket> &sock, const unsigned int &current_id);
        void gameUpdate(std::shared_ptr<boost::asio::ip::udp::socket> &udpsock,
                        std::shared_ptr<boost::asio::ip::udp::endpoint> &endpoint, const unsigned int &current_id);
        void joinRoom(std::unique_ptr<boost::asio::ip::tcp::socket> &sock);
        ConnectionToClientManager _connectionManager;
        std::vector<
                    std::pair<
                              unsigned int, std::unique_ptr<boost::asio::ip::tcp::socket>
                             >
                   > _client;
        MessageComp _messageComp;
        gate_t *_game_infoFirst;
        gate_t *_game_infoSecond;
        gate_t _game_infoNull;
        std::string _ip;
        unsigned int _client_id = 0;
        unsigned int _playerInRoom = 0;
        unsigned short _port;
        bool _roomExist = false;
        bool _gameLaunched = false;
        bool _getEndpoint = true;
        unsigned int _count = 0;
        boost::asio::io_context _io_context;
};

#endif /* !SERVER_HPP_ */
