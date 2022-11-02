#include "all_your_base.h"

namespace all_your_base {

unsigned int exp(unsigned int inputBase, unsigned int inputExponent) {
    unsigned int output{ 1 };
    
    if (inputExponent == 0) {
        return output; 
    }
    else if (inputBase == 0) {
        output = 0;
        return output;
    }
    else {
        unsigned int itr{ inputExponent };

        while (itr > 0) {
            output *= inputBase;
            itr--;
        }
    }

    return output;
}

std::vector<unsigned int> convert(unsigned int inputBase, std::vector<unsigned int>& inputDigits, unsigned int outputBase) {
    if (inputBase != 0 && inputBase != 1 && outputBase != 0 && outputBase != 1) {
        unsigned int j{ 0 };
        unsigned int decimal{ 0 };
        std::vector<unsigned int> output;

        for (std::size_t i = inputDigits.size(); i > 0; --i) {
            if (inputBase - (inputDigits[i-1]) > 0) {
                decimal += inputDigits[i-1] * exp(inputBase, j);
                j++;
            }
            else {
                throw std::invalid_argument("\n"+std::to_string(inputDigits[i-1])+" is an invalid digit in base "+std::to_string(inputBase)+".\n");
            }
        }

        while (decimal > 0) {
            output.insert(output.begin(), (decimal % outputBase));

            if (decimal/outputBase == 0 && ((decimal/outputBase) % outputBase) != 0) {
                output.insert(output.begin(), ((decimal/outputBase) % outputBase));
            }

            decimal /= outputBase;
        }

        return output;
    }
    else {
        throw std::invalid_argument("\nBases must be greater than 1.\n");
    }
}

}