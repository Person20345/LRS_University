#include "matrix_test.h"


void print(Matrix<int>* m) {
	for (int i = 0; i < m->stringsNum(); i++) {
		if (i == 0)
			printf("/ ");
		else if (i == m->stringsNum() - 1)
			printf("\\ ");
		else
			printf("| ");

		for (int j = 0; j < m->columsNum(); j++)
			if (j != m->columsNum() - 1)
				printf("%-4d", (*(*m)[i])[j]);
			else
				printf("%d", (*(*m)[i])[j]);

		if (i == m->stringsNum() - 1)
			printf(" /\n");
		else if (i == 0)
			printf(" \\\n");
		else
			printf(" |\n");
	}
}



void print(Matrix<double>* m) {
	for (int i = 0; i < m->stringsNum(); i++) {
		if (i == 0)
			printf("/ ");
		else if (i == m->stringsNum() - 1)
			printf("\\ ");
		else
			printf("| ");

		for (int j = 0; j < m->columsNum(); j++)
			if (j != m->columsNum() - 1)
				printf("%-10f", (*(*m)[i])[j]);
			else
				printf("%f", (*(*m)[i])[j]);

		if (i == m->stringsNum() - 1)
			printf(" /\n");
		else if (i == 0)
			printf(" \\\n");
		else
			printf(" |\n");
	}
}



void matrix_test() {
	// test sum
	Matrix<int> m1(DYNAMICARRAY_TYPE, 4, 10);
	Matrix<int> m2(DYNAMICARRAY_TYPE, 4, 10);

	(*m1[1])[4] = -19;
	(*m2[1])[4] = 16;
	print(&m1);
	print(&m2);

	m2 = m1 + m2 + m2;
	print(&m1);

	// test mul
	Matrix<double> m3(DYNAMICARRAY_TYPE, 3, 3);
	Matrix<double> m4(DYNAMICARRAY_TYPE, 3, 3);
	double value;

	(*m3[0])[0] = 1;
	(*m3[0])[1] = 2;
	(*m3[1])[1] = 1;
	(*m3[1])[0] = 0;

	(*m4[0])[0] = 1;
	(*m4[0])[1] = 2;
	(*m4[1])[1] = 3;
	(*m4[1])[0] = 4;

	printf("here");

	print(&m3);
	print(&m4);

	m3 = m3 * m4;

	print(&m3);

	// test strings

	m3.addStr(0, 0);
	print(&m3);
	m3.subtractClm(1, m3.divideClm(0, 4));
	print(&m3);

	(*m3[1])[0] = 0;
	value = m3.norm(2);
	printf("%f\n", value);
}