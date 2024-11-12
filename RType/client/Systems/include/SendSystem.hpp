/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** SendSystem
*/

#ifndef SENDSYSTEM_HPP_
#define SENDSYSTEM_HPP_

#include "../../ECS/System.hpp"
#include "../../utilities/include/Network/PacketSenderBoost.hpp"
#include "ConnectionToServerManager.hpp"

class SendSystem : public System {
    public:
        void Init();
        void Update(ConnectionToServerManager &network);
    private:
};

#endif /* !SENDSYSTEM_HPP_ */
