# CMake generated Testfile for 
# Source directory: /home/bsp75/Desktop/Emulators/GB-Emulator-in-C
# Build directory: /home/bsp75/Desktop/Emulators/GB-Emulator-in-C/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(check_gbe "/home/bsp75/Desktop/Emulators/GB-Emulator-in-C/build/tests/check_gbe")
set_tests_properties(check_gbe PROPERTIES  _BACKTRACE_TRIPLES "/home/bsp75/Desktop/Emulators/GB-Emulator-in-C/CMakeLists.txt;96;add_test;/home/bsp75/Desktop/Emulators/GB-Emulator-in-C/CMakeLists.txt;0;")
subdirs("lib")
subdirs("gbemu")
subdirs("tests")
