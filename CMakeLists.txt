#----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.1)
project (exec)

#----------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#----------------------------------------------------------------------------
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

#----------------------------------------------------------------------------
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)
set(PROJECT_LINK_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "-Wall")
add_compile_options(${CMAKE_CXX_FLAGS})
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

#----------------------------------------------------------------------------
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(MyLibrary STATIC ${SOURCES})

#----------------------------------------------------------------------------
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

#----------------------------------------------------------------------------
target_link_libraries(${PROJECT_NAME} MyLibrary)

#----------------------------------------------------------------------------
enable_testing()
include (CTest)
add_test (MemTest exec)
#ctest -T memcheck


