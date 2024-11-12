/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** EventSystem
*/

#include "../ECS/Manager.hpp"
#include "../include/EventSystem.hpp"
#include "../../Components/ComponentsList.hpp"
#include  "../../include/Pause.hpp"

extern Manager manager;

void EventSystem::Init()
{
	manager.defineSystem<Position, EventSystem>();
	manager.defineSystem<Speed, EventSystem>();
	manager.defineSystem<Controlable, EventSystem>();
}

bool EventSystem::Update(sf::Event event)
{
	for (auto const& entity : entityList) {
		auto& controlable = manager.getComponent<Controlable>(entity);

		if (controlable.controlable == false)
			continue;
		if (event.type == sf::Event::Closed)
    	    return false;
		else if (event.type == sf::Event::KeyPressed)
    	    manageKey(getKey(event.key.code), entity);
	}
	return true;
}

void EventSystem::manageKey(KeyEnum key, Entity entity)
{
	auto& position = manager.getComponent<Position>(entity);
	auto& speed = manager.getComponent<Speed>(entity);
	auto& name = manager.getComponent<Name>(entity);

	std::cout << name.name << std::endl;
	switch (key) {
		case KeyEnum::UP:
			if (position.y - speed.y >= 0)
				position.y -= speed.y;
			break;
		case KeyEnum::DOWN:
			if (position.y + speed.y <= 1500)
				position.y += speed.y;
			break;
		case KeyEnum::LEFT:
			if (position.x - speed.x >= 0)
				position.x -= speed.x;
			break;
		case KeyEnum::RIGHT:
			if (position.x + speed.x <= 1500)
				position.x += speed.x;
			break;
	}
}

KeyEnum EventSystem::getKey(sf::Keyboard::Key key)
{
	 switch (key) {
        case sf::Keyboard::Up: return KeyEnum::UP; break;
        case sf::Keyboard::Down: return KeyEnum::DOWN; break;
        case sf::Keyboard::Left: return KeyEnum::LEFT; break;
        case sf::Keyboard::Right: return KeyEnum::RIGHT; break;
        case sf::Keyboard::Space: return KeyEnum::SPACE; break;
        default: return KeyEnum::UNDEFINED; break;
    }
}