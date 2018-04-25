#ifndef COMPLEX_H_
#define COMPLEX_H_

typedef struct {
    double real;
    double imag;
} Complex;

std::string complex_to_string(Complex);

Complex create_complex(double r, double i);

double module_complex(Complex);

Complex add_complex(Complex, Complex);
Complex substract_complex(Complex, Complex);

Complex mult_complex(Complex, Complex);
Complex mult_complex_by_number(Complex, double);

Complex divide_complex_by_number(Complex, double);
Complex divide_complex(Complex, Complex);

#endif /* COMPLEX_H_ */
