# CMake generated Testfile for 
# Source directory: F:/Dokument/program/CPP/OOP/lab3
# Build directory: F:/Dokument/program/CPP/OOP/build/lab3
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Lab3Test "F:/Dokument/program/CPP/OOP/build/lab3/Debug/lab3.exe")
  set_tests_properties(Lab3Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab3/CMakeLists.txt;16;add_test;F:/Dokument/program/CPP/OOP/lab3/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Lab3Test "F:/Dokument/program/CPP/OOP/build/lab3/Release/lab3.exe")
  set_tests_properties(Lab3Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab3/CMakeLists.txt;16;add_test;F:/Dokument/program/CPP/OOP/lab3/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Lab3Test "F:/Dokument/program/CPP/OOP/build/lab3/MinSizeRel/lab3.exe")
  set_tests_properties(Lab3Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab3/CMakeLists.txt;16;add_test;F:/Dokument/program/CPP/OOP/lab3/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Lab3Test "F:/Dokument/program/CPP/OOP/build/lab3/RelWithDebInfo/lab3.exe")
  set_tests_properties(Lab3Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab3/CMakeLists.txt;16;add_test;F:/Dokument/program/CPP/OOP/lab3/CMakeLists.txt;0;")
else()
  add_test(Lab3Test NOT_AVAILABLE)
endif()
