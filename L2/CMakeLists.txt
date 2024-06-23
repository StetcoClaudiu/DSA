cmake_minimum_required(VERSION 3.5.0)
project(L2 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(L2 App.cpp ExtendedTest.cpp ExtendedTest.h ShortTest.cpp ShortTest.h SortedBag.cpp SortedBag.h SortedBagIterator.cpp SortedBagIterator.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
