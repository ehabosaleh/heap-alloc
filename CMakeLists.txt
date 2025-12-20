cmake_minimum_required(VERSION 3.10)

project(heap_alloc C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(heap_alloc
    src/heap.c
)

target_include_directories(heap_alloc
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(test_heap
    examples/main.c
)

target_link_libraries(test_heap
    PRIVATE heap_alloc
)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(heap_alloc PRIVATE
        -Wall -Wextra -Wpedantic
    )
endif()

