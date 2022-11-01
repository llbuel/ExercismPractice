#include "anagram.h"

namespace anagram {

anagram::anagram(const std::string& baseInput) {
    m_cleanInput = cleanString(baseInput);
}

std::string anagram::cleanString(const std::string& input) {
    std::string output{ input };
    std::string newLetter;
    
    for (std::size_t i = 0; i < output.size(); ++i) {
        if ((output[i] < 'a' || output[i] > 'z') && (output[i] < 'A' || output[i] > 'Z')) {
            output.erase(i, 1);
            i--;
        }
        else if (output[i] >= 'A' && output[i] <= 'Z') {
            newLetter = std::string(1,('a'+((output[i])-'A')));
            output.replace(i, 1, newLetter);
        }
    }

    m_letterCounts = createMap(output);

    return output;
}

std::map<std::string, int> anagram::createMap(const std::string& cleanStrInput) {
    std::map<std::string, int> outputMap;
    std::map<std::string, int>::iterator elementFound;
    std::string newLetter;

    for (std::size_t i = 0; i < cleanStrInput.size(); ++i) {
        if (cleanStrInput[i] >= 'A' && cleanStrInput[i] <= 'Z') {
            newLetter = std::string(1,('a'+((cleanStrInput[i])-'A')));
        }
        else {
            newLetter = cleanStrInput[i];
        }
        
        elementFound = outputMap.find(newLetter);

        if (elementFound != outputMap.end()) {
            elementFound->second++;
        }
        else {
            outputMap.insert({newLetter, 1});
        }
    }

    return outputMap;
}

std::vector<std::string> anagram::matches(const std::vector<std::string>& testStrVector) {
    std::vector<std::string> outputVec{ testStrVector };
    
    for (std::size_t i = 0; i < outputVec.size(); ++i) {
        if (createMap(outputVec[i]) != m_letterCounts || m_cleanInput == cleanString(outputVec[i])) {
            outputVec.erase(outputVec.begin()+i);
            --i;
        }
    }

    return outputVec;
}

}