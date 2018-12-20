#include "project_classes/Ground.hpp"

//constructor
Ground::Ground(char type, float width, float height, float posX, float posY, float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Ground::Ground(){}

//destructod
Ground::~Ground(){}