# tests_v2_cpp/CMakeLists.txt

# Ajouter GoogleTest comme dépendance locale
add_subdirectory(
    ${CMAKE_SOURCE_DIR}/dependencies/googletest
    googletest_build
)

# Crée l’exécutable de test
add_executable(test_app
    test_stack.cpp
    lang/test_unsigned_int.cpp
)

# Lier la librairie du projet et GoogleTest
target_link_libraries(test_app
    PRIVATE
        core
        GTest::gtest_main
)

# Déplacer les sorties dans le répertoire dédié
set_target_properties(test_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_SOURCE_DIR}/dependencies/CTest/bin
)

# Enregistrement des tests pour CTest
include(GoogleTest)
gtest_discover_tests(test_app)
