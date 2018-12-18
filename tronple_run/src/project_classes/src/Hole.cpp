#include "project_classes/Hole.hpp"

//constructor
Hole::Hole(char type, float width, float height, float posX, float posY)
: Cell(type, width, height, posX, posY) {}

Hole::Hole(){}

//destructor
Hole::~Hole(){}