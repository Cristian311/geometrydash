#include "RenderObject.h"

std::string RenderObject::getName() const {
    return name;
}

void RenderObject::setName(const std::string& objectName) {
    name = objectName;
}

void RenderObject::update(){

}

std::ostream& operator<<(std::ostream& os, const RenderObject& obj) {
    const auto position = obj.getPosition();
    const auto rotation = obj.getRotation();
    os << "RenderObject ["
       << "Nume: " << obj.name << ", "
       << "Pozitie: (X: " << position.x << ", Y: " << position.y << "), "
       << "Rotatie: (Degrees: " << rotation.asDegrees()
       << " Radians: " << rotation.asRadians() << ")"
       << "]\n";
    return os;
}