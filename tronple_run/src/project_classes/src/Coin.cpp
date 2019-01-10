#include "project_classes/Coin.hpp"

//constructor
Coin::Coin(const char type, const float width, const float height, const float posX, const float posY, const float posZ, const int value)
: Cell(type, width, height, posX, posY, posZ), _value(value) {}

Coin::Coin(){}

//getter
int Coin::getValue() const{
	return _value;
}

//setter
 void Coin::setValue(const int value){
 	_value = value;
 }

//destructor
Coin::~Coin(){}