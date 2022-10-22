#ifndef ALLERGIES_H
#define ALLERGIES_H

#include <string>
#include <unordered_set>
#include <vector>

namespace allergies {

class allergy_test{
private:
    std::unordered_set<std::string> m_allergies;

    void set_allergies(int score);
public:
    allergy_test(int score);
    
    bool is_allergic_to(std::string allergen) const;
    std::unordered_set<std::string> get_allergies() const { return m_allergies; };
};

std::vector<int> toReverseBinary(int decimal);

}

#endif
