#include <iostream>
#include <vector>

#include "utility/convert.h"
#include "utility/arraysize.h"
#include "utility/iddist.h"

#include "network/socketaddressfactory.h"
#include "network/socketutil.h"
#include "network/tcpsocket.h"
#include "network/socketaddress.h"

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
    idDist.RegisterId((std::numeric_limits<int>::max)()); // register id to max value
    cout << idDist.MallocId() << endl;                  // 0
    idDist.ResetId(1000);                               // reset id to 1000
    cout << idDist.GetCurId() << endl;                  // 1000
    cout << idDist.MallocId() << endl;                  // 1001

    // network
    using namespace jahac::network;
    CSocketUtil::StaticInit();

    TCP_SOCKET_SHARED_PTR tcpSocketPtr = CSocketUtil::CreateTCPSocket(E_SOCKET_ADDRESS_FAMILY::INET);
    SOCKET_ADDRESS_SHARED_PTR socketAddrPtr = CSocketAddressFactory::CreateIPv4FromString("192.168.1.10:9998");

    if (NO_ERROR != tcpSocketPtr->Bind(*socketAddrPtr))
    {
        cout << "bind fail" << endl;
    }

    if (NO_ERROR != tcpSocketPtr->Listen(1))
    {
        cout << "listen fail" << endl;
    }

    while(1)
    {
        TCP_SOCKET_SHARED_PTR newSocket = tcpSocketPtr->Accept(*socketAddrPtr);
        if (nullptr != newSocket)
        {
            cout << "new connect!" << endl;
        }

        Sleep(100);
    }

    socketAddrPtr.reset();
    tcpSocketPtr.reset();

    CSocketUtil::CleanUp();

    cout << "Hello World!" << endl;
    return 0;
}
