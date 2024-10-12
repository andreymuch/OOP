project(Lab1)

add_executable(lab1 src/main.cpp src/box_capacity.cpp test_main.cpp)

target_link_libraries(lab1 gtest gtest_main)

add_test(NAME Lab1Test COMMAND lab1)