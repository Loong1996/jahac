#include "tcpsocket.h"

#include<ws2tcpip.h>

#include "network/socketaddress.h"
#include "network/socketutil.h"

namespace jahac {
namespace network {


CTCPSocket::~CTCPSocket()
{
#if _WIN32
    closesocket(socket_);
#else
    close(socket_);
#endif
}

int CTCPSocket::Connect(const CSocketAddress& address)
{
    const int err = ::connect(socket_, &address.sockAddr_, address.GetSize());

    if (0 > err)
    {
        return -CSocketUtil::GetLastError();
    }

    return NO_ERROR;
}

int CTCPSocket::Bind(const CSocketAddress& bindAddress)
{
    const int err = ::bind(socket_, &bindAddress.sockAddr_, bindAddress.GetSize());
    if (0 != err)
    {
        return -CSocketUtil::GetLastError();
    }

    return NO_ERROR;
}

int CTCPSocket::Listen(int backlog)
{
    const int err = ::listen(socket_, backlog);
    if (0 > err)
    {
        return -CSocketUtil::GetLastError();
    }

    return NO_ERROR;
}

TCP_SOCKET_SHARED_PTR CTCPSocket::Accept(CSocketAddress &fromAddress)
{
    socklen_t len = fromAddress.GetSize();
    SOCKET socket = ::accept(socket_, &fromAddress.sockAddr_, &len);

    if (INVALID_SOCKET != socket)
    {
        return TCP_SOCKET_SHARED_PTR(new CTCPSocket(socket));
    }

    return nullptr;
}

int32_t CTCPSocket::Send(const void* data, std::size_t len)
{
    const int sendSizeCount = ::send(socket_, static_cast<const char*>(data), len, 0);
    if (0 > sendSizeCount)
    {
        return -CSocketUtil::GetLastError();
    }

    return sendSizeCount;
}

int32_t CTCPSocket::Receive(void *buffer, size_t len)
{
     const int recvSizeCount = ::recv( socket_,static_cast<char*>(buffer), len, 0);
    if(0 > recvSizeCount)
    {
        return -CSocketUtil::GetLastError();
    }

    return recvSizeCount;
}


}}
