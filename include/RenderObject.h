#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class RenderObject : public sf::Drawable {
private:
    sf::RectangleShape shape;
    std::string name;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
public:
    RenderObject(sf::Vector2f size = {64.f, 40.f}, sf::Color color = sf::Color::White);

    std::string getName() const;
    void setName(const std::string& objectName);
    void setPosition(sf::Vector2f position);
    void setRotation(sf::Angle rotation);
    void setSize(sf::Vector2f size);
    void setFillColor(sf::Color color);

    friend std::ostream& operator<<(std::ostream& os, const RenderObject& obj);
};
