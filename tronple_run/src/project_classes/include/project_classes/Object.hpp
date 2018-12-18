#pragma once
#include <iostream>

class Object {

private:
    char _type;
    float _width;
    float _height;
    float _posX;
    float _posY;

public:

    // constructor
    Object(char type, float width, float height, float posX, float posY);
    Object();

    // getter
    char getType() const;
    float getWidth() const;
    float getHeight() const;
    float getPosX() const;
    float getPosY() const;

    // setter
    void setType(char type);
    void setWidth(float &width);
    void setHeight(float &height);
    void setPosX(float &posX);
    void setPosY(float &posY);

    // collision
    bool collision(Object*);

    //destructor
    ~Object();
};