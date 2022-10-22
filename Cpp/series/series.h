#ifndef SERIES_H
#define SERIES_H

#include <string>
#include <vector>
#include <stdexcept>

namespace series {

std::vector<int> digits(std::string numberStr);
std::vector<std::vector<int>> slice(std::string numberStr, std::size_t sliceLength);

}

#endif