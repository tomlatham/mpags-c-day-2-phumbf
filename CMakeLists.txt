# - Main (Make buildscript for mpags-cipher)
# Comments in a (Make Script are lines beginning with a '#'

#Set (Make requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
# Do this to begin with to make it easy to see what the compiler command/flags are used.
# Can also be done by removing the 'set' command and running make as 'make VERBOSE=1'.
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Don't allow C++ Compiler Vendor Extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# - Use our standard set of flags if the GNU/Clang compilers are used
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")
endif()


# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher mpags-cipher.cpp MPAGSCipher/TransformChar.cpp MPAGSCipher/TransformChar.hpp MPAGSCipher/processCommandLine.hpp MPAGSCipher/processCommandLine.cpp MPAGSCipher/runCaesarCipher.hpp MPAGSCipher/runCaesarCipher.cpp)
target_include_directories(mpags-cipher PRIVATE MPAGSCipher)
target_compile_features(mpags-cipher PRIVATE cxx_auto_type cxx_uniform_initialization cxx_binary_literals)
