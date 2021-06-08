#include <iostream>

#include "linkedlist.h"

/**
 * Functions for class DynamicArray
 * 
 * 23.05.2021
 **/



// private function

template <typename type>
typename LinkedList<type>::Element* LinkedList<type>::getElement(int index) const {
	try {
   if (index < 0 || index >= size_)
      throw "Index out of range";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

	typename LinkedList<type>::Element* element = head_;

  for (int i = 0; i < index; i++)
  	element = element->next_;

  return element;
}



// constructors

template <typename type>
LinkedList<type>::LinkedList() {
	size_ = 0;
}



template <typename type>
LinkedList<type>::LinkedList(const type* items, int count) {
	size_ = 0;

	for (int i = 0; i < count; i++)
		this->addBack(items[i]);
}



template <typename type>
LinkedList<type>::LinkedList(const LinkedList<type>& list) {
	size_ = 0;

	for (int i = 0; i < size_; i++)
		this->addBack(list.get(i));
}



// get info about array

template <typename type>
int LinkedList<type>::length() const {
	return size_;
}



template <typename type>
type LinkedList<type>::get(int index) const {
  typename LinkedList<type>::Element* element = LinkedList<type>::getElement(index);

  return element->value_;
}



template <typename type>
type LinkedList<type>::getFirst() const {
	try {
   if (size_ == 0)
      throw "Index out of range";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

  return head_->value_;
}



template <typename type>
type LinkedList<type>::getLast() const {
	try {
   if (size_ == 0)
      throw "Index out of range";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }
  return tail_->value_;
}



// get list from array_[indexStart, indexEnd] inclusive
template <typename type>
LinkedList<type>* LinkedList<type>::getSubList(int indexStart, int indexEnd) const {
	try {
   if (indexEnd < 0 || indexEnd >= size_)
      throw "Index out of range";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

	typename LinkedList<type>::Element* element = LinkedList<type>::getElement(indexStart);

	LinkedList<type>* retList = (LinkedList<type>*) new LinkedList<type>;

	for (int i = indexStart; i < indexEnd + 1; i++) {
		retList->addBack(element->value_);
		element = element->next_;
	}

	return retList;
}



// change array

template <typename type>
void LinkedList<type>::addBack(type item) {
	size_++;
	
	if (size_ - 1 == 0) {
		head_ = (LinkedList<type>::Element*) new LinkedList<type>::Element;
		tail_ = head_;
		tail_->value_ = item;
	} else {
		tail_->next_ = (LinkedList<type>::Element*) new LinkedList<type>::Element;
		tail_ = tail_->next_;
		tail_->value_ = item;
	}
}



template <typename type>
void LinkedList<type>::addBack(const type* items, int count) {
 	for (int i = 0; i < count; i++)
 		LinkedList<type>::addBack(items[i]);
}



template <typename type>
void LinkedList<type>::addForward(type item) {
	size_++;
	if (size_ - 1 == 0) {
		head_ = (LinkedList<type>::Element*) new LinkedList<type>::Element;
		tail_ = head_;
		head_->value_ = item;
	} else {
		typename LinkedList<type>::Element* element = head_;
	
		head_ = (LinkedList<type>::Element*) new LinkedList<type>::Element;
		head_->value_ = item;

		head_->next_ = element;
	}
}



template <typename type>
void LinkedList<type>::addForward(const type* items, int count) {
	for (int i = 1; i < count; i++)
		LinkedList<type>::addForward(items[i]);
}



template <typename type>
void LinkedList<type>::insert(type item, int index) {
	try {
   if (index < 0 || index >= size_)
      throw "Index out of range";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

	typename LinkedList<type>::Element* element_1;
	typename LinkedList<type>::Element* element_2;

	if (index == 0) {
		element_1 = head_;

		head_ = (LinkedList<type>::Element*) new LinkedList<type>::Element;
		head_->value_ = item;
		head_->next_ = element_1;
	} else {
		element_1 = LinkedList<type>::getElement(index - 1);
		element_2 = element_1->next_;

		element_1->next_ = (LinkedList<type>::Element*) new LinkedList<type>::Element;
		element_1->next_->next_ = element_2;
		element_1->next_->value_ = item;
	}

	size_++;
}



template <typename type>
void LinkedList<type>::remove(int index) {
	typename LinkedList<type>::Element* element_1;
	typename LinkedList<type>::Element* element_2;

	if (index == 0) {
		element_1 = head_->next_;

		delete head_;
		head_ = element_1;
	} else {
		element_1 = LinkedList<type>::getElement(index - 1);
		element_2 = element_1->next_->next_;

		delete element_1->next_;
		element_1->next_ = element_2;

		if (index == size_ - 1)
			tail_ = element_1;
	}

	size_--;
}



template <typename type>
LinkedList<type>* LinkedList<type>::concat(LinkedList<type>& list) {
	LinkedList<type>* ret_list = (LinkedList<type>*) new LinkedList<type>;
	typename LinkedList<type>::Element* element = this->head_;

	for (int i = 0; i < this->size_; i++) {
		ret_list->addBack(element->value_);
		element = element->next_;
	}

	element = list.head_;

	for (int i = 0; i < list.size_; i++) {
		ret_list->addBack(element->value_);
		element = element->next_;
	}

	return ret_list;
}



// operators overloading

template <typename type>
type& LinkedList<type>::operator[] (int index) {
	return LinkedList<type>::getElement(index)->value_;
}



// destructor

template <typename type>
LinkedList<type>::~LinkedList() {
	if (size_ > 0) {
		head_->destroy();
		delete head_;
	}
}



// Element functions

template <typename type>
LinkedList<type>::Element::Element() {
	next_ = nullptr;
}



template <typename type>
void LinkedList<type>::Element::destroy() {
	if (next_ != nullptr) {
		next_->destroy();
		delete next_;
	}
}