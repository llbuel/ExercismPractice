#define CATCH_CONFIG_MAIN
#include "source.cpp"
#include <catch2/catch.hpp>
#include <sstream>

using namespace std;

struct addTest {
    int a;
    int b;
    int expected;
    string msg;
};

vector<addTest> addCases = {
    {10, 0, 90,   "add case 1"},
    {6, 41, -11,  "add case 2"},
    {0, 45, -45,  "add case 3"},
    {10, 0, 90,   "add case 4"},
    {23, 59, 447, "add case 5"},
    {5, -32, 52,  "add case 6"},
    {-1, -1, 3,   "add case 7"},
    {10, 3, 87,   "add case 8"},
};

string errorMsg(int expected, int actual, string test)
{
    stringstream ret;
    ret << "[" << expected << " != " << actual << "] test case: " << test;
    return ret.str();
}

TEST_CASE("add_tests")
{
    for (addTest a : addCases) {
        test::templateClass c(a.a, a.b);
        
        const auto actual = c.classFcn();
        INFO(errorMsg(a.expected, actual, a.msg));
        REQUIRE(a.expected == actual);
    }
}
