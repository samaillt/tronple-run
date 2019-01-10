#include "project_classes/Arrival.hpp"

//constructor
Arrival::Arrival(const char type, const float width, const float height, const float posX, const float posY, const float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Arrival::Arrival(){}

//destructor
Arrival::~Arrival(){}