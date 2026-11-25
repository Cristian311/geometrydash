#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f position, float width, float height)
    : shape(
        sf::PrimitiveType::Triangles,
        {
            sf::Vertex{{width / 2.f, 0.f}, sf::Color::Red},
            sf::Vertex{{width, height}, sf::Color::Red},
            sf::Vertex{{0.f, height}, sf::Color::Red}
        }
    ),
      width(width),
      height(height) {
    shape.setPosition(position);
}

void Obstacle::update(float deltaSeconds, float windowWidth, float groundY) {
    const float speedPixelsPerSecond = 180.f;
    shape.move({-speedPixelsPerSecond * deltaSeconds, 0.f});

    if (shape.getPosition().x + width < 0.f) {
        shape.setPosition({windowWidth, groundY - height});
    }
}

VertexArrayRenderObject& Obstacle::getShape() {
    return shape;
}

const VertexArrayRenderObject& Obstacle::getShape() const {
    return shape;
}
