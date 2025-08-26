#include "db.h"
#include <cppconn/exception.h>
#include <iostream>

DB::DB(const std::string &host, const std::string &user, const std::string &pass, const std::string &db) {
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(host, user, pass);
    con->setSchema(db);
    std::cout << "Connected to database successfully.\n";
}

DB::~DB() {
    delete con;
}

sql::Connection* DB::getConnection() {
    return con;
}
