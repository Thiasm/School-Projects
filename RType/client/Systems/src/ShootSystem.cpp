/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** ShootSystem
*/

#include "../ECS/Manager.hpp"
#include "../../Components/ComponentsList.hpp"
#include "../include/ShootSystem.hpp"

extern Manager manager;

void ShootSystem::Init()
{
    timer = std::make_unique<Timer>(0);
    manager.defineSystem<Weapon, ShootSystem>();
    manager.defineSystem<Position, ShootSystem>();
    manager.defineSystem<HitBox, ShootSystem>();
}

void ShootSystem::Update(bool &Over)
{
	int count = 0;
    int current = timer->getMicro();

	for (auto const& entity : entityList) {
		auto& weapon = manager.getComponent<Weapon>(entity);
		auto& name = manager.getComponent<Name>(entity);

        weapon.wait += current;
		if (name.name == "Spaceship")
			count += 1;
		if (weapon.wait >= weapon.reloadTime) {
            Shoot(entity);
			weapon.wait = 0;
        }
    }
    timer->reset();
	if (count == 0)
		Over = true;
}

void ShootSystem::Shoot(Entity entity)
{
	auto& position = manager.getComponent<Position>(entity);
	auto& weapon = manager.getComponent<Weapon>(entity);
	auto& hitbox = manager.getComponent<HitBox>(entity);

	Texture texture;
	texture.texture.loadFromFile("../re/bullet.png");

	Entity bullet = manager.registerEntity();
	manager.addComponent(bullet, Name{"Bullet"});
	manager.addComponent(bullet, Position{position.x + hitbox.Width, position.y});
	manager.addComponent(bullet, texture);
    manager.addComponent(bullet, HitBox{12, 48});
	manager.addComponent(bullet, Speed{40, 0});
    manager.addComponent(bullet, Life{1});
    manager.addComponent(bullet, Controlable{false});
	manager.addComponent(bullet, Automatic{true, false});
	manager.addComponent(bullet, Damage{weapon.Damages});
}

