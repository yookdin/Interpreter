//
//  Address.hpp
//  Mock_SIP_Server
//
//  Created by Yuval Dinari on 12/23/15.
//  Copyright © 2015 Vonage. All rights reserved.
//

#ifndef Address_hpp
#define Address_hpp

#include <string>
using namespace std;


//==========================================================================================================
//==========================================================================================================
class Address
{
public:
    Address(){}
    Address(string _ip, int _port): ip(_ip), port(_port) {};
    bool is_complete() const { return (not ip.empty() && port > 0); }
    bool is_full() const { return not ip.empty() and port != -1; }
    
    bool operator==(const Address& other) { return (ip == other.ip && port == other.port); }
    bool operator!=(const Address& other) { return not (*this == other); };
    Address operator+(int i) const { return Address(ip, port+i); }
    string to_string() const { return (ip + ":" + std::to_string(port)); }
    
    string ip;
    int port = -1;
};


#endif /* Address_hpp */
