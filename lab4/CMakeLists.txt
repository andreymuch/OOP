project(Lab4)


set(SRC_FILES
    src/main.cpp
)
add_executable(lab4 ${SRC_FILES})
add_executable(lab4_test test_main.cpp)
target_link_libraries(lab4)
target_link_libraries(lab4_test gtest gtest_main)

add_test(NAME Lab4Test COMMAND lab4_test)
set(ENV{LC_ALL} "en_US.UTF-8")
set(ENV{LANG} "en_US.UTF-8")
