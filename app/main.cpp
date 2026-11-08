#include <SFML/Graphics.hpp>
#include <RenderHandler.h>
#include <RectangleRenderObject.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    RenderHandler renderHandler(window);
    renderHandler.changeWindowName("Geometry Dash");
    renderHandler.setResolution(800, 600);

    const sf::Vector2f rectangleSize{64.f, 40.f};
    RectangleRenderObject rectangle(rectangleSize, sf::Color::Green);
    const auto windowSize = window.getSize();
    rectangle.setPosition({25.f, static_cast<float>(windowSize.y) - rectangleSize.y - 25.f});
    
    renderHandler.addObjectsToRender(rectangle);

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