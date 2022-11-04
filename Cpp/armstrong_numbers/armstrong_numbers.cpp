#include "armstrong_numbers.h"

namespace armstrong_numbers {

std::vector<int> getDigits(int inputNumber) {
    std::vector<int> digits;

    while (inputNumber > 0) {
        digits.insert(digits.begin(),(inputNumber%10));
        inputNumber /= 10;
    }

    return digits;
}

int power(int base, int exponent) {
    if (base > 0 && exponent > 0) {
        int result{ base };

        for (int i = 1; i < exponent; ++i) {
            result *= base;
        }

        return result;
    }
    else if (base > 0 && exponent == 0) {
        return 1;
    }

    return 0;
}

bool is_armstrong_number(int testNumber) {
    std::vector<int> digits{ getDigits(testNumber) };
    std::size_t digitCount{ digits.size() };
    int armSum{ 0 };

    for (std::size_t i = 0; i < digitCount; ++i) {
        armSum += power(digits[i], digitCount);
    }

    return (testNumber == armSum);
}

}