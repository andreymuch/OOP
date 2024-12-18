project(Lab7)


set(SRC_FILES
    src/main.cpp
)
add_executable(lab7 ${SRC_FILES})
add_executable(lab7_test test_main.cpp)
target_link_libraries(lab7)
target_link_libraries(lab7_test gtest gtest_main)

add_test(NAME Lab7Test COMMAND lab7_test)
set(ENV{LC_ALL} "en_US.UTF-8")
set(ENV{LANG} "en_US.UTF-8")
