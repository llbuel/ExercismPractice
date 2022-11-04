#include "acronym.h"

namespace acronym {

std::string cleanString(const std::string& inputString) {
    std::string outputString{ inputString };

    for (std::size_t i = 0; i < outputString.size(); ++i) {
        if (outputString[i] >= 'a' && outputString[i] <= 'z') {
            char newChar{ static_cast<char>((outputString[i]-'a') + 'A') };
            outputString[i] = newChar;
        }
        else if ((outputString[i] < 'A' || outputString[i] > 'Z') && (outputString[i] < '0' || outputString[i] > '9')) {
            outputString.replace(i,1," ");
        }
    }

    return outputString;
}

std::string acronym(const std::string& fullPhrase) {
    std::string cleanPhrase{ cleanString(fullPhrase) };
    std::size_t itr{ 0 };
    std::string outputAcronym;

    while (itr != std::string::npos) {
        if (itr == 0){
            outputAcronym += cleanPhrase[0];
        }
        else if (itr != (cleanPhrase.size()-1) && cleanPhrase[itr+1] != ' ') {
            outputAcronym += cleanPhrase[itr+1];
        }

        itr = cleanPhrase.find(' ',itr+1);
    }

    return outputAcronym;
}

}