#pragma once
#include "Cell.hpp"

class Arrival : public Cell {

private:
	bool _victory;

public:

    // constructor
    Arrival(char type, float width, float height, float posX, float posY, bool vitory);
    Arrival();

    //getter
    bool getVictory() const;

    //setter
    void setVictory(bool vitory);

    //destructor
    ~Arrival();
};