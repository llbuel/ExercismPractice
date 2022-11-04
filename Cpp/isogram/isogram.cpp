#include "isogram.h"

namespace isogram {

std::string cleanString(const std::string& inputString) {
    std::string outputString{ inputString };
    for (std::size_t i = 0; i < outputString.size(); ++i) {
        if (outputString[i] >= 'A' && outputString[i] <= 'Z') {
            char newChar{ static_cast<char>((outputString[i] - 'A') + 'a') };
            outputString[i] = newChar;
        }
        else if (outputString[i] == ' ' || outputString[i] == '-') {
            outputString.erase(i,1);
            --i;
        }
    }

    return outputString;
}

bool is_isogram(const std::string& phrase) {
    std::string cleanPhrase = cleanString(phrase);
    std::map<char, int> phraseMap;
    std::map<char, int>::const_iterator mapItr;

    for (std::size_t i = 0; i < cleanPhrase.size(); ++i) {
        mapItr = phraseMap.find(cleanPhrase[i]);

        if (mapItr == phraseMap.end()) {
            phraseMap.insert({cleanPhrase[i],1});
        }
        else {
            return false;
        }
    }

    return true;
}

}