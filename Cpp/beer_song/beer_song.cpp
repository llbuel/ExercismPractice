#include "beer_song.h"

namespace beer_song {

std::vector<std::string> getBaseVerse() {
    std::vector<std::string> baseVerse = {" of beer on the wall, ",
                                          " of beer.\n",
                                          "Take ", " down and pass it around, ",
                                          " of beer on the wall.\n",
                                          "Go to the store and buy some more, ",
                                          " of beer on the wall.\n"};

    return baseVerse;
}

std::string verse(int current_bottles) {
    std::vector<std::string> baseVerseVec = getBaseVerse();

    std::string strInsertLine1;
    std::string strInsertLine2;
    std::string strInsertLine3;
    std::string strInsertLine4;

    std::string fullVerse;

    if (current_bottles > 2) {
        strInsertLine1 = std::to_string(current_bottles) + " bottles";
        strInsertLine2 = strInsertLine1;
        strInsertLine3 = "one";
        strInsertLine4 = std::to_string(current_bottles - 1) + " bottles";

        fullVerse = strInsertLine1 + baseVerseVec[0] +
                    strInsertLine2 + baseVerseVec[1] +
                    baseVerseVec[2] + strInsertLine3 + baseVerseVec[3] +
                    strInsertLine4 + baseVerseVec[4];
    }
    else if (current_bottles > 1) {
        strInsertLine1 = std::to_string(current_bottles) + " bottles";
        strInsertLine2 = strInsertLine1;
        strInsertLine3 = "one";
        strInsertLine4 = std::to_string(current_bottles - 1) + " bottle";

        fullVerse = strInsertLine1 + baseVerseVec[0] +
                    strInsertLine2 + baseVerseVec[1] +
                    baseVerseVec[2] + strInsertLine3 + baseVerseVec[3] +
                    strInsertLine4 + baseVerseVec[4];
    }
    else if (current_bottles > 0) {
        strInsertLine1 = std::to_string(current_bottles) + " bottle";
        strInsertLine2 = strInsertLine1;
        strInsertLine3 = "it";
        strInsertLine4 = "no more bottles";

        fullVerse = strInsertLine1 + baseVerseVec[0] +
                    strInsertLine2 + baseVerseVec[1] +
                    baseVerseVec[2] + strInsertLine3 + baseVerseVec[3] +
                    strInsertLine4 + baseVerseVec[4];
    }
    else {
        strInsertLine1 = "No more bottles";
        strInsertLine2 = "no more bottles";
        strInsertLine4 = "99 bottles";

        fullVerse = strInsertLine1 + baseVerseVec[0] +
                    strInsertLine2 + baseVerseVec[1] +
                    baseVerseVec[5] + 
                    strInsertLine4 + baseVerseVec[6];
    }

    return fullVerse;
}

std::string sing(int current_bottles, int end_bottles) {
    std::string fullVerse{""};
    
    while (current_bottles > (end_bottles - 1)) {
        if (current_bottles > end_bottles) {
            fullVerse += verse(current_bottles) + "\n";
        }
        else {
            fullVerse += verse(current_bottles);
        }

        current_bottles--;
    }

    return fullVerse;
}

std::string sing(int current_bottles) {
    std::string fullVerse{""};
    
    while ((current_bottles + 1) > 0) {
        if (current_bottles > 0) {
            fullVerse += verse(current_bottles) + "\n";
        }
        else {
            fullVerse += verse(current_bottles);
        }

        current_bottles--;
    }

    return fullVerse;
}

}