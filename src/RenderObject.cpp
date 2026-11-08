#include "RenderObject.h"

RenderObject::RenderObject(sf::Vector2f size, sf::Color color)
    : shape(size) {
    shape.setFillColor(color);
}

void RenderObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}

std::string RenderObject::getName() const {
    return name;
}

void RenderObject::setName(const std::string& objectName) {
    name = objectName;
}

void RenderObject::setPosition(sf::Vector2f position) {
    shape.setPosition(position);
}

void RenderObject::setRotation(sf::Angle rotation) {
    shape.setRotation(rotation);
}

void RenderObject::setSize(sf::Vector2f size) {
    shape.setSize(size);
}

void RenderObject::setFillColor(sf::Color color) {
    shape.setFillColor(color);
}
void RenderObject::update(){

}

std::ostream& operator<<(std::ostream& os, const RenderObject& obj) {
    sf::Vector2f pos = obj.shape.getPosition();
    sf::Angle rot = obj.shape.getRotation();
    os << "RenderObject ["
       << "Nume: " << obj.name << ", "
       << "Pozitie: (X: " << pos.x << ", Y: " << pos.y << "), "
       << "Rotatie: (Degrees: " << rot.asDegrees() << " Radians: " << rot.asRadians() << ")"
       << "]";
    return os;
}