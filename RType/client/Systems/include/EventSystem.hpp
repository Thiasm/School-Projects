/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** EventSystem
*/

#ifndef EVENTSYSTEM_HPP_
#define EVENTSYSTEM_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../../ECS/System.hpp"

enum KeyEnum {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    P,
    SPACE,
    UNDEFINED,
};


class EventSystem : public System {
    public:
        void Init();
        bool Update(sf::Event);

    private:
        void manageKey(KeyEnum, Entity);
        KeyEnum getKey(sf::Keyboard::Key);
};

#endif /* !EVENTSYSTEM_HPP_ */
