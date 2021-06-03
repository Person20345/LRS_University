#include <iostream>

#include "dynamicarray.h"

/**
 * Functions for class DynamicArray
 * 
 * 23.05.2021
 **/



// constructors

template <typename type>
DynamicArray<type>::DynamicArray() {
	size_ = 0;
}



template <typename type>
DynamicArray<type>::DynamicArray(int size) {
	size_ = size;
	array_ = (type*) new type[size_];
}



template <typename type>
DynamicArray<type>::DynamicArray(type* items, int count) {
	size_ = count;
	array_ = (type*) new type[size_];

	for (int i = 0; i < size_; i++)
		array_[i] = items[i];
}



template <typename type>
DynamicArray<type>::DynamicArray(const DynamicArray<type>& array) {
	size_ = array.length();

	array_ = (type*) new type[size_];

	for (int i = 0; i < size_; i++)
		array_[i] = array.get(i);
}



// get info about array

template <typename type>
int DynamicArray<type>::length() const {
	return size_;
}



template <typename type>
type DynamicArray<type>::get(int index) const {
	try {
   if (index < 0 || index >= size_)
      throw "Index out of range";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  return array_[index];
}



// change functions

template <typename type>
void DynamicArray<type>::add(type item) {
	size_++;
	type* updated_array = (type*) new type[size_];

	for (int i = 0; i < size_ - 1; i++)
		updated_array[i] = array_[i];

	updated_array[size_ - 1] = item;

	if (size_ > 1)
		delete array_;

	array_ = updated_array;
}



template <typename type>
void DynamicArray<type>::add(const type* items, int count) {
	this->resize(size_ + count);

	for (int i = 0; i < count; i++)
		array_[size_ - count + i] = items[i];
}



template <typename type>
int DynamicArray<type>::remove(int index) {
	try {
   if (index < 0 || index >= size_)
      throw "Index out of range";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

	size_--;
	type* updated_array = (type*) new type[size_];

	for (int i = 0; i < size_; i++)
		if (i < index)
			updated_array[i] = array_[i];
		else if (i >= index)
			updated_array[i] = array_[i + 1];

	array_ = updated_array;

	return index;
}



template <typename type>
void DynamicArray<type>::set(int index, type item) {
	try {
   if (index < 0 || index >= size_)
      throw "Index out of range";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  array_[index] = item;
}



template <typename type>
void DynamicArray<type>::resize(int newSize) {
	type* updated_array = (type*) new type[newSize];

	for (int i = 0; i < newSize; i++)
		if (i < size_)
			updated_array[i] = array_[i];
		else
			updated_array[i] = 0;

	delete[] array_;
	array_ = updated_array;
	size_ = newSize;
}



// operators overloading

template <typename type>
type& DynamicArray<type>::operator[] (int index) {
	try {
   if (index < 0 || index >= size_)
      throw "Index out of range";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  return array_[index];
}



// destructor

template <typename type>
DynamicArray<type>::~DynamicArray() {
	if (size_ > 0)
		delete[] array_;
}