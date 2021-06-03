#include "linkedlist_test.h"



void print(LinkedList<double>* list) {
	std::cout << "Lenght: " << list->length() << " :: ";
	for (int i = 0; i < list->length(); i++)
		std::cout << "[" << i << "]:" << (*list)[i] << " ";
	std::cout << std::endl << std::endl;
}


void linkedlist_test() {
	LinkedList<double> list;

	list.addBack(10.23);

	std::cout << "First last:" << list.getFirst() << " " << list.getLast() << std::endl;

	print(&list);

	list.addBack(43.98);

	list.addForward(8);

	list.addBack(11.7);

	list.addForward(9.09);

	std::cout << "First last:" << list.getFirst() << " " << list.getLast() << std::endl;

	print(&list);

	list[2] = 10.9;

	print(&list);

	list.remove(1);
	list.remove(0);
	list.remove(1);

	print(&list);

	list.insert(89.8909, 1);

	print(&list);

	list.insert(123.4, 0);

	print(&list);

	LinkedList<double> list2;
	LinkedList<double>* list3;

	list2.addBack(1.1);
	list2.addBack(2.2);
	list2.addBack(3.3);
	list2.addBack(4.4);

	print(&list2);

	list3 = list.concat(list2);

	print(list3);
}