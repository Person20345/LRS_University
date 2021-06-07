#include <ctime>

#include "vector_time_test.h"

/**
 * with count = 10 000 000
 * DynamicArray: 14 sec.
 * LinkedList: 19 sec.
 **/

void vector_time_test() {
	// LINKEDLIST_TYPE or DYNAMICARRAY_TYPE
	int size = 3;
	Vector<int> vec1(DYNAMICARRAY_TYPE, size);
	Vector<int> vec2(DYNAMICARRAY_TYPE, size);

	for (int i = 0; i < size; i++) {
		vec1[i] = 1*i;
		vec2[i] = 10*i;
	}

	int count = 10000000;
	
	// init time counter in seconds 
	time_t start_time, end_time, delta_time;
	time(&start_time);

	for (int i = 0; i < count; i++) {
		vec1 = vec1 + vec2;
		vec1 = vec1 - vec2;
	}

	// end time counter
	time(&end_time);
	delta_time = difftime(end_time, start_time);
	// print how long did the process take
	std::cout << '\t' << delta_time << " sec.\n";
}