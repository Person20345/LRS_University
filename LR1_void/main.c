#include "include/headers.h"

// gcc main.c src/functions.c src/double.c src/int.c

int main () {
	uint32_t numOfTerms;
	Poly poly1 = initPolyDouble (1);
	Poly poly2 = initPolyDouble (1);

	uint32_t degree;
	double multiplier;

	void** ppointer;

	printf("  Write num of terms in poly1: ");
	scanf("%u", &numOfTerms);

	for (int i = 0; i < numOfTerms; i++) {
		printf("    Write degree: ");
		scanf("%u", &degree);
		printf("    Write multiplier: ");
		scanf("%lf", &multiplier);

		ppointer = poly1.multipliers;
		poly1 = addTerm (&poly1, &multiplier, degree);
		free (ppointer);
	}

	printf("  Write num of terms in poly2: ");
	scanf("%u", &numOfTerms);
	
	for (int i = 0; i < numOfTerms; i++) {
		printf("    Write degree: ");
		scanf("%u", &degree);
		printf("    Write multiplier: ");
		scanf("%lf", &multiplier);

		ppointer = poly2.multipliers;
		poly2 = addTerm (&poly2, &multiplier, degree);
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
	ppointer = poly2.multipliers;
	poly2 = compositionPoly (&poly1, &poly2);
	free (ppointer);

	printf("composition: ");
	printPoly(&poly2);
	printf("\n");


	// test mulPoly()
	ppointer = poly2.multipliers;
	poly2 = mulPoly(&poly1, &poly2);
	free (ppointer);

	printf("mul: ");
	printPoly(&poly2);
	printf("\n");

	// test mulPolyScalar ()
	printf("    Write scalar for multiplication with poly: ");
	scanf("%lf", &multiplier);

	ppointer = poly2.multipliers;
	poly2 = mulPolyScalar (&poly2, &multiplier);
	free (ppointer);

	printf("scalar * poly: ");
	printPoly(&poly2);
	printf("\n");

	// test сalculatePoly ()
	void* var;
	double* varD;

	printf("    Write scalar for calculatig: ");
	scanf("%lf", &multiplier);

	ppointer = poly2.multipliers;
	var = сalculatePoly (&poly2, &multiplier);
	free (ppointer);

	varD = (double*) var;
	printf("calculate: %lf\n", *varD);

	return 0;
}