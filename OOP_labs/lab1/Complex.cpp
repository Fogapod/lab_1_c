#include <iostream>
#include <math.h>
#include "Complex.h"


std::string complex_to_string(Complex c){
	return "[" + std::to_string(c.real) + " + i" + ((c.imag < 0)? "(" + std::to_string(c.imag) + ")": std::to_string(c.imag)) + "]";
}

Complex create_complex(double r, double i){
	Complex c;
	c.real = r;
	c.imag = i;

	return c;
}

double module_complex(Complex c){
    return sqrt(c.real * c.real + c.imag * c.imag);
}

Complex add_complex(Complex c1, Complex c2){
	Complex c3;
	c3.real = c1.real + c2.real;
	c3.imag = c1.imag + c2.imag;

	return c3;
}

Complex substract_complex(Complex c1, Complex c2){
	Complex c3;
	c3.real = c1.real - c2.real;
	c3.imag = c1.imag - c2.imag;

	return c3;
}

Complex mult_complex(Complex c1, Complex c2){
	Complex c3;
	c3.real = c1.real * c2.real - c1.imag * c2.imag;
	c3.imag = c1.imag * c2.real + c2.imag * c1.real;

	return c3;
}

Complex mult_complex_by_number(Complex c1, double n){
	Complex c;
	c.real = c1.real * n;
	c.imag = c1.imag * n;

	return c;
}

Complex divide_complex_by_number(Complex c1, double n){
	Complex c;
	c.real = c1.real / n;
	c.imag = c1.imag / n;

	return c;
}

Complex divide_complex(Complex c1, Complex c2){
	Complex c3;

	double num = c2.real * c2.real + c2.imag * c2.imag;

	c3.real = c1.real * c2.real + c1.imag * c2.imag;
	c3.imag = c1.imag * c2.real - c2.imag * c1.real;

	
    return divide_complex_by_number(c3, num);
}
