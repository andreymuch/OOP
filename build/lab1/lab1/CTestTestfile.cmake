# CMake generated Testfile for 
# Source directory: F:/Dokument/program/CPP/OOP/lab1
# Build directory: F:/Dokument/program/CPP/OOP/build/lab1/lab1
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Lab1Test "F:/Dokument/program/CPP/OOP/build/lab1/lab1/Debug/lab1.exe")
  set_tests_properties(Lab1Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab1/CMakeLists.txt;7;add_test;F:/Dokument/program/CPP/OOP/lab1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Lab1Test "F:/Dokument/program/CPP/OOP/build/lab1/lab1/Release/lab1.exe")
  set_tests_properties(Lab1Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab1/CMakeLists.txt;7;add_test;F:/Dokument/program/CPP/OOP/lab1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Lab1Test "F:/Dokument/program/CPP/OOP/build/lab1/lab1/MinSizeRel/lab1.exe")
  set_tests_properties(Lab1Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab1/CMakeLists.txt;7;add_test;F:/Dokument/program/CPP/OOP/lab1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Lab1Test "F:/Dokument/program/CPP/OOP/build/lab1/lab1/RelWithDebInfo/lab1.exe")
  set_tests_properties(Lab1Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab1/CMakeLists.txt;7;add_test;F:/Dokument/program/CPP/OOP/lab1/CMakeLists.txt;0;")
else()
  add_test(Lab1Test NOT_AVAILABLE)
endif()
