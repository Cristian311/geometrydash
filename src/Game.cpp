#include "Game.h"

const float groundMargin = 25.f;
const float playerHeight = 64.f;
const float obstacleWidth = 60.f;
const float obstacleHeight = 60.f;
const float obstacleStartOffset = 120.f;

Game::Game(sf::RenderWindow& renderWindow)
    : window(renderWindow),
      renderer(renderWindow),
      player(sf::Color::Green) {
    const sf::Vector2u windowSize = window.getSize();
    const float groundY = static_cast<float>(windowSize.y) - groundMargin;

    player.setPosition({80.f, groundY - playerHeight});

    Obstacle initialObstacle(
        {
            static_cast<float>(windowSize.x) - obstacleStartOffset,
            groundY - obstacleHeight
        },
        obstacleWidth,
        obstacleHeight
    );
    obstacles.push_back(initialObstacle);

    renderer.changeWindowName("Geometry Dash");
    renderer.setResolution(static_cast<int>(windowSize.x), static_cast<int>(windowSize.y));
    renderer.addObjectsToRender(player.getShape());
    for (Obstacle& obstacle : obstacles) {
        renderer.addObjectsToRender(obstacle.getShape());
    }
}

void Game::handleEvents() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void Game::update() {
    const sf::Vector2u windowSize = window.getSize();
    const float deltaSeconds = clock.restart().asSeconds();
    const float groundY = static_cast<float>(windowSize.y) - groundMargin;

    for (Obstacle& obstacle : obstacles) {
        obstacle.update(
            deltaSeconds,
            static_cast<float>(windowSize.x),
            groundY
        );
    }
}

void Game::render() {
    window.clear(sf::Color::Black);
    renderer.update();
    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}
