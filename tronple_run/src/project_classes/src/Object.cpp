#include "project_classes/Object.hpp"

 //constructor
Object::Object(const char type, const float width, const float height, const float posX, const float posY, const float posZ)
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
void Object::setType(const char type) {
    _type = type;
}
void Object::setWidth(const float &width) {
    _width = width;
}
void Object::setHeight(const float &height){
    _height = height;
}
void Object::setPosX(const float &posX) {
    _posX = posX;
}
void Object::setPosY(const float &posY){
    _posY = posY;
}
void Object::setPosZ(const float &posZ){
    _posZ = posZ;
}

//destructor
Object::~Object(){}