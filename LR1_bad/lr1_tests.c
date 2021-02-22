#include "plib.h"

/* sum define function overloading
#define sum(plib, X, Y) _Generic((X),\
    Poly*:   _Generic((Y),\
        Poly*: (plib)->sum_Poly_Poly,\
        Term*: (plib)->sum_Poly_Term\
    )\
)(X, Y)
*/



void test1 (void) {
  Poly poly1 = setPoly (sizeof(double));
  Poly poly2 = setPoly (sizeof(double));

  int howMuchTerms;

  printf("Write how  much terms will be in poly1");
  scanf("%d", howMuchTerm);

  int coef, degree;

  printf("Poly1:\n");
  for (int i = 0; i < howMuchTerm; i++) {
    printf("    Write coefficient: ");
    scanf("%lf", coef);
    printf("\n");

    printf("    Write degree: ");
    scanf("%lf", degree);
    printf("\n");
  }
}



int main (void) {
  test1();

  return 0;
}