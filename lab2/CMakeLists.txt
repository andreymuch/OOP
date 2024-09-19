# Указываем название проекта
project(Lab2)

# Создаём исполняемый файл для проекта lab2
add_executable(lab2 src/main.cpp test_main.cpp)  # test_main.cpp - файл с тестами

# Подключаем библиотеки Google Test
target_link_libraries(lab2 gtest gtest_main)

# Указываем, что это тесты
add_test(NAME Lab2Test COMMAND lab2)