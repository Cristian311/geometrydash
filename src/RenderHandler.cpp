#include "RenderHandler.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

RenderHandler::RenderHandler(sf::RenderWindow& renderWindow) : window(&renderWindow) {

}

void RenderHandler::addObjectsToRender(const sf::Drawable& object){
    renderObjects.push_back(object);
    consoleWrite
}
void RenderHandler::update(){
    for(auto object : renderObjects){
        window->draw(object);
    }
}

void RenderHandler::setResolution(const int x, const int y){
    sf::Vector2u size(static_cast<unsigned int>(x), static_cast<unsigned int>(y))
    this->window->setSize(size);

    consoleWrite("Set new Resolution X: " + std::to_string(size.x) +" Y: " + std::to_string(size.y));
}

void RenderHandler::changeWindowName(const std::string& name){
    this->window->setTitle(name);
    consoleWrite("Set new window name: " + name);
}

void RenderHandler::consoleWrite(std::string message){
    std::cout<<message<<std::endl;
}