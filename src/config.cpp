#include "config.hpp"

st_service_config service_config;

void read_config_file(const char* _filename, st_service_config &_config)
{
  boost::property_tree::ptree tree;
  boost::property_tree::ini_parser::read_ini(_filename,tree);
  _config.dbhost_address =  tree.get<std::string>("service.dbhost");
  _config.dbhost_port = tree.get<std::string>("service.dbport");
  _config.dbuser = tree.get<std::string>("service.dbuser");
  _config.dbpassword = tree.get<std::string>("service.dbpassword");
  _config.dbdatabase = tree.get<std::string>("service.dbdatabase");
  _config.dbtable = tree.get<std::string>("service.dbtable");
  _config.service_port = tree.get<std::string>("service.service_port");
  _config.query_begin = tree.get<std::string>("service.query_begin");
  _config.query_end = tree.get<std::string>("service.query_end");
}

