#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



// multiplier with degree
typedef struct Term {
  double multiplier;
  double degree;
} Term;



// array of Terms
typedef struct Polynomial {
  Term* objects;
  int size;
} Poly;



// just raises a number to a power
// only for degree >= 0
double computeDegree_Double_Int (double x, unsigned int degree);

Poly computeDegree_Poly_Int (const Poly* poly, unsigned int degree);



Term setTerm(void);

// set to all values 0
Poly setPoly(void);



// print without "\n"
void printTerm (Term* term);

void printPoly (Poly* poly);



// write new Term
Term enterTerm(void);



// sum Polynomial and Term
Poly sum_Poly_Term (const Poly* poly, const Term* term);

// sum Polynomial and Polynomial
Poly sum_Poly_Poly (const Poly* poly1, const Poly* poly2);



// sort and add similar degrees
Poly sortPoly(const Poly* poly);



// sum overloading
#define sum(X, Y) _Generic((X),\
    Poly*:   _Generic((Y),\
        Poly*: sum_Poly_Poly,\
        Term*: sum_Poly_Term\
    )\
)(X, Y)



// multiplication Polynomial and Scalar
Poly mul_Poly_Scalar (const Poly* poly, double number);

// multiplication Polynomial and Polynomial
Poly mul_Poly_Term (const Poly* poly, const Term* term);

// multiplication Polynomial and Term
Poly mul_Poly_Poly (const Poly* poly1, const Poly* poly2);



// mul overloading
#define mul(X, Y) _Generic((X),\
    Poly*:   _Generic((Y),\
        Poly*: mul_Poly_Poly,\
        Term*: mul_Poly_Term,\
        double*: mul_Poly_Scalar\
    )\
)(X, Y)



// substitute x in the polynomial
double compute (const Poly* poly, double x);

// substitute polynomial 2 in the polynomial 1
Poly composition (const Poly* poly1, const Poly* poly2);