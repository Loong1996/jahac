#include <iostream>
#include "utility/convert.h"
#include "utility/arraysize.h"

using namespace std;


int main()
{
    // arraysize
    int arry[3];
    cout << JAHAC_ARRAY_SZIE(arry)            << endl; // 3
    cout << JAHAC_ARRAY_SIZE_INNER(arry)      << endl; // 3
    cout << JAHAC_ARRAY_SIZE_VIRTUOSO(arry)   << endl; // 3
    cout << jahac::arraysize::ArraySize(arry) << endl; // 3

    // string convert
    cout << jahac::convert::StringConvert<int>("1234") << endl;


    cout << "Hello World!" << endl;
    return 0;
}
