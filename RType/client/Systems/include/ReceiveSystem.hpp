/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** ReceiveSystem
*/

#ifndef RECEIVESYSTEM_HPP_
#define RECEIVESYSTEM_HPP_

#include "../../ECS/System.hpp"
#include "../../utilities/include/Network/PacketReceiverBoost.hpp"
#include "ConnectionToServerManager.hpp"

class ReceiveSystem : public System {
    public:
        void Init();
        void Update(ConnectionToServerManager&);
    private:
        void updateAlly(int*, int, Entity);
        //void displayEnemy(gate_t*);
        sf::Sprite SAlly;
        sf::Texture TAlly;
};

#endif /* !RECEIVESYSTEM_HPP_ */

