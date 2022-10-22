#include "phone_number.h"

namespace phone_number {

std::string phone_number::parseNumber(std::string input) {
    bool isAreaCode{ false };
    int areaCodeCount{ 3 };

    for (std::size_t i = 0; i < input.length(); ++i) {
        if (i == 0 && input[i] == '(') {
            isAreaCode = true;
            input.erase(i,1);
            i--;
        }
        else if (input[i] > '9' || input[i] < '0') {
            input.erase(i,1);
            i--;
        }
        else {
            if (isAreaCode && areaCodeCount > 0) {
                areaCode_.push_back(input[i]);
                areaCodeCount--;
            }
            else if (isAreaCode && areaCodeCount == 0) {
                isAreaCode = false;
            }
        }
    }

    if (input.length() == 11 && input[0] != '1') {
        throw std::domain_error("\nNot a valid phone number.\n");
    }
    else if (input.length() == 11) {
        input.erase(0,1);

        if (areaCode_.empty()) {
            areaCode_ = input.substr(0,3);

            if (areaCode_[0] == '0' || areaCode_[0] == '1') {
                throw std::domain_error("\nNot a valid area code.\n");
            }
        }

        if (input[3] == '0' || input[3] == '1') {
            throw std::domain_error("\nNot a valid phone number.\n");
        }
    }
    else if (input.length() != 10) {
        throw std::domain_error("\nNot a valid phone number.\n");
    }
    else if (areaCode_.empty()) {
        areaCode_ = input.substr(0,3);

        if (areaCode_[0] == '0' || areaCode_[0] == '1') {
            throw std::domain_error("\nNot a valid area code.\n");
        }
    }
    else if (input[3] == '0' || input[3] == '1') {
        throw std::domain_error("\nNot a valid phone number.\n");
    }
    else if (areaCode_[0] == '0' || areaCode_[0] == '1') {
        throw std::domain_error("\nNot a valid area code.\n");
    }

    return input;
}

void phone_number::setFormattedNumber(std::string input) const {
    formattedNumber_ = input;
}

phone_number::phone_number (std::string numberStr) : numberStr_(numberStr) {
    std::string newStr{ parseNumber(numberStr) };
    number_ = newStr;
}

phone_number::operator std::string() const {
    std::string number{ number_ };

    for (std::size_t i = 0; i < number.length(); ++i) {
        switch (i) {
            case 0:
                number.insert(i, "(");
                break;
            case 4:
                number.insert(i, ") ");
                i += 1;
                break;
            case 9:
                number.insert(i, "-");
                break;
        }
    }
    
    setFormattedNumber(number);
    
    return formattedNumber_;
}

}