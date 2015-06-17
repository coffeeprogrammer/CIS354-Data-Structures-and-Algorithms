/**
 * @file   module5b.cpp
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   April 12, 2015
 * @brief  Test module for text tokenizer - CIS354 Module 05 - University of Maine at Augusta
 *
 * notes - this code does not exclude keys in comments or strings
 */

#include <iostream>
#include "Analyser.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout << "try this:" << endl;
		cout << "Module_05 keywords.txt delimiters.txt source.cpp" << endl;

		return 0;
	}

	Analyser analyserObject(argv[1], argv[2], argv[3]);

	analyserObject.buildDemlimiterSet();
	analyserObject.buildKeywordSet();
	analyserObject.tokenizeSource();

	analyserObject.printResults();

}
