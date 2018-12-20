#include "project_classes/Arch.hpp"

//constructor
Arch::Arch(char type, float width, float height, float posX, float posY, float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Arch::Arch(){}

//destructor
Arch::~Arch(){}