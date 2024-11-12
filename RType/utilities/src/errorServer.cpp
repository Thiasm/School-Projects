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
        std::cout << "The program has to be execute like : ./babel_server \"IP\" \"port\"" << std::endl;
    }
}

void errorServer::checkFirstArg(std::string str)
{
    unsigned int count = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.')
            count++;
        else if (str[i] < '0' || str[i] > '9') {
            std::cout << "The program has to be execute like :"<< str[i] << "./babel_server \"IP\" \"port\"" << std::endl;
            _isError = true;
        }
    }
    if (count != 3) {
        std::cout << "The program has to be execute like : ./babel_server \"IP\" \"port\"" << std::endl;
        _isError = true;
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