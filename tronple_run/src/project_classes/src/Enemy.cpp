#include "project_classes/Enemy.hpp"


//constructor
Enemy::Enemy(char type, float width, float height, float posX, float posY, float posZ)
: Object(type, width, height, posX, posY, posZ){}

Enemy::Enemy(){}

//destructor
Enemy::~Enemy(){}