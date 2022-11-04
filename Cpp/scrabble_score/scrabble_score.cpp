#include "scrabble_score.h"

namespace scrabble_score {

static const std::map<int, std::vector<char>> scoreMap = {{1,{'A','E','I','O','U','L','N','R','S','T'}},
                                                          {2,{'D','G'}},
                                                          {3,{'B','C','M','P'}},
                                                          {4,{'F','H','V','W','Y'}},
                                                          {5,{'K'}},
                                                          {6,{}},
                                                          {7,{}},
                                                          {8,{'J','X'}},
                                                          {9,{}},
                                                          {10,{'Q','Z'}}};

std::string normalizeString(const std::string& inputString) {
    std::string outputString{ inputString };
    
    for (std::size_t i = 0; i < outputString.size(); ++i) {
        if (outputString[i] >= 'a' && outputString[i] <= 'z') {
            char newLetter{ static_cast<char>((outputString[i]-'a') + 'A') };
            outputString[i] = newLetter;
        }
    }

    return outputString;
}

int getLetterScore(char letter) {
    for (std::map<int, std::vector<char>>::const_iterator mapItr = scoreMap.begin(); mapItr != scoreMap.end(); ++mapItr) {
        if (std::find(mapItr->second.begin(), mapItr->second.end(), letter) != mapItr->second.end()) {
            return mapItr->first;
        }
    }

    return 0;
}

int score(const std::string& word) {
    std::string cleanWord{ normalizeString(word) };
    int scoreSum{ 0 };

    for (std::size_t i = 0; i < cleanWord.size(); ++i) {
        scoreSum += getLetterScore(cleanWord[i]);
    }

    return scoreSum;
}

}