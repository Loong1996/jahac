#ifndef JAHAC_NETWORK_TCPSOCKET_H
#define JAHAC_NETWORK_TCPSOCKET_H

#include <memory>

#include <winsock2.h>

namespace jahac {
namespace network {


class CTCPSocket;
class CSocketAddress;
using TCP_SOCKET_SHARED_PTR = std::shared_ptr<CTCPSocket>;

class CTCPSocket
{
    friend class CSocketUtil;
public:
    ~CTCPSocket();

    int Connect(const CSocketAddress& address);
    int Bind(const CSocketAddress& bindAddress);
    int Listen(int backlog);
    TCP_SOCKET_SHARED_PTR Accept(CSocketAddress& fromAddress);

    int32_t Send(const void* data, std::size_t len);
    int32_t Receive(void* buffer, std::size_t len);

private:
    CTCPSocket(const SOCKET socket) : socket_(socket) { }
    SOCKET socket_;
};


}}

#endif // JAHAC_NETWORK_TCPSOCKET_H
