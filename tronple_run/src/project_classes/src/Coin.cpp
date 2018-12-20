#include "project_classes/Coin.hpp"

//constructor
Coin::Coin(char type, float width, float height, float posX, float posY, float posZ, int value)
: Cell(type, width, height, posX, posY, posZ), _value(value) {}

Coin::Coin(){}

//getter
int Coin::getValue() const{
	return _value;
}

//setter
 void Coin::setValue(int value){
 	_value = value;
 }

//destructor
Coin::~Coin(){}