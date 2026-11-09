#include <SFML/Graphics.hpp>
#include <RenderObject.h>

class RectangleRenderObject : public RenderObject {
private:
    sf::RectangleShape rectangle;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    RectangleRenderObject(sf::Vector2f size = {64.f, 40.f}, sf::Color color = sf::Color::White);

};