#include "project_classes/Block.hpp"

//constructor
Block::Block(const char type, const float width, const float height, const float posX, const float posY, const float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Block::Block(){}

//destructor
Block::~Block(){}