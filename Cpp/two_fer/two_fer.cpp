#include "two_fer.h"

namespace two_fer {

std::string two_fer(){
    std::string phrase("One for you, one for me.");

    return phrase;
}

std::string two_fer(std::string name)
{
    std::string phrase{"One for "};
    
    phrase.append(name);
    phrase.append(", one for me.");
    
    return phrase;
}

}