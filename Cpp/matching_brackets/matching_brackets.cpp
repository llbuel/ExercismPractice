#include "matching_brackets.h"

namespace matching_brackets {

bool check(const std::string& testString) {
    std::vector<int> bracketOpenVec;
    std::string::const_iterator itr{ testString.begin() };
    int vecIdx{ -1 };
    int closeBracketCheck{ 0 };
    int prevBracketCheck{ 0 };

    while (itr != testString.end()) {
        switch (*itr) {
            case '(':
                prevBracketCheck = closeBracketCheck;
                closeBracketCheck += 2;

                bracketOpenVec.push_back(2);

                vecIdx++;

                break;
            case '[':
                prevBracketCheck = closeBracketCheck;
                closeBracketCheck += 4;

                bracketOpenVec.push_back(4);

                vecIdx++;

                break;
            case '{':
                prevBracketCheck = closeBracketCheck;
                closeBracketCheck += 8;

                bracketOpenVec.push_back(8);

                vecIdx++;

                break;
            case ')':
                if (vecIdx < 0) {
                    return false;
                }
                else {
                    closeBracketCheck -= 2;

                    if (prevBracketCheck != closeBracketCheck) {
                        return false;
                    }

                    bracketOpenVec.erase(bracketOpenVec.begin() + vecIdx);

                    prevBracketCheck -= bracketOpenVec[--vecIdx];
                }
                break;
            case ']':
                if (vecIdx < 0) {
                    return false;
                }
                else {
                    closeBracketCheck -= 4;

                    if (prevBracketCheck != closeBracketCheck) {
                        return false;
                    }

                    bracketOpenVec.erase(bracketOpenVec.begin() + vecIdx);

                    prevBracketCheck -= bracketOpenVec[--vecIdx];
                }
                break;
            case '}':
                if (vecIdx < 0) {
                    return false;
                }
                else {
                    closeBracketCheck -= 8;

                    if (prevBracketCheck != closeBracketCheck) {
                        return false;
                    }

                    bracketOpenVec.erase(bracketOpenVec.begin() + vecIdx);

                    prevBracketCheck -= bracketOpenVec[--vecIdx];
                }
                break;
        }

        if (closeBracketCheck < 0) {
            return false;
        }

        ++itr;
    }

    if (closeBracketCheck == 0) {
        return true;
    }
    else {
        return false;
    }
}

}