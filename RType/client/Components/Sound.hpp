/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <SFML/Audio.hpp>
#include <iostream>

struct Sound {
    //sf::Music sound;
    std::string path;
    bool playing;
};

#endif /* !SOUND_HPP_ */
