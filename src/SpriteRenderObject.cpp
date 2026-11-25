#include <SFML/Graphics.hpp>
#include "SpriteRenderObject.h"
#include <ostream>

SpriteRenderObject::SpriteRenderObject(const sf::Texture& texture, sf::IntRect intRect)
    : texture(texture), sprite(this->texture, intRect) {
}

void SpriteRenderObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(sprite, states);
}

std::ostream& operator<<(std::ostream& os, const SpriteRenderObject& object) {
    os << "SpriteRenderObject{"
       << static_cast<const RenderObject&>(object)
       << "}";
    return os;
}
