#include "project_classes/Cell.hpp"

 //constructor
Cell::Cell(char type, float width, float height, float posX, float posY, float posZ)
:Object(type, width, height, posX, posY, posZ){}

Cell::Cell(){};

//destructor
Cell::~Cell(){}