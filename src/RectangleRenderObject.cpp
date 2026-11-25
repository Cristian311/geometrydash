#include <SFML/Graphics.hpp>
#include "RectangleRenderObject.h"
#include <ostream>

RectangleRenderObject::RectangleRenderObject(sf::Vector2f size, sf::Color color)
    : rectangle(size) {
    rectangle.setFillColor(color);
}

void RectangleRenderObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rectangle, states);
}

sf::Vector2f RectangleRenderObject::getSize() const {
    return rectangle.getSize();
}

std::ostream& operator<<(std::ostream& os, const RectangleRenderObject& object) {
    const sf::Vector2f size = object.getSize();
    os << "RectangleRenderObject{"
       << static_cast<const RenderObject&>(object)
       << "size: " << size.x << " x " << size.y << "}";
    return os;
}
