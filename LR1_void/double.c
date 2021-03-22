#include "headers.h"



static void printDouble (const void* variable) {
	double* pointer;
	pointer = (double*) variable;
	printf ("%.1f", *pointer);
}

static int сompareWithZeroDouble (const void* variable) {
	double* pointer = (double*) variable;
	if (*pointer == 0.0)
		return 0;
	else if (*pointer > 0.0)
		return 1;
	else
		return -1;
}

static void* initNullDouble () {
	void* answer = (void*) malloc (sizeof(double));

	double* pointer = (double*) answer;
  *pointer = 0.0;

  return answer;
}



static void* sumDouble (const void* variable1, const void* variable2) {
	void* answer = (void*) malloc (sizeof(double));
	double* variable1_ = (double*) variable1;
  double* variable2_ = (double*) variable2;
  double* answer_ = (double*) answer;
  *answer_ = *variable1_ + *variable2_;

  return answer;
}

static void* mulDouble (const void* variable1, const void* variable2) {
	void* answer = (void*) malloc (sizeof(double));
	double* variable1_ = (double*) variable1;
  double* variable2_ = (double*) variable2;
  double* answer_ = (double*) answer;
  *answer_ = *variable1_ * *variable2_;

  return answer;
}



Poly initPolyDouble (uint32_t size) {
	Poly newPoly;

	newPoly.dataSize = sizeof(double);

	newPoly.size = size;
	if (size > 0)
		newPoly.multipliers = (void**) calloc(newPoly.size, sizeof(void*));
		for (int i = 0; i < newPoly.size; i++)
			newPoly.multipliers[i] = initNullDouble();

	newPoly.print = printDouble;
	newPoly.сompareWithZero = сompareWithZeroDouble;
	newPoly.initNull = initNullDouble;

	newPoly.sum = sumDouble;
	newPoly.mul = mulDouble;

	newPoly.init = initPolyDouble;

	return newPoly;
}