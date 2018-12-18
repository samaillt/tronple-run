#pragma once
#include "Cell.hpp"

class Bonus : public Cell {

public:

    // constructor
    Bonus(char type, float &width, float &height, float &posX, float &posY);
    Bonus();

    //destructor
    ~Bonus();
};