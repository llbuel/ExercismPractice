#include "complex_numbers.h"

namespace complex_numbers {

Complex Complex::conj() const {
    Complex conjugate;

    conjugate.real_ = real_;
    conjugate.imag_ = (-1) * imag_;

    return conjugate;
}

Complex Complex::exp() const {
    Complex exponential;
    float coeff{ std::exp(real_) };

    exponential.real_ = coeff * cos(imag_);
    exponential.imag_ = coeff * sin(imag_);

    return exponential;
}

Complex Complex::operator * (const Complex& rhs) const {
    Complex result;

    result.real_ = (real_ * rhs.real_) - (imag_ * rhs.imag_);
    result.imag_ = (imag_ * rhs.real_) + (real_ * rhs.imag_);

    return result;
}

Complex Complex::operator / (const Complex& rhs) const {
    if ((rhs.real_ != 0) || (rhs.imag_ != 0)) {
        Complex result;

        result.real_ = ((real_ * rhs.real_) + (imag_ * rhs.imag_)) / ((rhs.real_ * rhs.real_) + (rhs.imag_ * rhs.imag_));
        result.imag_ = ((imag_ * rhs.real_) - (real_ * rhs.imag_)) / ((rhs.real_ * rhs.real_) + (rhs.imag_ * rhs.imag_));

        return result;
    }
    else {
        throw std::domain_error("\nDivision by zero is undefined.\n");
    }
}

Complex Complex::operator + (const Complex& rhs) const {
    Complex result;

    result.real_ = real_ + rhs.real_;
    result.imag_ = imag_ + rhs.imag_;

    return result;
}

Complex Complex::operator - (const Complex& rhs) const {
    Complex result;

    result.real_ = real_ - rhs.real_;
    result.imag_ = imag_ - rhs.imag_;

    return result;
}

}