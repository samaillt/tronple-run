#include "project_classes/Object.hpp"

 //constructor
Object::Object(char type, float width, float height, float posX, float posY)
:_type(type), _width(width), _height(height), _posX(posX), _posY(posY){}

Object::Object(){};

// getter
char Object::getType() const {
    return _type;
}

float Object::getWidth() const {
    return _width;
}

float Object::getHeight() const {
    return _height;
}

float Object::getPosX() const {
    return _posX;
}

float Object::getPosY() const {
    return _posY;
}

// setter
void Object::setType(char type) {
    _type = type;
}

void Object::setWidth(float &width) {
    _width = width;
}

void Object::setHeight(float &height){
    _height = height;
}

void Object::setPosX(float &posX) {
    _posX = posX;
}

void Object::setPosY(float &posY){
    _posY = posY;
}

// collision (à faire)
bool Object::collision(Object*) {

    return true;
}

//destructor
Object::~Object(){}