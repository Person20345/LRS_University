#include "plib.h"

/* sum define function overloading
#define sum(plib, X, Y) _Generic((X),\
    Poly*:   _Generic((Y),\
        Poly*: (plib)->sum_Poly_Poly,\
        Term*: (plib)->sum_Poly_Term\
    )\
)(X, Y)
*/


void test1Poly(void) {
  Term ourTerm = setTerm();
  Poly poly = setPoly();
  Term* helpTerm;
  int sizePoly;

  printf("\t\tHow much Terms will be in poly: ");
  scanf("%d", &sizePoly);
  printf("\n");

  for (int i = 0; i < sizePoly; i++) {
    printf("Write term %d:\n", (i+1));
    ourTerm = enterTerm();

    helpTerm = poly.objects;
    poly = sum_Poly_Term (&poly, &ourTerm);
    free(helpTerm);
  }

  printf("Poly1:\n\t");
  printPoly (&poly);
  printf("\n");

  free(poly.objects);
} 


void test2Poly(void) {
  Term ourTerm = setTerm();

  Term* helpTerm;

  Poly poly1 = setPoly();
  Poly poly2 = setPoly();

  poly1.size = 0;
  poly2.size = 0;

  int sizePoly1, sizePoly2;

  int isThereNegativeDegrees = 0;

  // input data

  printf("\t\tHow much Terms will be in poly 1: ");
  scanf("%d", &sizePoly1);
  printf("\n");

  for (int i = 0; i < sizePoly1; i++) {
    printf("Write term %d:\n", (i+1));
    ourTerm = enterTerm();

    helpTerm = poly1.objects;
    poly1 = sum_Poly_Term (&poly1, &ourTerm);
    free(helpTerm);
  }

  printf("\t\tHow much Terms will be in poly 2: ");
  scanf("%d", &sizePoly2);
  printf("\n");

  for (int i = 0; i < sizePoly2; i++) {
    printf("Write term %d:\n", (i+1));
    ourTerm = enterTerm();

    helpTerm = poly2.objects;
    poly2 = sum_Poly_Term (&poly2, &ourTerm);
    free(helpTerm);
  }

  // printing results

  printf("Poly1:\n\t");
  printPoly (&poly1);
  printf("\n");

  printf("Poly2:\n\t");
  printPoly (&poly2);
  printf("\n");

  printf("\n");

  printf("sum poly1 and poly2:\n\t");
  Poly sum_ = sum_Poly_Poly (&poly1, &poly2);
  printPoly (&sum_);
  printf("\n");

  printf("mul sum and 10:\n\t");
  Poly mul1_ = mul_Poly_Scalar (&sum_, 10);
  printPoly (&mul1_);
  printf("\n");

  printf("multiplication mul and sum:\n\t");
  Poly mul2_ = mul_Poly_Poly (&sum_, &mul1_);
  printPoly (&mul2_);
  printf("\n");

  printf("x = 10 in multiplication mul and sum: \n\t ");
  double compute_ = compute (&mul2_, 10.0);
  printf("%f\n", compute_);

  printf("poly2 in poly 1:\n\t");
  Poly compos_ = composition(&poly1, &poly2);
  printPoly (&compos_);
  printf("\n");

  // free memory

  free(poly1.objects);
  free(poly2.objects);

  free(sum_.objects);
  free(mul1_.objects);
  free(mul2_.objects);
  free(compos_.objects);
} 



int main (void) {
  test2Poly();
  return 0;
}