#include "project_classes/Coin.hpp"

//constructor
Coin::Coin(char type, float width, float height, float posX, float posY, int point)
: Cell(type, width, height, posX, posY), _point(point) {}

Coin::Coin(){}

//getter
int Coin::getPoint() const{
	return _point;
}

//setter
 void Coin::setPoint(int point){
 	_point = point;
 }

//destructor
Coin::~Coin(){}