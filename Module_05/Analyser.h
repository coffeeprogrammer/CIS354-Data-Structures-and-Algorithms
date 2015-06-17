 /**
 * @file   Analyser.h
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   April 12, 2015
 * @brief  Analyser class for tokenizing strings from source code based on keywords in C++ or other languages - CIS354 Module 05 - University of Maine at Augusta
 *
 * notes - this code does not exclude keys in comments or strings
 */

#ifndef ANALYSER_H
#define ANALYSER_H
#include <set>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Analyser
{
public:
	Analyser(string kwFileName, string delimitersFileName, string sourceFileName);
	void tokenizeSource();
	void buildKeywordSet();
	void buildDemlimiterSet();
	bool validateToken(string potentialToken);
	void printResults();

private:
	multiset<string> keywordTotals;
	set<string> keywordSet;
	set<char> delimiters;
	string kwfName;
	string delimfName;
	string srcfName;
};

#endif