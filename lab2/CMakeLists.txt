project(Lab2)

add_executable(lab2 src/main.cpp test_main.cpp)  

target_link_libraries(lab2 gtest gtest_main)


add_test(NAME Lab2Test COMMAND lab2)
set(ENV{LC_ALL} "en_US.UTF-8")
set(ENV{LANG} "en_US.UTF-8")
