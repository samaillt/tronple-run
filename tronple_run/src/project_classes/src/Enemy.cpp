#include "project_classes/Enemy.hpp"


//constructor
Enemy::Enemy(const char type, const float width, const float height, const float posX, const float posY, const float posZ)
: Object(type, width, height, posX, posY, posZ){}

Enemy::Enemy(){}

//destructor
Enemy::~Enemy(){}