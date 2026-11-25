#include "Player.h"
#include "Obstacle.h"
#include <ostream>

Player::Player(sf::Color color)
    : shape({64.f, 64.f}, color) {
}

void Player::setPosition(const sf::Vector2f& position) {
    startPosition = position;
    shape.setPosition(position);
}

void Player::jump() {
    if (onGround) {
        verticalSpeed = -550.f;
        onGround = false;
    }
}

void Player::update(float deltaSeconds, float groundY) {
    const float gravity = 1400.f;
    verticalSpeed += gravity * deltaSeconds;
    shape.move({0.f, verticalSpeed * deltaSeconds});

    const float playerBottom = shape.getPosition().y + shape.getSize().y;
    if (playerBottom >= groundY) {
        shape.setPosition({shape.getPosition().x, groundY - shape.getSize().y});
        verticalSpeed = 0.f;
        onGround = true;
    }
}

void Player::reset() {
    shape.setPosition(startPosition);
    verticalSpeed = 0.f;
    onGround = true;
}

bool Player::collidesWith(const Obstacle& obstacle) const {
    const sf::FloatRect playerBounds{shape.getPosition(), shape.getSize()};
    return playerBounds.findIntersection(obstacle.getBounds()).has_value();
}

RectangleRenderObject& Player::getShape() {
    return shape;
}

const RectangleRenderObject& Player::getShape() const {
    return shape;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player{" << player.shape << "}";
    return os;
}
