/**
 * @file   NonAlphaNumException.h
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   February 28, 2015
 * @brief  Recursive character counter with exception handling - CIS354 Module 03 - University of Maine at Augusta
 *
 * exception handling class
 */
#ifndef NONALPHANUMEXCEPTION_H
#define NONALPHANUMEXCEPTION_H
#include <stdexcept>
using namespace std;

class NonAlphaNumException : public runtime_error
{
public:
	NonAlphaNumException() : runtime_error("You entered a non alphanumeric character") {}
	
};

#endif
