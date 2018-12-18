#pragma once
#include <iostream>
#include "project_classes/Object.hpp"


class Character : public Object {

private:
    float _initX;
    float _initY;
    float _speed;

public:

    // constructor 
    Character(char type, float width, float height, float posX, float posY, char initX, float initY, float speed);
    Character();

    // getter
    float getSpeed() const;
    float getInitX() const;
    float getInitY() const;

    // setter
    void setSpeed(float &speed);
    void setInitX(float &initX);
    void setInitY(float &initY);

    // move methods
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    //destructor
    ~Character();
};