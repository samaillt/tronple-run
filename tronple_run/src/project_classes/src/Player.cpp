#include "project_classes/Player.hpp"


Player::Player(const char type, const float width, const float height, const float posX, const float posY, const float posZ, const float speed, const std::string pseudo, const uint score, const bool isAlive, const float verticalPos, const float horizontalPos, const Orientation orientation)
: Object(type, width, height, posX, posY, posZ), _speed(speed), _pseudo(pseudo), _score(score), _isAlive(isAlive), _height(1.f), _verticalPos(verticalPos), _horizontalPos(horizontalPos), _orientation(orientation){}

Player::Player(){};

uint Player::getScore() const {
	return _score;
}
bool Player::isAlive() const{
	return _isAlive; // If true = Player alive
}
std::string Player::getPseudo() const{
	return _pseudo;
}
float Player::getSpeed() const{
	return _speed;
}
float Player::getHeight() const{
	return _height;
}
float Player::getVerticalPos() const{
	return _verticalPos;
}
float Player::getHorizontalPos() const{
	return _horizontalPos;
}
float Player::getOrientation() const{
	return	_orientation;
}

void Player::setScore(const uint score){
	_score = score;
}
void Player::setIsAlive(const bool isAlive){
	_isAlive = isAlive;
}
void Player::setPseudo(const std::string &pseudo){
	_pseudo = pseudo;
}
void Player::setSpeed(const float &speed){
	_speed = speed;
}
void Player::setHeight(const uint height){
	_height = height;
}
void Player::setVerticalPos(const uint verticalPos){
	_verticalPos = verticalPos;
}
void Player::setHorizontalPos(const uint horizontalPos){
	_horizontalPos = horizontalPos;
}
void Player::setOrientation(const Orientation &orientation){
	_orientation = orientation;
}

void Player::inscrementScore(const uint point){
	_score += point;
}

void Player::moveForward(const float &distance){
	if (_orientation == Player::FRONT)
		_posY += distance;
	if (_orientation == Player::LEFT)
		_posX += distance;
	if (_orientation == Player::BACK)
		_posY -= distance;
	if (_orientation == Player::RIGHT)
		_posX -= distance;
}

void Player::moveDown(const float &distance){
	_posZ -= distance;
}

void Player::jump() {
	_posZ = _verticalPos + 1;
}

void Player::scaleDown() {
	
}

void Player::resetVerticalPosition() {
	_posZ = _verticalPos;
}

void Player::moveRight() {
	if (_orientation == Player::FRONT)
		_posX = _horizontalPos - 1;
	if (_orientation == Player::LEFT)
		_posY = _horizontalPos + 1;
	if (_orientation == Player::BACK)
		_posX = _horizontalPos + 1;
	if (_orientation == Player::RIGHT)
		_posY = _horizontalPos - 1;
}

void Player::resetHorizontalPosition() {
	if (_orientation == Player::FRONT || _orientation == Player::BACK)
		_posX = _horizontalPos;
	if (_orientation == Player::LEFT || _orientation == Player::RIGHT)
		_posY = _horizontalPos;
}

void Player::resetScale() {

}

void Player::moveLeft() {
	if (_orientation == Player::FRONT)
		_posX = _horizontalPos + 1;
	if (_orientation == Player::LEFT)
		_posY = _horizontalPos - 1;
	if (_orientation == Player::BACK)
		_posX = _horizontalPos - 1;
	if (_orientation == Player::RIGHT)
		_posY = _horizontalPos + 1;
}

//destructor
Player::~Player(){}