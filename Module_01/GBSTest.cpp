/**
 * @file   GBSTest.cpp
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   January 16, 2015
 * @brief  Generic Binary Search - CIS354 Module 01 - University of Maine at Augusta
 *
 * Test module for GenericBinarySearch class
 */

#include <iostream>
#include <string>
#include "GenericBinarySearch.h"
using namespace std;


int main()
{
	// the integers
	int intList[] = {9, 2, 67, 12, 78, 35, 89, 64, 16, -9, 54, - 13};   // size 12
	cout << "array before sort: ";
	GenericBinarySearch<int>::printArray(intList, 12);
	GenericBinarySearch<int>::insertionSort(intList, 12);
	cout << "array after sort: ";
	GenericBinarySearch<int>::printArray(intList, 12);
	cout << "the int 35 was found at index: ";
	cout << GenericBinarySearch<int>::binarySearch(intList, 35, 12) << endl ;

	cout << endl << endl;

	// the doubles
	double doubleList[] = { 58.63, 3.14159, -9.943, 7.07, 92.5, 12, 78.2, 33.6, 54.0001, -2 }; // size 10
	cout << "array before sort: ";
	GenericBinarySearch<double>::printArray(doubleList, 10);
	GenericBinarySearch<double>::insertionSort(doubleList, 10);
	cout << "array after sort: ";
	GenericBinarySearch<double>::printArray(doubleList, 10);
	cout << "the double 78.2 was found at index: ";
	cout << GenericBinarySearch<double>::binarySearch(doubleList, 78.2, 10) << endl;

	cout << endl << endl;

	// the strings
	string stringList[] = {"George Boole", "John Backus", "Alan Turing", "Linus Torvalds", "Donald Knuth", "Steve Gibson", "Adi Shamir", "Bjarne Stroustrup"};
	cout << "array before sort: ";
	GenericBinarySearch<string>::printArray(stringList, 8);
	GenericBinarySearch<string>::insertionSort(stringList, 8);
	cout << "array after sort: ";
	GenericBinarySearch<string>::printArray(stringList, 8);
	cout << "the string Donald Knuth was found at index: ";
	cout << GenericBinarySearch<string>::binarySearch(stringList, "Donald Knuth", 8);
	cout << endl << "the string Chad Botting was not found so we get a negative: ";
	cout << GenericBinarySearch<string>::binarySearch(stringList, "Chad Botting", 8);

	getchar(); // pause the program before exit
	return 0;
}