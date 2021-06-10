#include "complex.h"



Complex Complex::operator + (Complex number) {
	Complex ret;

	ret.Re = this->Re + number.Re;
	ret.Im = this->Im + number.Im;

	return ret;
}



Complex Complex::operator - (Complex number) {
	Complex ret;

	ret.Re = this->Re - number.Re;
	ret.Im = this->Im - number.Im;

	return ret;
}



Complex Complex::operator * (Complex number) {
	Complex ret;

	ret.Re = (this->Re * number.Re) - (this->Im * number.Im);
	ret.Im = (this->Re * number.Im) + (number.Re * this->Im);

	return ret;
}



Complex Complex::operator * (double number) {
	Complex ret;

	ret.Re = ret.Re * number;
	ret.Im = ret.Im * number;

	return ret;
}



Complex Complex::operator * (int number) {
	Complex ret;

	ret.Re = ret.Re * number;
	ret.Im = ret.Im * number;

	return ret;
}



Complex Complex::operator / (Complex number) {
	Complex ret;

	ret.Re = ((this->Re * number.Re) + (this->Im * number.Im)) /
	         ((number.Re * number.Re) + (number.Im * number.Im));
	ret.Im = ((this->Im * number.Re) - (this->Re * number.Im)) /
	         ((number.Re * number.Re) + (number.Im * number.Im));

	return ret;
}



void Complex::operator = (Complex number) {
	this->Re = number.Re;
	this->Im = number.Im;
}



void Complex::operator = (double number) {
	this->Re = number;
	this->Im = 0;
}



void Complex::operator = (int number) {
	this->Re = (double)number;
	this->Im = 0;
}



void Complex::operator *= (Complex number) {
	this->Re = (this->Re * number.Re) - (this->Im * number.Im);
	this->Im = (this->Re * number.Im) + (number.Re * this->Im);
}



void Complex::operator /= (Complex number) {
	this->Re = ((this->Re * number.Re) + (this->Im * number.Im)) /
	           ((number.Re * number.Re) + (number.Im * number.Im));
	this->Im = ((this->Im * number.Re) - (this->Re * number.Im)) /
	           ((number.Re * number.Re) + (number.Im * number.Im));
}



void Complex::operator += (Complex number) {
	this->Im = this->Im + number.Im;
	this->Re = this->Re + number.Re;
}



void Complex::operator -= (Complex number) {
	this->Im = this->Im - number.Im;
	this->Re = this->Re - number.Re;
}



bool Complex::operator == (Complex number) {
	return (this->Re == number.Re && this->Im == number.Im);
}



bool Complex::operator != (Complex number) {
	return (this->Re != number.Re || this->Im != number.Im);
}



bool Complex::operator > (Complex number) {
	return (this->Re > number.Re);
}



bool Complex::operator < (Complex number) {
	return (this->Re < number.Re);
}



bool Complex::operator >= (Complex number) {
	return (this->Re >= number.Re);
}



bool Complex::operator <= (Complex number) {
	return (this->Re <= number.Re);
}



Complex sqrt(Complex number) {
	Complex ret;

	double sqrt_z = sqrt(sqrt((number.Im * number.Im) + (number.Re * number.Re)));

	ret.Re = sqrt_z * cos(atan(number.Im/number.Re));
	ret.Im = sqrt_z * sin(atan(number.Im/number.Re));

	return ret;
}



Complex pow(Complex number, double pow_) {
	Complex ret;

	double sqrt_z = pow((double)sqrt((number.Im * number.Im) + (number.Re * number.Re)), pow_);

	ret.Re = sqrt_z * cos(atan(number.Im/number.Re) * pow_);
	ret.Im = sqrt_z * sin(atan(number.Im/number.Re) * pow_);

	return ret;
}