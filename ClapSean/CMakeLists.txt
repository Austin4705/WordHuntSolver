cmake_minimum_required(VERSION 3.16.5)
project(ClapSean)

set(CMAKE_CXX_STANDARD 20)


include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(ClapSean main.cpp permutation.cpp permutation.h fileReader.cpp fileReader.h trie.cpp trie.h node.cpp node.h)

target_link_libraries(ClapSean gtest_main)
add_test(NAME example_test COMMAND ClapSean)