#ifndef DB_H
#define DB_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <string>

class DB {
private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
public:
    DB(const std::string &host, const std::string &user, const std::string &pass, const std::string &db);
    ~DB();
    sql::Connection* getConnection();
};

#endif
