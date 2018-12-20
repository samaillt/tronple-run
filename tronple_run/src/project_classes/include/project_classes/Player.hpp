#pragma once

#include "project_classes/Character.hpp"

class Player : public Character {

private:
	std::string _pseudo;
	uint _score;
	bool _isAlive;

public:

	//constructor
    Player(char type, float width, float height, float posX, float posY, float posZ, char initX, float initY, float speed, 
        std::string pseudo, uint score, bool isAlive);
    Player();

    //getter
    uint getScore() const;
    bool getIsAlive() const;
    std::string getPseudo() const;

    //setter
    void setScore(const uint score);
    void setIsAlive(const bool isAlive);
    void setPseudo(const std::string &pseudo);

    //method
	void inscrementScore(const uint point);
    
    //destructor
    ~Player();
};