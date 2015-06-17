/**
 * @file   module3.cpp
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   February 28, 2015
 * @brief  Recursive character counter with exception handling - CIS354 Module 03 - University of Maine at Augusta
 *
 * Test module for character counter class
 */

#include <iostream>
#include <string>
#include "charcounter.h"

using namespace std;

// prompts the user for input, helps out with error handling, prints character count that was returned
void prompt()
{
	charcounter cc;  // create charcounter object
	string aString;
	char aChar;
	int count = -1;

	cout << "Please enter a sentence or phrase:" << endl;
	getline(cin, aString);
	cout << "Please enter the character you wish to count occurrence of: " << endl;
	cin >> aChar;
	
	try
	{
		count  = cc.count(aString, aChar);		
	}
	catch(NonAlphaNumException &e)
	{
		cout << e.what(); // print out what the exception was
	}
	cout << endl << "the count was: " << count << endl;
}


int main()
{
	prompt();  // get user input
	
	cin.get(); // due to various reasons, this needs to be twice.
	cin.get();
	return 0;
}
