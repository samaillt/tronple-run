#include "../include/project_classes/Exception.hpp"

Exception::Exception():_level(0), _code(0), _message(""){

}

Exception::Exception(const int level, const int code, const char* message):_level(level), _code(code), _message(message){
	
}

int Exception::getLevel() const{
	return _level;
}

int Exception::getCode() const{
	return _code;
}

const char* Exception::what() const noexcept{
	return _message.c_str();
}

Exception::~Exception(){

}