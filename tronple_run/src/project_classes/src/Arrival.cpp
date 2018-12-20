#include "project_classes/Arrival.hpp"

//constructor
Arrival::Arrival(char type, float width, float height, float posX, float posY, float posZ)
: Cell(type, width, height, posX, posY, posZ), _victory(0) {}

Arrival::Arrival(){}

//getter
bool Arrival::getVictory() const{
	return _victory;
}

//setter
 void Arrival::setVictory(bool victory){
 	_victory = victory;
 }

//destructor
Arrival::~Arrival(){}