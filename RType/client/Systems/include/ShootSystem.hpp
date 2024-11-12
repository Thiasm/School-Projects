/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** ShootSystem
*/

#ifndef SHOOTSYSTEM_HPP_
#define SHOOTSYSTEM_HPP_

#include "../../ECS/System.hpp"

class ShootSystem : public System {
    public:
        void Init();
        void Update(bool&);
        void Shoot(Entity);
    private:
        std::unique_ptr<Timer> timer;
};

#endif /* !SHOOTSYSTEM_HPP_ */

