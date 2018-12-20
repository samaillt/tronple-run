#include "project_classes/Arrival.hpp"

//constructor
Arrival::Arrival(char type, float width, float height, float posX, float posY, float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Arrival::Arrival(){}

//destructor
Arrival::~Arrival(){}