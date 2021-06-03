#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

template <typename type>
class DynamicArray {
private:
	type* array_;
	int size_;
	
public:
	// constructors
	DynamicArray();
	DynamicArray(int size);
	DynamicArray(type* items, int count);
	DynamicArray(const DynamicArray<type>& array);

	// get info about array
	int length() const;
	type get(int index) const;

	// change array
	void add(type item);
	void add(const type* items, int count);
	int remove(int index);
	void set(int index, type item);
	void resize(int newSize);

	// operators overloading
	type& operator[] (int index);

	// destructor
	~DynamicArray();
};

#endif