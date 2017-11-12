//
//  IP_Address.hpp
//  SIPTester
//
//  Created by Yuval Dinari on 4/9/17.
//  Copyright © 2017 Yuk. All rights reserved.
//

#ifndef IP_Address_hpp
#define IP_Address_hpp

#define MAX_IP_ADDRESS_STR_LENGTH 46

#include <netinet/in.h>
#include "sip_tester_utils.hpp"


union sockaddr_union
{
    sockaddr_in  ipv4;	// IPv4 transport address
    sockaddr_in6 ipv6;	// IPv6 transport address
};


//==========================================================================================================
//==========================================================================================================
class IP_Address
{
public:
    // Default constructor.
    IP_Address();
    
    // Copy constructor.
    IP_Address(const IP_Address &other);
    
    // Create an address from an struct sockaddr type.
    static IP_Address from_sockaddr(const sockaddr *sa);
    
    // Create an address from an IP address string.
    static IP_Address from_string(const char *str);
    
    // Create an address from an IP address string.
    static IP_Address from_string(const std::string & str);
        
    // Determine whether the address is a loopback address.
    bool is_loopback() const;
    
    // Determine whether the address is a multicast address.
    bool is_multicast() const;
    
    // Determine whether the address is unspecified.
    bool is_unspecified() const;
    
    // Determine whether the address is a link local address.
    bool is_link_local() const;
    
    // Get whether the address is an IP version 4 address.
    bool is_v4() const;
    
    // Get whether the address is an IP version 6 address.
    bool is_v6() const;
    
    // Assign from another address.
    IP_Address & operator=(const IP_Address &other);
    
    // Compare two addresses for equality.
    bool operator==(const IP_Address& a);
    bool operator==(const IP_Address& a) const;
    
    // Compare two addresses for inequality.
    bool operator!=(const IP_Address& a);
    
    // Get the address as a string.
    std::string to_string() const;
    
    // Get the address as a struct sockaddr.
    void to_sockaddr(sockaddr *sa) const;
    
private:
    int version = 0;
    sockaddr_union _addr;
};


#endif /* IP_Address_hpp */
