#ifndef CRYPTO_SQUARE_H
#define CRYPTO_SQUARE_H

#include <string>
#include <vector>

namespace crypto_square {

class cipher {
private:
    std::string m_normalizedString;
    std::size_t m_normalizedLength;
    int m_segmentLength;
    std::string m_normalizedOutputString;
    std::string m_cleanOutputString;
    std::vector<std::string> m_inputSegments;

    std::string cleanString(const std::string& input);
    std::vector<std::string> createSegments(const std::string& inputString);
    std::string readSegments(const std::vector<std::string>& segments);

public:
    cipher(const std::string& input);

    std::string normalize_plain_text() const { return m_normalizedString; }
    std::vector<std::string> plain_text_segments() { return m_inputSegments; }
    std::string cipher_text() { return m_cleanOutputString; }
    std::string normalized_cipher_text() { return m_normalizedOutputString; }

};

}

#endif