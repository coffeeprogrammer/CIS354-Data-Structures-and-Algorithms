/**
 * @file   charcounter.h
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   February 28, 2015
 * @brief  Recursive character counter with exception handling - CIS354 Module 03 - University of Maine at Augusta
 *
 * character counter class header file
 */

#ifndef CHARCOUNTER_H
#define CHARCOUNTER_H
#include <string>
#include "NonAlphaNumException.h"

using namespace std;

class charcounter
{
public:
	static int count(const string& s, char a);
	
private:
	static int count(const string& s, char a, int i);

};

#endif
