#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <inttypes.h>
#ifndef SCNu8
#define SCNu8 "hhu"
#endif



typedef struct Polynomial {
	void** multipliers;
	uint32_t size;
	uint8_t dataSize;

	void (*print) (const void*);
	int (*сompareWithZero) (const void*);
	void* (*initNull) ();

	void* (*sum) (const void*, const void*);
	void* (*mul) (const void*, const void*);

	struct Polynomial (*init) (uint32_t);

} Poly;



// ============================================================================
// These functions must be implemented for all types that we will want to use

// Type "double"

void printDouble (const void* variable) {
	double* pointer;
	pointer = (double*) variable;
	printf ("%.1f", *pointer);
}

int сompareWithZeroDouble (const void* variable) {
	double* pointer = (double*) variable;
	if (*pointer == 0.0)
		return 0;
	else if (*pointer > 0.0)
		return 1;
	else
		return -1;
}

void* initNullDouble () {
	void* answer = (void*) malloc (sizeof(double));

	double* pointer = (double*) answer;
  *pointer = 0.0;

  return answer;
}



void* sumDouble (const void* variable1, const void* variable2) {
	void* answer = (void*) malloc (sizeof(double));
	double* variable1_ = (double*) variable1;
  double* variable2_ = (double*) variable2;
  double* answer_ = (double*) answer;
  *answer_ = *variable1_ + *variable2_;

  return answer;
}

