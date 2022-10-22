#include "raindrops.h"

namespace raindrops {

std::string convert(int input){
    std::string strOut{""};
    
    for (int i = 0; i < 4; i++){
        switch (i){
            case 0:
                if (input % 3 == 0){
                    strOut.append("Pling");
                }

                break;
            case 1:
                if (input % 5 == 0){
                    strOut.append("Plang");
                }

                break;
            case 2:
                if (input % 7 == 0){
                    strOut.append("Plong");
                }

                break;
            case 3:
                if ((input % 3 != 0) && (input % 5 != 0) && (input % 7 != 0)){
                    strOut.append(std::to_string(input));
                }

                break;
            default:
                strOut.append("");
        }
    }

    return strOut;
}

}