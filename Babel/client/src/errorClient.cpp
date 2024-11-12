/*
** EPITECH PROJECT, 2020
** error_handling_arguments
** File description:
** babel
*/

#include "../include/errorClient.hpp"

errorClient::errorClient(int argc, char **argv)
{
    checkNumbArg(argc);
    if (_isError == false) {
        checkSecondArg(std::string(argv[1]));
    }
}

void errorClient::checkNumbArg(int argc)
{
    if (argc != 2) {
        _isError = true;
        std::cout << "The program has to be execute like : ./babel_client \"port\"" << std::endl;
    }
}

void errorClient::checkSecondArg(std::string str)
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

bool errorClient::getIsError() const
{
    return (_isError);
}