#include "plib.h"



Term setTerm (void) {
  Term term = {0, 0};
  return term;
}




Poly setPoly (void) {
  Poly poly = {0, 0};
  return poly;
}



void printTerm (Term* term) {
  if (term->multiplier == 0) {
    printf("0");
  } else {
    printf("(%.1f * x^%.1f)",term->multiplier, term->degree);
  }
}



void printPoly (Poly* poly) {
  if (poly->size == 0)
    printf("0");
  else
    for (int i = 0; i < poly->size; i++) {
      printTerm(&poly->objects[i]);

      if (i < (poly->size - 1))
        printf(" + ");
    }
}



Term enterTerm(void) {
  Term term = setTerm();
  printf("\tWrite Degree: ");
  scanf("%lf", &term.degree);
  printf("\n\tWrite Multiplier: ");
  scanf("%lf", &term.multiplier);
  printf("\n");
  return term;
}



// O(n)
double computeDegree_Double_Int (double x, int degree) {
  double ret = 1;
  if (degree > 0)
    for (int i = 0; i < degree; i++)
      ret = ret * x;
  else 
    for (int i = 0; i < degree; i++)
      ret = ret / x;
  return ret;
}



// O(n^3)?
Poly computeDegree_Poly_Int (const Poly* poly, unsigned int degree) {
  Poly ret = *poly;

  for (int i = 0; i < (degree - 1); i++)
    ret = mul_Poly_Poly (&ret, poly);

  return ret;
}



// O(n)
Poly sum_Poly_Term (const Poly* poly, const Term* term) {
  // if term = 0

  Poly answer = setPoly();

  if (term->multiplier == 0) {
    answer.size = poly->size;
    answer.objects = (Term*) malloc (sizeof(Term) * answer.size);

    for (int i = 0; i < poly->size; i++)
      answer.objects[i] = poly->objects[i];

    return answer;
  } else {
    // set size1 = (size0 + 1) with a margin
    answer.size = poly->size + 1;
    answer.objects = (Term*) malloc (sizeof(Term) * answer.size);
  }


  // find = 0 => not found,
  // find = 1 => found place + drop in old cell & multiplier of this cell = 0
  // find = 2 => found place + drop in old cell,
  // find = 3 => found place + drop in new cell,
  int find = 0;

  for (int i = 0; i < poly->size; i++) {
    if (find == 0) {
      if (poly->objects[i].degree == term->degree) {
        answer.objects[i] = poly->objects[i];
        answer.objects[i].multiplier += term->multiplier;
        
        if (answer.objects[i].multiplier == 0) {
          find = 1;
          // use size2 = (size1 - 2) becouse one of term  = 0, we reduce it
          answer.size = answer.size - 2;
          answer.objects = (Term*) realloc (answer.objects,
                                            sizeof(Term) * answer.size);

        } else {
          find = 2;
          // use size2 = (size1 - 1) becouse number of terms preserved
          answer.size = answer.size - 1;
          answer.objects = (Term*) realloc (answer.objects,
                                            sizeof(Term) * answer.size);
        }

      } else if (poly->objects[i].degree > term->degree) {
        find = 3;
        // do not change size becouse we had not this degree in our
        // polynomial, we must add new terms in it
        answer.objects[i] = (Term) *term;

      } else if (poly->objects[i].degree < term->degree) {
        answer.objects[i] = poly->objects[i];
      }
    } else if (find == 1) {
        answer.objects[i - 1] = poly->objects[i];
    } else if (find == 2) {
        answer.objects[i] = poly->objects[i];
    } else if (find == 3) {
        answer.objects[i] = poly->objects[i - 1];
    }
  }

  // if all degrees less than term's
  if (find == 0) {
    // do not change size becouse we had not this degree in our
    // polynomial, we must add new terms in it
    answer.objects[answer.size - 1] = (Term) *term;
  } else if (find == 3) {
    answer.objects[answer.size - 1] = poly->objects[poly->size - 1];
  }

  return answer;
}



