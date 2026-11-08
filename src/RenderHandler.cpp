#include "RenderHandler.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

RenderHandler::RenderHandler(sf::RenderWindow& renderWindow) : window(&renderWindow) {

}

void RenderHandler::addObjectsToRender(RenderObject& object){
    renderObjects.push_back(&object);
}

void RenderHandler::update(){
    for(auto* object : renderObjects){
        window->draw(*object);
        object->update();
    }
}

void RenderHandler::setResolution(const int x, const int y){
    sf::Vector2u size(static_cast<unsigned int>(x), static_cast<unsigned int>(y));
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

std::ostream& operator<<(std::ostream& os, const RenderHandler& obj){
    os << "RenderHandler deseneaza " <<  std::to_string(obj.renderObjects.size()) << " obiecte \n";
    sf::Vector2u window_size = obj.window->getSize();
    os << "Marime fereastra X: " << window_size.x << " Y: " << window_size.y;
    os << "\nObiecte: \n";
    for(const auto* object : obj.renderObjects)
        os << *object;
    return os;
}