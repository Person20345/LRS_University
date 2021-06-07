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
	Sequence<type>* coordinates_;
public:
  Matrix();

};

#endif