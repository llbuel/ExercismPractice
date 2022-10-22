#include "difference_of_squares.h"

namespace difference_of_squares {

int square_of_sum(int num) {
    return (((num * num) * ((num + 1) * (num + 1))) / 4);
}

int sum_of_squares(int num) {
    return ((num * (num + 1) * ((2 * num) + 1)) / 6);
}

int difference(int num) {
    return (square_of_sum(num) - sum_of_squares(num));
}

}