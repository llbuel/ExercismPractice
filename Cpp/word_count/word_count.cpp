#include "word_count.h"

namespace word_count {

std::vector<std::string> removeQuotes(std::vector<std::string>& vector) {
    std::vector<std::string>::iterator findQuotes{ std::find_if(vector.begin(), vector.end(), [](const std::string& substr) { return substr.find("\'") != std::string::npos; }) };
    
    while (findQuotes != vector.end()) {
        std::string element{ vector[findQuotes - vector.begin()] };

        if (element[0] == '\'' && element[element.length() - 1] == '\'') {
            vector[findQuotes - vector.begin()].erase(element.length() - 1, 1);
            vector[findQuotes - vector.begin()].erase(0,1);
        }
        
        findQuotes = std::find_if(findQuotes+1, vector.end(), [](const std::string& substr) { return substr.find("\'") != std::string::npos; });
    }

    return vector;
}

std::vector<std::string> removeEmptyElements(std::vector<std::string>& vector) {
    std::vector<std::string>::iterator findEmpty{ std::find(vector.begin(), vector.end(), "") };

    while (findEmpty != vector.end()) {
        vector.erase(findEmpty);
        findEmpty = std::find(vector.begin(), vector.end(), "");
    }

    return vector;
}

char upperToLowerCase(char c) {
    if (std::isupper(c)) {
        return std::tolower(c);
    }
    else {
        return c;
    }
}

std::string cleanStr(const std::string& input) {
    std::string outStr{ input };

    std::transform(outStr.begin(), outStr.end(), outStr.begin(), upperToLowerCase);

    std::size_t foundPos{ outStr.find_first_not_of(" \t\n\v\f\r,") };

    while (foundPos != std::string::npos) {
        if (!((outStr[foundPos] >= 'a' && outStr[foundPos] <= 'z') || (outStr[foundPos] >= 'A' && outStr[foundPos] <= 'Z') || (outStr[foundPos] >= '0' && outStr[foundPos] <= '9') || outStr[foundPos] == '\'')) {
            outStr.replace(foundPos,1, " ");
        }

        foundPos = outStr.find_first_not_of(" \t\n\v\f\r,", foundPos+1);
    }

    return outStr;
}

std::map<std::string, int> words(const std::string& phrase) {
    std::map<std::string, int> outMap;
    std::vector<std::string> tokenVec;
    std::string newPhrase{ cleanStr(phrase) };
    
    int currentWordLength{ 0 };
    int vecStart{ 0 };

    std::size_t foundPos{ newPhrase.find_first_of(" \t\n\v\f\r,") };
    std::size_t nextWordStart;
    
    if (!newPhrase.empty()) {
        while (foundPos != std::string::npos) {
            currentWordLength = foundPos;

            tokenVec.push_back(newPhrase.substr(vecStart, currentWordLength));

            nextWordStart = newPhrase.find_first_not_of(" \t\n\v\f\r,", foundPos);
            newPhrase.erase(vecStart, nextWordStart);
            
            foundPos = newPhrase.find_first_of(" \t\n\v\f\r,");
        }

        tokenVec.push_back(newPhrase);
    }

    tokenVec = removeEmptyElements(tokenVec);
    tokenVec = removeQuotes(tokenVec);

    for (std::size_t i = 0; i < tokenVec.size(); ++i) {
        std::vector<std::string>::iterator foundWord{ std::find(tokenVec.begin(), tokenVec.end(), tokenVec[0]) };

        while (foundWord != tokenVec.end()) {
            outMap[tokenVec[foundWord - tokenVec.begin()]];
            outMap.find(tokenVec[foundWord - tokenVec.begin()])->second++;

            tokenVec.erase(foundWord);
            foundWord = std::find(tokenVec.begin(), tokenVec.end(), tokenVec[0]);
        }
    } 

    return outMap;   
}

}