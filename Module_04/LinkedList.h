/**
* @file   LinkedList.h
* @Author Chad Botting (coffeeprogrammer0@gmail.com)
* @date   March 22, 2015
* @brief  Linked list class file- CIS354 Module 04 - University of Maine at Augusta
*
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
using namespace std;

template<typename T>
class Node
{
public:
	T element; // Element contained in the node
	Node<T>* next; // Pointer to the next node

	Node() // No-arg constructor
	{
		next = NULL;
	}

	Node(T element) // Constructor
	{
		this->element = element;
		next = NULL;
	}
};

template<typename T>
class Iterator: public std::iterator<std::forward_iterator_tag, T>
{
public:
	Iterator(Node<T>* p)
	{
		current = p;
	};

	Iterator operator++() // Prefix ++
	{
		current = current->next;
		return *this;
	}

	Iterator operator++(int dummy) // Postfix ++
	{
		Iterator temp(current);
		current = current->next;
		return temp;
	}

	T& operator*()
	{
		return current->element;
	}

	bool operator==(const Iterator<T>& iterator)
	{
		return current == iterator.current;
	}

	bool operator!=(const Iterator<T>& iterator)
	{
		return current != iterator.current;
	}

private:
	Node<T>* current;
};

template<typename T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	virtual ~LinkedList();
	void addFirst(T element);
	void addLast(T element);
	T getFirst() const;
	T getLast() const;
	T removeFirst() throw (runtime_error);
	T removeLast();
	void add(T element);
	void add(int index, T element);
	void clear();
	bool contains(T element) const;
	T get(int index) const;
	int indexOf(T element) const;
	bool isEmpty() const;
	int lastIndexOf(T element) const;
	void remove(T element);
	int getSize() const;
	T removeAt(int index);
	T set(int index, T element);
	void reverse();

	Iterator<T> begin()
	{
		return Iterator<T>(head);
	};

	Iterator<T> end()
	{
		return Iterator<T>(tail->next);
	};

private:
	Node<T>* head;
	Node<T>* tail;
	int size;
};

template<typename T>
LinkedList<T>::LinkedList()
{
	head = tail = NULL;
	size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	head = tail = NULL;
	size = 0;

	Node<T>* current = list.head;
	while (current != NULL)
	{
		this->add(current->element);
		current = current->next;
	}
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
	Node<T>* newNode = new Node<T>(element);
	newNode->next = head;
	head = newNode;
	size++;

	if (tail == NULL)
		tail = head;
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
	if (tail == NULL)
	{
		head = tail = new Node<T>(element);
	}
	else
	{
		tail->next = new Node<T>(element);
		tail = tail->next;
	}

	size++;
}

template<typename T>
T LinkedList<T>::getFirst() const
{
	if (size == 0)
		throw runtime_error("Index out of range");
	else
		return head->element;
}

template<typename T>
T LinkedList<T>::getLast() const
{
	if (size == 0)
		throw runtime_error("Index out of range");
	else 
		return tail->element;
}

template<typename T>
T LinkedList<T>::removeFirst() throw (runtime_error)
{
	if (size == 0)
		throw runtime_error("No elements in the list");
	else
	{
		Node<T>* temp = head;
		head = head->next;
		if (head == NULL) tail = NULL;
		size--;
		T element = temp ->element;
		delete temp;
		return element;
	}
}

template<typename T>
T LinkedList<T>::removeLast()
{
	if (size == 0)
		throw runtime_error("No elements in the list");
	else if (size == 1)
	{
		Node<T>* temp = head;
		head = tail = NULL;
		size = 0;
		T element = temp->element;
		delete temp;
		return element;
	}
	else
	{
		Node<T>* current = head;
		
		for (int i = 0; i < size - 2; i++)
			current = current->next;

		Node<T>* temp = tail;
		tail = current;
		tail->next = NULL;
		size--;
		T element = temp->element;
		delete temp;
		return element;
	}
}

template<typename T>
void LinkedList<T>::add(T element)
{
	addLast(element);
}

template<typename T>
void LinkedList<T>::add(int index, T element)
{
	if (index == 0)
		addFirst(element);
	else if (index >= size)
		addLast(element);
	else
	{
		Node<T>* current = head;
		for (int i = 1; i < index; i++)
			current = current->next;
		Node<T>* temp = current->next;
		current->next = new Node<T>(element);
		(current->next)->next = temp;
		size++;
	}
}

template<typename T>
void LinkedList<T>::clear()
{
	while (head != NULL)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}

	tail = NULL;
	size = 0;
}

template<typename T>
T LinkedList<T>::get(int index) const
{
	if (index < 0 || index > size -1)
		throw runtime_error("Index out of range");

	Node<T>* current = head;
	for (int i = 0; i < index; i++)
		current = current->next;

	return current->element;
}

template<typename T>
int LinkedList<T>::indexOf(T element) const
{
	// Implement it in this exercise
	Node<T>* current = head;
	for (int i = 0; i < size; i++)
	{
		if (current->element == element)
			return i;
		current = current->next;
	}

	return -1;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
	return head == NULL;
}

template<typename T>
int LinkedList<T>::getSize() const
{
	return size;
}

template<typename T>
T LinkedList<T>::removeAt(int index)
{
	if (index < 0 || index >= size)
		throw runtime_error("Index out of range");
	else if (index == 0)
		return removeFirst();
	else if (index == size - 1)
		return removeLast();
	else
	{
		Node<T>* previous = head;

		for (int i = 1; i < index; i++)
		{
			previous = previous->next;
		}

		Node<T>* current = previous->next;
		previous->next = current->next;
		size--;
		T element = current->element;
		delete current;
		return element;
	}
}


template<typename T>
void LinkedList<T>::remove(T element)
{
	// could check for head here, but screw that

	while(contains(element))
	{
		Node<T>* current = head;
		Node<T>* previous = NULL;
		while(current != NULL)
		{
			if (current->element == element)
			{
				// remove the current
				Node <T>* temp;
				temp = current;
				if (previous != NULL)
					previous->next = current->next;
				else
					head = current->next;
				delete temp;
				size--;
				break; // exit the while loop
			} // end of if block
			previous = current;
			current = current->next;
		} // end of while loop
		if (current != NULL)
			;
			//cerr << endl << "it seems you removed an element" << endl;
		//else // if (current == NULL)
			//cerr << endl << "we reach the end of the list and did not find element " <<
				//element << " therefore it was not removed" << endl;
	}
} // end of method

template<typename T>
bool LinkedList<T>::contains(T element) const
{
	bool returnValue = false;
	if (indexOf(element) > -1)
	{
		returnValue = true;
	}

	return returnValue;
}

template<typename T>
void LinkedList<T>::reverse()
{
	
	
	Node<T> *current = head;
	Node<T> *next = head->next;
	Node<T> *previous = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	Node<T> *temp;

	temp = head;
	head = tail;
	tail = temp;

}

#endif

