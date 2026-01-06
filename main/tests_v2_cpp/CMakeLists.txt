# tests_v2_cpp/CMakeLists.txt

# Chercher GoogleTest (si installé sur le système)
find_package(GTest REQUIRED)
# Crée l’exécutable de test avec l'ensemble des fichiers
# qu'il faut lancer (les fichiers de tests)
add_executable(test_app
    test_stack.cpp
    test_unsigned_int.cpp
)
add_subdirectory(${CMAKE_SOURCE_DIR}/dependencies/googletest googletest_build)
# Lier la librairie et gtest
target_link_libraries(test_app
    PRIVATE
        core
        GTest::gtest_main
)
# déplacer les sorties dans le répertoire dédié
set_target_properties(test_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_SOURCE_DIR}/dependencies/CTest/bin
)

# Ajouter le test pour CTest
include(GoogleTest)
gtest_discover_tests(test_app)
