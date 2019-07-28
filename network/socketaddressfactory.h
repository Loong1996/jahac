#ifndef JAHAC_NETWORK_SOCKETADDRESSFACTORY_H
#define JAHAC_NETWORK_SOCKETADDRESSFACTORY_H

#include <string>

#include "network/socketaddress.h"

namespace jahac {
namespace network {


class CSocketAddressFactory
{
public:
    static SOCKET_ADDRESS_SHARED_PTR CreateIPv4FromString(const std::string& address);
};


}}

#endif // JAHAC_NETWORK_SOCKETADDRESSFACTORY_H
