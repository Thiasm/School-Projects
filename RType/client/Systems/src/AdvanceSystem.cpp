/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** AdvanceSystem
*/

#include "../ECS/Manager.hpp"
#include "../../Components/ComponentsList.hpp"
#include "../include/AdvanceSystem.hpp"

extern Manager manager;

void AdvanceSystem::Init()
{
	manager.defineSystem<Position, AdvanceSystem>();
	manager.defineSystem<Automatic, AdvanceSystem>();
	manager.defineSystem<Speed, AdvanceSystem>();
}

void AdvanceSystem::Update()
{
    for (auto const& entity : entityList) {
		auto& position = manager.getComponent<Position>(entity);
        auto& automatic = manager.getComponent<Automatic>(entity);
		auto& speed = manager.getComponent<Speed>(entity);
		
		if (automatic.move == true)
			position.x += speed.x;

		if (position.x <= -1920 && automatic.parallax == true)
				position.x = 0;
		}
}