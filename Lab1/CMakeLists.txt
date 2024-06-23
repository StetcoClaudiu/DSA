cmake_minimum_required(VERSION 3.5.0)
project(Lab1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Lab1 App.cpp ExtendedTest.cpp ExtendedTest.h FixedCapBiMap.cpp FixedCapBiMap.h FixedCapBiMapIterator.cpp FixedCapBiMapIterator.h ShortTest.cpp ShortTest.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
