#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class RenderObject : public sf::Drawable, public sf::Transformable {
protected:
    std::string name;
    int id;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
    
public:
    std::string getName() const;
    void setName(const std::string& objectName);
    virtual void update();
    friend std::ostream& operator<<(std::ostream& os, const RenderObject& obj);
};
