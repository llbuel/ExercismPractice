#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <string>
#include <vector>

namespace beer_song {

std::string verse(int current_bottles);
std::string sing(int current_bottles, int end_bottles);
std::string sing(int current_bottles);

std::vector<std::string> getBaseVerse();

}

#endif