#pragma once

#include "project_classes/Character.hpp"

class Enemy : public Character {

private:

public:
    // constructor
    Enemy(char type, float width, float height, float posX, float posY, char initX, float initY, float speed);
    Enemy();
    
    //destructor
    ~Enemy();
};

