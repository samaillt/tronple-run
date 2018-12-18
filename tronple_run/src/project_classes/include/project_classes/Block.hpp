#pragma once
#include "Cell.hpp"

class Block : public Cell {

public:

    // constructor
    Block(char type, float &width, float &height, float &posX, float &posY);
    Block();

    //destructor
    ~Block();
};