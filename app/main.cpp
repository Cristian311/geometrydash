#include <SFML/Graphics.hpp>
#include <RenderHandler.h>
#include <RectangleRenderObject.h>
#include <SpriteRenderObject.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

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

    //text sprite
    const sf::Vector2f spriteSize{64.f, 64.f};
    sf::Texture texture;
    if (!texture.loadFromFile("../../../../textures/icons/cube_6.png")) {
        std::cerr << "Nu am putut incarca textura\n";
        return 1;
    }
    sf::Vector2i spritePosition(0, 0);
    sf::Vector2i spriteSize = static_cast<sf::Vector2i>(texture.getSize());
    SpriteRenderObject sprite(texture, sf::IntRect(spritePosition, spriteSize));

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