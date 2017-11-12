//
//  IP_Address.cpp
//  SIPTester
//
//  Created by Yuval Dinari on 4/9/17.
//  Copyright © 2017 Yuk. All rights reserved.
//

#include <arpa/inet.h>
#include "IP_Address.hpp"


//==========================================================================================================
//==========================================================================================================
IP_Address::IP_Address()
{
    memset(&_addr, 0, sizeof(sockaddr_union));
}


//==========================================================================================================
//==========================================================================================================
IP_Address::IP_Address(const IP_Address &other)
{
    memcpy(&_addr, &other._addr, sizeof(sockaddr_union));
    version = other.version;
}


//==========================================================================================================
//==========================================================================================================
IP_Address IP_Address::from_string(const char *str)
{
    IP_Address tmp;
    
    if (inet_pton(AF_INET, str, &tmp._addr.ipv4.sin_addr.s_addr) == 1)
    {
        tmp._addr.ipv4.sin_family = AF_INET;
        tmp.version = 4;
        return tmp;
    }
    else if(inet_pton(AF_INET6, str, &tmp._addr.ipv6.sin6_addr.s6_addr) == 1)
    {
        tmp._addr.ipv6.sin6_family = AF_INET6;
        tmp.version = 6;
        return tmp;
    }
    else
    {
        THROW << "Failed to create IP_Address from string: " << str;
    }
}


//==========================================================================================================
//==========================================================================================================
IP_Address IP_Address::from_string(const std::string & str)
{
    return from_string(str.c_str());
}


//==========================================================================================================
//==========================================================================================================
bool IP_Address::is_loopback() const
{
    if(is_v4())
    {
        return (_addr.ipv4.sin_addr.s_addr & 0x000000FF) == 0x0000007F;
    }
    else
    {
        return ((_addr.ipv6.sin6_addr.s6_addr[0] == 0) && (_addr.ipv6.sin6_addr.s6_addr[1] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[2] == 0) && (_addr.ipv6.sin6_addr.s6_addr[3] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[4] == 0) && (_addr.ipv6.sin6_addr.s6_addr[5] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[6] == 0) && (_addr.ipv6.sin6_addr.s6_addr[7] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[8] == 0) && (_addr.ipv6.sin6_addr.s6_addr[9] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[10] == 0) && (_addr.ipv6.sin6_addr.s6_addr[11] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[12] == 0) && (_addr.ipv6.sin6_addr.s6_addr[13] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[14] == 0) && (_addr.ipv6.sin6_addr.s6_addr[15] == 1));
    }
}


//==========================================================================================================
//==========================================================================================================
bool IP_Address::is_multicast() const
{
    if (is_v4())
    {
        return (_addr.ipv4.sin_addr.s_addr & 0x000000F0) == 0x000000E0;
    }
    else
    {
        return (_addr.ipv6.sin6_addr.s6_addr[0] == 0xff);
    }
}


//==========================================================================================================
//==========================================================================================================
bool IP_Address::is_unspecified() const
{
    if (is_v4())
    {
        return _addr.ipv4.sin_addr.s_addr == 0;
    }
    else
    {
        return ((_addr.ipv6.sin6_addr.s6_addr[0] == 0) && (_addr.ipv6.sin6_addr.s6_addr[1] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[2] == 0) && (_addr.ipv6.sin6_addr.s6_addr[3] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[4] == 0) && (_addr.ipv6.sin6_addr.s6_addr[5] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[6] == 0) && (_addr.ipv6.sin6_addr.s6_addr[7] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[8] == 0) && (_addr.ipv6.sin6_addr.s6_addr[9] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[10] == 0) && (_addr.ipv6.sin6_addr.s6_addr[11] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[12] == 0) && (_addr.ipv6.sin6_addr.s6_addr[13] == 0)
                && (_addr.ipv6.sin6_addr.s6_addr[14] == 0) && (_addr.ipv6.sin6_addr.s6_addr[15] == 0));
    }
}


