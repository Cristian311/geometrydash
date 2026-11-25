#pragma once

#include <RectangleRenderObject.h>

class Player {
private:
    RectangleRenderObject shape;

public:
    explicit Player(sf::Color color = sf::Color::Green);

    void setPosition(const sf::Vector2f& position);

    RectangleRenderObject& getShape();
    const RectangleRenderObject& getShape() const;
};
