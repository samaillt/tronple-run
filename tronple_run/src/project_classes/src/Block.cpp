#include "project_classes/Block.hpp"

//constructor
Block::Block(char type, float width, float height, float posX, float posY, float posZ)
: Cell(type, width, height, posX, posY, posZ) {}

Block::Block(){}

//destructor
Block::~Block(){}