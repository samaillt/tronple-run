#include <iostream>
#include <cstdlib>

#ifndef __EXCEPTION__HPP
#define __EXCEPTION__HPP

class Exception : public std::exception {
protected:
	int _level;
	int _code;
	std::string _message;
	
public:
	Exception();
	Exception(const int level, const int code, const char* message);
	int getLevel() const;
	int getCode() const;
	const char* what() const noexcept;
	virtual ~Exception();
};


#endif