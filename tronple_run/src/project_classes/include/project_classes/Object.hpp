#pragma once
#include <iostream>

class Object {

private:
    char _type;
    float _width;
    float _height;
    float _posX;
    float _posY;
    float _posZ;

public:

    // constructor
    Object(char type, float width, float height, float posX, float posY, float posZ);
    Object();

    // getter
    char getType() const;
    float getWidth() const;
    float getHeight() const;
    float getPosX() const;
    float getPosY() const;
    float getPosZ() const;

    // setter
    void setType(char type);
    void setWidth(float &width);
    void setHeight(float &height);
    void setPosX(float &posX);
    void setPosY(float &posY);
    void setPosZ(float &posZ);

    // collision
    bool collision(Object*);

    //destructor
    ~Object();
};