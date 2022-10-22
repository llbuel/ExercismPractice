#include "allergies.h"

namespace allergies {

allergy_test::allergy_test(int score) {
    set_allergies(score);
}

void allergy_test::set_allergies(int score) {
    std::vector<int> binary{ toReverseBinary(score) };
    std::vector<std::string> allergen_list{"eggs",
                                           "peanuts",
                                           "shellfish",
                                           "strawberries",
                                           "tomatoes",
                                           "chocolate",
                                           "pollen",
                                           "cats"};
    std::size_t listLimit{ allergen_list.size() };

    if (binary.size() > listLimit) {
        binary.erase(binary.begin()+8, binary.end());

        std::size_t eraseItr{ listLimit - 1 };
        while (binary[eraseItr] != 1) {
            binary.erase(binary.begin()+(binary.size()-1));
            eraseItr--;
        }
    }

    for (std::size_t itr = 0; itr < binary.size(); itr++) {
        if (binary[itr] == 1){
            m_allergies.insert(allergen_list[itr]);
        }
    }
}

bool allergy_test::is_allergic_to(std::string allergen) const{
    std::unordered_set<std::string> allergies{ m_allergies };
    bool isAllergic{ false };

    std::unordered_set<std::string>::const_iterator itr_find = allergies.find(allergen);

    if (itr_find != allergies.end()) {
        isAllergic = true;
    }

    return isAllergic;
}

std::vector<int> toReverseBinary(int decimal) {
    if (decimal == 0){
        std::vector<int> binary{ 0 };
        return binary;
    }
    else if (decimal < 0) {
        throw std::domain_error("\nMust be a positive integer.");
    }
    else {
        int rem{ 0 };
        std::vector<int> binary;

        while (decimal != 1) {
            rem = decimal % 2;
            
            binary.push_back(rem);

            decimal /= 2;
        }

        binary.push_back(decimal);

        return binary;
    }
}

}