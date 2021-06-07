#include "vector_test.h"

void print(Vector<int>* vec) {
	std::cout << "(";
	for (int i = 0; i < vec->dimensions() - 1; i++)
		std::cout << (*vec)[i] << ", ";
	std::cout << (*vec)[vec->dimensions() - 1] << ")";
}

void print(Vector<Complex>* vec) {
	std::cout << "(";
	for (int i = 0; i < vec->dimensions() - 1; i++) {
		std::cout << (*vec)[i].Re << " + " << (*vec)[i].Im << "*i, ";
	}
	std::cout << (*vec)[vec->dimensions() - 1].Re << " + " << (*vec)[vec->dimensions() - 1].Im << "*i)";
}

void print(Complex* value) {
	std::cout << value->Re << " + " << value->Im << "*i";
}

void print(int* value) {
	std::cout << value;
}

void print(double* value) {
	std::cout << value;
}



void init(int* value, int i) {
	(*value) = i;
}

void init(double* value, int i) {
	(*value) = i + i/10;
}

void init(Complex* value, int i) {
	(*value).Re = i;
	(*value).Im = (i+1)*10;
}



void vector_test() {
	// LINKEDLIST_TYPE or DYNAMICARRAY_TYPE
	int size = 3;
	Vector<Complex> vec1(DYNAMICARRAY_TYPE, size);
	Vector<Complex> vec2(DYNAMICARRAY_TYPE, size);
	Vector<Complex> vec3(DYNAMICARRAY_TYPE, size);
	Complex value;

	// for debug
	vec1.setIndex(1);
	vec2.setIndex(2);
	vec3.setIndex(3);

	for (int i = 0; i < size; i++) {
		init(&vec1[i], i);
		init(&vec2[i], i*2);
	}
	print(&vec1);
	printf("\n");
	print(&vec2);
	printf("\n");

	vec3 = vec1 + vec2;
	print(&vec3);
	printf("\n");

	vec3 = vec1 - vec2;
	print(&vec3);
	printf("\n");

	value = vec1 * vec2;
	printf("cross = ");
	print(&value);
	printf("\n");

	value = vec3.norm();
	printf("norm ");
	print(&vec3);
	printf(" = ");
	print(&value);
	printf("\n");

	value = vec3.m_norm();
	printf("m-norm ");
	print(&vec3);
	printf(" = ");
	print(&value);
	printf("\n");

	value = vec2.l_norm();
	printf("l-norm ");
	print(&vec2);
	printf(" = ");
	print(&value);
	printf("\n");

	value = -10;
	vec3 = vec3 * value;
	print(&vec3);
	printf("\n");

	value = vec3.m_norm();
	printf("m-norm ");
	print(&vec3);
	printf(" = ");
	print(&value);
	printf("\n");
}