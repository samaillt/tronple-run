#include "project_classes/Cell.hpp"

 //constructor
Cell::Cell(char type, float width, float height, float posX, float posY)
:Object(type, width, height, posX, posY){}

Cell::Cell(){};

//destructor
Cell::~Cell(){}