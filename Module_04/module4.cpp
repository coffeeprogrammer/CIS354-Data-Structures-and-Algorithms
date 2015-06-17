/**
 * @file   module4.cpp
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   March 22, 2015
 * @brief  Linked list main file - CIS354 Module 04 - University of Maine at Augusta
 *
 * Test module for linked list class
 */
#include <iostream>
#include <string>
#include <regex>
#include "LinkedList.h"
using namespace std;

// function prototypes
void parseText(string text, LinkedList<string> *list);

int main()
{
	LinkedList<string> list;
	string HouseofUsher;
	HouseofUsher = "DURING the whole of a dull, dark, and soundless day in the autumn of the year," \
		"when the clouds hung oppressively low in the heavens, I had been passing alone, on horseback, " \
		"through a singularly dreary tract of country; and at length found myself, as the shades of the " \
		"evening drew on, within view of the melancholy House of Usher.";


	cout << HouseofUsher << endl;
	cout << endl;

	parseText(HouseofUsher, &list);
	list.remove("of");

	// Traverse a list using iterators 
	for (Iterator<string> iterator = list.begin(); iterator != list.end(); iterator++) 
	{ 
		cout << *iterator << " ";
	} 

	getchar();

}

void parseText(string text, LinkedList<string> *list)
{
	// from http://www.informit.com/articles/article.aspx?p=2064649&seqNum=7
	// I really don't understand this function very well
	//regex re("[\\s,]+");
	regex re("[\\s,;.]+");

	sregex_token_iterator it(text.begin(), text.end(), re, -1);
	sregex_token_iterator reg_end;
	for (; it != reg_end; ++it)
	{
		// std::cout << it->str() << std::endl;
		list->add(it->str());
	}
}