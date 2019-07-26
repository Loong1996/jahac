#include <iostream>
#include "utility/convert.h"
#include "utility/arraysize.h"
#include "utility/iddist.h"

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
    cout << jahac::convert::StringConvert<int>("1234") << endl; // 1234

    // id dist
    jahac::iddist::CIdDist<int> idDist;
    cout << idDist.MallocId() << endl;                  // 1
    idDist.RegisterId(std::numeric_limits<int>::max()); // register id to max value
    cout << idDist.MallocId() << endl;                  // 0
    idDist.ResetId(1000);                               // reset id to 1000
    cout << idDist.GetCurId() << endl;                  // 1000
    cout << idDist.MallocId() << endl;                  // 1001



    cout << "Hello World!" << endl;
    return 0;
}
