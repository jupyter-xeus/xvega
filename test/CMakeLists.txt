# Copyright (c) 2020, QuantStack and XVega Contributors
#
# Distributed under the terms of the BSD 3-Clause License.
#
# The full license is in the file LICENSE, distributed with this software.

cmake_minimum_required(VERSION 3.8)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    project(xvega-test)

    find_package(xvega REQUIRED CONFIG)
    set(XVEGA_INCLUDE_DIR ${xvega_INCLUDE_DIRS})
endif ()

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting tests build type to Release")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
else()
    message(STATUS "Tests build type is ${CMAKE_BUILD_TYPE}")
endif()

string(TOUPPER "${CMAKE_BUILD_TYPE}" U_CMAKE_BUILD_TYPE)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR (CMAKE_CXX_COMPILER_ID MATCHES "Intel" AND NOT WIN32))
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-parameter -Wextra -Wreorder -Wconversion -Wsign-conversion")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wold-style-cast -Wunused-variable -ftemplate-backtrace-limit=0")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${_cxx_std_flag} /MP /bigobj")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFEST:NO")
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  add_definitions(-D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  if(NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-parameter -Wextra -Wreorder -Wconversion -Wsign-conversion")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wold-style-cast -Wunused-variable")
  else() # We are using clang-cl
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFEST:NO")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING)
  endif()
else()
  message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

find_package(doctest REQUIRED)
find_package(Threads)

set(XVEGA_TESTS
    main.cpp
    test_marks.cpp
    test_encodings.cpp
    test_view_compositions.cpp
    test_transformations.cpp
    test_configurations.cpp
    test_selections.cpp
    test_data.cpp
)

foreach(filename IN LISTS XVEGA_TESTS)
    string(REPLACE ".cpp" "" targetname ${filename})
    add_executable(${targetname} ${filename} main.cpp ${XVEGA_HEADERS})
    target_include_directories(${targetname} PRIVATE ${XVEGA_INCLUDE_DIR})
    target_compile_features(${targetname} PRIVATE cxx_std_17)
    target_link_libraries(${targetname} PRIVATE xvega doctest::doctest Threads::Threads)
    add_custom_target(
        x${targetname}
        COMMAND ${targetname}
        DEPENDS ${targetname} ${filename} ${XVEGA_HEADERS})
endforeach()

add_executable(test_xvega_lib ${XVEGA_TESTS} ${XVEGA_HEADERS})

target_include_directories(test_xvega_lib PRIVATE ${XVEGA_INCLUDE_DIR})
target_compile_features(test_xvega_lib PRIVATE cxx_std_17)
target_link_libraries(test_xvega_lib PRIVATE xvega doctest::doctest Threads::Threads)

add_custom_target(xtest COMMAND test_xvega_lib DEPENDS test_xvega_lib)
