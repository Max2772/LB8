cmake_minimum_required(VERSION 3.10)

project(LabWork8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USE_ADDRESS_SANITIZER "Enable AddressSanitizer" OFF)
option(USE_THREAD_SANITIZER "Enable ThreadSanitizer" OFF)

if(USE_ADDRESS_SANITIZER AND USE_THREAD_SANITIZER)
    message(FATAL_ERROR "AddressSanitizer and ThreadSanitizer cannot be used together.")
elseif(USE_ADDRESS_SANITIZER)
    set(SANITIZER_FLAGS "-fsanitize=address")
elseif(USE_THREAD_SANITIZER)
    set(SANITIZER_FLAGS "-fsanitize=thread")
else()
    set(SANITIZER_FLAGS "")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZER_FLAGS}")

set(SRCS
    task1.cpp
    file_utils.cpp
    array_utils.cpp
    input.cpp
    logic.cpp
    output.cpp
    search_sort.cpp
    string_utils.cpp
    struct_input.cpp
    head.h
)

add_executable(app ${SRCS})
target_link_libraries(app PRIVATE pthread)

