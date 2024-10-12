project(Lab2)

add_executable(lab2 src/main.cpp test_main.cpp)  

target_link_libraries(lab2 gtest gtest_main)


add_test(NAME Lab2Test COMMAND lab2)