/**
 * @file   charcounter.cpp
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   February 28, 2015
 * @brief  Recursive character counter with exception handling - CIS354 Module 03 - University of Maine at Augusta
 *
 * character counter class
 */

#include <iostream>
#include "charcounter.h"
using namespace std;

// the count function that is public facing, this function in turn calls another overloaded
// count function which is private.  We do this because initially no index value is being passed in
int charcounter::count(const string& s, char a)
{
	return count(s,a, 0);
}

// the private overloaded count class.  This is the recursive function, it works by passing in a string, a character,
// and an index.  With each recursive call only the index value changes, it is purpose is to specify the current point
// in the string we are examining.
int charcounter::count(const string& s, char a, int index)
{
	if (index >= s.size())	// if we reached the end of our string
		return 0;

	if ( s[index] < ' ' || s[index] > '~' )	// check ansi range, all control charaters are out of this range
		throw NonAlphaNumException(); // throw exception if character is not letter, number or space.
     
	int incrementor = 0;  // assume that we will not find the character we are looking for
	
	if (s[index] == a) // if we find the character we are looking for.
		incrementor++;  // then increment the incrementor

	return count(s, a, index+1) + incrementor;
}
