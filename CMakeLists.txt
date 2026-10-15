cmake_minimum_required(VERSION 3.20)

project(m32os LANGUAGES C)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_EXTENSIONS OFF)

add_library(m32os_core STATIC core/src/ring_buffer.c)

target_include_directories(m32os_core PUBLIC core/include)
add_executable(unit_tests tests/test_ring_buffer.c)
target_link_libraries(unit_tests PRIVATE m32os_core)
target_compile_options(m32os_core PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wshadow
    -Werror
)