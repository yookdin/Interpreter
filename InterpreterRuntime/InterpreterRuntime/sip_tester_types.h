//
//  sip_tester_types.h
//  SIPTester
//
//  Created by Yuval Dinari on 10/9/17.
//  Copyright © 2017 Yuk. All rights reserved.
//

#ifndef sip_tester_types_h
#define sip_tester_types_h

//==========================================================================================================
// Supported link layer type of a PCAP file.
//==========================================================================================================
enum PcapLinkLayerType {
    LINKTYPE_BSD_LOOPBACK = 0,
    LINKTYPE_ETHERNET     = 1
};


//==========================================================================================================
//==========================================================================================================
enum ProtocolKind {UDP, TCP, TLS};
string to_string(ProtocolKind kind);
ProtocolKind string_to_protocol_kind(string str);


//==========================================================================================================
// What to reset after a run is finished
//==========================================================================================================
enum class ResetKind {
    NO_RESET,           // Do reset anything
    HISTORY_ONLY,       // Reset the messages and calls history
    CONNECTION_ONLY,    // Reset the connection to the server|client
    ALL                 // Reset history and connection
};


//==========================================================================================================
// How verbose should a run be
//==========================================================================================================
enum class LogLevel {
    NOTHING,        // Do not print any default messages
    TITLES,         // Print script titles
    SIP_MESSAGES,   // Print SIP messages
    ALL             // Print everything
};


//==========================================================================================================
//==========================================================================================================
enum SIP_EntityKind {CLIENT, SERVER};


//==========================================================================================================
// For SIP messages
//==========================================================================================================
enum Direction {INCOMING, OUTGOING, ANY};
string to_string(Direction);
Direction string_to_direction(string direction_str);


//==========================================================================================================
//==========================================================================================================
enum AudioCodecType { OPUS, OPUS2, ISAC, ILBC, PCMU };


#endif /* sip_tester_types_h */
