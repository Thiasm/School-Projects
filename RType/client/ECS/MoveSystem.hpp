/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** SpawnSystem
*/

#ifndef SPAWNSYSTEM_HPP_
#define SPAWNSYSTEM_HPP_

#include "System.hpp"
#include "Manager.hpp"
#include "../../Components/Position.hpp"
#include "../../Components/Life.hpp"
#include "../../Components/Speed.hpp"


extern Manager manager;

class MoveSystem : public System {
    public:
        void Init()
        {
            manager.defineSystem<Position, MoveSystem>();
            manager.defineSystem<Speed, MoveSystem>();
        }
        void Update()
        {
            for (auto const& entity: entityList) {
                auto &speed = manager.getComponent<Speed>(entity);
                auto &position = manager.getComponent<Position>(entity);

                std::cout << "Current entity Speed: " << speed.speed << std::endl;
                std::cout << "Current entity Position: " << position.x << "|" << position.y << std::endl;
            }
        }
};

#endif /* !SPAWNSYSTEM_HPP_ */
