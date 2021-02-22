#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct Polynomial {
    void* coefficients;
    int size;
    int dataSize;
} Poly;



Poly setPoly (int dataSize);



void printPolyDouble(const Poly* poly);

void printPolyInt(const Poly* poly);



void setTerm (Poly* poly, int degree, const void* coefficient);



Poly sum (const Poly* poly1, const Poly* pol2);



Poly mulPolyScalar (const Poly* poly1, const Poly* pol2);



Poly mulPolyPoly (const Poly* poly1, const Poly* pol2);



double compute (const Poly* poly, double x);



Poly composition (const Poly* poly1, const Poly* pol2);