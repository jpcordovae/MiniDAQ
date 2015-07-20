#ifndef __GPSDB__HPP__
#define __GPSDB__HPP__

// std includes
#include <string>
#include <fstream>
#include <iostream>

/* MySQL Connector/C++ specific headers */
#include "cppconn/driver.h"
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/metadata.h>
#include <cppconn/resultset_metadata.h>
#include <cppconn/exception.h>
#include <cppconn/warning.h>

// mysql includes
#include "mysql_driver.h"
#include "mysql_connection.h"

class CDatabase
{
private:
   bool isConnected;
   std::string hostname;
   std::string username;
   std::string password; //TODO: encrypt this
   std::string database;
   sql::Driver *sql_driver;
   sql::Connection *sql_connection;
   sql::Statement *sql_statement;
   sql::Statement *sql_statement_insert;
   sql::ResultSet *sql_resultset;
   sql::PreparedStatement *sql_preparedstatement;
   sql::Savepoint *sql_savepoint;
   std::string log_file_name;
   std::fstream log_file;

   void local_log(char *);

public:
   CDatabase();
   ~CDatabase();

   typedef boost::shared_ptr<CDatabase> CDatabase_ptr;

   bool connect(void);
   bool disconnect(void);
   bool is_connected(void);

   //set
   void set_hostname(std::string _hostname);
   void set_username(std::string _username);
   void set_password(std::string _password);
   void set_database(std::string _database);

   // get
   std::string get_hostname() { return hostname; }
   std::string get_username() { return username; }
   std::string get_password() { return password; }
   std::string get_database() { return database; }

   sql::ResultSet *getSQLQuery(std::string _str){
      return sql_statement->executeQuery(_str);
   }

   int insert(const std::string &_str);// return rows updated

};

extern CDatabase *DB;
typedef CDatabase::CDatabase_ptr CDatabase_ptr;

#endif
