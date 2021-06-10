#include <stdlib.h>
#include <stdio.h>

int main() {
	int *p = malloc(sizeof(int));
	void * p2 = p + 3;
	int * pi = p2 - 3;

	*p = 5;

	*(int*)p2 = 6;

	printf("%i", *pi);
}