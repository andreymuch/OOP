cmake_minimum_required(VERSION 3.16)
project(OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1  
)


FetchContent_MakeAvailable(googletest)

enable_testing()


add_subdirectory(lab1)
add_subdirectory(lab2)
