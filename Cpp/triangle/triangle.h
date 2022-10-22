#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include <stdexcept>

namespace triangle {

int kind(double side1, double side2, double side3);

class flavor {
public:
    static const int equilateral;
    static const int isosceles;
    static const int scalene;
    
};

}

#endif