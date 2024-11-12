/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Menu
*/

#include "../include/Menu.hpp"

Menu::Menu(sf::RenderWindow &wind): win(wind)
{
}

Menu::~Menu()
{
}

sf::RenderWindow *Menu::getwin()
{
    return &win;
}

void Menu::change_color(Button *play, Button *exit_game, Button *option)
{
    if (which == play->getId())
        play->SetColor(sf::Color::Red);
    else
        play->SetColor(sf::Color::White);
    if (which == option->getId())
        option->SetColor(sf::Color::Red);
    else
        option->SetColor(sf::Color::White);
    if (which == exit_game->getId())
        exit_game->SetColor(sf::Color::Red);
    else
        exit_game->SetColor(sf::Color::White);
}

void Menu::handleMoveMenu(Pause *pause)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        which++;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        which--;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && which == 2) {
        win.close();
        exit(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && which == 0) {
        std::cout << "zebi" << std::endl;
        isActive = false;
    }  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && which == 1) {
        pause->PauseLoop();
    }  
}

void Menu::GameLoop()
{
    sf::Music music;
    Button play("JOIN ROOM", sf::Vector2f{1920/2 - 125, 1080/2 - 100}, 0);
    Button exit_game("EXIT", sf::Vector2f{1920/2 - 65, 1080/2 + 300}, 2);
    Sprite background("../re/1.jpg", sf::Vector2f{0, 0});
    Text title("R-TYPE", 60, sf::Vector2f{780, 100}, sf::Color::Red);    
    Button option("OPTION", sf::Vector2f{1920/2 - 95, 1080/2 + 100}, 1);
    Pause pause(win, &music);

    music.openFromFile("../re/music.wav");
    music.play();
    music.setLoop(true);
    while (win.isOpen() && isActive) {
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
                exit(0);
            }
            handleMoveMenu(&pause);
        }
        win.clear();
        change_color( &play, &exit_game, &option);
        win.draw(background.getSprite());
        win.draw(option.getTextDraw());
        win.draw(play.getTextDraw());
        win.draw(exit_game.getTextDraw());
        win.draw(title.getText());
        win.display();
    }
}