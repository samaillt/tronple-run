#include "project_classes/Character.hpp"

 //constructor
Character::Character(char type, float width, float height, float posX, float posY, char initX, float initY, float speed)
:Object(type, width, height, posX, posY), _initX(initX), _initY(initX), _speed(speed){}

Character::Character(){};

// getter
float Character::getSpeed() const {
    return _speed;
}

float Character::getInitX() const {
    return _initX;
}

float Character::getInitY() const {
    return _initY;
}

// setter

void Character::setSpeed(float &speed){
    _speed = speed;
}

void Character::setInitX(float &initX){
    _initX = initX;
}

void Character::setInitY(float &initY){
    _initY = initY;
}

// Move Method (à faire)
void Character::moveRight(){

}

void Character::moveLeft(){

}

void Character::moveUp(){

}

void Character::moveDown(){

}

//destructor
Character::~Character(){}