#pragma once

#include <VertexArrayRenderObject.h>

class Obstacle {
private:
    VertexArrayRenderObject shape;
    float width;
    float height;

public:
    Obstacle(sf::Vector2f position, float width, float height);

    void update(float deltaSeconds, float windowWidth, float groundY);
    VertexArrayRenderObject& getShape();
    const VertexArrayRenderObject& getShape() const;
};
