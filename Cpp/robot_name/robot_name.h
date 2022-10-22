#ifndef ROBOT_NAME_H
#define ROBOT_NAME_H

#include <algorithm>
#include <random>
#include <string>
#include <vector>

namespace robot_name {

class robot {
private:
    std::string m_robot_name;
    static std::vector<std::string> s_name_vec;

    std::string generateName() const;

public:
    robot() : m_robot_name(generateName()) {}
    
    std::string name() const { return m_robot_name; }
    void reset();
    std::vector<std::string> getNameVector() const { return s_name_vec; }
};

std::vector<std::string> robot::s_name_vec;

}

#endif
