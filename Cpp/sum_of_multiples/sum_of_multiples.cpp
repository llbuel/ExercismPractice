#include "sum_of_multiples.h"

namespace sum_of_multiples {

int to(std::vector<int> bases, int limit) {
    std::vector<int> multiples{ getMultiples(bases, limit) };
    int sum{ 0 };

    for (std::size_t i = 0; i < multiples.size(); i++) {
        sum += multiples[i];
    }

    return sum;
}

std::vector<int> getMultiples(std::vector<int> bases, int limit) {
    std::vector<int> multiples;

    for (std::size_t i = 0; i < bases.size(); i++) {
        int j{ 0 };
        int mult{ bases[i] };
        
        while (mult < limit) {
            if (std::find(multiples.begin(), multiples.end(), mult) == multiples.end()) {
                multiples.push_back(mult);
            }

            mult = bases[i] * (j + 2);
            j++;
        }
    }

    return multiples;
}

}