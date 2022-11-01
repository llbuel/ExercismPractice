#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <string>
#include <vector>
#include <map>

namespace anagram {

class anagram {
private:
    std::string m_cleanInput;
    std::map<std::string, int> m_letterCounts;

    std::string cleanString(const std::string& input);
    std::map<std::string, int> createMap(const std::string& cleanStrInput);

public:
    anagram(const std::string& baseInput);

    std::vector<std::string> matches(const std::vector<std::string>& testStrVector);

};

}

#endif