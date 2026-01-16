# main/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
project(MyProject C CXX)

# Langue standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Activer les tests
enable_testing()

# -------------------------
# Apply AddressSanitizer for debugging (buffer overflow / use-after-free)
# Note: detect_leaks=1 is NOT supported on macOS
# -------------------------
option(ENABLE_ASAN "Enable AddressSanitizer" ON)
if (ENABLE_ASAN)
    if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
        message(STATUS "macOS detected: ASan enabled (no leak detection)")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
    elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
        message(STATUS "Linux detected: ASan enabled (full support)")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g -fno-omit-frame-pointer")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -fno-omit-frame-pointer")
    endif()
else()
    message(STATUS "AddressSanitizer disabled")
endif()

# Ajouter le code source
add_subdirectory(src)
add_subdirectory(tests_v2_cpp)

# redirection des sorties dans le bon répertoire des dependencies 
set(CTEST_CUSTOM_TEST_OUTPUT_TRUNCATION "NONE")
set(CTEST_PARALLEL_LEVEL 4)

set(ENV{CTEST_OUTPUT_ON_FAILURE} 1)
set(ENV{CTEST_PROGRESS_OUTPUT} 0)

# end page
