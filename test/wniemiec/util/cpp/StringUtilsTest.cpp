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

TEST_F(StringUtilsTest, test_replace_all_with_one_value_and_new_value_with_size_one)
{
    std::string str = "hello world";
    std::string expected_str = "hello-world";
    std::string old_value = " ";
    std::string new_value = "-";
    std::string obtained_str = StringUtils::replace_all(str, old_value, new_value);

    EXPECT_STREQ(
        expected_str.c_str(),
        obtained_str.c_str()
    );
}

TEST_F(StringUtilsTest, test_replace_all_with_one_value_and_new_value_with_size_two)
{
    std::string str = "hello world";
    std::string expected_str = "hello--world";
    std::string old_value = " ";
    std::string new_value = "--";
    std::string obtained_str = StringUtils::replace_all(str, old_value, new_value);

    EXPECT_STREQ(
        expected_str.c_str(),
        obtained_str.c_str()
    );
}

