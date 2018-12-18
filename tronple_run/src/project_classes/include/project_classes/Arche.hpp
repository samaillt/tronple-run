#pragma once
#include "Cell.hpp"

class Arche : public Cell {

public:

    // constructor
    Arche(char type, float width, float height, float posX, float posY);
    Arche();

    //destructor
    ~Arche();
};