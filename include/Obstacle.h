#pragma once

#include <ostream>
#include <VertexArrayRenderObject.h>

class Obstacle {
private:
    VertexArrayRenderObject shape;
    float width;
    float height;
    sf::Vector2f initialPosition;

public:
    Obstacle(sf::Vector2f position, float width, float height);
    Obstacle(const Obstacle& other) = default;
    Obstacle& operator=(const Obstacle& other) = default;

    void update(float deltaSeconds, float windowWidth, float groundY);
    void reset();
    sf::FloatRect getBounds() const;
    VertexArrayRenderObject& getShape();
    const VertexArrayRenderObject& getShape() const;
    friend std::ostream& operator<<(std::ostream& os, const Obstacle& obstacle);
};
