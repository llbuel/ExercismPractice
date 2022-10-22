#include "secret_handshake.h"

namespace secret_handshake {

std::vector<std::string> commands(int decimal) {
    std::vector<int> binary{ toReverseBinary(decimal) };
    std::vector<std::string> out_commands;

    std::vector<std::string> command_list {"wink",
                                           "double blink",
                                           "close your eyes",
                                           "jump"};

    bool dontflip{ false };

    for (std::size_t itr = (binary.size() - 1); (itr + 1) > 0; itr--) {
        if ((itr == 4) && (binary[itr] == 1)) {
            dontflip = true;
        }
        else if (binary[itr] == 1) {
            out_commands.push_back(command_list[itr]);
        }
    }

    if (!dontflip) {
        std::reverse(out_commands.begin(), out_commands.end());
    }

    return out_commands;
}

std::vector<int> toReverseBinary(int decimal) {
    if (decimal == 0){
        std::vector<int> binary{ 0 };
        return binary;
    }
    else if ((decimal < 0) || (decimal > 31)) {
        throw std::domain_error("\nMust be an integer between 0 and 31.");
    }
    else {
        int rem{ 0 };
        std::vector<int> binary;

        while (decimal != 1) {
            rem = decimal % 2;
            
            binary.push_back(rem);

            decimal /= 2;
        }

        binary.push_back(decimal);

        return binary;
    }
}

}