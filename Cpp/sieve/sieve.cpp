#include "sieve.h"

namespace sieve {

std::vector<int> primes(int N) {
    std::vector<int> prime_vec;
    std::vector<bool> sift((N - 1), true);

    if (N >= 2) {
        for (int i = 2; i * i <= N; ++i) {
            if (sift[i-2]) {
                for (int j = 0; (i * i) + (j * i) <= N; ++j) {
                    int k = (i * i) + (j * i);
                    
                    sift[k-2] = false;
                }
            }
        }
    }

    for (std::size_t itr = 0; itr != sift.size(); itr++) {
        if (sift[itr]) {
            prime_vec.push_back(itr+2);
        }
    }

    return prime_vec;
}

}