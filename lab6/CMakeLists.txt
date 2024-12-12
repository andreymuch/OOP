project(Lab6)


set(SRC_FILES
    src/main.cpp
)
add_executable(lab6 ${SRC_FILES})
add_executable(lab6_test test/test_main.cpp)
target_link_libraries(lab6)
target_link_libraries(lab6_test gtest gtest_main)

add_test(NAME Lab6Test COMMAND lab6_test)
set(ENV{LC_ALL} "en_US.UTF-8")
set(ENV{LANG} "en_US.UTF-8")
