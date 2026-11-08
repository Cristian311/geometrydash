#pragma once

#include <SFML/Graphics.hpp>
#include <RenderObject.h>
#include <string>
#include <vector>

class RenderHandler {
    private:
    sf::RenderWindow* window;
    std::vector<RenderObject*> renderObjects;
    
    public:
    RenderHandler(sf::RenderWindow& renderWindow);
    void setResolution(const int x, const int y);
    void changeWindowName(const std::string& name);
    void addObjectsToRender(RenderObject& object);
    void update();
    void consoleWrite(std::string message);
    friend std::ostream& operator<<(std::ostream& os, const RenderHandler& obj);
};