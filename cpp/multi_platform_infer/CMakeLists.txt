cmake_minimum_required(VERSION 3.21)
project(infer_test)

set(CMAKE_CXX_STANDARD 17)

set(platform A)

if(${platform} STREQUAL "A")
    add_compile_definitions(INFER_IN_A)
elseif(${platform} STREQUAL "B")
    add_compile_definitions(INFER_IN_B)
else()
    message(FATAL_ERROR "platform is error" )
endif()

message(STATUS "platform is ${platform}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# sdk
set(SDK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third/${platform})
include_directories(${SDK_DIR}/original_infer)
include_directories(${SDK_DIR}/container_infer)

add_executable(${PROJECT_NAME} src/main.cpp)
