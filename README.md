# 42 C++ Piscine (CPP Modules)

This repository contains my solutions for the C++ modules of the 42 school core curriculum. The primary goal of these modules is to introduce Object-Oriented Programming (OOP) concepts using the **C++98** standard.

## 📚 Modules Overview

The curriculum is divided into 10 progressive modules, each focusing on specific concepts of C++ and Object-Oriented Programming:

* **Module 00**: Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and basic OOP.
* **Module 01**: Memory allocation, pointers to members, references, switch statement.
* **Module 02**: Ad-hoc polymorphism, operator overloading, and Orthodox Canonical class form.
* **Module 03**: Inheritance.
* **Module 04**: Subtype polymorphism, abstract classes, interfaces.
* **Module 05**: Repetition and Exceptions.
* **Module 06**: C++ casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`).
* **Module 07**: C++ templates.
* **Module 08**: Templated containers, iterators, algorithms.
* **Module 09**: STL (Standard Template Library) in practice.

## 🛠️ Compilation & Usage

All projects are written in **C++98** and compile with `c++` or `g++` using the strict school flags:
```bash
-Wall -Wextra -Werror -std=c++98
```

To compile any exercise, navigate to its respective directory and run `make`:

```bash
cd "Module 00/ex00"
make
./megaphone "shhhhh... I think the students are asleep..."
```

Standard Makefile rules apply:
- `make` - Compiles the project.
- `make clean` - Removes object files.
- `make fclean` - Removes object files and the executable.
- `make re` - Recompiles the project from scratch.

## 📜 Rules & Constraints

- All code must comply strictly with the **C++98** standard.
- The use of external libraries (like Boost) is strictly forbidden.
- The use of the Standard Template Library (STL) is restricted until the final modules.
- From Module 02 onwards, every class must be designed in **Orthodox Canonical Form**, meaning they must explicitly include:
  1. Default constructor
  2. Copy constructor
  3. Copy assignment operator
  4. Destructor
- Memory management is crucial; no memory leaks are tolerated.

---
*This structure reflects the standard 42 curriculum requirements for the C++ branches.*