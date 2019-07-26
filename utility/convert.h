#ifndef JAHAC_UTILITY_CONVERT_H
#define JAHAC_UTILITY_CONVERT_H

#include <string>
#include <sstream>

namespace jahac {
namespace convert {


template<typename T>
static T StringConvert(const std::string& str)
{
    T t;
    std::stringstream ss(str);
    ss >> t;

    return t;
}

template<typename T>
static T StringConvert(const std::string& str, const T& default_value)
{
    T t;
    std::stringstream ss(str);
    if (ss >> t)
    {
        return t;
    }

    return default_value;
}


}}

#endif // JAHAC_UTILITY_CONVERT_H
