#ifndef JAHAC_NETWORK_TCPSOCKET_H
#define JAHAC_NETWORK_TCPSOCKET_H

#include <memory>

#include <winsock2.h>

namespace jahac {
namespace convert {


class CTCPSocket;
class CSocketAddress;
using TCP_SOCKET_SHARED_PTR = std::shared_ptr<CTCPSocket>;

class CTCPSocket
{
    friend class CSocketUtil;
public:
    int Connect(const CSocketAddress& address);
    int Bind(const CSocketAddress& toAddress);
    int Listen(int log);
    TCP_SOCKET_SHARED_PTR Accept(CSocketAddress& fromAddress);

    int64_t Send(const void* data, std::size_t len);
    int64_t Receive(void* buffer, std::size_t len);

private:
    CTCPSocket(const SOCKET socket) : socket_(socket) { }
    SOCKET socket_;
};


}}

#endif // JAHAC_NETWORK_TCPSOCKET_H
