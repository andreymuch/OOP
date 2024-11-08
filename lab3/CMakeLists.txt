project(Lab3)


set(SRC_FILES
    src/Array.cpp
    src/Figure.cpp
    src/Pentagon.cpp
    src/Rhombus.cpp
    src/Trapezoid.cpp
    src/main.cpp
)
add_executable(lab3 ${SRC_FILES} test_main.cpp)

target_link_libraries(lab3 gtest gtest_main)

add_test(NAME Lab3Test COMMAND lab3)
set(ENV{LC_ALL} "en_US.UTF-8")
set(ENV{LANG} "en_US.UTF-8")
