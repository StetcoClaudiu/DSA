cmake_minimum_required(VERSION 3.5.0)
project(L3 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(L3 App.cpp ExtendedTest.cpp ExtendedTest.h ShortTest.cpp ShortTest.h SortedSet.cpp SortedSet.h SortedSetIterator.cpp SortedSetIterator.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
