#include "robot_name.h"

namespace robot_name {

std::string robot::generateName() const {
    std::string name;
    std::vector<std::string> letters{"A","B","C","D",
                                     "E","F","G","H",
                                     "I","J","K","L",
                                     "M","N","O","P",
                                     "Q","R","S","T",
                                     "U","V","W","X",
                                     "Y","Z"};
    std::vector<std::string> digits{"0","1","2","3","4",
                                    "5","6","7","8","9"};

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distributionLetters(0,25);
    std::uniform_int_distribution<int> distributionDigits(0,9);

    int letter1 = distributionLetters(generator);
    int letter2 = distributionLetters(generator);
    int digit1 = distributionDigits(generator);
    int digit2 = distributionDigits(generator);
    int digit3 = distributionDigits(generator);

    name = letters[letter1] + letters[letter2] + digits[digit1] + digits[digit2] + digits[digit3];

    if (!s_name_vec.empty()) {
        while (std::find(s_name_vec.begin(), s_name_vec.end(), name) != s_name_vec.end()) {
            letter1 = distributionLetters(generator);
            letter2 = distributionLetters(generator);
            digit1 = distributionDigits(generator);
            digit2 = distributionDigits(generator);
            digit3 = distributionDigits(generator);

            name = letters[letter1] + letters[letter2] + digits[digit1] + digits[digit2] + digits[digit3];
        }
    }

    s_name_vec.push_back(name);

    return name;
}

void robot::reset() { 
    std::string new_name{ generateName() };
    m_robot_name = new_name;
}

}