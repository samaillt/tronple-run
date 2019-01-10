#include "project_classes/Hole.hpp"

//constructor
Hole::Hole(const char type, const float width, const float height, const float posX, const float posY, const float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Hole::Hole(){}

//destructor
Hole::~Hole(){}