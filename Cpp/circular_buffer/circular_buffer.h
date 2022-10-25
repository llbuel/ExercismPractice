#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace circular_buffer {

template <typename T> class circular_buffer {
private:
    std::vector<T> m_bufferVec;
    int m_earliestEntry;
    int m_latestEntry;
    std::size_t m_bufferLen;

private:
    bool checkElementIsFree(std::size_t elementPos) {
        if (m_bufferVec.empty() || (elementPos > (m_bufferVec.size()-1) && elementPos < m_bufferLen)) {
            return true;
        }
        else {
            return false;
        }
    }

public:
    circular_buffer(std::size_t length) : m_earliestEntry(0), m_latestEntry(0), m_bufferLen(length) {}

public:
    T read() {
        if (!m_bufferVec.empty()) {
            T outVal{ m_bufferVec[m_earliestEntry] };
            bool isLast{ m_earliestEntry == m_latestEntry };
            
            if (!isLast) {
                m_bufferVec.erase(m_bufferVec.begin() + m_earliestEntry);
                m_latestEntry = (m_latestEntry+(m_bufferLen-1)) % m_bufferLen;

                if (m_earliestEntry == m_latestEntry) {
                    m_earliestEntry = 0;
                    m_latestEntry = 0;
                }
            }
            else {
                m_bufferVec.erase(m_bufferVec.begin());
            }

            return outVal;
        }
        else {
            throw std::domain_error("\nNo values to read.\n");
        }
    }

    void write(const T& input) {
        if (checkElementIsFree((m_latestEntry+1) % m_bufferLen)) {
            m_bufferVec.push_back(input);

            if (m_bufferVec.size() > 1) {
                m_latestEntry = (m_latestEntry + 1) % m_bufferLen;
            }
        }
        else {
            throw std::domain_error("\nBuffer is full. Must overwrite the buffer to place value.\n");
        }
    }

    void overwrite(const T& input) {
        if (checkElementIsFree((m_latestEntry+1) % m_bufferLen)) {
            m_latestEntry = (m_latestEntry + 1) % m_bufferLen;

            m_bufferVec.push_back(input);
        }
        else {
            m_bufferVec[m_earliestEntry] = input;
            m_latestEntry = (m_latestEntry+1) % m_bufferLen;
            m_earliestEntry = (m_earliestEntry+1) % m_bufferLen;
        }
    }

    void clear() {
        m_bufferVec.clear();
        m_earliestEntry = 0;
        m_latestEntry = 0;
    }

};

}

#endif