#pragma once
#include "StaticObject.hpp"

class Malus : public StaticObject {

public:

    // constructor
    Malus(char type, float width, float height, float posX, float posY);
    Malus();

    //destructor
    ~Malus();
};