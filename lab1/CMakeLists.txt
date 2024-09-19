# Устанавливаем имя проекта для lab1
project(Lab1)

# Добавляем исполняемый файл для lab1
add_executable(lab1 src/main.cpp src/box_capacity.cpp test_main.cpp)

# Подключаем Google Test
target_link_libraries(lab1 gtest gtest_main)

# Добавляем тесты
add_test(NAME Lab1Test COMMAND lab1)