#include <SFML/Graphics.hpp>
#include "SpriteRenderObject.h"

SpriteRenderObject::SpriteRenderObject(const sf::Texture& texture, sf::IntRect intRect)
    : texture(texture), sprite(this->texture, intRect) {
}

void SpriteRenderObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(sprite, states);
}
