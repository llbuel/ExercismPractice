#define CATCH_CONFIG_MAIN
#include "rna_transcription.h"
#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("transcribes_cytidine_to_guanosine")
{
    REQUIRE('G' == rna_transcription::to_rna('C'));
}

TEST_CASE("transcribes_guanosine_to_cytidine")
{
    REQUIRE('C' == rna_transcription::to_rna('G'));
}

TEST_CASE("transcribes_adenosine_to_uracil")
{
    REQUIRE('U' == rna_transcription::to_rna('A'));
}

TEST_CASE("transcribes_thymidine_to_adenosine")
{
    REQUIRE('A' == rna_transcription::to_rna('T'));
}

TEST_CASE("transcribes_all_dna_nucleotides_to_their_rna_complements")
{
    REQUIRE("UGCACCAGAAUU" == rna_transcription::to_rna("ACGTGGTCTTAA"));
}