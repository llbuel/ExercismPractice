#include "trinary.h"

namespace trinary {

int power(int base, int exponent) {
    int value{ base };

    if (exponent == 0) {
        value = 1;
    }
    else if (exponent == 1) {
        return value;
    }
    else if (exponent > 1) {    
        for (int i = 0; i < (exponent-1); ++i) {
            value *= base;
        }
    }

    return value;
}

int to_decimal(std::string numStr) {
    int offset = '0';
    int digit{ 0 };
    int numInt{ 0 };
    int base{ 3 };
    int exponent{ 0 };
    
    for (size_t i = numStr.length()-1; (i+1) > 0; --i) {
        if (numStr[i] > '9' || numStr[i] < '0') {
            numInt = 0;
            break;
        }
        else {
            digit = numStr[i] - offset;
            exponent = (numStr.length()-1) - i;

            numInt += digit * power(base, exponent);
        }
    }

    return numInt;
}

}