#include "etl.h"

namespace etl {

std::map<char, int> transform(const std::map<int, std::vector<char>>& oldMap) {
    std::map<char, int> newMap;
    
    for (std::map<int, std::vector<char>>::const_iterator mapItr = oldMap.begin(); mapItr != oldMap.end(); ++mapItr) {
        for (std::vector<char>::const_iterator vecItr = mapItr->second.begin(); vecItr != mapItr->second.end(); ++vecItr) {
            if (*vecItr >= 'A' && *vecItr <= 'Z') {
                char newLetter = 'a' + (*vecItr - 'A');
                std::pair<char, int> pairInsert = std::make_pair(newLetter, mapItr->first);
                newMap.insert(pairInsert);
            }
            else if (*vecItr >= 'a' && *vecItr <= 'z') {
                std::pair<char, int> pairInsert = std::make_pair(*vecItr, mapItr->first);
                newMap.insert(pairInsert);
            }
        }
    }

    return newMap;
}

}