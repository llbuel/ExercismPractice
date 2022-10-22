#include "nucleotide_count.h"

namespace nucleotide_count {

counter::counter(std::string strand) {
    for (std::size_t validate_itr = 0, len = strand.length(); validate_itr != len; ++validate_itr) {
        if ((strand[validate_itr] != 'A') && (strand[validate_itr] != 'T') && (strand[validate_itr] != 'C') && (strand[validate_itr] != 'G')) {
            throw std::invalid_argument("Not a valid DNA sequence.");
        }
    }
    
    m_strand = strand;

    int count_A{ 0 };
    int count_T{ 0 };
    int count_C{ 0 };
    int count_G{ 0 };
    
    for (std::size_t strand_itr = 0, len = strand.length(); strand_itr != len; ++strand_itr) {
        switch (strand[strand_itr]) {
            case 'A':
                count_A++;
                break;
            case 'T':
                count_T++;
                break;
            case 'C':
                count_C++;
                break;
            case 'G':
                count_G++;
                break;
        }
    }

    std::map<char, int>::iterator nucleotide_itr_A = m_nucleotides.find('A');
    nucleotide_itr_A->second = count_A;

    std::map<char, int>::iterator nucleotide_itr_T = m_nucleotides.find('T');
    nucleotide_itr_T->second = count_T;

    std::map<char, int>::iterator nucleotide_itr_C = m_nucleotides.find('C');
    nucleotide_itr_C->second = count_C;

    std::map<char, int>::iterator nucleotide_itr_G = m_nucleotides.find('G');
    nucleotide_itr_G->second = count_G;
}

std::map<char, int> counter::nucleotide_counts() const {
    const std::map<char, int> nucleotide_map{ m_nucleotides };

    return nucleotide_map;
}

int counter::count(char nucleotide) const {
    if ((nucleotide != 'A') && (nucleotide != 'T') && (nucleotide != 'C') && (nucleotide != 'G')) {
        throw std::invalid_argument("Not a valid nucleotide.");
    }
    else {
        const std::map<char, int> nucleotide_map{ m_nucleotides };
        const std::map<char, int>::const_iterator count_itr = nucleotide_map.find(nucleotide);
        const char count_return = count_itr->second;

        return count_return;
    }
}

}