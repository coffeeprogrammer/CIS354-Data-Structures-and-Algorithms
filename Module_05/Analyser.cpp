 /**
 * @file   Analyser.cpp
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   April 12, 2015
 * @brief  Analyser class for tokenizing strings from source code based on keywords in C++ or other languages - CIS354 Module 05 - University of Maine at Augusta
 *
 * notes - this code does not exclude keys in comments or strings
 */

#include "Analyser.h";

Analyser::Analyser(string kwFileName, string delimitersFileName, string sourceFileName)
{
	kwfName = kwFileName;
	delimfName = delimitersFileName;
	srcfName = sourceFileName;
}

void Analyser::tokenizeSource()
{
	fstream inputFile;  // create file stream object
	inputFile.open(srcfName);  // open source code file.

	if (!inputFile.good())
	{
		cout << "source file does not seem to be open, check to make sure you specified the correct file name.\n";
		return;
	}

	string lineFromSource;
	string potentialToken;
	int indexStart=0;
	int indexStop=0;

	while(!inputFile.eof())
	{
		potentialToken.clear();
		indexStart = 0;
		indexStop = 0;
		getline(inputFile, lineFromSource);   // read the the file one line at a time

		for(string::iterator c = lineFromSource.begin(); c != lineFromSource.end(); ++c) // iterate though the current line of source code one character at a time.
		{		
			if (delimiters.find(*c) != delimiters.end()) // if the current character is a delimiter
			{
				potentialToken = lineFromSource.substr(indexStart, indexStop - indexStart);  // is this line a bad idea?
				if (potentialToken.length() > 0)
				{
					//cout << " start: " << indexStart << " stop: " << indexStop << " - " << potentialToken << endl;
					if(validateToken(potentialToken))		// is the potential token actually a c++ keyword? 
					{
						cout << potentialToken << endl;		// if so print it out
						keywordTotals.insert(potentialToken); // add the token to the multiset keywords total
					}

					
				}
				indexStart = distance(lineFromSource.begin(), c) + 1;	// reset the starting index to one character
																		// passed the current character (which is a delimiter)
			}
			indexStop = distance(lineFromSource.begin(), c) + 1;	// reset the stopping index one passed current iteration
																	// this will happen every iteration.
		} // end of for block

		// for checking the very last token
		potentialToken = lineFromSource.substr(indexStart, indexStop - indexStart);  // again, is the .substr deal a bad idea?

		if (validateToken(potentialToken))
		{
			cout << potentialToken << endl;
			keywordTotals.insert(potentialToken); // add the token to the multiset keywords total
		}
	} // end of while loop

	inputFile.close();  // close the file
}

void Analyser::buildKeywordSet()
{
	fstream inputFile;
	inputFile.open(kwfName);

	if (!inputFile.good())
	{
		cout << "keywords file does not seem to be open, check to make sure you specified the correct file name. \n";
		return;
	}

	string keywordFromFile;

	while(!inputFile.eof())
	{
		getline(inputFile, keywordFromFile);

		keywordSet.insert(keywordFromFile);
	}
	inputFile.close();
}

void Analyser::buildDemlimiterSet()
{
	fstream inputFile;
	inputFile.open(delimfName);

	if (!inputFile.good())
	{
		cout << "demlimiters file does not seem to be open, check to make sure you specified the correct file name. \n";
		return;
	}

	string delimiterFromFile;

	while(!inputFile.eof())
	{
		getline(inputFile, delimiterFromFile);
		delimiters.insert(delimiterFromFile[0]);
	}

	inputFile.close();
	delimiters.insert('\t');
	delimiters.insert('\n');

}

bool Analyser::validateToken(string potentialToken)
{
	if(keywordSet.find(potentialToken) != keywordSet.end())
		return true;

	return false;
}

void Analyser::printResults()
{

	cout << endl << "printing results: " << endl;
	for(set<string>::iterator i = keywordSet.begin(); i != keywordSet.end(); ++i)
	{
		if(keywordTotals.count(*i) >= 1)
		{
			cout << *i << " occurred " << keywordTotals.count(*i) << " times." << endl;
		}
	}
}
