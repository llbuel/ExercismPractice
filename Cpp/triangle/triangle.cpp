#include "triangle.h"

namespace triangle {

const int flavor::equilateral = 0;
const int flavor::isosceles = 1;
const int flavor::scalene = 2;

int kind(double side1, double side2, double side3){
    flavor flavor;
    
    if ((side1 > 0) && (side2 > 0) && (side3 > 0) && (side1+side2>side3) && (side2+side3>side1) && (side3+side1>side2)){
        if (side1 == side2){
            if (side1 == side3){
                return flavor.equilateral;
            } else {
                return flavor.isosceles;
            }
        } else {
            if (side2 == side3){
                return flavor.isosceles;
            } else {
                if (side1 == side3){
                    return flavor.isosceles;
                } else {
                    return flavor.scalene;
                }
            }
        }
    } else {
        std::string errorMessage = std::string("Domain Error -- Triangle not possible");

        throw std::domain_error(errorMessage);
    }
}

}