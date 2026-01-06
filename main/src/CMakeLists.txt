# src/CMakeLists.txt

# Crée une librairie à partir du code C
file(GLOB ALL_C_SOURCES
    "*.c"
    "utils/*.c"
    "ui/term/*.c"
)
# exclude main.c
list(REMOVE_ITEM ALL_C_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.c")
# add files
add_library(core ${ALL_C_SOURCES})

# Indiquer où trouver les headers (attention pas de relatif
# car multi-point de vue de compilation ici)
target_include_directories(core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

