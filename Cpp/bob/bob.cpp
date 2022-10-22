#include "bob.h"

namespace bob {

std::string cleanStr(std::string input) {
    std::string outStr{ input };

    for (std::size_t i = 0; i < outStr.length(); ++i) {
        if ((outStr[i] < 'a' || outStr[i] > 'z') && (outStr[i] < 'A' || outStr[i] > 'Z') && (outStr[i] < '0' || outStr[i] > '9') && outStr[i] != '?') {
            outStr.erase(i,1);
            i--;
        }
    }

    return outStr;
}

std::string hey(std::string speak) {
    std::string response;

    std::string lowerCaseLetters;
    std::string upperCaseLetters;
    std::string numbers;
    std::string qMark;

    speak = cleanStr(speak);

    for (std::size_t i = 0; i < speak.length(); ++i) {
        if (speak[i] >= '0' && speak[i] <= '9') {
            numbers.push_back(speak[i]);
        }
        else if (speak[i] >= 'A' && speak[i] <= 'Z') {
            upperCaseLetters.push_back(speak[i]);
        }
        else if (speak[i] >= 'a' && speak[i] <= 'z') {
            lowerCaseLetters.push_back(speak[i]);
        }
        else {
            qMark.push_back(speak[i]);
        }
    }

    if (lowerCaseLetters.empty() && (speak[speak.length()-1] == '?') && !upperCaseLetters.empty()) {
        response = "Calm down, I know what I'm doing!";
    }
    else if ((speak[speak.length()-1] == '?')) {
        response = "Sure.";
    }
    else if (lowerCaseLetters.empty() && !upperCaseLetters.empty()) {
        response = "Whoa, chill out!";
    }
    else if (speak.empty()) {
        response = "Fine. Be that way!";
    }
    else {
        response = "Whatever.";
    }

    return response;
}

}