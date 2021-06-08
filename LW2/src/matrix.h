#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include "sequence.h"
#include "linkedlist_sequence.h"
#include "dynamicarray_sequence.h"

#include "complex.h"

#define LINKEDLIST_TYPE 0
#define DYNAMICARRAY_TYPE 1

template <typename type>
class Matrix {
private:
	Sequence<Sequence<type> >* values_;
	int colums_num_;
	int strings_num_;

	int sequence_type_;

  int index_;
public:
  Matrix();
  Matrix(int TYPE);
  Matrix(int TYPE, int strings_num, int colums_num);

  void setSequence(int TYPE);
  void setSize(int strings_num, int colums_num);

  int columsNum();
  int stringsNum();
  int sequenceType();

  Matrix<type> operator + (Matrix<type>& mat);
  Matrix<type> operator - (Matrix<type>& mat);
  Matrix<type> operator * (Matrix<type>& mat);
  Matrix<type> operator * (type value);
  Matrix<type> operator / (type value);

  void operator = (Matrix<type> mat);

	Sequence<type>* operator [] (int index);

  // return index of string there are changes
  int addStr(int indexTo, int indexThis);
  int subtractStr(int indexFrom, int indexThis);

  int multiplyStr(int indexThis, type value);
  int divideStr(int indexThis, type value);

  // return index of colum there are changes
  int addClm(int indexTo, int indexThis);
  int subtractClm(int indexFrom, int indexThis);

  int multiplyClm(int indexThis, type value);
  int divideClm(int indexThis, type value);

  type norm(int p);
};

#endif