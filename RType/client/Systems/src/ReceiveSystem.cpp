/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** ReceiveSystem
*/

#include "../ECS/Manager.hpp"
#include "../../Components/ComponentsList.hpp"
#include "../include/ReceiveSystem.hpp"

extern Manager manager;

void ReceiveSystem::Init()
{
    manager.defineSystem<Online, ReceiveSystem>();
    manager.defineSystem<Position, ReceiveSystem>();
    TAlly.loadFromFile("../re/spaceship.png");
    SAlly.setTexture(TAlly);
}

void ReceiveSystem::updateAlly(int *content, int size, Entity entity)
{
    auto& position = manager.getComponent<Position>(entity);

    for (int i = 0; i < size; i += 8) {
        if (content[0] == -1234 && content[1] == -1234) {
            manager.removeEntity(entity);
            return;
        }
        position.x = content[i];
        position.y = content[i + 1];
    }
}


/*void ReceiveSystem::displayEnemy(gate_t *gate)
{

}*/

void ReceiveSystem::Update(ConnectionToServerManager &network)
{
    gate_t *gate = network.receiveGameInfo();

    for (auto const& entity : entityList) {
	    auto& name = manager.getComponent<Name>(entity);

        if (name.name == "Spaceship") {
            updateAlly(gate->content, gate->size_1, entity);
            return;
        }
    }
}