//==========================================================================================================
//==========================================================================================================
bool IP_Address::is_link_local() const
{
    if (is_v4())
    {
        return (_addr.ipv4.sin_addr.s_addr & 0x0000FFFF) == 0x0000FEA9;
    }
    else
    {
        return ((_addr.ipv6.sin6_addr.s6_addr[0] == 0xFE)
                && (_addr.ipv6.sin6_addr.s6_addr[1] >= 0x80) && (_addr.ipv6.sin6_addr.s6_addr[1] < 0xc0));
    }
}


//==========================================================================================================
//==========================================================================================================
bool IP_Address::is_v4() const
{
    return (version == 4);
}


//==========================================================================================================
//==========================================================================================================
bool IP_Address::is_v6() const
{
    return (version == 6);
}


//==========================================================================================================
//==========================================================================================================
IP_Address & IP_Address::operator=(const IP_Address &other)
{
    memcpy(&_addr, &other._addr, sizeof(sockaddr_union));
    version = other.version;
    return *this;
}


//==========================================================================================================
//==========================================================================================================
bool IP_Address::operator==(const IP_Address& a)
{
    return (version == a.version and
            memcmp(&_addr, &a._addr, sizeof(sockaddr_union)) == 0);
}


//==========================================================================================================
//==========================================================================================================
bool IP_Address::operator==(const IP_Address& a) const
{
    return (version == a.version and
            memcmp(&_addr, &a._addr, sizeof(sockaddr_union)) == 0);
}


//==========================================================================================================
//==========================================================================================================
bool IP_Address::operator!=(const IP_Address& a)
{
    return not (*this == a);
}


//==========================================================================================================
//==========================================================================================================
std::string IP_Address::to_string() const
{
    char result[MAX_IP_ADDRESS_STR_LENGTH];
    
    if (is_v4())
    {
        inet_ntop(AF_INET, &_addr.ipv4.sin_addr.s_addr, result, sizeof(result));
    }
    else
    {
        inet_ntop(AF_INET6, &_addr.ipv6.sin6_addr.s6_addr, result, sizeof(result));
    }
    
    return string(result);
}


//==========================================================================================================
//==========================================================================================================
IP_Address IP_Address::from_sockaddr(const sockaddr *sa)
{
    char addr[MAX_IP_ADDRESS_STR_LENGTH];
    bzero(addr, sizeof(addr));
    
    if(sa->sa_family == AF_INET and
       inet_ntop(AF_INET, &((sockaddr_in *)sa)->sin_addr, addr, sizeof(addr)))
    {
        return IP_Address::from_string(addr);
    }
    else if(sa->sa_family == AF_INET6 &&
            inet_ntop(AF_INET6, &((sockaddr_in6 *)sa)->sin6_addr, addr, sizeof(addr)))
    {
        return IP_Address::from_string(addr);
    }
    
    THROW << "Failed creating IP_Address from scokaddr";
}


//==========================================================================================================
//==========================================================================================================
void IP_Address::to_sockaddr(sockaddr *sa) const
{
    memset(sa, 0, sizeof(*sa));
    
    if(is_v4())
    {
        inet_pton(AF_INET, to_string().c_str(), &((sockaddr_in *)sa)->sin_addr);
        ((sockaddr_in *)sa)->sin_family = AF_INET;
        ((sockaddr_in *)sa)->sin_port = _addr.ipv4.sin_port;
#ifdef __APPLE__
        ((sockaddr_in *)sa)->sin_len = sizeof(sockaddr_in);
#endif
    }
    else
    {
        inet_pton(AF_INET6, to_string().c_str(), &((sockaddr_in6 *)sa)->sin6_addr);
        ((sockaddr_in6 *)sa)->sin6_family = AF_INET6;
        ((sockaddr_in6 *)sa)->sin6_port = _addr.ipv6.sin6_port;
#ifdef __APPLE__
        ((sockaddr_in6 *)sa)->sin6_len = sizeof(sockaddr_in6);
#endif
    }
}

