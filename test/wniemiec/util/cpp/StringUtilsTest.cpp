#include "StringUtilsTest.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace wniemiec::util::cpp;

//-----------------------------------------------------------------------------
//		Tests
//-----------------------------------------------------------------------------
TEST_F(StringUtilsTest, test_split_with_two_terms)
{
    std::string str = "hello world "; 
    std::string sep = " ";
    std::vector<std::string> expectedTerms = std::vector<std::string>();
    expectedTerms.push_back("hello");
    expectedTerms.push_back("world");
    std::vector<std::string> terms = StringUtils::split(str, sep);
    EXPECT_EQ(
        expectedTerms,
        terms
    );
}

TEST_F(StringUtilsTest, test_split_with_three_terms)
{
    std::string str = "hello world two"; 
    std::string sep = " ";
    std::vector<std::string> expectedTerms = std::vector<std::string>();
    expectedTerms.push_back("hello");
    expectedTerms.push_back("world");
    expectedTerms.push_back("two");
    std::vector<std::string> terms = StringUtils::split(str, sep);
    EXPECT_EQ(
        expectedTerms,
        terms
    );
}
