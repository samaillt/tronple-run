#include "project_classes/Object.hpp"

 //constructor
Object::Object(char type, float width, float height, float posX, float posY, float posZ)
:_type(type), _width(width), _height(height), _posX(posX), _posY(posY), _posZ(posZ){}

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
float Object::getPosZ() const {
    return _posZ;
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
void Object::setPosZ(float &posZ){
    _posZ = posZ;
}

//destructor
Object::~Object(){}