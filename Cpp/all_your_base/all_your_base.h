#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <vector>
#include <stdexcept>

namespace all_your_base {

unsigned int exp(unsigned int inputBase, unsigned int inputExponent);
std::vector<unsigned int> convert(unsigned int inputBase, std::vector<unsigned int>& inputDigits, unsigned int outputBase);

}

#endif