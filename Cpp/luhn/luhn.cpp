#include "luhn.h"

namespace luhn {

std::string cleanString(const std::string& inputString) {
    std::string outputString{ inputString };
    std::size_t itr{ outputString.find(' ') };

    while (itr != std::string::npos) {
        outputString.erase(itr,1);
        itr = outputString.find(' ');
    }

    return outputString;
}

bool isNumeric(char inputChar) {
    return ((inputChar - '0' >= 0) && (inputChar - '0' <= 9));
}

bool valid(const std::string& inputString) {
    std::string testString{ cleanString(inputString) };
    int digit{ 0 };
    int checksum{ 0 };
    
    if (testString.size() > 1) {
        for (std::size_t i = 0; i < testString.size(); ++i) {
            if (isNumeric(testString[i]) && ((testString.size()-i) % 2 == 0)) {
                if (((testString[i] - '0') * 2) > 9) {
                    digit = ((testString[i] - '0') * 2) - 9;
                }
                else {
                    digit = (testString[i] - '0') * 2;
                }
            }
            else if (isNumeric(testString[i])) {
                digit = testString[i] - '0';
            }
            else {
                return false;
            }

            checksum += digit;
        }

        if (checksum % 10 == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

}