#include "project_classes/Cell.hpp"

 //constructor
Cell::Cell(const char type, const float width, const float height, const float posX, const float posY, const float posZ)
:Object(type, width, height, posX, posY, posZ){}

Cell::Cell(){};

//destructor
Cell::~Cell(){}