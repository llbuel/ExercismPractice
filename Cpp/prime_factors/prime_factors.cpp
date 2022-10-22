#include "prime_factors.h"

namespace prime_factors {

std::vector<int> of(int input) {
    std::vector<int> factors;

    while (input % 2 == 0) {
        factors.push_back(2);
        input /= 2;
    }

    int i = 3;
    while (i * i <= input) {
        if (input % i == 0) {
            factors.push_back(i);
            input /= i;
        }
        else {
            i += 2;
        }
    }

    if (input != 1) {
        factors.push_back(input);
    }

    return factors;
}

}