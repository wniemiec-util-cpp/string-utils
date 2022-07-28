#include "StringUtilsTest.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../../../../include/wniemiec/util/cpp/StringUtils.hpp"

using namespace wniemiec::util::cpp;

//-----------------------------------------------------------------------------
//		Test hooks
//-----------------------------------------------------------------------------
void StringUtilsTest::set_up() 
{
    selected_string = std::string();
    obtained_result = std::string();
    obtained_terms = std::vector<std::string>();
}


//-----------------------------------------------------------------------------
//		Tests
//-----------------------------------------------------------------------------
TEST_F(StringUtilsTest, test_split_with_two_terms)
{
    with_str("hello world");
    do_split_with_sep("  ");
    assert_terms_are({
        "hello",
        "world"
    });
}

TEST_F(StringUtilsTest, test_split_with_three_terms)
{
    with_str("hello world two");
    do_split_with_sep(" ");
    assert_terms_are({
        "hello",
        "world",
        "two"
    });
}

TEST_F(StringUtilsTest, test_split_with_separator_size_two)
{
    with_str("hello  world");
    do_split_with_sep("  ");
    assert_terms_are({
        "hello",
        "world"
    });
}

TEST_F(StringUtilsTest, test_split_with_empty_str)
{
    with_str("");
    do_split_with_sep(" ");
    assert_terms_are({""});
}

TEST_F(StringUtilsTest, test_replace_all_with_one_value_and_new_value_with_size_one)
{
    with_str("hello world");
    do_replace_all_with_old_and_new_value(" ", "-");
    assert_result_is("hello-world");
}

TEST_F(StringUtilsTest, test_replace_all_with_one_value_and_new_value_with_size_two)
{
    with_str("hello world");
    do_replace_all_with_old_and_new_value(" ", "--");
    assert_result_is("hello--world");
}


//-----------------------------------------------------------------------------
//		Methods
//-----------------------------------------------------------------------------
void StringUtilsTest::with_str(std::string str)
{
    selected_string = str;
}

void StringUtilsTest::do_split_with_sep(std::string sep)
{
    obtained_terms = StringUtils::split(selected_string, sep);
}

void StringUtilsTest::assert_terms_are(std::vector<std::string> expected_terms)
{
    EXPECT_EQ(expected_terms, obtained_terms);
}

void StringUtilsTest::do_replace_all_with_old_and_new_value(
    std::string old_value, 
    std::string new_value
)
{
    obtained_result = StringUtils::replace_all(
        selected_string, 
        old_value, 
        new_value
    );

    
}

void StringUtilsTest::assert_result_is(std::string expected_result)
{
    EXPECT_STREQ(
        expected_result.c_str(),
        obtained_result.c_str()
    );
}

   