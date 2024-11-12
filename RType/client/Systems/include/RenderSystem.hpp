/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** RenderSystem
*/

#ifndef RENDERSYSTEM_HPP_
#define RENDERSYSTEM_HPP_

#include "../../utilities/include/Network/PacketReceiverBoost.hpp"
#include "ConnectionToServerManager.hpp"
#include "../../ECS/System.hpp"

class RenderSystem : public System {
    public:
        void Init();
        void Update(sf::RenderWindow&);
        sf::Sprite SAlly;
        sf::Texture TAlly;
    private:
};

#endif /* !RENDERSYSTEM_HPP_ */

