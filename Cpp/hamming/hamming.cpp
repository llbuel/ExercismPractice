#include "hamming.h"

namespace hamming {

int compute(std::string strand1, std::string strand2) {
    if (strand1.length() != strand2.length()) {
        throw std::domain_error(std::string("DNA strands cannot be compared."));
    } 
    else {
        int result{ 0 };

        for (std::size_t itr = 0, len = strand1.length(); itr != len; itr++) {
            if (strand1[itr] != strand2[itr]) {
                result++;
            }
        }
        
        return result;
    } 
}

}