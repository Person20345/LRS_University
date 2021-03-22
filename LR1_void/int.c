#include "headers.h"



static void printInt (const void* variable) {
	int* pointer;
	pointer = (int*) variable;
	printf ("%d", *pointer);
}

static int сompareWithZeroInt (const void* variable) {
	int* pointer = (int*) variable;
	if (*pointer == 0)
		return 0;
	else if (*pointer > 0)
		return 1;
	else
		return -1;
}

static void* initNullInt () {
	void* answer = (void*) malloc (sizeof(int));

	int* pointer = (int*) answer;
  *pointer = 0;

  return answer;
}



static void* sumInt (const void* variable1, const void* variable2) {
	void* answer = (void*) malloc (sizeof(int));
	int* variable1_ = (int*) variable1;
  int* variable2_ = (int*) variable2;
  int* answer_ = (int*) answer;
  *answer_ = *variable1_ + *variable2_;

  return answer;
}

static void* mulInt (const void* variable1, const void* variable2) {
	void* answer = (void*) malloc (sizeof(int));
	int* variable1_ = (int*) variable1;
  int* variable2_ = (int*) variable2;
  int* answer_ = (int*) answer;
  *answer_ = *variable1_ * *variable2_;

  return answer;
}



Poly initPolyInt (uint32_t size) {
	Poly newPoly;

	newPoly.dataSize = sizeof(int);

	newPoly.size = size;
	if (size > 0)
		newPoly.multipliers = (void**) calloc(newPoly.size, sizeof(void*));
		for (int i = 0; i < newPoly.size; i++)
			newPoly.multipliers[i] = initNullInt();

	newPoly.print = printInt;
	newPoly.сompareWithZero = сompareWithZeroInt;
	newPoly.initNull = initNullInt;

	newPoly.sum = sumInt;
	newPoly.mul = mulInt;
	
	newPoly.init = initPolyInt;

	return newPoly;
}