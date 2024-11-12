/*
** EPITECH PROJECT, 2020
** error_handling_arguments
** File description:
** babel
*/

#include <string>
#include <iostream>

class errorServer
{
private:
    bool _isError = false;
public:
    errorServer(int argc, char **argv);
    void checkNumbArg(int argc);
    void checkFirstArg(std::string str);
    void checkSecondArg(std::string str);
    bool getIsError() const;
};
