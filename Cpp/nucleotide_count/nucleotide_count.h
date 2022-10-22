#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <stdexcept>
#include <string>

namespace nucleotide_count {

class counter {
private:
    std::string m_strand{""};
    std::map<char, int> m_nucleotides{ {'A',0}, {'T',0}, {'C',0}, {'G',0} };

public:
    counter(std::string strand);

    std::map<char, int> nucleotide_counts() const;
    int count(char nucleotide) const;
};

}

#endif