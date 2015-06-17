/**
 * @file   GenericStackVector.h
 * @Author Chad Botting (coffeeprogrammer0@gmail.com)
 * @date   February 09, 2015
 * @brief  Generic Vector Based Stack - CIS354 Module 02 - University of Maine at Augusta
 *
 * A generic stack which is based on the c++ vector class.
 */

#ifndef GENERICSTACKVECTOR_H
#define GENERICSTACKVECTOR_H
#include <vector>

template<typename T>
class Stack
{
public:
	Stack();  // default constructor
	~Stack();
	bool empty() const; // tells whether stack is empty
	void push(T value);
	T pop();
	int getSize() const;
	

private:
	std::vector<T> elements; // create a generic vector
};

// default constructor
template<typename T>
Stack<T>::Stack() {}

// default deconstructor
template<typename T>
Stack<T>::~Stack() {}
 
/**
 * determines if the stack is empty
 *
 * <Longer description>
 *
 * @return Return true if stack is empty and false if not.
 */
template<typename T>
bool Stack<T>::empty() const
{
	return elements.empty();
}

/**
 * push an element on the stack
 *
 * <Longer description>
 * <May span multiple lines or paragraphs as needed>
 *
 * @param  value - on element to be pushed
 */
template<typename T>
void Stack<T>::push(T value)
{
	elements.push_back(value);
}

/**
 * Pop element off the stack and return its value
 *
 * <Longer description>
 *
 * @return elements at the end or top of the stack being popped
 */
template<typename T>
T Stack<T>::pop()
{
	if (!elements.empty()) // make sure stack is not empty
	{
		T value = elements.back(); // collect the value at the end of stack
		elements.pop_back(); // reduce stack by one
		return value; // return collected value
	}
}

/**
 * Return the size of the stack
 *
 * <Longer description>
 *
 * @return number of elements in the stack
 */
template<typename T>
int Stack<T>::getSize() const
{
	return elements.size();
}

#endif
