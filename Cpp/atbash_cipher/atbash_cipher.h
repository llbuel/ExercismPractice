#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H

#include <map>
#include <string>

namespace atbash_cipher {

std::map<char, char> getCipher();
std::string remSpecialChars(std::string text);

std::string encode(std::string text);
std::string decode(std::string encodedText);

}

#endif