#include "dynamicarray_test.h"



void print(DynamicArray<int>* array) {
	for (int i = 0; i < array->length(); i++)
		std::cout << "[" << i << "]: " << (*array)[i] << "   ";
	std::cout << std::endl;
}



void dynamicarray_test() {
	DynamicArray<int> array;

	int size = 5;
	int* iarr = (int*) new int[size];
	for (int i = 0; i < size; i++)
		iarr[i] = i;

	array.add(iarr, size);

	array.add(-2);
	print(&array);

	array[0] = 45;

	print(&array);

	array.resize(2);

	print(&array);

	array.add(99);
	print(&array);

	array.add(100);
	print(&array);

	array.add(89);
	print(&array);

	array.remove(2);
	print(&array);
}