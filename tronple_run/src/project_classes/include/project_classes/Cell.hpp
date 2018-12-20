#pragma once
#include "project_classes/Object.hpp"

class Cell : public Object {

public:

    // constructor
    Cell(char type, float width, float height, float posX, float posY, float posZ);
    Cell();

    //destructor
    ~Cell();
};