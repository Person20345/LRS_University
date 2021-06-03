#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>

template <typename type>
class Sequence {
public:
	virtual type getFirst() const = 0;
	virtual type getLast() const = 0;
	virtual type get(int index) const = 0;
	virtual Sequence<type>* getSubSequence(int indexStart, int indexEnd) const = 0;
	virtual int length() const = 0;

	virtual void addBack(type item) = 0;
	virtual void addForward(type item) = 0;
	virtual void insert(type item, int index) = 0;
	virtual Sequence<type>* concat(const Sequence<type>& value) = 0;

	friend Sequence<type>* Sequence<type>::concat(const Sequence<type>& value);
};

#endif