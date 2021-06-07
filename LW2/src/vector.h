#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include "sequence.h"
#include "linkedlist_sequence.h"
#include "dynamicarray_sequence.h"

#include "complex.h"

#define LINKEDLIST_TYPE 0
#define DYNAMICARRAY_TYPE 1

template <typename type>
class Vector {
private:
	Sequence<type>* coordinates_;
  int sequence_type_;

  int index_;
public:
  Vector();
	Vector(int TYPE);
  Vector(int TYPE, int size);

  void setSequence(int TYPE);
  void setIndex(int index);
  int getIndex();

  void setSize(int size);

  type norm();
  type m_norm();
  type l_norm();

  int dimensions();
  int sequenceType();
  
  Vector<type> operator + (Vector<type>& vector);
  Vector<type> operator - (Vector<type>& vector);

  type operator * (Vector<type>& vector);
  
  Vector<type> operator * (type value);

  type& operator [] (int index);

  void operator = (Vector<type> vector);

  ~Vector();
};

#endif