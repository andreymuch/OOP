# CMake generated Testfile for 
# Source directory: F:/Dokument/program/CPP/OOP/lab4
# Build directory: F:/Dokument/program/CPP/OOP/build/lab4
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Lab4Test "F:/Dokument/program/CPP/OOP/build/lab4/Debug/lab4_test.exe")
  set_tests_properties(Lab4Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab4/CMakeLists.txt;12;add_test;F:/Dokument/program/CPP/OOP/lab4/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Lab4Test "F:/Dokument/program/CPP/OOP/build/lab4/Release/lab4_test.exe")
  set_tests_properties(Lab4Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab4/CMakeLists.txt;12;add_test;F:/Dokument/program/CPP/OOP/lab4/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Lab4Test "F:/Dokument/program/CPP/OOP/build/lab4/MinSizeRel/lab4_test.exe")
  set_tests_properties(Lab4Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab4/CMakeLists.txt;12;add_test;F:/Dokument/program/CPP/OOP/lab4/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Lab4Test "F:/Dokument/program/CPP/OOP/build/lab4/RelWithDebInfo/lab4_test.exe")
  set_tests_properties(Lab4Test PROPERTIES  _BACKTRACE_TRIPLES "F:/Dokument/program/CPP/OOP/lab4/CMakeLists.txt;12;add_test;F:/Dokument/program/CPP/OOP/lab4/CMakeLists.txt;0;")
else()
  add_test(Lab4Test NOT_AVAILABLE)
endif()
