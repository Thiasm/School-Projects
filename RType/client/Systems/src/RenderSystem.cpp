/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** RenderSystem
*/

#include "../ECS/Manager.hpp"
#include "../../Components/ComponentsList.hpp"
#include "../include/RenderSystem.hpp"

extern Manager manager;

void RenderSystem::Init()
{
    manager.defineSystem<Texture, RenderSystem>();
    manager.defineSystem<Position, RenderSystem>();
	TAlly.loadFromFile("../re/spaceship.png");
    SAlly.setTexture(TAlly);
}

void RenderSystem::Update(sf::RenderWindow &window)
{
	for (auto const& entity : entityList) {
		auto& position = manager.getComponent<Position>(entity);
		auto& design = manager.getComponent<Texture>(entity);
		
		design.sprite.setTexture(design.texture);
		design.sprite.setPosition(sf::Vector2f(position.x, position.y));
		window.draw(design.sprite);
    }
}
