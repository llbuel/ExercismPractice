#include "food_chain.h"

namespace food_chain {

std::string verse(int verseNum) {
    std::string thisVerse;
    std::map<int, std::string> animalMap{{0, "fly"},{1, "spider"},{2, "bird"},{3, "cat"},
                                        {4, "dog"},{5, "goat"},{6, "cow"},{7, "horse"}};

    std::map<std::string, std::string> verseMap{{"fly", "I don't know why she swallowed the fly."},
                                                {"spider", "It wriggled and jiggled and tickled inside her.\n"},
                                                {"bird", "How absurd to swallow a bird!\n"},
                                                {"cat", "Imagine that, to swallow a cat!\n"},
                                                {"dog", "What a hog, to swallow a dog!\n"},
                                                {"goat", "Just opened her throat and swallowed a goat!\n"},
                                                {"cow", "I don't know how she swallowed a cow!\n"},
                                                {"horse", "She's dead, of course!\n"}};

    thisVerse = "I know an old lady who swallowed a " + animalMap[(verseNum - 1)] + ".\n";
    thisVerse += verseMap[animalMap[(verseNum - 1)]];

    if (verseNum != 8) {
        for (int i = (verseNum - 1); (i+1) > 0; --i) {
            if ((i != 2 && i != 0) || (i == 2 && verseNum < 3)) {
                thisVerse += "She swallowed the " + animalMap[i] + " to catch the " + animalMap[i-1] + ".\n"; 
            }
            else if (i == 2 && verseNum > 2) {
                thisVerse += "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n";
            }
            else if (i == 0 && verseNum > 1) {
                thisVerse += verseMap[animalMap[i]];
            }
        }

        thisVerse += " Perhaps she'll die.\n";
    }

    return thisVerse;
}

std::string verses(int startVerseNum, int endVerseNum) {
    std::string song;
    
    for (int i = startVerseNum; i < (endVerseNum + 1); ++i) {
        song += verse(i) + "\n";
    }

    return song;
}

std::string sing() { 
    return verses(1,8); 
}

}