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



Poly sum (const Poly* poly, const Term* term) {
  if (term->multiplier != 0) {
    Poly answer;
    answer.size = poly->size + 1;
    answer.objects = (Term*) malloc(sizeof(Term) * answer.size);

    // find = 0 => not found,
    // find = 1 => found place + drop in old cell and multiplier of this cell = 0
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
            // use size2 = (size1 - 2) becouse one of term  = 0, we reduce it,
            // but in start of function we set size1 = (size0 + 1) with a margin
            answer.size = answer.size - 2;
            answer.objects = (Term*) realloc(answer.objects,
                                         sizeof(Term) * answer.size);

          } else {
            find = 2;
            // use size2 = (size1 - 1) becouse number of terms preserved,
            // but in start of function we set size1 = (size0 + 1) with a margin
            answer.size = answer.size - 1;
            answer.objects = (Term*) realloc(answer.objects,
                                         sizeof(Term) * answer.size);
          }

        } else if (poly->objects[i].degree > term->degree) {
          find = 3;
          answer.objects[i] = (Term) *term;
          // do not change size becouse we had not this degree in our
          // polynomial, we must add new terms in it,
          // in start of function we set size1 = (size0 + 1) with a margin

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

    if (find == 0) {
      // if all degrees less than pOne's
      find = 3;
      answer.objects[answer.size - 1] = (Term) *term;
      // do not change size becouse we had not this degree in our
      // polynomial, we must add new terms in it,
      // in start of function we set size1 = (size0 + 1) with a margin
    } else if (find == 3) {
      answer.objects[answer.size - 1] = poly->objects[poly->size - 1];
    }

    return answer;
  } else {
    return *poly;
  }
}



void printPoly (Poly * poly) {
  for (int i = 0; i < poly->size; i++) {
    printf("(%.1f * x^%.1f)",poly->objects[i].multiplier, poly->objects[i].degree);
    if (i < (poly->size - 1))
      printf(" + ");
  }
  printf("\n");
}



int main (void) {
  Term terms[10];

  Poly poly1, poly2;

  poly1.size = 0;
  poly2.size = 0;

  for (int i = 0; i < 10; i++) {
    if (i != 3) {
      terms[i].degree = i;
      terms[i].multiplier = i;

      poly2 = sum (&poly2, &terms[i]);
      printPoly (&poly2);
    }
  }
    
  Term term1 = {4, 5};
    
  poly2 = sum (&poly2, &term1);
  printPoly (&poly2);

  Term term2 = {10, 3};
    
  poly2 = sum (&poly2, &term2);
  printPoly (&poly2);

  return 0;
}


