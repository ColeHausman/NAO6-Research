cmake_minimum_required(VERSION 2.8)
project(cpp-reference-code)

find_package(qibuild)

# Create a executable named cpp-reference-code
# with the source file: main.cpp
qi_create_bin(main "main.cpp")

# Add a simple test:
qi_create_test(test "test.cpp")

qi_use_lib(main ALERROR ALPROXIES ALCOMMON) # required to use ALProxies
