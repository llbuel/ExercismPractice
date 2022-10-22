#ifndef SECRET_HANDSHAKE_H
#define SECRET_HANDSHAKE_H

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

namespace secret_handshake {

std::vector<std::string> commands(int decimal);
std::vector<int> toReverseBinary(int decimal);

}

#endif
