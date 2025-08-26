# Payroll Management System — C++ + MySQL (Work in Progress)

A console-based payroll system implemented in **C++** with **MySQL** as the database.  
This WIP version demonstrates database connectivity, a minimal menu, and basic employee operations.

## Repository Contents
- `main.cpp` – Console app skeleton (WIP).
- `db.hpp`, `db.cpp` – MySQL connection wrapper using MySQL Connector/C++.
- `schema.sql` – Database schema and sample rows.
- `CMakeLists.txt` – Simple CMake build script.
- `.gitattributes` – Ensures SQL is counted in GitHub language breakdown.

## Build (example)
- Install MySQL Server and MySQL Connector/C++.
- Create DB: run `schema.sql` in MySQL.
- Configure connector include/lib paths if needed, then:
  - `cmake -S . -B build`
  - `cmake --build build`
  - Run `./build/payroll`
