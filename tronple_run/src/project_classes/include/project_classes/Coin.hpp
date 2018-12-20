#pragma once
#include "Cell.hpp"

class Coin : public Cell {

private:
	int _value;

public:

    // constructor
    Coin(char type, float width, float height, float posX, float posY, float posZ, int value);
    Coin();

    //getter
    int getValue() const;

    //setter
    void setValue(int value);

    //destructor
    ~Coin();
};