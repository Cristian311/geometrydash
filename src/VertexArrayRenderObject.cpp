#include "VertexArrayRenderObject.h"
#include <ostream>

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

std::size_t VertexArrayRenderObject::getVertexCount() const {
    return vertexArray.getVertexCount();
}

std::ostream& operator<<(std::ostream& os, const VertexArrayRenderObject& object) {
    os << "VertexArrayRenderObject{"
       << static_cast<const RenderObject&>(object)
       << "vertices: " << object.getVertexCount() << "}";
    return os;
}
