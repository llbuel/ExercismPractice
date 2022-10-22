#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>

namespace word_count {

std::map<std::string, int> words(const std::string& phrase);

}

#endif