#include "grains.h"

namespace grains {

long long unsigned int square(long long unsigned int squareNum)
{
    if (squareNum >= 1){
        return std::pow(2, (squareNum - 1));
    } else {
        return 0;
    }
}

long long unsigned int total(){
    long long unsigned int totalGrains{0};
    
    for (int i = 0; i < 64; i++){
        totalGrains = totalGrains + square(i+1);
    }

    return totalGrains;
}

}