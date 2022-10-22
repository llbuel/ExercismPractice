#include "reverse_string.h"

namespace reverse_string {

std::string reverse_string(std::string word){
    std::string new_word{word};

    if (word.length() > 0){
        for (int i = (word.length()-1); i > -1; i--){
            new_word[(word.length() - 1) - i] = word[i];
        }
    } else {
        new_word = "";
    }

    return new_word;
}

}