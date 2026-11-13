#include <SFML/Graphics.hpp>
#include <RenderHandler.h>
#include <RectangleRenderObject.h>
#include <SpriteRenderObject.h>
#include <VertexArrayRenderObject.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    const auto windowSize = window.getSize();

    RenderHandler renderHandler(window);
    renderHandler.changeWindowName("Geometry Dash");
    renderHandler.setResolution(800, 600);

    
    //test rectangle
    const sf::Vector2f rectangleSize{64.f, 40.f};
    RectangleRenderObject rectangle(rectangleSize, sf::Color::Green);
    
    rectangle.setPosition({25.f, static_cast<float>(windowSize.y) - rectangleSize.y - 25.f});
    renderHandler.addObjectsToRender(rectangle);

    //spike
    constexpr float spikeWidth = 60.f;
    constexpr float spikeHeight = 60.f;
    VertexArrayRenderObject spike(
        sf::PrimitiveType::Triangles,
        {
            sf::Vertex{{spikeWidth / 2.f, 0.f}, sf::Color::Red},
            sf::Vertex{{spikeWidth, spikeHeight}, sf::Color::Red},
            sf::Vertex{{0.f, spikeHeight}, sf::Color::Red}
        }
    );
    spike.setPosition({
        (static_cast<float>(windowSize.x) - spikeWidth) / 2.f,
        (static_cast<float>(windowSize.y) - spikeHeight) / 2.f
    });
    renderHandler.addObjectsToRender(spike);

    //test sprite
    sf::Texture texture;
    if (!texture.loadFromFile("textures/icons/cube_6.png")) {
        std::cerr << "Nu am putut incarca textura\n";
        return 1;
    }
    sf::Vector2i spritePosition(0, 0);
    sf::Vector2i spriteSize = static_cast<sf::Vector2i>(texture.getSize());
    SpriteRenderObject sprite(texture, sf::IntRect(spritePosition, spriteSize));
    sprite.setScale({
        spikeWidth / static_cast<float>(spriteSize.x),
        spikeHeight / static_cast<float>(spriteSize.y)
    });
    sprite.setPosition(sf::Vector2f(0, spike.getPosition().y));
    renderHandler.addObjectsToRender(sprite);

    auto lastUpdate = std::chrono::steady_clock::now();

    while (window.isOpen())
    { 
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        auto now = std::chrono::steady_clock::now();

        if (now - lastUpdate >= std::chrono::milliseconds(500))
        {
            system("cls");
            std::cout<<renderHandler;

            lastUpdate = now;
        }
        
        renderHandler.update();
        
        window.display();
    }
}