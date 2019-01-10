#include "project_classes/Arch.hpp"

//constructor
Arch::Arch(const char type, const float width, const float height, const float posX, const float posY, const float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Arch::Arch(){}

//destructor
Arch::~Arch(){}