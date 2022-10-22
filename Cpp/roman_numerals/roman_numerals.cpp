#include "roman_numerals.h"

namespace roman_numerals {

std::string convert(int decimal) {
    std::string roman;
    while (decimal > 0) {
        if (decimal >= 1000) {
            roman += "M";
            decimal -= 1000;
        }
        else if (decimal >= 900 && decimal < 1000) {
            while (decimal >= 900) {
                roman += "C";
                decimal -= 100;
            }

            roman += "M";
            decimal -= 800;
        }
        else if (decimal >= 500) {
            roman += "D";
            decimal -= 500;
        }
        else if (decimal >= 400 && decimal < 500) {
            while (decimal >= 400) {
                roman += "C";
                decimal -= 100;
            }

            roman += "D";
            decimal -= 300;
        }
        else if (decimal >= 100) {
            roman += "C";
            decimal -= 100;
        }
        else if (decimal >= 90 && decimal < 100) {
            while (decimal >= 90) {
                roman += "X";
                decimal -= 10;
            }

            roman += "C";
            decimal -= 80;
        }
        else if (decimal >= 50) {
            roman += "L";
            decimal -= 50;
        }
        else if (decimal >= 40 && decimal < 50) {
            while (decimal >= 40) {
                roman += "X";
                decimal -= 10;
            }

            roman += "L";
            decimal -= 30;
        }
        else if (decimal >= 10) {
            roman += "X";
            decimal -= 10;
        }
        else if (decimal >= 9 && decimal < 10) {
            while (decimal == 9) {
                roman += "I";
                decimal -= 1;
            }

            roman += "X";
            decimal -= 5;

            break;
        }
        else if (decimal >= 5 && decimal < 9) {
            roman += "V";

            if (decimal == 5) {
                break;
            }

            decimal -= 1;
            
            while (decimal > 4) {
                roman += "I";
                decimal -= 1;
            }

            break;
        }
        else if (decimal >= 4 && decimal < 5) {
            while (decimal == 4) {
                roman += "I";
                decimal -= 1;
            }

            roman += "V";
            decimal -= 1;

            break;
        }
        else {
            roman += "I";
            decimal -= 1;
        }
    }

    return roman;
}

}