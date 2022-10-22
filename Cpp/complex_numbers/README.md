# Complex Numbers

A complex number is a number in the form "A+iB" where A and B are real and i satisfies i^(2) = -1.

"A" is called the real part and "B" is called the imaginary part of Z. The conjugate of the number A+iB is the number A-iB. The absolute value of a complex number is a real number |Z| = sqrt(A\^2 + B\^2). The square of the absolute value |Z|\^2 is the result of multiplication of Z by its complex conjugate.

The sum/difference of two complex numbers involves adding/subtracting their real and imaginary parts separately: (A+iB) + (C+iD) = (A+C) + i(B+D) and (A+iB) - (C+iD) = (A-C) + i(B-D).

Multiplication result is by definition (A+iB) \* (C+iD) = (AC - BD) + i(BC + AD).

The reciprocal of a non-zero complex number is 1 / (A+iB) = A/(A^2 + B^2) - iB/(A^2 + B^2).

Dividing a complex number A+iB by another C+iD gives: (A+iB) / (C+iD) = (AC + BD)/(C^2 + D^2) + i(BC - AD)/(C^2 + D^2).

Raising ***e*** to a complex exponent can be expressed as **e**^(A+iB) = **e**^A \* **e**^(iB), the last term of which is given by Euler's formula e^(iB) = cos(B) + i sin(B).

Implement the following operations:

addition, subtraction, multiplication and division of two complex numbers,
conjugate, absolute value, exponent of a given complex number.
Assume the programming language you are using does not have an implementation of complex numbers.

## Example

```cpp
Complex c1(1.0, 2.0)
Complex c2(1.0, 2.0)
c1 + c2 == Complex(2.0, 4.0)
c1 * c2 == Complex(-3.0, 4.0)
```

## License
[MIT](https://choosealicense.com/licenses/mit/)
