/**
 * @file   GenericBinarySearch.h
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   January 16, 2015
 * @brief  Generic Binary Search - CIS354 Module 01 - University of Maine at Augusta
 *
 * Rewrite a binary search function to use a generic type for array elements.
 * Program must also sort the elements before the search.
 * Test the function with array of int, double, and string values.
 * (has code from Y. Daniel Liang)
 */

#ifndef GENERICBINARYSEARCH_H
#define GENERICBINARYSEARCH_H
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class GenericBinarySearch
{
public:
	static int binarySearch(const T list[], T key, int listSize);
	static void insertionSort(T list[], int listSize);
	static void printArray(T list[], int listSize);

private:
};

/**
 * A generic classic binary search
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param list a generic sorted array to be searched
 * @param key the value we are searching for
 * @param listSize the size or number of elements in the array
 * @return zero based index value of the key we were searching for, returns a negative value if not found
 *
 * Example Usage:
 * @code
 *    GenericBinarySearch<string>::binarySearch(intList, 99, 14); // search an intList of size 14 for the number 99.
 * @endcode
 */
template<typename T>
int GenericBinarySearch<T>::binarySearch(const T list[], T key, int listSize)
{
	// the following are index values
	int low = 0;
	int high = listSize - 1;

	while (high >= low)
	{
		
		int mid = (low+high)/2; // calculate middle of the array
		if (key < list[mid]) // is the element we are looking for less than element in the middle?
			high = mid - 1; // if it is then move the high index to one less than the middle.
		else if (key==list[mid]) // in this condition we found what we were looking for, we are done
			return mid;
		else // the only other condition is that element is not in the first half
			low = mid + 1; // so move the low index up 
	}

	return - low - 1; // if not found return negative value.
}

/**
 * A generic class insertion sort method
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  list a generic unsorted array
 * @param  listSize the size of the array
 * @return 
 *
 * Example Usage:
 * @code
 *    GenericBinarySearch<string>::insertionSort(myArray, 120); // perform a insertion sort on "myArray" of size 120
 * @endcode
 */
template<typename T>
void GenericBinarySearch<T>::insertionSort(T list[], int listSize)
{
	for (int i = 1; i < listSize; i++)
	{
		T currentElement = list[i]; // set the second element equal to currentElement
		int k;
		for (k = i - 1; k >= 0 && list[k] > currentElement; k--) // loop while k greater than zero
		{												// and element at k is greater than currentElement
			list[k+1] = list[k];		// swap currentElement with kth element
		}							// kth comes first but is larger, see logic in for statement
	
		// Insert the current element into list[k+1]
		list[k+1] = currentElement;
	}
}

/**
 * print the contents of an array
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  list the array to be printed
 * @param  listSize the size of array to be printed
 * @return Description of the return value
 */
template<typename T>
void GenericBinarySearch<T>::printArray(T list[], int listSize)
{
	for(int i = 0; i < listSize; i++)
	{
		cout << list[i] << ", ";
	}
	cout << endl;
}

#endif