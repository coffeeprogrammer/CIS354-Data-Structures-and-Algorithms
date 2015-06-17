/**
 * @file   GenericStackTest.cpp
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   February 09, 2015
 * @brief  Generic Vector Based Stack - CIS354 Module 02 - University of Maine at Augusta
 *
 * Test module for GenericStackVector class
 */

#include <iostream>
#include <string>
#include "GenericStackVector.h"
using namespace std;

int main()
{
	Stack<string> objStackA;
	if ( objStackA.empty() == 1 )
	{
		cout << "Stack is empty" << endl << endl;
	}

	cout << "pushing the following on the stack: "<< endl << " Chad, Larry, Diana, Sally, Barack " << endl;

	objStackA.push("Chad");
	objStackA.push("Larry");
	objStackA.push("Diana");
	objStackA.push("Sally");
	objStackA.push("Barack");

	cout << endl << " the size of the stack is: " << objStackA.getSize() << endl;
	//cout << objStackA.pop() << endl;

	cout << "Popping everything off the stack: " << endl;
	while (!objStackA.empty())
		cout << objStackA.pop() << endl;

	if ( objStackA.empty() == 1 )
	{
		cout << endl << "Stack is empty" << endl << endl;
	}
	
	getchar();

	return 0;
}