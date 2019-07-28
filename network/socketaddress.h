#ifndef JAHAC_NETWORK_SOCKETADDRESS_H
#define JAHAC_NETWORK_SOCKETADDRESS_H

#include <stdint.h>
#include <memory>

#include <winsock2.h>

namespace jahac {
namespace network {


class CSocketAddress;
using SOCKET_ADDRESS_SHARED_PTR = std::shared_ptr<CSocketAddress>;

class CSocketAddress
{
    friend class CUDPSocket;
    friend class CTCPSocket;
public:
    CSocketAddress(uint32_t address, uint16_t port)
    {
        this->GetSockAddrInRef().sin_family = AF_INET;
        this->GetIP4Ref() = htonl(address);
        this->GetSockAddrInRef().sin_port = htons(port);
    }

    CSocketAddress()
    {
        this->GetSockAddrInRef().sin_family = AF_INET;
        this->GetIP4Ref() = INADDR_ANY;
        this->GetSockAddrInRef().sin_port = 0;
    }

    CSocketAddress(const sockaddr& sockAddr)
    {
        memcpy(&sockAddr_, &sockAddr, sizeof(sockaddr));
    }

    uint32_t GetSize() const { return sizeof(sockAddr_); }

#if _WIN32
    uint32_t&       GetIP4Ref()       { return reinterpret_cast<uint32_t&>(this->GetSockAddrInRef().sin_addr.S_un.S_addr); }
    const uint32_t& GetIP4Ref() const { return reinterpret_cast<const uint32_t&>( this->GetSockAddrInRef().sin_addr.S_un.S_addr); }
#else

#endif

    sockaddr_in&       GetSockAddrInRef()       { return reinterpret_cast<sockaddr_in&>(sockAddr_); }
    const sockaddr_in& GetSockAddrInRef() const { return reinterpret_cast<const sockaddr_in&>(sockAddr_); }

private:
    sockaddr sockAddr_;
};


}}

#endif // JAHAC_NETWORK_SOCKETADDRESS_H
