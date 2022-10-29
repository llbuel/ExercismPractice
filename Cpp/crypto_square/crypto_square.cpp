#include "crypto_square.h"

namespace crypto_square {

cipher::cipher(const std::string& input) {
    m_normalizedString = cleanString(input);
    m_normalizedLength = m_normalizedString.size();
    m_inputSegments = createSegments(m_normalizedString);
    m_cleanOutputString = readSegments(m_inputSegments);
}

std::string cipher::cleanString(const std::string& input) {
    std::string output{ input };
    std::size_t itr{ 0 };
    
    while (itr < output.size()) {
        if (output[itr] >= 'A' && output[itr] <= 'Z') {
            std::string newLetter{ std::string(1,('a' + (output[itr] - 'A'))) };
            output.replace(itr, 1, newLetter);
            itr++;
        }
        else if ((output[itr] < 'a' || output[itr] > 'z') && (output[itr] < '0' || output[itr] > '9')) {
            output.erase(itr,1);
        }
        else {
            itr++;
        }
    }

    return output;
}

std::vector<std::string> cipher::createSegments(const std::string& inputString) {
    std::vector<std::string> outputVector;
    unsigned int charLength{ 0 };

    if (m_normalizedLength > 0) {

        while (!(m_normalizedLength < (charLength * charLength) - charLength)) {
            ++charLength;
        }

        if ((charLength-1) * (charLength-1) == m_normalizedLength) {
            --charLength;
        }

        unsigned int itr{ 0 };

        while (itr*charLength < m_normalizedLength) {
            std::string thisSegment{ "" };

            for (unsigned int j = 0; j < charLength; ++j) {
                if ((j+(itr*charLength)) < m_normalizedLength) {
                    thisSegment += inputString[j+(itr*charLength)];
                }
            }

            itr++;
            outputVector.push_back(thisSegment);
        }
    }

    m_segmentLength = charLength;
    return outputVector;
}

std::string cipher::readSegments(const std::vector<std::string>& segments) {
    std::string outputString;

    for (int colNum = 0; colNum < m_segmentLength; ++colNum) {
        for (std::size_t rowNum = 0; rowNum < segments.size(); ++rowNum) {
            if (((segments[rowNum]))[colNum] != '\000') {
                outputString += std::string(1,(segments[rowNum])[colNum]);
                m_normalizedOutputString += std::string(1,(segments[rowNum])[colNum]);
            }
            else {
                m_normalizedOutputString += " ";
            }
        }
        
        if ((colNum+1) != m_segmentLength) {
            m_normalizedOutputString += " ";
        }
    }

    return outputString;
}

}