#include "project_classes/Arrival.hpp"

//constructor
Arrival::Arrival(char type, float width, float height, float posX, float posY, bool victory)
: Cell(type, width, height, posX, posY), _victory(victory) {}

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