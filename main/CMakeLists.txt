# main/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
project(MyProject C CXX)

# Langue standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Activer les tests
enable_testing()

# Ajouter le code source
add_subdirectory(src)
add_subdirectory(tests_v2_cpp)

# redirection des sorties dans le bon répertoire des dependencies 
set(CTEST_CUSTOM_TEST_OUTPUT_TRUNCATION "NONE")
set(CTEST_PARALLEL_LEVEL 4)

set(ENV{CTEST_OUTPUT_ON_FAILURE} 1)
set(ENV{CTEST_PROGRESS_OUTPUT} 0)

find_package(GTest REQUIRED)
target_link_libraries(test_app PRIVATE core GTest::gtest_main)

