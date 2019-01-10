#include "project_classes/Ground.hpp"

//constructor
Ground::Ground(const char type, const float width, const float height, const float posX, const float posY, const float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Ground::Ground(){}

//destructod
Ground::~Ground(){}