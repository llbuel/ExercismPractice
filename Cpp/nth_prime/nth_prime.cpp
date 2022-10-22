#include "nth_prime.h"

namespace nth_prime {

int nth(int index) {
    if (index > 0) { 
        int itr{ 1 };
        int prime_test{ 2 };
        
        while (itr <= index) {
            if (isPrime(prime_test)) {
                itr++;
                prime_test++;
            }
            else {
                prime_test++;
            }
        }

        return (prime_test - 1);
    }
    else {
        throw std::domain_error("N must be a positive integer.");
    }
}

bool isPrime(int test) {
    if (test == 2 || test == 3) {
        return true;
    }
    else if (test <= 1 || test % 2 == 0 || test % 3 == 0) {
        return false;
    }
    
    for (int itr = 5; itr * itr <= test; itr += 6) {
        if (test % itr == 0 || test % (itr + 2) == 0) {
            return false;
        }
    }

    return true;
}

}