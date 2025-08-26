#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <cppconn/connection.h>

class Employee {
public:
    static void addEmployee(sql::Connection* con);
    static void listEmployees(sql::Connection* con);
};

#endif
