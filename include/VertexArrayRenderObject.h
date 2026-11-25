#pragma once

#include <ostream>
#include <SFML/Graphics.hpp>
#include <RenderObject.h>
#include <vector>

class VertexArrayRenderObject : public RenderObject {
private:
    sf::VertexArray vertexArray;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    VertexArrayRenderObject(sf::PrimitiveType primitiveType, const std::vector<sf::Vertex>& vertices);
    std::size_t getVertexCount() const;
    friend std::ostream& operator<<(std::ostream& os, const VertexArrayRenderObject& object);
};