// O(n)
Poly sum_Poly_Poly (const Poly* poly1, const Poly* poly2) {
  Poly answer = setPoly();
  answer.size = poly1->size + poly2->size;
  answer.objects = (Term*) malloc (sizeof(Term) * answer.size);

  if (poly2->size == 0) {
    answer.size = poly1->size;
    answer.objects = (Term*) malloc (sizeof(Term) * answer.size);

    for (int i = 0; i < poly1->size; i++)
      answer.objects[i] = poly1->objects[i];

    return answer;
  } else if (poly1->size == 0) {
    answer.size = poly2->size;
    answer.objects = (Term*) malloc (sizeof(Term) * answer.size);

    for (int i = 0; i < poly2->size; i++)
      answer.objects[i] = poly2->objects[i];

    return answer;
  } else {
    // set size with a margin
    answer.size = poly1->size + poly2->size;
    answer.objects = (Term*) malloc (sizeof(Term) * answer.size);
  }

  int posAnswer = 0, posPoly1 = 0, posPoly2 = 0;

  // set first answer Term, to do not check every time in cycle
  // Polynomial structure contains only sorted Terms 
  // and we use firstly the smallest Term
  if (poly1->objects[posPoly1].degree < poly2->objects[posPoly2].degree) {
    answer.objects[posAnswer] = poly1->objects[posPoly1];
    posPoly1++;
  } else {
    answer.objects[posAnswer] = poly2->objects[posPoly2];
    posPoly2++;
  }
  posAnswer++;

  Term helpTerm = setTerm();

  // status = 0 => do not added
  // status = 1 => added
  int status = 0;

  while (status == 0) {
    // set our helpTerm
    if (posPoly1 < poly1->size && posPoly2 < poly2->size) {
      // if we have terms in poly1 and poly2
      if (poly1->objects[posPoly1].degree <= poly2->objects[posPoly2].degree) {
        helpTerm = poly1->objects[posPoly1];
        posPoly1++;
      } else {
        helpTerm = poly2->objects[posPoly2];
        posPoly2++;
      }
    } else if (posPoly1 == poly1->size && posPoly2 == poly2->size) {
      status = 1;
      answer.size = posAnswer;
      answer.objects = (Term*) realloc (answer.objects,
                                        sizeof(Term) * answer.size);
    } else {
      if (posPoly1 == poly1->size) {
        helpTerm = poly2->objects[posPoly2];
        posPoly2++;
      } else if (posPoly2 == poly2->size) {
        helpTerm = poly1->objects[posPoly1];
        posPoly1++;
      }
    }

    // calculate helpTerm in answer
    if (status != 1) {
      if (answer.objects[posAnswer - 1].degree == helpTerm.degree) {
        answer.objects[posAnswer - 1].multiplier += helpTerm.multiplier;

        // if previous and new Terms decreased
        if (answer.objects[posAnswer - 1].multiplier == 0)
          posAnswer--;

      } else {
        answer.objects[posAnswer] = helpTerm;
        posAnswer++;
      }
    }
  }

  return answer;
}



// O(n^2)
Poly sortPoly(const Poly* poly) {
  if (poly->size == 0)
    return *poly;

  Poly answer = setPoly();

  // bubble sort
  for (int i = 0; i < poly->size; i++)
    answer = sum_Poly_Term(&answer, &poly->objects[i]);

  return answer;
}



// O(n)
Poly mul_Poly_Scalar (const Poly* poly, double number) {
  Term term = {number, 0};

  // Term k * x^0 = k
  Poly answer = mul_Poly_Term (poly, &term);

  return answer;
}



// O(n)
Poly mul_Poly_Term (const Poly* poly, const Term* term) {
  Poly answer = setPoly();

  if (term->multiplier == 0) {
    answer.size = 0;
  } else {
    answer.size = poly->size;
    answer.objects = (Term*) malloc (sizeof(Term) * answer.size);
  }

  for (int i = 0; i < poly->size; i++) {
    answer.objects[i].multiplier = poly->objects[i].multiplier*term->multiplier;
    answer.objects[i].degree = poly->objects[i].degree + term->degree;
  }

  return answer;
}



// O(n^2)
Poly mul_Poly_Poly (const Poly* poly1, const Poly* poly2) {
  Poly answer = setPoly();
  Poly mul;
  Term* freeObjects;

  // why I can't free(mul)?
  for (int i = 0; i < poly1->size; i++) {
    mul = mul_Poly_Term(poly2, &poly1->objects[i]);
    freeObjects = answer.objects;
    answer = sum_Poly_Poly(&mul, &answer);
    free(mul.objects);
    free(freeObjects);
  }

  return answer;
}



// O(n)
double compute (const Poly* poly, double x) {
  double ret = 0;

  for (int i = 0; i < poly->size; i++)
    ret += poly->objects[i].multiplier * computeDegree_Double_Int(x,
                                                       poly->objects[i].degree);

  return ret;
}



// O(n^2)?
Poly composition (const Poly* poly1, const Poly* poly2) {
  Poly answer = setPoly();
  Poly polyValue;

  for (int i = 0; i < poly1->size; i++) {
    polyValue = computeDegree_Poly_Int (poly2, 
                                    (unsigned int) poly1->objects[i].degree);
    polyValue = mul_Poly_Scalar (&polyValue, poly1->objects[i].multiplier);
    answer = sum_Poly_Poly (&answer, &polyValue);
  }

  return answer;
}