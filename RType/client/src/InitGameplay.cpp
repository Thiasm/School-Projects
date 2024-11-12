/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** InitEntities
*/

#include "../include/Gameplay.hpp"

extern Manager manager;

void Gameplay::InitMusic()
{
	gameMusic.openFromFile("../re/gameMusic.wav");
    gameMusic.play();
    gameMusic.setLoop(true);
	gameMusic.setVolume(10);
}

void Gameplay::InitComponents()
{
	manager.registerComponent<Name>();
   	manager.registerComponent<Life>();
	manager.registerComponent<Position>();
	manager.registerComponent<Controlable>();
	manager.registerComponent<Texture>();
	manager.registerComponent<Speed>();
	manager.registerComponent<Automatic>();
	manager.registerComponent<HitBox>();
	manager.registerComponent<Weapon>();
	manager.registerComponent<Damage>();
	manager.registerComponent<Sound>();
	manager.registerComponent<Online>();

}

void Gameplay::InitSystems()
{
	SRender = manager.registerSystem<RenderSystem>();
    SRender->Init();
	SAdvance = manager.registerSystem<AdvanceSystem>();
	SAdvance->Init();
	SEvent = manager.registerSystem<EventSystem>();
	SEvent->Init();
	SSpawn = manager.registerSystem<SpawnSystem>();
	SSpawn->Init();
	SColision = manager.registerSystem<ColisionSystem>();
	SColision->Init();
	SClear = manager.registerSystem<ClearSystem>();
	SClear->Init();
	SShoot = manager.registerSystem<ShootSystem>();
	SShoot->Init();
	SSend = manager.registerSystem<SendSystem>();
	SSend->Init();
	SReceive = manager.registerSystem<ReceiveSystem>();
	SReceive->Init();
}

void Gameplay::InitSpaceship()
{
	Texture texture;
	texture.texture.loadFromFile("../re/spaceship.png");

	Entity spaceship = manager.registerEntity();
	manager.addComponent(spaceship, Name{"Spaceship"});
	manager.addComponent(spaceship, Life{100});
	manager.addComponent(spaceship, Position{100, 540});
	manager.addComponent(spaceship, Damage{50});
	manager.addComponent(spaceship, texture);
	manager.addComponent(spaceship, Speed{64, 48});
	manager.addComponent(spaceship, Controlable{true});
	manager.addComponent(spaceship, HitBox{24, 64});
	manager.addComponent(spaceship, Weapon{25, 1000000, 0});
}

void Gameplay::InitSpaceshipSec()
{
	Texture texture;
	texture.texture.loadFromFile("../re/spaceship.png");

	Entity spaceship = manager.registerEntity();
	manager.addComponent(spaceship, Name{"Spaceship"});
	manager.addComponent(spaceship, Life{100});
	manager.addComponent(spaceship, Position{100, 540});
	manager.addComponent(spaceship, texture);
	manager.addComponent(spaceship, Weapon{25, 1000000, 0});
	manager.addComponent(spaceship, HitBox{24, 64});
	manager.addComponent(spaceship, Online{});
}

void Gameplay::InitMap()
{
	Texture texture;
	texture.texture.loadFromFile("../re/map.png");

	Entity map = manager.registerEntity();
	manager.addComponent(map, Name{"Map"});
	manager.addComponent(map, Position{0, 0});
	manager.addComponent(map, texture);
	manager.addComponent(map, Speed{-8, 0});
	manager.addComponent(map, Automatic{true, true});
}

void Gameplay::InitEntities()
{	
	InitMap();
	InitSpaceship();
	InitSpaceshipSec();
}
