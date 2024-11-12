/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** ColisionSystem
*/

#include "../ECS/Manager.hpp"
#include "../include/ColisionSystem.hpp"
#include "../../Components/ComponentsList.hpp"

extern Manager manager;

void ColisionSystem::Init()
{
	manager.defineSystem<Position, ColisionSystem>();
	manager.defineSystem<Life, ColisionSystem>();
	manager.defineSystem<HitBox, ColisionSystem>();
	manager.defineSystem<Damage, ColisionSystem>();
}

void ColisionSystem::Update()
{
	for (auto const& first : entityList) {
		auto& name = manager.getComponent<Name>(first);
		if (name.name != "Enemy")
			continue;
		for (auto const& second : entityList) {
			auto& nameS = manager.getComponent<Name>(second);
			if (nameS.name == "Bullet" || nameS.name == "Spaceship")
				checkColision(first, second);
		}
	}
}

void ColisionSystem::checkColision(Entity first, Entity second)
{
	auto& firstPos = manager.getComponent<Position>(first);
	auto& firstHitbox = manager.getComponent<HitBox>(first);
	auto& firstDamage = manager.getComponent<Damage>(first);
	auto& firstLife = manager.getComponent<Life>(first);
	auto& secondPos = manager.getComponent<Position>(second);
	auto& secondHitbox = manager.getComponent<HitBox>(second);
	auto& secondLife = manager.getComponent<Life>(second);
	auto& secondDamage = manager.getComponent<Damage>(second);

	if (firstPos.x < secondPos.x + secondHitbox.Width &&
   	firstPos.x + firstHitbox.Width > secondPos.x &&
   	firstPos.y < secondPos.y + secondHitbox.Height &&
   	firstHitbox.Height + firstPos.y > secondPos.y) {
			secondLife.health = 0;
			firstLife.health = 0;
	}
}