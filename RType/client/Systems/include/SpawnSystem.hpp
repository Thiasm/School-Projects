/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** SpawnSystem
*/

#ifndef SPAWNSYSTEM_HPP_
#define SPAWNSYSTEM_HPP_

#include "../../ECS/System.hpp"
#include "../include/Timer.hpp"
#include <iostream>
#include <memory>

class SpawnSystem : public System {
    public:
        void Init();
        void Update();
        void createEnemy();
};

#endif /* !SPAWNSYSTEM_HPP_ */
