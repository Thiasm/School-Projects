/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** SendSystem
*/

#include "../ECS/Manager.hpp"
#include "../../Components/ComponentsList.hpp"
#include "../include/SendSystem.hpp"

extern Manager manager;

void SendSystem::Init()
{
    manager.defineSystem<Position, SendSystem>();
	manager.defineSystem<Controlable, SendSystem>();
	manager.defineSystem<Name, SendSystem>();
}

void SendSystem::Update(ConnectionToServerManager &network)
{
	int index = 0;
	std::vector<int> spaceship;
	std::vector<int> enemy;
	int totalSize = 8 * entityList.size();
	gate_t *gate = (gate_t*)std::malloc(sizeof(gate_t) + (totalSize + 8));

	gate->size = sizeof(gate_t) - 8 + (totalSize);
	gate->type = RequestType::GAME_UPDATE;
	
	for (auto const& entity : entityList) {
		int x = manager.getComponent<Position>(entity).x;
		int y = manager.getComponent<Position>(entity).y;
		std::string name = manager.getComponent<Name>(entity).name;
		
		if (name == "Spaceship")
			spaceship.insert(spaceship.end(), {x, y});
		else if (name == "Enemy")
			enemy.insert(enemy.end(), {x, y});
	}

	gate->size_1 = 0;
	gate->size_2 = 0;
	gate->size_3 = 0;
	for (int pos : spaceship) {
		gate->content[index++] = pos;
		gate->size_1 += 4;
	}
	if (gate->size_1 == 0) {
		gate->content[0] = -1234;
		gate->content[1] = -1234;
		gate->size_1 = 8;
		index = 2;
	}
	for (int pos : enemy) {
		gate->content[index++] = pos;
		gate->size_2 += 4;
	}
	network.sendGameInfo(gate);
	free(gate);
}
