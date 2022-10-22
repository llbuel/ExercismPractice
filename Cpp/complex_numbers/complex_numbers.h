#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBERS_H

#include <cmath>
#include <stdexcept>

namespace complex_numbers {

class Complex {
private:
    float real_;
    float imag_;

public:
    Complex(float real, float imaginary) : real_(real), imag_(imaginary) {}
    Complex() : real_(0), imag_(0) {}

    float real() const { return real_; }
    float imag() const { return imag_; }
    float abs() const { return (std::sqrt((real_ * real_) + (imag_ * imag_))); }
    Complex conj() const;
    Complex exp() const;

    Complex operator * (const Complex& rhs) const;
    Complex operator + (const Complex& rhs) const;
    Complex operator - (const Complex& rhs) const;
    Complex operator / (const Complex& rhs) const;

};

}

#endif