# src/CMakeLists.txt

# Crée une librairie à partir du code C
file(GLOB CORE_SOURCES
    "*.c"
    "utils/*.c"
    "ui/term/*.c"
)
add_library(core ${CORE_SOURCES})

# Indiquer où trouver les headers (attention pas de relatif
# car multi-point de vue de compilation ici)
target_include_directories(core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

