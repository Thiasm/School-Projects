/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** Iclient
*/

#ifndef ICLIENT_HPP_
#define ICLIENT_HPP_

#include <vector>
#include <iostream>
#include <QApplication>
#include <memory>

#include "clientConnect.hpp"

class Iclient {
    public:
        virtual ~Iclient() = default;
        virtual void launch() = 0;
        virtual void getUsername() = 0;
    protected:
    private:
};

#endif /* !ICLIENT_HPP_ */
