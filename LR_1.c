#include <stdio.h>
#include <stdlib.h>



typedef struct Term {
  double multiplier;
  double degree;
} Term;



typedef struct Polynomial {
  Term* objects;
  int size;
} Poly;



void printTerm (Term * term) {
  if (term->multiplier == 0) {
    printf("0");
  } else {
    printf("(%.1f * x^%.1f)",term->multiplier, term->degree);
  }
}



void printPoly (Poly * poly) {
  if (poly->size == 0) {
    printf("0");
  } else {
    for (int i = 0; i < poly->size; i++) {
      printTerm(&poly->objects[i]);

      if (i < (poly->size - 1))
        printf(" + ");
    }
  }
}



Term enterTerm() {
  Term term;
  printf("\tWrite Degree: ");
  scanf("%lf", &term.degree);
  printf("\n\tWrite Multiplier: ");
  scanf("%lf", &term.multiplier);
  printf("\n");
  return term;
}



Poly sum_Poly_Term (const Poly* poly, const Term* term) {
  // if term = 0
  if (term->multiplier == 0)
    return *poly;

  Poly answer;
  // set size1 = (size0 + 1) with a margin
  answer.size = poly->size + 1;
  answer.objects = (Term*) malloc (sizeof(Term) * answer.size);

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



Poly sum_Poly_Poly (const Poly* poly1, const Poly* poly2) {
  if (poly2->size == 0)
    return *poly1;
  else if (poly1->size == 0)
    return *poly2;

  Poly answer;
  // set size with a margin
  answer.size = poly1->size + poly2->size;
  answer.objects = (Term*) malloc (sizeof(Term) * answer.size);

  int actualAnswerSize;

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

  Term helpTerm;

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



#define sum(X, Y) _Generic((X),\
    Poly*:   _Generic((Y),\
        Poly*: sum_Poly_Poly,\
        Term*: sum_Poly_Term\
    )\
)(X, Y)




/* Tests for sum poly term
int main (void) {
  Term ourTerm;

  Poly poly1;

  poly1.size = 0;

  for (int i = 0; i < 10; i++) {
    printf("Write term %d:\n", i);
    ourTerm = enterTerm();

    poly1 = sum (&poly1, &ourTerm);
    printf("Sum:\n");
    printPoly (&poly1);
  }

  return 0;
}
*/


// Tests for sum poly poly
int main (void) {
  Term ourTerm;

  Poly poly1, poly2;

  poly1.size = 0;
  poly2.size = 0;

  for (int i = 0; i < 1; i++) {
    printf("Write term %d:\n", (i+1));
    ourTerm = enterTerm();

    poly1 = sum (&poly1, &ourTerm);
  }

  printf("Poly1:\n\t");
  printPoly (&poly1);
  printf("\n");

  for (int i = 0; i < 1; i++) {
    printf("Write term %d:\n", (i+1));
    ourTerm = enterTerm();

    poly2 = sum (&poly2, &ourTerm);
  }

  printf("Poly1:\n\t");
  printPoly (&poly2);
  printf("\n");

  printf("sum:\n\t");
  poly1 = sum (&poly1, &poly2);
  printPoly (&poly1);
  printf("\n");

  return 0;
}

/*
int main (void) {
  Term ourTerm;

  Poly poly1, poly2;

  poly1.size = 0;
  poly2.size = 0;

  return 0;
}
*/