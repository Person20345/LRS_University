#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// just printing without "\n" in the end
// print without 0-elements
void printPoly (const Poly* poly);



// print with 0-elements
void printFullPoly (const Poly* poly);



// add new pair (multiplier * x^degree)
Poly addTerm (const Poly* poly, const void* multiplier, uint32_t degree);



Poly sumPoly (const Poly* poly1, const Poly* poly2);



Poly mulPoly (const Poly* poly1, const Poly* poly2);



Poly mulPolyScalar (const Poly* poly, const void* scalar);



void* сalculatePoly (const Poly * poly, const void* variable);



// set poly2 in poly1
Poly compositionPoly (const Poly* poly1, const Poly* poly2);

#endif