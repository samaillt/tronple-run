#include "project_classes/Ground.hpp"

//constructor
Ground::Ground(char type, float width, float height, float posX, float posY)
: Cell(type, width, height, posX, posY) {}

Ground::Ground(){}

//destructod
Ground::~Ground(){}