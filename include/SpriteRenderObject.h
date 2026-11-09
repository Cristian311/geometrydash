#include <SFML/Graphics.hpp>
#include <RenderObject.h>

class SpriteRenderObject : public RenderObject {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    SpriteRenderObject(const sf::Texture& texture, sf::IntRect intRect);
};