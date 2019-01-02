#include "project_classes/Player.hpp"


//constructor
Player::Player(char type, float width, float height, float posX, float posY, float posZ, float speed, 
	std::string pseudo, uint score, bool isAlive)
: Object(type, width, height, posX, posY, posZ), _speed(speed), _pseudo(pseudo), _score(score), _isAlive(isAlive){}

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
float Player::getSpeed() const{
	return _speed;
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
void Player::setSpeed(const float speed){
	_speed = speed;
}

//method
void Player::inscrementScore(const uint point){
	_score += point;
}

//destructor
Player::~Player(){}