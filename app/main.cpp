#include <SFML/Graphics.hpp>
#include <RenderHandler.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    RenderHandler renderHandler(window);
    renderHandler.changeWindowName("Geometry Dash");
    renderHandler.setResolution(800, 600);
    renderHandler.consoleWrite("salut");

    while (window.isOpen())
    { 
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        renderHandler.update();
        
        window.display();
    }
}