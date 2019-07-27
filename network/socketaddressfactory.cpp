#include "socketaddressfactory.h"

#include <ws2tcpip.h>

namespace jahac {
namespace convert {


SOCKET_ADDRESS_SHARED_PTR CSocketAddressFactory::CreateIPv4FromString(const std::string& address)
{
    auto pos = address.find_last_of(':');
    std::string host, service;
    if(pos != std::string::npos)
    {
        host = address.substr(0, pos);
        service = address.substr(pos + 1);
    }
    else
    {
        host = address;
        //use default port...
        service = "0";
    }
    addrinfo hint;
    memset(&hint, 0, sizeof( hint ));
    hint.ai_family = AF_INET;

    addrinfo* result;
    int error = getaddrinfo(host.c_str(), service.c_str(), &hint, &result);
    if(error != 0 && result != nullptr)
    {
        // error
        return nullptr;
    }

    while(!result->ai_addr && result->ai_next)
    {
        result = result->ai_next;
    }

    if(!result->ai_addr)
    {
        return nullptr;
    }

    auto toRet = std::make_shared<CSocketAddress>(*result->ai_addr);

    freeaddrinfo(result);

    return toRet;
}


}}
