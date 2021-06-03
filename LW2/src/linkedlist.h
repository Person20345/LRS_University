#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>



template <typename type>
class LinkedList {
private:
	class Element;

	Element* head_;
	Element* tail_;
	int size_;

	Element* getElement(int index) const;
public:
	// constructors
	LinkedList();
	LinkedList(const type* items, int count);
	LinkedList(const LinkedList& list);

	// get info about array
	int length() const;
	type get(int index) const;
	type getFirst() const;
	type getLast() const;
	LinkedList<type>* getSubList(int indexStart, int indexEnd) const;

	// change array
	// set items in end of list
	void addBack(type item);
	void addBack(const type* items, int count);
	// set items in start of list
	void addForward(type item);
	void addForward(const type* items, int count);
	// set element in middle of list
	void insert(type item, int index);
	// remove element
	void remove(int index);
	// concatination
	LinkedList<type>* concat(LinkedList<type>& list);

	// operators overloading
	type& operator[] (int index);

	// friend functions
	friend LinkedList<type>* LinkedList<type>::concat(LinkedList<type>& list);

	// destructor
	~LinkedList();
};



template <typename type>
class LinkedList<type>::Element {
public:
	type value_;
	Element* next_;

	Element();
	void destroy();
};

#endif