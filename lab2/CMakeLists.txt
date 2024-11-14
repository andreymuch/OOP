project(Lab2)

add_executable(lab2 src/Money.cpp src/main.cpp)  
add_executable(lab2_test src/Money.cpp test_main.cpp)

target_link_libraries(lab2)
target_link_libraries(lab2_test gtest gtest_main) 

add_test(NAME Lab2Test COMMAND lab2_test)
set(ENV{LC_ALL} "en_US.UTF-8")
set(ENV{LANG} "en_US.UTF-8")
