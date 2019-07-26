#ifndef JAHAC_UTILITY_ARRAYSIZE_H
#define JAHAC_UTILITY_ARRAYSIZE_H

#include <cstddef>

namespace jahac {
namespace arraysize {


#define JAHAC_ARRAY_SZIE(x)          (*(&x + 1) - x)
#define JAHAC_ARRAY_SIZE_INNER(x)    (sizeof(x) / sizeof(x[0]))
#define JAHAC_ARRAY_SIZE_VIRTUOSO(x) (1[&x] - x) // example: for (int* p = x; p < 1[&x]; ++p)

// Ref: <<Effective Modern C++>>
template<typename T, std::size_t N>
constexpr std::size_t ArraySize(T (&)[N]) noexcept
{
    return N;
}


}}

#endif // JAHAC_UTILITY_ARRAYSIZE_H
