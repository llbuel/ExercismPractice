#ifndef SAY_H
#define SAY_H

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

namespace say {

std::string in_english(unsigned long long int number);
std::vector<int> getDigits(unsigned long long int number);

}

#endif
