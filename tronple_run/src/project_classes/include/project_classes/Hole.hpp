#pragma once
#include "Cell.hpp"

class Hole : public Cell {

public:

    // constructor
    Hole(char type, float width, float height, float posX, float posY, float posZ);
    Hole();

    //destructor
    ~Hole();
};