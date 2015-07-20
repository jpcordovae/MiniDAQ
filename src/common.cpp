#include "common.hpp"

std::string timestamp_sql()
{
    // Get current time, as an example
    boost::posix_time::ptime dt = boost::posix_time::microsec_clock::universal_time();

    // Create a time_zone_ptr 'for the desired time zone and use it to create a local_date_time
    boost::local_time::time_zone_ptr zone(new boost::local_time::posix_time_zone("GMT-3"));
    boost::local_time::local_date_time dt_with_zone(dt, zone);
    std::stringstream strm;

    // Set the formatting facet on the stringstream and print the local_date_time to it.
    // Ownership of the boost::local_time::local_time_facet object goes to the created std::locale object.
    strm.imbue(std::locale(std::cout.getloc(), new boost::local_time::local_time_facet("%Y-%m-%d %H:%M:%S UTC%Q")));
    strm << dt_with_zone;

    // Print the stream's content to the console
    //cout << strm.str() << endl;
    return strm.str();
}
