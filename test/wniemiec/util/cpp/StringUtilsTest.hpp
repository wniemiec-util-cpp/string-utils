#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include <vector>

namespace wniemiec { namespace util { namespace cpp {

    class StringUtilsTest : public testing::Test
    {
    //-------------------------------------------------------------------------
    //		Attributes
    //-------------------------------------------------------------------------
    private:
        std::string selected_string;
        std::string obtained_result;
        std::vector<std::string> obtained_terms;


    //-------------------------------------------------------------------------
    //		Test hooks
    //-------------------------------------------------------------------------
    protected:
        void SetUp() override { set_up(); };
        void set_up();


    //-------------------------------------------------------------------------
    //		Methods
    //-------------------------------------------------------------------------
    protected:
        void with_str(std::string str);    
        void do_split_with_delimiter(std::string delimiter);
        void assert_terms_are(std::vector<std::string> expected_terms);
        void do_to_upper();
        void assert_result_is(std::string expected_result);
        void do_replace_all_with_old_and_new_value(
            std::string old_value, 
            std::string new_value
        );
    };
}}}
