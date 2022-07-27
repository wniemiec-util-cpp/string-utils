#include "../../../../include/wniemiec/util/cpp/StringUtils.hpp"

#include <iostream>
#include <vector>
#include <string.h>
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
std::vector<std::string> StringUtils::split(std::string str, std::string sep)
{
    if (str.empty())
        return std::vector<std::string>();

    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;

    current = strtok(cstr,sep.c_str());

    while(current != NULL) 
    {
        arr.push_back(current);
        
        current = strtok(NULL,sep.c_str());
    }

    return arr;
}

std::string StringUtils::to_upper(std::string str)
{
    if (str.empty())
        return str;
    
    std::string upper_string = str;

    std::transform(
        upper_string.begin(), 
        upper_string.end(), 
        upper_string.begin(), 
        ::toupper
    );

    return upper_string;
}

std::string StringUtils::replace_all(std::string str, std::string old_str, std::string new_str)
{
    std::string replaced_str = str;
    int index;
    
    while ((index = replaced_str.find(old_str)) != std::string::npos) {
        replaced_str.replace(index, new_str.length(), new_str);
    }

    return replaced_str;
}