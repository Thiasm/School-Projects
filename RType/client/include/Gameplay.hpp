/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** GameplaySystem
*/

#ifndef GAMEPLAYSYSTEM_HPP_
#define GAMEPLAYSYSTEM_HPP_

#include "../ECS/Manager.hpp"
#include "../Components/ComponentsList.hpp"
#include "../Systems/SystemList.hpp"
#include "Pause.hpp"
#include "ConnectionToServerManager.hpp"
#include "../include/End.hpp"

class Gameplay {
    public:
        Gameplay(sf::RenderWindow &, ConnectionToServerManager &network);
        ~Gameplay();

        // ECS
        void InitComponents();
        void InitSystems();
        void InitEntities();
        void UpdateSystems();
        void InitSpaceshipSec();

        // Entities
        void InitMap();
        void InitSpaceship();
        
        // Game
        void UpdateEventSystems();
        void GameLoop();

        void InitMusic();
    private:
        // SFML
        sf::RenderWindow &window;
        sf::Event event;
        sf::Music gameMusic;

        // Systems
        std::shared_ptr<RenderSystem> SRender;
        std::shared_ptr<AdvanceSystem> SAdvance;
        std::shared_ptr<EventSystem> SEvent;
        std::shared_ptr<SpawnSystem> SSpawn;
        std::shared_ptr<ColisionSystem> SColision;
        std::shared_ptr<ClearSystem> SClear;
        std::shared_ptr<ShootSystem> SShoot;
        std::shared_ptr<SendSystem> SSend;
        std::shared_ptr<ReceiveSystem> SReceive;

        // Tools
        std::unique_ptr<Timer> timer;
        std::unique_ptr<Pause> pause;
        std::unique_ptr<End> end;
        bool Over;
        int PlayerNumber;

        // Network
        ConnectionToServerManager &_network;
};

#endif /* !GAMEPLAYSYSTEM_HPP_ */
