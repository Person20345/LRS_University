#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
public:
  double Re;
	double Im;

	Complex operator + (Complex number);
  Complex operator - (Complex number);

  Complex operator * (Complex number);
  Complex operator * (double number);
  Complex operator * (int number);
  Complex operator / (Complex number);

  void operator = (Complex number);
  void operator = (double number);
  void operator = (int number);

  void operator *= (Complex number);
  void operator /= (Complex number);

  void operator += (Complex number);
  void operator -= (Complex number);

  bool operator == (Complex number);
  bool operator != (Complex number);

  bool operator > (Complex number);
  bool operator < (Complex number);
  bool operator >= (Complex number);
  bool operator <= (Complex number);
};

Complex sqrt(Complex number);

#endif