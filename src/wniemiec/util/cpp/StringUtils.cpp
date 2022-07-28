#include "../../../../include/wniemiec/util/cpp/StringUtils.hpp"

#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>

using namespace wniemiec::util::cpp;

//-------------------------------------------------------------------------
//      Constructor
//-------------------------------------------------------------------------
StringUtils::StringUtils()
{
}


//-------------------------------------------------------------------------
//      Methods
//-------------------------------------------------------------------------
std::vector<std::string> StringUtils::split(std::string str, std::string delimiter)
{
    if (str.empty()) {
        return std::vector<std::string>({str});
    }

    std::vector<std::string> terms = std::vector<std::string>();
    int start = 0;
    int end = str.find(delimiter);
    
    while (end != -1) {
        terms.push_back(str.substr(start, end - start));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }

    terms.push_back(str.substr(start, end - start));

    return terms;
}

std::string StringUtils::to_upper(std::string str)
{
    if (str.empty()) {
        return str;
    }
    
    std::string upper_string = str;

    std::transform(
        upper_string.begin(), 
        upper_string.end(), 
        upper_string.begin(), 
        ::toupper
    );

    return upper_string;
}

std::string StringUtils::replace_all(
    std::string str, 
    std::string old_value, 
    std::string new_value
)
{
    if (str.empty() || old_value.empty()) {
        return str;
    }

    std::vector<std::string> terms = split(str, old_value);
    std::stringstream replaced_str;

    for (int i = 0; i < terms.size() - 1; i++) {
        replaced_str << terms[i] << new_value;
    }

    replaced_str << terms[terms.size() - 1];

    return replaced_str.str();
}
