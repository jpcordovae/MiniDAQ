#include "database.hpp"
#include "cppconn/exception.h"

CDatabase *DB;

CDatabase::CDatabase()
{
    log_file_name = "log_db.txt";
    isConnected = false;
    log_file.open(log_file_name.c_str(),std::fstream::in | std::fstream::out | std::fstream::app);
    if(!log_file.is_open())
    {
	std::cerr << "CZDataBase Error: can't open log file " << log_file_name << std::endl;
    }
}

CDatabase::~CDatabase()
{
    log_file.close();
}

bool CDatabase::connect()
{
    try
    {
	sql_driver = get_driver_instance();
	sql_connection = sql_driver->connect(hostname.c_str(),username.c_str(),password.c_str());
	//sql_connection->setAutoCommit(0);
	sql_connection->setSchema(database.c_str());
	sql_statement = sql_connection->createStatement();
    }catch(sql::SQLException &e)
    {
	std::cout << "ERROR: SQLException in " << __FILE__;
	std::cout << " (" << __func__<< ") on line " << __LINE__ << std::endl;
	std::cout << "ERROR: " << e.what();
	std::cout << " (MySQL error code: " << e.getErrorCode();
	std::cout << ", SQLState: " << e.getSQLState() << ")" << std::endl;
	
	if (e.getErrorCode() == 1047)
	{
	    /*
	      Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
	      Message: Unknown command
	    */
	    std::cout << "\nYour server does not seem to support Prepared Statements at all. ";
	    std::cout << "Perhaps MYSQL < 4.1?" << std::endl;
	}
	
	return false;
	
    }catch(std::runtime_error &e)
    {
	std::cout << "ERROR: runtime_error in " << __FILE__;
	std::cout << " (" << __func__ << ") on line " << __LINE__ << std::endl;
	std::cout << "ERROR: " << e.what() << std::endl;
	
	return false;
    }
    
    return true;
    
}

bool CDatabase::disconnect(void)
{
    return true;
}

void CDatabase::set_hostname(std::string _hostname)
{
    hostname = _hostname;
}

void CDatabase::set_username(std::string _username)
{
    username = _username;
}

void CDatabase::set_password(std::string _password)
{
    password = _password;
}

void CDatabase::set_database(std::string _database)
{
    database = _database;
}

void CDatabase::local_log(char *_msg)
{
    if(!log_file.is_open())
    {
	return;
    }

    log_file << _msg << std::endl; //TODO: put timestamp
}

bool CDatabase::is_connected(void)
{
    return isConnected;
}

int CDatabase::insert(const std::string& _str)
{
    sql_statement_insert = sql_connection->createStatement();
    int ret = sql_statement_insert->executeUpdate(_str.c_str());
    delete sql_statement_insert;
    return ret;
}
 
