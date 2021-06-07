#include <iostream>

#include "linkedlist_sequence.h"


template <typename type>
LinkedListSequence<type>::LinkedListSequence() {
	list_ = (LinkedList<type>*) new LinkedList<type>; 
}



template <typename type>
LinkedListSequence<type>::LinkedListSequence(const type* items, int count) {
	list_ = (LinkedList<type>*) new LinkedList<type>;

	for (int i = 0; i < count; i++)
		list_->addBack(items[i]);
}



template <typename type>
LinkedListSequence<type>::LinkedListSequence(const Sequence<type>& value) {
	list_ = (LinkedList<type>*) new LinkedList<type>;

	for (int i = 0; i < value.length(); i++)
		list_->addBack(value.get(i));
}



template <typename type>
void LinkedListSequence<type>::resize(int size) {
	if (size < list_->length()) {
		for (int i = 0; i < list_->length() - size; i++)
			list_->remove(list_->length() - i - 1);
	} else if (size > list_->length()) {
		type value;
		for (int i = 0; i < size - list_->length(); i++)
			list_->addBack(value);
	}
}



template <typename type>
type LinkedListSequence<type>::getFirst() const {
	return list_->getFirst();
}



template <typename type>
type LinkedListSequence<type>::getLast() const {
	return list_->getLast();
}



template <typename type>
type LinkedListSequence<type>::get(int index) const {
	return list_->get(index);
}



template <typename type>
LinkedListSequence<type>* LinkedListSequence<type>::getSubSequence(int indexStart, int indexEnd) const {
	LinkedList<type>* retList_ll;

	retList_ll = list_->getSubList(indexStart, indexEnd);

	LinkedListSequence<type>* retList_lls;

	for (int i = 0; i < retList_ll->length(); i++)
		retList_lls->addBack(retList_ll->get(i));

	return retList_lls;
}



template <typename type>
int LinkedListSequence<type>::length() const {
	return list_->length();
}



template <typename type>
void LinkedListSequence<type>::addBack(type item) {
	list_->addBack(item);
}



template <typename type>
void LinkedListSequence<type>::addForward(type item) {
	list_->addForward(item);
}



template <typename type>
void LinkedListSequence<type>::insert(type item, int index) {
	list_->insert(item, index);
}



template <typename type>
type& LinkedListSequence<type>::operator[] (int index) const {
	return (*list_)[index];
}



template <typename type>
LinkedListSequence<type>* LinkedListSequence<type>::concat(const Sequence<type>& value) {
	LinkedList<type>* secondList_ll = (LinkedList<type>*) new LinkedList<type>;
	LinkedList<type>* retList_ll;

	for (int i = 0; i < value.length(); i++)
		secondList_ll->addBack(value.get(i));

	retList_ll = list_->concat(*secondList_ll);

	LinkedListSequence<type>* retList_lls;

	for (int i = 0; i < retList_ll->length(); i++)
		retList_lls->addBack(retList_ll->get(i));

	return retList_lls;
}



template <typename type>
LinkedListSequence<type>::~LinkedListSequence() {
	delete list_;
}