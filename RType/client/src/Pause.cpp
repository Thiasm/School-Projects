/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Pause
*/

#include "Pause.hpp"
#include <string>

Pause::Pause(sf::RenderWindow &wind, sf::Music *mus): win(wind), music(mus)
{
    volume = music->getVolume();
}

Pause::~Pause()
{
}

void Pause::HandleInput(Text *text)
{
    if (event.type == sf::Event::Closed) {
        win.close();
        exit(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && which != 2)
        which = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (which != 0 || which != 1)) 
        which = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && which == 0)
        which = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && which == 1)
        which = 0; 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && which == 1) {
        volume = volume + 5;
        music->setVolume(volume);
        text->setText(std::to_string(volume));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && which == 0) {
        volume = volume - 5;
        music->setVolume(volume);
        text->setText(std::to_string(volume));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && which == 2) {
         isActive = false;
         music->play();
    }
}

void Pause::changeColor(Button *up, Button *down, Button *exit_game)
{
    if (which == up->getId())
        up->SetColor(sf::Color::Red);
    else
        up->SetColor(sf::Color::White);
    if (which == down->getId())
        down->SetColor(sf::Color::Red);
    else
        down->SetColor(sf::Color::White);
    if (which == exit_game->getId())
        exit_game->SetColor(sf::Color::Red);
    else
        exit_game->SetColor(sf::Color::White);
}

void Pause::PauseLoop()
{
    Sprite background("../re/1.jpg", sf::Vector2f{0, 0});
    Text vol("PAUSE", 40, sf::Vector2f{1920/2 - 140, 300}, sf::Color::Red);    
    Button down("-", sf::Vector2f{1920/2 - 250, 1080/2 + 70}, 0);
    Button up("+", sf::Vector2f{1920/2 + 115, 1080/2 + 70}, 1);
    Button exit_game("RESUME", sf::Vector2f{1920/2 - 125, 1080/2 + 300}, 2);
    Text title("R-TYPE", 60, sf::Vector2f{780, 100}, sf::Color::Red);    
    Text musicVol(std::to_string(volume), 30, sf::Vector2f{1920/2 - 50, 1080/2 + 70}, sf::Color::Yellow);

    isActive = true;
    music->pause();
    while (win.isOpen() && isActive) {
        while (win.pollEvent(event))
            HandleInput(&musicVol);
        changeColor(&up, &down, &exit_game);
        win.clear();
        win.draw(background.getSprite());
        win.draw(vol.getText());
        win.draw(exit_game.getTextDraw());
        win.draw(up.getTextDraw());
        win.draw(down.getTextDraw());
        win.draw(musicVol.getText());
        win.draw(title.getText());
        win.display();
    }
}
