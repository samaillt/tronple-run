#pragma once
#include "Cell.hpp"

class Malus : public Cell {

public:

    // constructor
    Malus(char type, float width, float height, float posX, float posY, float posZ);
    Malus();

    //destructor
    ~Malus();
};