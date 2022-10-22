#include "series.h"

namespace series {

std::vector<int> digits(std::string numberStr) {
    int thisDigit{ 0 };
    std::vector<int> digitVec;
    int offset = '0';

    for (std::size_t i = 0; i < numberStr.length(); ++i) {
        thisDigit = numberStr[i] - offset;
        digitVec.push_back(thisDigit);
    }

    return digitVec;
}

std::vector<std::vector<int>> slice(std::string numberStr, std::size_t sliceLength) {
    std::vector<int> thisVec;
    std::vector<std::vector<int>> sliceVec;

    if (sliceLength > numberStr.length()) {
        throw std::domain_error("\nSlice is not possible.\n");
    }
    
    for (std::size_t i = 0; i < (numberStr.length() - sliceLength + 1); ++i) {
        thisVec = digits(numberStr.substr(i,sliceLength));
        sliceVec.push_back(thisVec);
    }

    return sliceVec;
} 

}