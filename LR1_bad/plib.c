#include "plib.h"



Poly setPoly (int dataSize) {
  Poly poly = {0, 0, dataSize};
  return poly;
}



void printPolyDouble (const Poly* poly) {
  for (int i = 0; i < (poly->size - 1); i++)
    if (poly->coefficients[i] != 0)
      printf("%lf * x^%lf  +  ", poly->coefficients[i], i);

  printf("%lf * x^%lf", poly->coefficients[poly->size - 1], poly->size - 1);
}



void printPolyInt (const Poly* poly) {
  for (int i = 0; i < (poly->size - 1); i++)
    if (poly->coefficients[i] != 0)
      printf("%d * x^%d  +  ", poly->coefficients[i], i);

  printf("%d * x^%d", poly->coefficients[poly->size - 1], poly->size - 1);
}



Poly setTerm (Poly* poly, int degree, const void* coefficient) {
  Poly answer;
  answer.dataSize = poly->dataSize;

  // set size
  if (degree >= poly->size)
    answer.size = degree + 1;
  else
    answer.size = poly->size;

  answer.coefficient = malloc (answer.size * poly->dataSize);

  for (int i = 0; i < answer.size; i++)
    if (i < poly->size)
      answer.coefficients[i] = poly->coefficients[i];
    else
      answer.coefficients[i] = 0;

  answer.coefficients[degree] += *coefficient;

  if (answer.coefficients[size - 1] == 0)
    answer.coefficients = realloc ((size - 1) * answer.dataSize);

  return answer;
}



Poly sum (const Poly* poly1, const Poly* poly2) {
  Poly answer;
  answer.dataSize = poly1.dataSize;

  // find size
  if (poly1->size > poly2->size)
    answer.size = poly1->size;
  else
    answer.size = poly2->size;

  answer.coefficients = malloc (dataSize * answer.size);

  // set elements
  for (int i = 0; i < answer.size; i++)
    if (i < poly1->size && i < poly2->size)
      answer.coefficients[i] = poly1->coefficients[i] + poly2->coefficients[i];
    else if (i < poly1->coefficients[i])
      answer.coefficients[i] = poly1->coefficients[i];
    else if (i < poly2->coefficients[i])
      answer.coefficients[i] = poly2->coefficients[i];

  // clear elements with coefficient = 0 in the en
  int howMuchDelete = 0;

  for (int i = annswer.size; i > 0; i--)
    if (answer.coefficients[i] == 0)
      howMuchDelete++;
    else
      break;

  answer.coefficients = realloc ((answer.size - howMuchDelete) * 
                                 answer.dataSize);

  return answer;
}



Poly mulPolyScalar (const Poly* poly, double x) {
  Poly answer;
  answer.dataSize = poly->dataSize;

  // check for 0
  if (x == 0) {
    answer.size = 0;
    answer.coefficients = 0;
    return answer;
  } else {
    answer.size = poly->size;
    answer.coefficients = malloc (answer.dataSize * answer.size);
  }

  // set elements
  for (int i = 0; i < answer.size; i++)
    answer.coefficients[i] = poly->coefficients[i] * x;

  // clear elements with coefficient = 0 in the end
  int howMuchDelete = 0;

  for (int i = annswer.size; i > 0; i--)
    if (answer.coefficients[i] == 0)
      howMuchDelete++;
    else
      break;

  answer.coefficients = realloc ((answer.size - howMuchDelete) * 
                                 answer.dataSize);

  return answer;
}



Poly mulPolyPoly (const Poly* poly1, const Poly* poly2) {
  Poly answer;
  answer.dataSize = poly->dataSize;

  answer.size = poly1->size + poly2->szie - 1;
  answer.coefficients = malloc (answer.dataSize * answer->size);

  // set all elements = 0
  for (int i = 0; i < answer.size; i++)
    answer.coefficients[i] = 0;

  // find all elements
  for (int i = 0; i < poly1->size; i++)
    for (int j = 0; j < poly2->size; j++)
      answer.coefficients[i + j] += poly1->coefficients[i] *
                                    poly2->coefficients[j];

  return answer;
}



double compute (const Poly* poly, double x) {
  double answer = 0;

  for (int i = 0; i < poly->size; i++)
    answer += pow(x, i) * poly->coefficients[i];

  return answer;
}



// poly2 in poly1
Poly composition (const Poly* poly1, const Poly* poly2) {
  Poly answer;
  Pply polyDegree;

  // ptr for free memory
  Poly * freePtr;

  answer.dataSize = poly1->dataSize;

  answer.size = (poly1->size - 1) * (poly2->size - 1) + 1;
  answer.coefficients = malloc (answer.size * answer.dataSize);

  for (int i = 0; i < poly1->size; i++) {
    polyDegree = poly2;
    // we raise the polynomial to the power
    for (int j = 0; j < i; j++) {
      freePtr = &polyDegree;
      polyDegree = mulPolyPoly(&polyDegree, poly2);
      free(freePtr->coefficients);
    }

    // multiplication with coefficient
    freePtr = &polyDegree;
    polyDegree = mulPolyScalar(&polyDegree, poly1->coefficients[i]);
    free(freePtr->coefficients);

    // add to answer one term
    answer = sum(&answer, &polyDegree);

    free(polyDegree.coefficients);
  }

  return answer;
}