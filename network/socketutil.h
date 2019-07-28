#ifndef JAHAC_NETWORK_SOCKETUTIL_H
#define JAHAC_NETWORK_SOCKETUTIL_H

#include "network/tcpsocket.h"

namespace jahac {
namespace network {

enum class E_SOCKET_ADDRESS_FAMILY
{
    INET  = AF_INET,
    INET6 = AF_INET6
};


class CSocketUtil
{
public:
    static bool StaticInit();
    static void CleanUp();

    static int  GetLastError();

    static int  Select();

    static TCP_SOCKET_SHARED_PTR CreateTCPSocket(E_SOCKET_ADDRESS_FAMILY efamily);
};


}}

#endif // JAHAC_NETWORK_SOCKETUTIL_H
