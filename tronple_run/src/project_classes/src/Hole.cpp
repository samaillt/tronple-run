#include "project_classes/Hole.hpp"

//constructor
Hole::Hole(char type, float width, float height, float posX, float posY, float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Hole::Hole(){}

//destructor
Hole::~Hole(){}