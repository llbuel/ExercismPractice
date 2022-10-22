#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <string>
#include <vector>
#include <stdexcept>

namespace circular_buffer {

template <typename T>
class circular_buffer;

template <>
class circular_buffer<int> {

public:
    circular_buffer(int length);

    int read();
    void write(int input);
    void overwrite(int input);
    void clear();
};

template <>
class circular_buffer<std::string> {

public:
    circular_buffer(int length);

    std::string read();
    void write(std::string input);
    void overwrite(std::string input);
    void clear();
};

}

#endif