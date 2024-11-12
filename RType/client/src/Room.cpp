/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Room
*/

#include "Room.hpp"

Room::Room(sf::RenderWindow &wind, ConnectionToServerManager &network): win(wind), net(network)
{
}

Room::~Room()
{
}

void Room::DrawPlayer(Line *first, Line *second, Text *wait, Text *press)
{
    win.draw(first->getSprite());
    win.draw(first->getText());
    if (isTwo) {
        win.draw(second->getSprite());
        win.draw(second->getText());
        if (player == RequestType::PLAYER2)
            win.draw(wait->getText());
    } 
    if (player == RequestType::PLAYER1)
        win.draw(press->getText());
}

bool Room::getIsTwo()
{
    return (isTwo);
}

RequestType Room::getPlayer()
{
    return (player);
}

void Room::GameLoop()
{
    player = net.joinRoom();
    Sprite background("../re/1.jpg", sf::Vector2f{0, 0});
    Text title("R-TYPE", 60, sf::Vector2f{780, 100}, sf::Color::White);    
    Text room("ROOM", 40, sf::Vector2f{830, 300}, sf::Color::Red);
    Text press("Press enter to start the game", 30,  sf::Vector2f{600, 1080/2 + 200}, sf::Color::White);
    Text wait("waiting for the host to start", 30,  sf::Vector2f{600, 1080/2 + 200}, sf::Color::White);
    Line first("../re/spaceship.png", sf::Vector2f{1920/2 - 200, 1080/2 - 100}, "Player 1", player, 1);
    Line second("../re/spaceship.png", sf::Vector2f{1920/2 - 200, 1080/2 + 100}, "Player 2", player, 2);
        
    while (win.isOpen() && isActive) {
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
                exit(0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && player == RequestType::PLAYER1 && isTwo == true)
                gameLaunch = true;
        }
        if (gameLaunch == true)
            isActive = false;
        win.clear();
        isTwo = net.getRoomInfo(gameLaunch);
        win.draw(background.getSprite());
        DrawPlayer(&first, &second, &wait, &press);
        win.draw(title.getText());
        win.draw(room.getText());
        win.display();
    }
}
