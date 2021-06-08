#include "src/complex.h"

#include "src/dynamicarray.h"
#include "src/dynamicarray.cpp"

#include "src/linkedlist.h"
#include "src/linkedlist.cpp"


#include "src/sequence.h"
#include "src/sequence.cpp"

#include "src/dynamicarray_sequence.h"
#include "src/dynamicarray_sequence.cpp"

#include "src/linkedlist_sequence.h"
#include "src/linkedlist_sequence.cpp"


#include "src/vector.h"
#include "src/vector.cpp"


#include "src/matrix.h"
#include "src/matrix.cpp"

/**
 * Templates file for each type in this program
 * 
 * 23.05.2021
 **/

// templates for DynamicArray
template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<Complex>;

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<Complex>;



template class Sequence<int>;
template class DynamicArraySequence<int>;
template class LinkedListSequence<int>;
template class Vector<int>;

template class Sequence<double>;
template class DynamicArraySequence<double>;
template class LinkedListSequence<double>;
template class Vector<double>;

template class Sequence<Complex>;
template class DynamicArraySequence<Complex>;
template class LinkedListSequence<Complex>;
template class Vector<Complex>;



template class Sequence<Sequence<int> >;
template class DynamicArraySequence<DynamicArraySequence<int> >;
template class LinkedListSequence<LinkedListSequence<int> >;

template class Sequence<Sequence<double> >;
template class DynamicArraySequence<DynamicArraySequence<double> >;
template class LinkedListSequence<LinkedListSequence<double> >;

template class Sequence<Sequence<Complex> >;
template class DynamicArraySequence<DynamicArraySequence<Complex> >;
template class LinkedListSequence<LinkedListSequence<Complex> >;



template class Matrix<int>;
template class Matrix<double>;
template class Matrix<Complex>;