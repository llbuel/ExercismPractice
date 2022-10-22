#define CATCH_CONFIG_MAIN
#include "collatz_conjecture.cpp"
#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("zero_steps_for_one") 
{
    REQUIRE(0 == collatz_conjecture::steps(1));
}

TEST_CASE("divide_if_even") 
{
    REQUIRE(4 == collatz_conjecture::steps(16));
}

TEST_CASE("even_and_odd_steps") 
{
    REQUIRE(9 == collatz_conjecture::steps(12));
}

TEST_CASE("large_number_of_even_and_odd_steps") 
{
    REQUIRE(152 == collatz_conjecture::steps(1000000));
}

TEST_CASE("zero_is_an_error") 
{
    REQUIRE_THROWS_AS(collatz_conjecture::steps(0), std::domain_error);
}

TEST_CASE("negative_value_is_an_error") 
{
    REQUIRE_THROWS_AS(collatz_conjecture::steps(-15), std::domain_error);
}