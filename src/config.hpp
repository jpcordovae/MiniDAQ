#include <boost/property_tree/ini_parser.hpp>
#include <string>
#include <list>

struct st_service_config {
  std::string dbhost_address;
  std::string dbhost_port;
  std::string dbuser;
  std::string dbpassword;
  std::string dbdatabase;
  std::string dbtable;
  std::string service_port;
  std::string query_begin;
  std::string query_end;
};

extern st_service_config service_config;

void read_config_file(const char* _filename, st_service_config &_config);

