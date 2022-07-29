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
    do_split_with_delimiter(" ");
    assert_terms_are({
        "hello",
        "world"
    });
}

TEST_F(StringUtilsTest, test_split_with_three_terms)
{
    with_str("hello world two");
    do_split_with_delimiter(" ");
    assert_terms_are({
        "hello",
        "world",
        "two"
    });
}

TEST_F(StringUtilsTest, test_split_with_separator_size_two)
{
    with_str("hello  world");
    do_split_with_delimiter("  ");
    assert_terms_are({
        "hello",
        "world"
    });
}

TEST_F(StringUtilsTest, test_to_upper_with_empty_str)
{
    with_str("");
    do_to_upper();
    assert_result_is("");
}

TEST_F(StringUtilsTest, test_to_upper_with_lower_str_size_one)
{
    with_str("h");
    do_to_upper();
    assert_result_is("H");
}

TEST_F(StringUtilsTest, test_to_upper_with_lower_str_size_two)
{
    with_str("he");
    do_to_upper();
    assert_result_is("HE");
}

TEST_F(StringUtilsTest, test_to_upper_with_upper_str_size_one)
{
    with_str("H");
    do_to_upper();
    assert_result_is("H");
}

TEST_F(StringUtilsTest, test_to_upper_with_upper_str_size_two)
{
    with_str("HE");
    do_to_upper();
    assert_result_is("HE");
}

TEST_F(StringUtilsTest, test_to_upper_with_upper_and_lower_str)
{
    with_str("hEllo wOrlD");
    do_to_upper();
    assert_result_is("HELLO WORLD");
}

TEST_F(StringUtilsTest, test_replace_all_with_old_value_and_new_value_with_size_one)
{
    with_str("hello world");
    do_replace_all_with_old_and_new_value(" ", "-");
    assert_result_is("hello-world");
}

TEST_F(StringUtilsTest, test_replace_all_with_old_value_and_new_value_with_size_two)
{
    with_str("hello world");
    do_replace_all_with_old_and_new_value(" ", "--");
    assert_result_is("hello--world");
}

TEST_F(StringUtilsTest, test_replace_all_with_big_old_value_and_small_new_value)
{
    with_str("0x563bd539d2f0 -> 0x563bd538e4c0");
    do_replace_all_with_old_and_new_value("0x563bd539d2f0", "n0");
    assert_result_is("n0 -> 0x563bd538e4c0");
}


//-----------------------------------------------------------------------------
//		Methods
//-----------------------------------------------------------------------------
void StringUtilsTest::with_str(std::string str)
{
    selected_string = str;
}

void StringUtilsTest::do_split_with_delimiter(std::string delimiter)
{
    obtained_terms = StringUtils::split(selected_string, delimiter);
}

void StringUtilsTest::assert_terms_are(std::vector<std::string> expected_terms)
{
    EXPECT_EQ(expected_terms, obtained_terms);
}

void StringUtilsTest::do_to_upper()
{
    obtained_result = StringUtils::to_upper(selected_string);
}

void StringUtilsTest::assert_result_is(std::string expected_result)
{
    EXPECT_STREQ(
        expected_result.c_str(),
        obtained_result.c_str()
    );
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
