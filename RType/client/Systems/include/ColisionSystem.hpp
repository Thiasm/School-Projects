/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** PhysicSystem
*/

#ifndef COLISIONSYSTEM_HPP_
#define COLISIONSYSTEM_HPP_

#include "../../ECS/System.hpp"

class ColisionSystem : public System {
    public:
        void Init();
        void Update();

    private:
        void checkColision(Entity, Entity);
};

#endif /* !COLISIONSYSTEM_HPP_ */
