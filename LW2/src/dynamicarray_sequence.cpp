#include <iostream>

#include "dynamicarray_sequence.h"



template <typename type>
DynamicArraySequence<type>::DynamicArraySequence() {
	array_ = (DynamicArray<type>*) new DynamicArray<type>;
}



template <typename type>
DynamicArraySequence<type>::DynamicArraySequence(const type* items, int count) {
	array_ = (DynamicArray<type>*) new DynamicArray<type>;

	for (int i = 0; i < count; i++)
		array_->add(items[i]);
}



template <typename type>
DynamicArraySequence<type>::DynamicArraySequence(const Sequence<type>& value) {
	array_ = (DynamicArray<type>*) new DynamicArray<type>;

	for (int i = 0; i < value.length(); i++)
		array_->add(value.get(i));
}



template <typename type>
void DynamicArraySequence<type>::resize(int size) {
	array_->resize(size);
}



template <typename type>
type DynamicArraySequence<type>::getFirst() const {
	return array_->get(0);
}



template <typename type>
type DynamicArraySequence<type>::getLast() const {
	return array_->get(array_->length() - 1);
}



template <typename type>
type DynamicArraySequence<type>::get(int index) const {
	return array_->get(index);
}



template <typename type>
DynamicArraySequence<type>* DynamicArraySequence<type>::getSubSequence(int indexStart, int indexEnd) const {
	int count = indexEnd - indexStart + 1;

	try {
   if (count <= 0)
      throw "Unable to create array with 0 elements";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

	type* retArray_t = (type*) new type[count];
	for (int i = 0; i < count; i++)
		retArray_t[i] = array_->get(indexStart + i);

	DynamicArraySequence<type>* retArray_das = (DynamicArraySequence<type>*) new DynamicArraySequence<type>(retArray_t, count);

	delete retArray_t;

	return retArray_das;
}



template <typename type>
int DynamicArraySequence<type>::length() const {
	return array_->length();
}



template <typename type>
void DynamicArraySequence<type>::addBack(type item) {
	array_->add(item);
}



template <typename type>
void DynamicArraySequence<type>::addForward(type item) {
	array_->add(item);
	for (int i = (array_->length() - 1); i > 0; i--)
		(*array_)[i] = (*array_)[i - 1];

	(*array_)[0] = item;
}



template <typename type>
void DynamicArraySequence<type>::insert(type item, int index) {
	array_->add(item);

	for (int i = (array_->length() - 1); i > index; i--)
		(*array_)[i] = (*array_)[i - 1];

	(*array_)[index] = item;
}



template <typename type>
type& DynamicArraySequence<type>::operator[] (int index) const {
	return (*array_)[index];
}



template <typename type>
DynamicArraySequence<type>* DynamicArraySequence<type>::concat(const Sequence<type>& value) {
	DynamicArraySequence<type>* retArray_das = (DynamicArraySequence<type>*) new DynamicArraySequence<type>((*this));
	
	for (int i = 0; i < value.length(); i++)
		retArray_das->addBack(value.get(i));

	return retArray_das;
}



template <typename type>
DynamicArraySequence<type>::~DynamicArraySequence() {
	delete array_;
}