void* mulDouble (const void* variable1, const void* variable2) {
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



// Type "int"

void printInt (const void* variable) {
	int* pointer;
	pointer = (int*) variable;
	printf ("%d", *pointer);
}

int сompareWithZeroInt (const void* variable) {
	int* pointer = (int*) variable;
	if (*pointer == 0)
		return 0;
	else if (*pointer > 0)
		return 1;
	else
		return -1;
}

void* initNullInt () {
	void* answer = (void*) malloc (sizeof(int));

	int* pointer = (int*) answer;
  *pointer = 0;

  return answer;
}



void* sumInt (const void* variable1, const void* variable2) {
	void* answer = (void*) malloc (sizeof(int));
	int* variable1_ = (int*) variable1;
  int* variable2_ = (int*) variable2;
  int* answer_ = (int*) answer;
  *answer_ = *variable1_ + *variable2_;

  return answer;
}

void* mulInt (const void* variable1, const void* variable2) {
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

// ============================================================================



// just printing without "\n" in the end
void printPoly (const Poly* poly) {
	for (int i = 0; i < poly->size; i++)
		if (poly->сompareWithZero(poly->multipliers[i]) != 0) {
			printf("(");
			poly->print(poly->multipliers[i]);
			printf(")x^%d", i);
			if (i < (poly->size - 1))
				printf(" + ");
		}
	printf("     size = %d", poly->size);
}



void printFullPoly (const Poly* poly) {
	for (int i = 0; i < poly->size; i++){
		printf("(");
		poly->print(poly->multipliers[i]);
		printf(")x^%d", i);
		if (i < (poly->size - 1))
			printf(" + ");
	}
}



Poly addTerm (const Poly* poly, const void* multiplier, uint32_t degree) {
	Poly answer;

	void* pointer;

	if (poly->size < (degree + 1)) {
		answer = poly->init (degree + 1);
		for (int i = 0; i < poly->size; i++) {
			pointer = answer.multipliers[i];
			answer.multipliers[i] = poly->sum (answer.multipliers[i],
			                                   poly->multipliers[i]);
			free(pointer);
		}
		pointer = answer.multipliers[degree];
		answer.multipliers[degree] = poly->sum (answer.multipliers[degree],
		                                        multiplier);
		free(pointer);
	}	else {
		answer = poly->init (poly->size);
		for (int i = 0; i < poly->size; i++)
			memcpy (answer.multipliers[i], poly->multipliers[i], poly->dataSize);

		pointer = answer.multipliers[degree];
		answer.multipliers[degree] = poly->sum (answer.multipliers[degree],
		                                        multiplier);
		free (pointer);
	}

	return answer;
}



Poly sumPoly (const Poly* poly1, const Poly* poly2) {
	Poly answer;

	void* pointer;

	uint8_t minSize;
	const Poly* maxPoly;

	if (poly1->dataSize == poly2->dataSize) {
		if (poly1->size < poly2->size) {
			answer = poly2->init (poly2->size);
			minSize = poly1->size;
			maxPoly = poly2;
		} else {
			answer = poly1->init (poly1->size);
			minSize = poly2->size;
			maxPoly = poly1;
		}

		for (int i = 0; i < minSize; i++) {
			pointer = answer.multipliers[i];
			answer.multipliers[i] = answer.sum (poly1->multipliers[i],
			                                     poly2->multipliers[i]);
			free (pointer);
		}

		for (int i = minSize; i < answer.size; i++) {
			pointer = answer.multipliers[i];
			answer.multipliers[i] = answer.sum (answer.multipliers[i],
			                                     maxPoly->multipliers[i]);
			free (pointer);
		}
	}

	return answer;
}



Poly mulPoly (const Poly* poly1, const Poly* poly2) {
	Poly answer;

	void* pointer;

	if (poly1->dataSize == poly2->dataSize) {
		answer = poly1->init ((poly1->size - 1) + (poly2->size - 1) + 1);
		for (int i = 0; i < poly1->size; i++)
			for (int j = 0; j < poly2->size; j++) {
				pointer = answer.multipliers[i+j];
				answer.multipliers[i+j] = answer.sum (answer.mul (poly1->multipliers[i],
				                                                  poly2->multipliers[j]),
				                                      answer.multipliers[i+j]);
				free (pointer);
			}
	}

	return answer;
}



Poly mulPolyScalar (const Poly* poly, const void* scalar) {
	Poly answer;

	void* pointer;

	if (poly->сompareWithZero(scalar) != 0) {
		answer = poly->init (poly->size);
		for (int i = 0; i < poly->size; i++) {
			pointer = answer.multipliers[i];
			answer.multipliers[i] = answer.sum (answer.mul (poly->multipliers[i],
			                                                scalar),
			                                    answer.multipliers[i]);
			free (pointer);
		}
	} else {
		answer = poly->init (0);
	}

	return answer;
}



void* сalculatePoly (const Poly * poly, const void* variable) {
	void* answer = poly->initNull ();
	void* pointer;

	void* degree = poly->initNull ();

	if (poly->сompareWithZero(variable) != 0)
		for (int i = 0; i < poly->size; i++) {
			pointer = degree;
			degree = poly->initNull ();
			free(pointer);

			// degree = x
			pointer = degree;
			degree = poly->sum (degree, variable);
			free(pointer);

			// degree = x^n = m
			for (int j = 1; j < i; j++) {
				pointer = degree;
				degree = poly->mul (degree, variable);
				free(pointer);
			}

			// degree = k * m
			pointer = degree;
			degree = poly->mul (degree, poly->multipliers[i]);
			free(pointer);

			// answer += degree
			pointer = answer;
			answer = poly->sum (answer, degree);
			free(pointer);
		}

	return answer;
}



Poly compositionPoly (const Poly* poly1, const Poly* poly2) {
	Poly answer;
	Poly degree;

	// to clean the memory
	void* pointer;
	void** ppointer;
	uint32_t oldSize;

	uint32_t sizeOfDegree;

	if (poly1->dataSize == poly2->dataSize) {
		degree = poly1->init (1);

		// set answer size
		answer = poly1->init ((poly1->size - 1) * (poly2->size - 1) + 1);

		for (int i = 0; i < poly1->size; i++) {
			// find size of polinomial in this degree
			sizeOfDegree = 1;
			for (int j = 0; j < i; j++)
				sizeOfDegree *= (poly2->size - 1);
			sizeOfDegree++;
			// set degree
			oldSize = degree.size;
			ppointer = degree.multipliers;
			degree = degree.init (sizeOfDegree);
			for (int j = 0; j < oldSize; j++)
				free (ppointer[j]);
			free (ppointer);


			// set first multiplier in degree
			oldSize = degree.size;
			ppointer = degree.multipliers;
			degree = sumPoly (&degree, poly2);
			for (int j = 0; j < oldSize; j++)
				free (ppointer[j]);
			free (ppointer);
			// degree
			for (int j = 1; j < i; j++) {
				oldSize = degree.size;
				ppointer = degree.multipliers;
				degree = mulPoly (&degree, poly2);
				for (int k = 0; k < oldSize; k++)
					free (ppointer[k]);
				free (ppointer);
			}

			// multiply on the coefficient
			oldSize = degree.size;
			ppointer = degree.multipliers;
			degree = mulPolyScalar (&degree, poly1->multipliers[i]);
			for (int j = 0; j < oldSize; j++)
				free (ppointer[j]);
			free (ppointer);

			// add to answer
			oldSize = answer.size;
			ppointer = answer.multipliers;
			answer = sumPoly (&answer, &degree);
			for (int j = 0; j < oldSize; j++)
				free (ppointer[j]);
			free (ppointer);
		}
	}

	return answer;
}



int main () {
	uint32_t numOfTerms;
	Poly poly1 = initPolyDouble (1);
	Poly poly2 = initPolyDouble (1);

	uint32_t degree;
	double multiplier;

	void** ppointer;
	uint32_t oldSize;

	printf("  Write num of terms in poly1: ");
	scanf("%u", &numOfTerms);

	for (int i = 0; i < numOfTerms; i++) {
		printf("    Write degree: ");
		scanf("%u", &degree);
		printf("    Write multiplier: ");
		scanf("%lf", &multiplier);

		oldSize = poly2.size;
		ppointer = poly1.multipliers;
		poly1 = addTerm (&poly1, &multiplier, degree);
		for (int j = 0; j < oldSize; j++)
			free (ppointer[j]);
		free (ppointer);
	}

	printf("  Write num of terms in poly2: ");
	scanf("%u", &numOfTerms);
	
	for (int i = 0; i < numOfTerms; i++) {
		printf("    Write degree: ");
		scanf("%u", &degree);
		printf("    Write multiplier: ");
		scanf("%lf", &multiplier);

		oldSize = poly2.size;
		ppointer = poly2.multipliers;
		poly2 = addTerm (&poly2, &multiplier, degree);
		for (int j = 0; j < oldSize; j++)
			free (ppointer[j]);
		free (ppointer);
	}

	// simple test addTerm()
	printf("      Poly1: ");
	printPoly(&poly1);
	printf("\n");
	printf("      Poly2: ");
	printPoly(&poly2);
	printf("\n");

	// test compositionPoly()
	oldSize = poly2.size;
	ppointer = poly2.multipliers;
	poly2 = compositionPoly (&poly1, &poly2);
	for (int j = 0; j < oldSize; j++)
		free (ppointer[j]);
	free (ppointer);

	printf("composition: ");
	printPoly(&poly2);
	printf("\n");


	// test mulPoly()
	oldSize = poly2.size;
	ppointer = poly2.multipliers;
	poly2 = mulPoly(&poly1, &poly2);
	for (int j = 0; j < oldSize; j++)
		free (ppointer[j]);
	free (ppointer);

	printf("mul: ");
	printPoly(&poly2);
	printf("\n");

	// test mulPolyScalar ()
	printf("    Write scalar for multiplication with poly: ");
	scanf("%lf", &multiplier);

	oldSize = poly2.size;
	ppointer = poly2.multipliers;
	poly2 = mulPolyScalar (&poly2, &multiplier);
	for (int j = 0; j < oldSize; j++)
		free (ppointer[j]);
	free (ppointer);

	printf("scalar * poly: ");
	printPoly(&poly2);
	printf("\n");

	// test сalculatePoly ()
	void* var;
	double* varD;

	printf("    Write scalar for calculatig: ");
	scanf("%lf", &multiplier);

	oldSize = poly2.size;
	ppointer = poly2.multipliers;
	var = сalculatePoly (&poly2, &multiplier);
	for (int j = 0; j < oldSize; j++)
		free (ppointer[j]);
	free (ppointer);

	varD = (double*) var;
	printf("calculate: %lf\n", *varD);

	return 0;
}