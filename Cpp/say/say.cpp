#include "say.h"

namespace say {

std::string in_english(unsigned long long int number) {
    if (number < 1000000000000) {
        std::vector<int> digits = getDigits(number);
        std::vector<std::string> number_key;
        number_key = {"one",
                      "two",
                      "three",
                      "four",
                      "five",
                      "six",
                      "seven",
                      "eight",
                      "nine"};
        std::string spelledNum;

        bool isTeen{ false };

        for (std::size_t i = (digits.size() - 1); (i + 1) > 0; i--) {
            switch ((i + 1) % 3) {
                case 0:
                    if ((digits[i]) > 0) {
                        if (i != digits.size() - 1) {
                            spelledNum.append(" ");
                        }

                        spelledNum.append(number_key[digits[i] - 1]);
                        spelledNum.append(" hundred");
                    }

                    break;
                case 2:
                    if ((digits[i]) > 0) {
                        if (i != digits.size() - 1) {
                            spelledNum.append(" ");
                        }

                        switch (digits[i]) {
                            case 1:
                                isTeen = true;
                                break;
                            case 2:
                                spelledNum.append("twenty");
                                break;
                            case 3:
                                spelledNum.append("thirty");
                                break;
                            case 4:
                                spelledNum.append("forty");
                                break;
                            case 5:
                                spelledNum.append("fifty");
                                break;
                            case 6:
                                spelledNum.append("sixty");
                                break;
                            case 7:
                                spelledNum.append("seventy");
                                break;
                            case 8:
                                spelledNum.append("eighty");
                                break;
                            case 9:
                                spelledNum.append("ninety");
                                break;
                        }
                    }

                    if ((digits[i] != 1) && (digits[i - 1] != 0) && (digits[i] > 0)) {
                        spelledNum.append("-");
                    }

                    break;
                case 1:
                    if (((digits[i]) > 0) || ((isTeen) && (digits[i] == 0))) {
                        if (isTeen) {
                            switch (digits[i]) {
                                case 0:
                                    spelledNum.append("ten");
                                    break;
                                case 1:
                                    spelledNum.append("eleven");
                                    break;
                                case 2:
                                    spelledNum.append("twelve");
                                    break;
                                case 3:
                                    spelledNum.append("thirteen");
                                    break;
                                case 4:
                                    spelledNum.append("fourteen");
                                    break;
                                case 5:
                                    spelledNum.append("fifteen");
                                    break;
                                case 6:
                                    spelledNum.append("sixteen");
                                    break;
                                case 7:
                                    spelledNum.append("seventeen");
                                    break;
                                case 8:
                                    spelledNum.append("eighteen");
                                    break;
                                case 9:
                                    spelledNum.append("nineteen");
                                    break;
                            }

                            isTeen = false;
                        }
                        else {
                            if (digits[i] > 0) {
                                if (digits[i+1] == 0) {
                                    spelledNum.append(" ");
                                }

                                spelledNum.append(number_key[digits[i] - 1]);
                            }
                        }

                        if (i==9) {
                            spelledNum.append(" billion");
                        }
                        else if (i==6) {
                            spelledNum.append(" million");
                        }
                        else if (i==3) {
                            spelledNum.append(" thousand");
                        }
                    }
                    else if ((digits.size() == 1) && (i < 2) && (digits[i] == 0)) {
                        spelledNum.append("zero");
                    }

                    break;
            }
        }

        return spelledNum;
    }
    else {
        throw std::domain_error("\nMust be an integer between 0 and 999,999,999,999.");
    }
}

std::vector<int> getDigits(unsigned long long int number) {
    std::vector<int> digit_vec;

    if (number > 0){
        while (number > 0) {
            digit_vec.push_back(number%10);
            number /= 10;
        }
    }
    else {
        digit_vec.push_back(0);
    }

    return digit_vec;
}

}