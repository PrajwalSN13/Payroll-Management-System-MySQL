#include "employee.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

void Employee::addEmployee(sql::Connection* con) {
    std::string fname, lname, dept, email;
    std::cout << "Enter First Name: ";
    std::cin >> fname;
    std::cout << "Enter Last Name: ";
    std::cin >> lname;
    std::cout << "Enter Department: ";
    std::cin >> dept;
    std::cout << "Enter Email: ";
    std::cin >> email;

    std::unique_ptr<sql::PreparedStatement> pstmt(
        con->prepareStatement("INSERT INTO employees(first_name,last_name,department,hire_date,email) VALUES (?,?,?,?,?)")
    );
    pstmt->setString(1, fname);
    pstmt->setString(2, lname);
    pstmt->setString(3, dept);
    pstmt->setString(4, "2025-08-26"); // placeholder hire_date
    pstmt->setString(5, email);
    pstmt->execute();

    std::cout << "Employee added successfully.\n";
}

void Employee::listEmployees(sql::Connection* con) {
    std::unique_ptr<sql::PreparedStatement> pstmt(
        con->prepareStatement("SELECT emp_id, first_name, last_name, email FROM employees")
    );
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    std::cout << "Employee Records:\n";
    while (res->next()) {
        std::cout << res->getInt("emp_id") << " - "
                  << res->getString("first_name") << " "
                  << res->getString("last_name") << " ("
                  << res->getString("email") << ")\n";
    }
}
