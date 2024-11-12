/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** GameplaySystem
*/

#include "../include/Gameplay.hpp"

extern Manager manager;

Gameplay::Gameplay(sf::RenderWindow &window, ConnectionToServerManager &network) : window(window), _network(network), Over(false)
{
	timer = std::make_unique<Timer>(10000);
	pause = std::make_unique<Pause>(window, &gameMusic);
	end = std::make_unique<End>(window);
	InitMusic();
	InitComponents();
 	InitSystems();
    InitEntities();
	/*if (network.player == RequestType::PLAYER1)
		PlayerNumber = 1;
	else
		PlayerNumber = 2;*/
}

Gameplay::~Gameplay()
{
}

void Gameplay::UpdateSystems()
{
	if (timer->isTimeMicro() == true) {
		SAdvance->Update();
		SShoot->Update(Over);
		SSpawn->Update();
		SColision->Update();
		SSend->Update(_network);
		SReceive->Update(_network);
		SClear->Update();
		timer->reset();
	}
}

void Gameplay::UpdateEventSystems()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		pause->PauseLoop();
    	gameMusic.pause();
	}
	if (!SEvent->Update(event))
		end->EndLoop();
	if (Over == true) {
		SShoot->Update(Over);
		SSend->Update(_network);
		end->EndLoop();
	}
}

void Gameplay::GameLoop()
{
	while (window.isOpen()) {
		while (window.pollEvent(event))
			UpdateEventSystems();
    	window.clear();
		UpdateSystems();
		SRender->Update(window);
		window.display();
    }
}