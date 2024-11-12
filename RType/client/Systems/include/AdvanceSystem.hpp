/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** AdvanceSystem
*/

#ifndef ADVANCESYSTEM_HPP_
#define ADVANCESYSTEM_HPP_

#include "../../ECS/System.hpp"
#include <iostream>

class AdvanceSystem : public System {
    public:
        void Init();
        void Update();
};

#endif /* !ADVANCESYSTEM_HPP_ */
