#include "grade_school.h"

namespace grade_school {

std::map<int, std::vector<std::string>> school::roster() const{
    const std::map<int, std::vector<std::string>> roster_map{ m_roster_map };

    return roster_map;
}

void school::add(std::string name, int grade) {
    m_roster_map.insert(std::pair<int, std::vector<std::string>>(grade, std::vector<std::string>()));

    m_roster_map[grade].push_back(name);

    std::sort(m_roster_map[grade].begin(), m_roster_map[grade].end());
}

std::vector<std::string> school::grade(int grade) const{
    std::map<int, std::vector<std::string>>::const_iterator grade_roster_itr{ m_roster_map.find(grade) };
    const std::vector<std::string> grade_roster{ grade_roster_itr->second };

    return grade_roster;
}

}