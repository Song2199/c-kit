cmake_minimum_required(VERSION 3.16)
project(c-kit VERSION 0.1.0 LANGUAGES C)

# C11 standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compiler warnings - treat warnings as errors
add_compile_options(-Wall -Wextra -Werror -pedantic)

# Debug: enable AddressSanitizer and debug symbols
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
endif()

# Collect source files
file(GLOB CKIT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Main library target
add_library(ckit STATIC ${CKIT_SOURCES})
target_include_directories(ckit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Tests
enable_testing()
file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_*.c")
foreach(TEST_SRC ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SRC} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SRC})
    target_link_libraries(${TEST_NAME} ckit)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
