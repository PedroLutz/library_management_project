# Library Management System in C++

This is a thread-safe library management system, written in C++. It allows for registering, updating and removing books, with binary file persistence.

# Functionalities
- Interface via Terminal (simple and organized UI)
- All data stored in `std::vector`
- Books stored as `std::shared_ptr` to allow for safe dynamic memory management
- Automatic data persistence in binary file upon system shutdown
- Automatic logging in `.txt` file after every operation

## Tecnologies and Applied Concepts
- C++ Programming Language
- Dynamic memory allocation and deallocation using RAII
- File I/O in C++ (`std::iostream`)
- Synchronization with `std::mutex`
- Book genres implemented using the Factory Essential Pattern
- Logger implemented using the Singleton Essential Pattern

## How to run
***This system runs on Linux only.***
```bash
g++ *.cpp -o exe
./exe
```

## Tests and Validation
- Checked with `valgrind` to ensure no memory leaks
- Error cases handled with clear terminal messages

## Learnings
This project helped me apply both fundamental and advanced concepts in C++, with a focus on:
- Essential patterns (Singleton and Factory)
- RAII (applied in `std::lock_guard`, for example)
- Basic exceptions
- Thread-safe operations in C++

# Author
- **Pedro Guilherme Rosa Lutz**
- **Email: pedrolutz@protonmail.com**
- **LinkedIn: https://www.linkedin.com/in/pedro-lutz-4001ba221/**
- **Github: PedroLutz**

## Images
<img width="244" height="175" alt="main screen" src="https://github.com/user-attachments/assets/1b325e28-c237-4989-996a-3f81dc4f6eda" />
<img width="259" height="193" alt="book registering screen" src="https://github.com/user-attachments/assets/95a58ccc-1343-4747-9540-6e0680172e92" />
<img width="251" height="264" alt="book list" src="https://github.com/user-attachments/assets/f2f29e6b-335a-4e5a-9618-f9746e7cf345" />
<img width="532" height="200" alt="log" src="https://github.com/user-attachments/assets/d485557e-1234-4e91-9f82-c66bfb75955b" />
