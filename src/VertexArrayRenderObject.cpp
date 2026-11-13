#include "VertexArrayRenderObject.h"

VertexArrayRenderObject::VertexArrayRenderObject(
    sf::PrimitiveType primitiveType,
    const std::vector<sf::Vertex>& vertices
) : vertexArray(primitiveType, vertices.size()) {
    for (std::size_t index = 0; index < vertices.size(); ++index) {
        vertexArray[index] = vertices[index];
    }
}

void VertexArrayRenderObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(vertexArray, states);
}
