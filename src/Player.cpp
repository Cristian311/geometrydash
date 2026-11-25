#include "Player.h"

Player::Player(sf::Color color)
    : shape({64.f, 64.f}, color) {
}

void Player::setPosition(const sf::Vector2f& position) {
    shape.setPosition(position);
}

RectangleRenderObject& Player::getShape() {
    return shape;
}

const RectangleRenderObject& Player::getShape() const {
    return shape;
}
