#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace grade_school {

class school{
    private:
        std::map<int, std::vector<std::string>> m_roster_map;

    public:
        std::map<int, std::vector<std::string>> roster() const;
        void add(std::string name, int grade);
        std::vector<std::string> grade(int grade) const;
};

}

#endif