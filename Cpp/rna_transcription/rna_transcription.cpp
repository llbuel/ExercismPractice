#include "rna_transcription.h"

namespace rna_transcription {

std::string to_rna(std::string dna) {
    std::string rna{""};

    for (std::size_t dna_itr = 0, len = dna.length(); dna_itr != len; ++dna_itr) {
        switch (dna[dna_itr]) {
            case 'A':
                rna.append("U");
                break;
            case 'T':
                rna.append("A");
                break;
            case 'C':
                rna.append("G");
                break;
            case 'G':
                rna.append("C");
                break;
        }
    }

    return rna;
}

char to_rna(char dna) {
    char rna;

    switch (dna) {
        case 'A':
            rna = 'U';
            break;
        case 'T':
            rna = 'A';
            break;
        case 'C':
            rna = 'G';
            break;
        case 'G':
            rna = 'C';
            break;
    }

    return rna;
}

}