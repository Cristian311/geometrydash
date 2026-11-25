#pragma once

#include <SFML/Graphics.hpp>
#include <RenderHandler.h>
#include <Player.h>
#include <Obstacle.h>
#include <vector>

class Game {
private:
    sf::RenderWindow& window;
    RenderHandler renderer;
    Player player;
    std::vector<Obstacle> obstacles;
    sf::Clock clock;

    void handleEvents();
    void update();
    void render();

public:
    explicit Game(sf::RenderWindow& renderWindow);
    void run();
};
