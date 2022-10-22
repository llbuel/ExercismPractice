#include "protein_translation.h"

namespace protein_translation {

std::vector<std::string> proteins(std::string rna) {
    std::vector<std::string> codons;
    std::vector<std::string> protein_vec;
    std::map<std::string, std::string> codon_map{{"AUG", "Methionine"},{"UUU", "Phenylalanine"},{"UUC", "Phenylalanine"},
                                                 {"UUA", "Leucine"},   {"UUG", "Leucine"},      {"UCU", "Serine"},
                                                 {"UCC", "Serine"},    {"UCA", "Serine"},       {"UCG", "Serine"},
                                                 {"UAU", "Tyrosine"},  {"UAC", "Tyrosine"},     {"UGU", "Cysteine"},
                                                 {"UGC", "Cysteine"},  {"UGG", "Tryptophan"},   {"UAA", "STOP"},
                                                 {"UAG", "STOP"},      {"UGA", "STOP"}};

    std::size_t itr_rna{ 0 };
    int itr_codon{ 0 };

    while (itr_rna < rna.length()) {
        codons.push_back(rna.substr(itr_rna, 3));

        itr_rna += 3;
        itr_codon++;
    }

    std::map<std::string, std::string>::iterator j;
    for (std::size_t i = 0; i < codons.size(); i++) {
        j = codon_map.find(codons[i]);

        if (j->second != "STOP") {
            protein_vec.push_back(j->second);
        }
        else {
            break;
        }
    }

    return protein_vec;
}

}