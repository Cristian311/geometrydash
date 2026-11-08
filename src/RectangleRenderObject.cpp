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

void RectangleRenderObject::setSize(sf::Vector2f size) {
    rectangle.setSize(size);
}

void RectangleRenderObject::setFillColor(sf::Color color) {
    rectangle.setFillColor(color);
}

sf::Vector2f RectangleRenderObject::getSize() const {
    return rectangle.getSize();
}

sf::Color RectangleRenderObject::getFillColor() const {
    return rectangle.getFillColor();
}