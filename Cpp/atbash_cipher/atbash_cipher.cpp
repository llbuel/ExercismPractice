#include "atbash_cipher.h"

namespace atbash_cipher {

std::map<char, char> getCipher() {
    static std::map<char, char> cipher = {{'a', 'z'},{'b', 'y'},{'c', 'x'},{'d', 'w'},
                                          {'e', 'v'},{'f', 'u'},{'g', 't'},{'h', 's'},
                                          {'i', 'r'},{'j', 'q'},{'k', 'p'},{'l', 'o'},
                                          {'m', 'n'},{'n', 'm'},{'o', 'l'},{'p', 'k'},
                                          {'q', 'j'},{'r', 'i'},{'s', 'h'},{'t', 'g'},
                                          {'u', 'f'},{'v', 'e'},{'w', 'd'},{'x', 'c'},
                                          {'y', 'b'},{'z', 'a'},
                                          {'A', 'z'},{'B', 'y'},{'C', 'x'},{'D', 'w'},
                                          {'E', 'v'},{'F', 'u'},{'G', 't'},{'H', 's'},
                                          {'I', 'r'},{'J', 'q'},{'K', 'p'},{'L', 'o'},
                                          {'M', 'n'},{'N', 'm'},{'O', 'l'},{'P', 'k'},
                                          {'Q', 'j'},{'R', 'i'},{'S', 'h'},{'T', 'g'},
                                          {'U', 'f'},{'V', 'e'},{'W', 'd'},{'X', 'c'},
                                          {'Y', 'b'},{'Z', 'a'}};

    return cipher;    
}

std::string remSpecialChars(std::string text) {
    for (size_t i = 0; i < text.length(); ++i) {
        if ((((text[i] < 'a') || (text[i] > 'z')) && ((text[i] < 'A') || (text[i] > 'Z')) && ((text[i] < '0') || (text[i] > '9'))) || (text[i] == ' ')) {
            text.erase(i,1);
            i--;
        }
    }

    return text;
}

std::string encode(std::string text) {
    std::map<char, char> cipherMap = getCipher();
    std::string encodedText{ text };

    encodedText = remSpecialChars(encodedText);
    
    char letter, new_letter;

    for (size_t i = 0; i < encodedText.length(); ++i) {
        if ((encodedText[i] < '0') || (encodedText[i] > '9')) {
            letter = encodedText[i];
            new_letter = cipherMap[letter];

            encodedText[i] = new_letter;
        }
    }

    if (encodedText.length() > 5) {
        int space_add_itr{ 1 };
        int space_add_offset{ 0 };
        size_t itr = (space_add_itr * 5) + space_add_offset;

        while (itr < encodedText.length()) {
            encodedText.insert((encodedText.begin() + (5 * space_add_itr) + space_add_offset), ' ');
            space_add_itr++;
            space_add_offset++;
            itr = (space_add_itr * 5) + space_add_offset;
        }
    }

    return encodedText;
}

std::string decode(std::string encodedText) {
    std::map<char, char> cipherMap = getCipher();
    std::string text{ encodedText };

    text = remSpecialChars(text);

    char letter, new_letter;

    for (size_t i = 0; i < text.length(); ++i) {
        if ((text[i] < '0') || (text[i] > '9')) {
            letter = text[i];
            new_letter = cipherMap[letter];

            text[i] = new_letter;
        }
    }

    return text;
}

}