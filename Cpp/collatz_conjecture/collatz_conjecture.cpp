#include "collatz_conjecture.h"

namespace collatz_conjecture {

int steps(int input) {
    if (input > 0) {
        int step_count{ 0 };

        while (input > 1) {
            if (input % 2 == 0) {
                input = input / 2;
            }
            else {
                input = (input * 3) + 1;
            }

            step_count++;
        }

        return step_count;
    }
    else {
        throw std::domain_error("Must be a positive integer.");
    }
}

}