/*
** EPITECH PROJECT, 2020
** error_handling_arguments
** File description:
** babel
*/

#include "../include/errorServer.hpp"

errorServer::errorServer(int argc, char **argv)
{
    checkNumbArg(argc);
    if (_isError == false) {
        checkFirstArg(std::string(argv[1]));
        checkSecondArg(std::string(argv[2]));
    }
}

void errorServer::checkNumbArg(int argc)
{
    if (argc != 3) {
        _isError = true;
        std::cout << "The program has to be execute like : ./babel_server 127.0.0.1 \"port\"" << std::endl;
    }
}

void errorServer::checkFirstArg(std::string str)
{
    if (str != "127.0.0.1") {
        _isError = true;
        std::cout << "the IP adress must be 127.0.0.1" << std::endl;
    }
}

void errorServer::checkSecondArg(std::string str)
{
    int nb;

    if (str.find_first_not_of("0123456789") != str.npos) {
        _isError = true;
        std::cout << "Only positive number for port argument" << std::endl;
        return;
    }
    nb = stoi(str);
    if (nb < 1024 || nb > 65535) {
        _isError = true;
        std::cout << "your port must be between 1024 and 65535" << std::endl;
    }
}

bool errorServer::getIsError() const
{
    return (_isError);
}