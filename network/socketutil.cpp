#include "socketutil.h"


namespace jahac {
namespace network {

bool CSocketUtil::StaticInit()
{
#if _WIN32
    WSADATA wsaData;
    const int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (NO_ERROR != result)
    {

        return false;
    }
#endif

    return true;
}

void CSocketUtil::CleanUp()
{
#if _WIN32
    WSACleanup();
#endif
}

int CSocketUtil::GetLastError()
{
#if _WIN32
    return WSAGetLastError();
#else
    return errno;
#endif
}

TCP_SOCKET_SHARED_PTR CSocketUtil::CreateTCPSocket(E_SOCKET_ADDRESS_FAMILY efamily)
{
    SOCKET s = ::socket(static_cast<int>(efamily), SOCK_STREAM, IPPROTO_TCP);

    if (INVALID_SOCKET != s)
    {
        return TCP_SOCKET_SHARED_PTR(new CTCPSocket(s));
    }

    return nullptr;
}



}}
