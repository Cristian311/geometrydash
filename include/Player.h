#pragma once

#include <ostream>
#include <RectangleRenderObject.h>

class Obstacle;

class Player {
private:
    RectangleRenderObject shape;
    sf::Vector2f startPosition{0.f, 0.f};
    float verticalSpeed = 0.f;
    bool onGround = true;

public:
    explicit Player(sf::Color color = sf::Color::Green);

    void setPosition(const sf::Vector2f& position);
    void jump();
    void update(float deltaSeconds, float groundY);
    void reset();
    bool collidesWith(const Obstacle& obstacle) const;

    RectangleRenderObject& getShape();
    const RectangleRenderObject& getShape() const;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};
