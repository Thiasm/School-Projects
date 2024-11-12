/*
** EPITECH PROJECT, 2020
** error_handling_arguments
** File description:
** babel
*/

#include <string>
#include <iostream>

class errorClient
{
private:
    bool _isError = false;
public:
    errorClient(int argc, char **argv);
    ~errorClient() = default;
    void checkNumbArg(int argc);
    void checkSecondArg(std::string str);
    bool getIsError() const;
};
