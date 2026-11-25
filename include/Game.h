#pragma once

#include <ostream>
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
    void reset();

public:
    explicit Game(sf::RenderWindow& renderWindow);
    void run();
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};
