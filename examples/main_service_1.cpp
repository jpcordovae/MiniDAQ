#include <cstdlib>
#include <iostream>

#define VERSION "0.1"

#include "common.hpp"
#include "database.hpp"
#include "tcp_service.hpp"
#include "tcp_client.hpp"
#include <boost/thread.hpp>
#include "config.hpp"

CDatabase_ptr db_ptr = CDatabase_ptr(new CDatabase);

void demonize_process(void)
{
  //
}

void show_banner()
{
                      
  std::cout << " _____ ____    _     " << std::endl;
  std::cout << "|_   _|  _ \\  / \\    " << std::endl;
  std::cout << "  | | | | | |/ _ \\   " << std::endl;
  std::cout << "  | | | |_| / ___ \\  " << std::endl;
  std::cout << "  |_| |____/_/   \\_\\ " << std::endl;
  std::cout << "                     " << std::endl;
  std::cout << "TCP Data Acquisition " << std::endl;
  std::cout << "******************** " << std::endl;

}

void show_config()
{
  std::cout << "service port  : " << service_config.service_port << std::endl;
  std::cout << "mysql host    : " << service_config.dbhost_address << std::endl;
  std::cout << "mysql port    : " << service_config.dbhost_port << std::endl;
  std::cout << "mysql user    : " << service_config.dbuser << std::endl;
  std::cout << "mysql passwd  : " << service_config.dbpassword << std::endl;
  std::cout << "mysql database: " << service_config.dbdatabase << std::endl;
  std::cout << "mysql table   : " << service_config.dbtable << std::endl;
  std::cout << "query begin   : " << service_config.query_begin << std::endl;
  std::cout << "query end     : " << service_config.query_end << std::endl;
}

int main(int argc, char *argv[])
{
  show_banner();
  std::cout << "VERSION " << VERSION << std::endl;
  std::cout << "started at " <<  timestamp_sql() << std::endl;
  std::cout << "reading config file at " << argv[2] << std::endl;
  read_config_file(argv[2],service_config);
  show_config();
  
  try
    {
      if (argc <= 1)
	{
	  std::cerr << "Usage: tcp_service <config_file>\n";
	  return EXIT_FAILURE;
	}

      db_ptr->set_hostname(service_config.dbhost_address.c_str());
      db_ptr->set_username(service_config.dbuser.c_str());
      db_ptr->set_password(service_config.dbpassword.c_str());
      db_ptr->set_database(service_config.dbdatabase.c_str()); // for schema
      
      if(db_ptr->connect())
        {
	  std::cout << "connected to database " << db_ptr->get_database() << std::endl;
        }else
	{
	  std::cout << "problems openning database " << db_ptr->get_database() << " at host " << db_ptr->get_host() << std::endl;
	  exit(EXIT_FAILURE);
	}
      
      boost::asio::io_service io_service;
      
      server s(io_service, std::atoi(argv[1]));
      s.set_query_begin(service_config.query_begin);
      s.set_query_end(service_config.query_end);
      
      io_service.run();
      
    }catch (std::exception& e)
    {
      std::cerr << "Exception: " << e.what() << "\n";
    }
  
  string input_text;
  
  while(input_text.compare("quit"))
    {
      std::cin >> input_text;
      std::cout << "input: " << input_text << std::endl;
    }
  
  return EXIT_SUCCESS;
}
