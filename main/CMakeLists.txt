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
