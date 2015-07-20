#ifndef __GPS_BASE_HPP__
#define __GPS_BASE_HPP__

#include <iostream>
#include <ctime>
#include <vector>

#include <boost/date_time.hpp>
#include <boost/shared_ptr.hpp>

std::string timestamp_sql();

typedef std::vector<boost::uint8_t> buffertype;
typedef boost::shared_ptr<buffertype> buffertype_ptr;

// Multy-Bytes fields are transmitted in network byte ordening (BIG ENDIAN)

// Information Element Identifiers
#define MO_HEADER_IEI                0x01 // MO Header IEI
#define MO_PAYLOAD_IEI               0x02 // MO Payload IEI
#define MO_LOCATION_INFORMATION_EIE  0x03 // MO Location Information EIE
#define MO_CONFIRMATION_IEI          0x05 // MO Confirmation IEI



struct information_elements{
    boost::uint8_t IEI; // Information Element ID
    boost::uint16_t information_element_lenght;
    boost::uint8_t *IEC; // Information Element Contents
};

struct message {
    boost::uint8_t protocol_revision_number;
    boost::uint16_t overall_message_lenght;
    boost::uint8_t *IERM; // Information Elements Related to Messages
};



#endif

