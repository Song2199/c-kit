# c-kit

A lightweight, reusable C container library built from scratch.

## Overview

c-kit provides fundamental data structures (dynamic array, linked list, stack, queue, hash table) with a focus on:

- **Memory safety**: Verified with AddressSanitizer and Valgrind
- **Clean API design**: Uniform error codes, clear ownership semantics
- **Test coverage**: Every module has dedicated unit tests
- **Modern tooling**: CMake build, GitHub Actions CI

## Project Structure

    c-kit/
    ├── include/ckit/     # Public header files (.h)
    ├── src/              # Implementation files (.c)
    ├── tests/            # Unit tests (test_*.c)
    ├── docs/             # Documentation
    ├── CMakeLists.txt    # Build configuration
    └── README.md         # This file

## Build

Debug build (with AddressSanitizer):

    mkdir -p build && cd build
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    make -j16

Release build:

    cmake -DCMAKE_BUILD_TYPE=Release ..
    make -j16

## Run Tests

    cd build
    ctest --output-on-failure

## Compiler Flags

- -Wall -Wextra -Werror -pedantic (all warnings treated as errors)
- -fsanitize=address (AddressSanitizer in Debug builds)
- C11 standard

## Modules (Planned)

| Module | Description | Status |
|--------|-------------|--------|
| ckit_vector | Dynamic array | Planned |
| ckit_list | Singly linked list | Planned |
| ckit_stack | Stack (LIFO) | Planned |
| ckit_queue | Queue (FIFO) | Planned |
| ckit_hashmap | Hash table | Planned |

## References

- [antirez/kilo](https://github.com/antirez/kilo) - inspiration for code organization
- CS50x 2026 - C fundamentals
- Jacob Sorber - C / Systems Programming

## License

MIT License. See LICENSE for details.

