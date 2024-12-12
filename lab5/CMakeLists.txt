project(Lab5)


set(SRC_FILES
    src/main.cpp
)
add_executable(lab5 ${SRC_FILES})
add_executable(lab5_test test_main.cpp)
target_link_libraries(lab5)
target_link_libraries(lab5_test gtest gtest_main)

add_test(NAME Lab5Test COMMAND lab5_test)
set(ENV{LC_ALL} "en_US.UTF-8")
set(ENV{LANG} "en_US.UTF-8")
