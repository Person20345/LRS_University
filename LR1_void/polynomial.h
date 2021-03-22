#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct Polynomial {
	void** multipliers;
	uint32_t size;
	uint8_t dataSize;

	void (*print) (const void*);
	int (*сompareWithZero) (const void*);
	void* (*initNull) ();

	void* (*sum) (const void*, const void*);
	void* (*mul) (const void*, const void*);

	struct Polynomial (*init) (uint32_t);

} Poly;

#endif