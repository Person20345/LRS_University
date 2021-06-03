#include "src/dynamicarray.h"
#include "src/dynamicarray.cpp"

#include "src/linkedlist.h"
#include "src/linkedlist.cpp"


#include "src/sequence.h"

#include "src/dynamicarray_sequence.h"
#include "src/dynamicarray_sequence.cpp"

#include "src/linkedlist_sequence.h"
#include "src/linkedlist_sequence.cpp"

/**
 * Templates file for each type in this program
 * 
 * 23.05.2021
 **/

// templates for DynamicArray
template class DynamicArray<int>;

template class LinkedList<double>;


template class Sequence<int>;
template class DynamicArraySequence<int>;

template class LinkedListSequence<int>;