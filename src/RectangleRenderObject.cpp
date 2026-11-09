#include <SFML/Graphics.hpp>
#include "RectangleRenderObject.h"

RectangleRenderObject::RectangleRenderObject(sf::Vector2f size, sf::Color color)
    : rectangle(size) {
    rectangle.setFillColor(color);
}

void RectangleRenderObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rectangle, states);
}

