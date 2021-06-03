#include "sequence_test.h"



void print(LinkedListSequence<int>* array) {
	std::cout << "length = " << array->length() << "     ";
	for (int i = 0; i < array->length(); i++)
		std::cout << "[" << i << "]: " << (*array)[i] << "   ";
	std::cout << std::endl;
}



void sequence_test() {
	LinkedListSequence<int> array;

	array.addBack(-2);
	array.addForward(9);

	printf("Last = %d\n", array.getLast());
	printf("First = %d\n", array.getFirst());
	
	print(&array);

	array.insert(10, 1);

	print(&array);

	array.insert(112, 0);

	print(&array);

	array.addForward(193);

	array.addForward(78);

	array.addForward(563);

	print(&array);

	LinkedListSequence<int>* array2 = array.getSubSequence(3, array.length() - 1);

	print(array2);

	LinkedListSequence<int>* array3;

	array3 = array.concat(*array2);

	print(array3);
}