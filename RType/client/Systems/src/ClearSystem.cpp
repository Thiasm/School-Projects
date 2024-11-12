/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** ClearSystem
*/

#include "../ECS/Manager.hpp"
#include "../../Components/ComponentsList.hpp"
#include "../include/ClearSystem.hpp"

extern Manager manager;

void ClearSystem::Init()
{
    manager.defineSystem<Life, ClearSystem>();
    manager.defineSystem<Position, ClearSystem>();
    manager.defineSystem<Controlable, ClearSystem>();
}

void ClearSystem::Update()
{
    for (auto entity = entityList.begin(); entity != entityList.end(); entity++) {
		auto& life = manager.getComponent<Life>(*entity);
        auto& position = manager.getComponent<Position>(*entity);
        auto& name = manager.getComponent<Name>(*entity);

        if (position.x < 0 || position.x > 1920 || life.health <= 0) {
            manager.removeEntity(*entity);
            break;
        }
    }
}
