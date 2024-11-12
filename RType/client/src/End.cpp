/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** End
*/

#include "End.hpp"

End::End(sf::RenderWindow &wind): win(wind)
{
}

End::~End()
{
}

void End::EndLoop()
{
    sf::Music music;
    Sprite background("../re/1.jpg", sf::Vector2f{0, 0});
    Text title("R-TYPE", 60, sf::Vector2f{780, 100}, sf::Color::Red);    
    Text credit("Made by Alex Goyer, Mathias Roulleaux, Vivian Rebollo", 30, sf::Vector2f{300, 500}, sf::Color::White);    

    music.openFromFile("../re/music.wav");
    music.play();
    music.setLoop(true);
    while (win.isOpen()) {
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
                exit(0);
            }
        }
        win.clear();
        win.draw(background.getSprite());
        win.draw(credit.getText());
        win.draw(title.getText());
        win.display();
    }
}
