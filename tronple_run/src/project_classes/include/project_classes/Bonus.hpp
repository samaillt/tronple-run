#pragma once
#include "Cell.hpp"

class Bonus : public Cell {

public:

    // constructor
    Bonus(char type, float width, float height, float posX, float posY, float posZ);
    Bonus();

    //destructor
    ~Bonus();
};