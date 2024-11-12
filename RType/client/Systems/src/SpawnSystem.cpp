/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** SpawnSystem
*/

#include "../ECS/Manager.hpp"
#include "../../Components/ComponentsList.hpp"
#include "../include/SpawnSystem.hpp"

extern Manager manager;

void SpawnSystem::Init()
{
    manager.defineSystem<Name, SpawnSystem>();
}

void SpawnSystem::Update()
{

    for (auto const& entity : entityList) {
		auto& name = manager.getComponent<Name>(entity);
		if (name.name == "Enemy")
			return;
    }
	    createEnemy();
}

void SpawnSystem::createEnemy()
{
	Texture texture;
	texture.texture.loadFromFile("../re/enemy.png");

	Entity enemy = manager.registerEntity();
    manager.addComponent(enemy, Life{50});
	manager.addComponent(enemy, Position{1900, rand() % 1000 + 1});
	manager.addComponent(enemy, Speed{-5, 0});
	manager.addComponent(enemy, texture);
	manager.addComponent(enemy, Damage{50});
	manager.addComponent(enemy, Controlable{false});
	manager.addComponent(enemy, Automatic{true, false});
    manager.addComponent(enemy, HitBox{56, 64});
	manager.addComponent(enemy, Name{"Enemy"});
}