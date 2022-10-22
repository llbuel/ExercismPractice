#include "pangram.h"

namespace pangram {

bool is_pangram(std::string sentence){
    std::string testStrLC{"abcdefghijklmnopqrstuvwxyz"};
    std::string testStrUC{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    char remSpace = ' ';
    
    std::string testSubstr{""};

    bool testResult{true};

    sentence.erase(std::remove(sentence.begin(), sentence.end(), remSpace), sentence.end());

    for (int i = 0; i < 26; i++){
        testSubstr = testStrLC.at(i);

        if (sentence.find(testSubstr) == std::string::npos){
            testSubstr = testStrUC.at(i);
            
            if (sentence.find(testSubstr) == std::string::npos){
                testResult = false;
                break;
            }
        }    
    }

    return testResult;
}

}