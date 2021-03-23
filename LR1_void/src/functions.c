#include "../include/headers.h"



// just printing without "\n" in the end
// print without 0-elements
void printPoly (const Poly* poly) {
	for (int i = 0; i < poly->size; i++)
		if (poly->сompareWithZero(poly->multipliers[i]) != 0) {
			printf("(");
			poly->print(poly->multipliers[i]);
			printf(")x^%d", i);
			if (i < (poly->size - 1))
				printf(" + ");
		}
}



// print with 0-elements
void printFullPoly (const Poly* poly) {
	for (int i = 0; i < poly->size; i++){
		printf("(");
		poly->print(poly->multipliers[i]);
		printf(")x^%d", i);
		if (i < (poly->size - 1))
			printf(" + ");
	}
}



// add new pair (multiplier * x^degree)
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
		answer = poly->init (1);
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



// set poly2 in poly1
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