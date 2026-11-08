#include <SFML/Graphics.hpp>
#include <string>

class RenderHandler {
    private:
    sf::RenderWindow* window;
    std::vector<sf::Drawable> renderObjects;
    
    public:
    RenderHandler(sf::RenderWindow& renderWindow);
    void setResolution(const int x, const int y);
    void changeWindowName(const std::string& name);
    void addObjectsToRender(sf::Drawable object);
    void update();
    void consoleWrite(std::string message);
};