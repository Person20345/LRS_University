#ifndef DYNAMICARRAY_SEQUENCE_H
#define DYNAMICARRAY_SEQUENCE_H

#include <iostream>

#include "sequence.h"
#include "dynamicarray.h"

template <typename type>
class DynamicArraySequence : public Sequence<type> {
private:
	DynamicArray<type>* array_;
public:
	DynamicArraySequence();
	DynamicArraySequence(const type* items, int count);
	DynamicArraySequence(const Sequence<type>& value);

	void resize(int size);
	
	type getFirst() const;
	type getLast() const;
	type get(int index) const;
	DynamicArraySequence<type>* getSubSequence(int indexStart, int indexEnd) const;
	int length() const;

	void addBack(type item);
	void addForward(type item);
	void insert(type item, int index);
	DynamicArraySequence<type>* concat(const Sequence<type>& value);

	type& operator[] (int index) const;
	
	friend DynamicArraySequence<type>* DynamicArraySequence<type>::concat(const Sequence<type>& value);

	~DynamicArraySequence();
};

#endif