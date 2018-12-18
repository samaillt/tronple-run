#include "project_classes/Player.hpp"


//constructor
Player::Player(char type, float width, float height, float posX, float posY, char initX, float initY, float speed, 
	std::string pseudo, uint score, bool isAlive)
: Character(type, width, height, posX, posY, initX, initY, speed), _pseudo(pseudo), _score(score), _isAlive(isAlive){}

Player::Player(){};

//getter
uint Player::getScore() const {
	return _score;
}

bool Player::getIsAlive() const{
	return _isAlive; // If true = Player alive
}

std::string Player::getPseudo() const{
	return _pseudo;
}

//setter
void Player::setScore(const uint score){
	_score = score;
}

void Player::setIsAlive(const bool isAlive){
	_isAlive = isAlive;
}

void Player::setPseudo(const std::string &pseudo){
	_pseudo = pseudo;
}

//method
void Player::inscrementScore(const uint point){
	_score += point;
}

//destructor
Player::~Player(){}