#define CATCH_CONFIG_MAIN
#include "armstrong_numbers.h"
#include <catch2/catch.hpp>

TEST_CASE("zero_is_an_armstrong_number")
{
    REQUIRE(armstrong_numbers::is_armstrong_number(0));
}

TEST_CASE("single_digit_numbers_are_armstrong_numbers")
{
    REQUIRE(armstrong_numbers::is_armstrong_number(5));
}

TEST_CASE("there_are_no_2_digit_armstrong_numbers")
{
    REQUIRE_FALSE(armstrong_numbers::is_armstrong_number(10));
}

TEST_CASE("three_digit_number_that_is_an_armstrong_number")
{
    REQUIRE(armstrong_numbers::is_armstrong_number(153));
}

TEST_CASE("three_digit_number_that_is_not_an_armstrong_number")
{
    REQUIRE_FALSE(armstrong_numbers::is_armstrong_number(100));
}

TEST_CASE("four_digit_number_that_is_an_armstrong_number")
{
    REQUIRE(armstrong_numbers::is_armstrong_number(9474));
}

TEST_CASE("four_digit_number_that_is_not_an_armstrong_number")
{
    REQUIRE_FALSE(armstrong_numbers::is_armstrong_number(9475));
}

TEST_CASE("seven_digit_number_that_is_an_armstrong_number")
{
    REQUIRE(armstrong_numbers::is_armstrong_number(9926315));
}

TEST_CASE("seven_digit_number_that_is_not_an_armstrong_number")
{
    REQUIRE_FALSE(armstrong_numbers::is_armstrong_number(9926314));
}