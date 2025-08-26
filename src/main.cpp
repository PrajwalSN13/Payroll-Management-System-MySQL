#include "db.h"
#include "employee.h"
#include <iostream>

int main() {
    DB db("tcp://127.0.0.1:3306", "root", "yourpassword", "payroll_db");
    sql::Connection* con = db.getConnection();

    int choice;
    do {
        std::cout << "\n--- Payroll Management System ---\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. List Employees\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: Employee::addEmployee(con); break;
            case 2: Employee::listEmployees(con); break;
            case 3: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice.\n"; break;
        }
    } while(choice != 3);

    return 0;
}
