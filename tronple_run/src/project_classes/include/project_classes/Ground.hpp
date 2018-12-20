#pragma once
#include "Cell.hpp"

class Ground : public Cell {

public:

    // constructor
    Ground(char type, float width, float height, float posX, float posY, float posZ);
    Ground();

    //destructor
    ~Ground();
};