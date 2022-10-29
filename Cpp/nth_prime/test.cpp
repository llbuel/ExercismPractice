#define CATCH_CONFIG_MAIN
#include "nth_prime.h"
#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("first")
{
    REQUIRE(2 == nth_prime::nth(1));
}

TEST_CASE("second")
{
    REQUIRE(3 == nth_prime::nth(2));
}

TEST_CASE("sixth")
{
    REQUIRE(13 == nth_prime::nth(6));
}

TEST_CASE("big_prime")
{
    REQUIRE(104743 == nth_prime::nth(10001));
}

TEST_CASE("weird_case")
{
    REQUIRE_THROWS_AS(nth_prime::nth(0), std::domain_error);
}