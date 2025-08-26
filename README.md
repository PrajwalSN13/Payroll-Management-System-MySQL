# Payroll Management System (C++ + MySQL)

## Overview
The Payroll Management System is a **console-based application** built using **C++** and **MySQL**.  
It is designed to manage employee records, salaries, tax deductions, and payroll history.  
This project demonstrates integration of **C++ with MySQL (via MySQL Connector/C++)**, relational schema design, and implementation of core CRUD operations.

---

## Features
- Add, update, delete, and view employee records.
- Manage payroll runs including base salary, deductions, and net salary.
- Enforce relational constraints (foreign keys, unique emails).
- Modular, menu-driven C++ interface for user interaction.
- Parameterized SQL queries for secure and consistent operations.

---

## System Architecture
- **Application Layer (C++):** Implements menu-driven interface, user input handling, and payroll logic.  
- **Data Access Layer (C++):** `DB` wrapper class for MySQL connectivity and query execution using prepared statements.  
- **Database Layer (MySQL):** Schema with two main tables:
  - `employees` – stores employee details.
  - `payroll` – stores salary, deductions, and payroll history linked to employees.

---

## Database Schema
### Employees Table
| Column      | Type         | Constraints          |
|-------------|------------- |----------------------|
| emp_id      | INT          | PRIMARY KEY, AUTO_INCREMENT |
| first_name  | VARCHAR(50)  | NOT NULL             |
| last_name   | VARCHAR(50)  | NOT NULL             |
| department  | VARCHAR(50)  | NULLABLE             |
| hire_date   | DATE         | NOT NULL             |
| email       | VARCHAR(100) | UNIQUE               |

### Payroll Table
| Column      | Type          | Constraints              |
|-------------|-------------- |--------------------------|
| payroll_id  | INT           | PRIMARY KEY, AUTO_INCREMENT |
| emp_id      | INT           | FOREIGN KEY → employees(emp_id) |
| base_salary | DECIMAL(10,2) | NOT NULL                 |
| deductions  | DECIMAL(10,2) | DEFAULT 0                |
| net_salary  | DECIMAL(10,2) | NOT NULL                 |
| run_date    | DATE          | NOT NULL                 |

---

## Tech Stack
- **Language:** C++17  
- **Database:** MySQL 8.x  
- **Driver:** MySQL Connector/C++  
- **Build Tool:** CMake / g++ (Linux) or MSVC (Windows)  

---

## How to Run
1. Install **MySQL Server** and **MySQL Connector/C++**.
2. Run `schema.sql` to create the database and tables.
3. Update database credentials in `main.cpp` or `config.json`.
4. Build and run:
   ```bash
   cmake -S . -B build
   cmake --build build
   ./build/payroll
