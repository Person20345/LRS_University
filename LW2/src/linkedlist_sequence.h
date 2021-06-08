#ifndef LINKEDLIST_SEQUENCE_H
#define LINKEDLIST_SEQUENCE_H

#include <iostream>

#include "sequence.h"
#include "linkedlist.h"

template <typename type>
class LinkedListSequence : public Sequence<type> {
private:
	LinkedList<type>* list_;
public:
	LinkedListSequence();
	LinkedListSequence(const type* items, int count);
	LinkedListSequence(const Sequence<type>& value);

	void resize(int size);

	type getFirst() const;
	type getLast() const;
	type get(int index) const;
	LinkedListSequence<type>* getSubSequence(int indexStart, int indexEnd) const;
	int length() const;

	void addBack(type item);
	void addForward(type item);
	void insert(type item, int index);
	LinkedListSequence<type>* concat(const Sequence<type>& value);

	type& operator[] (int index) const;
	void operator = (LinkedListSequence<type> list);

	friend LinkedListSequence<type>* LinkedListSequence<type>::concat(const Sequence<type>& value);

	~LinkedListSequence();
};

#endif