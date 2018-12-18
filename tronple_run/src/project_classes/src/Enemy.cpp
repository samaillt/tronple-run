#include "project_classes/Enemy.hpp"


//constructor
Enemy::Enemy(char type, float width, float height, float posX, float posY, char initX, float initY, float speed)
: Character(type, width, height, posX, posY, initX, initY, speed){}

Enemy::Enemy(){}

//destructor
Enemy::~Enemy(){}