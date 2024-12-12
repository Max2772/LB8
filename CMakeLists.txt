cmake_minimum_required(VERSION 3.10)
project(LabWork7)

set(SOURCE_FILES main.cpp)

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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZER_FLAGS}")

add_executable(app main.cpp)

