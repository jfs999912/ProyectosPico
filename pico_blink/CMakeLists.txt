cmake_minimum_required(VERSION 3.13)

# Inicializar Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico_blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(pico_blink
    main.c
)

# Enlazar bibliotecas estándar de la Pico
target_link_libraries(pico_blink pico_stdlib)

# Habilitar salida .uf2, .hex, .bin y deshabilitar salida por consola serial no usada
pico_add_extra_outputs(pico_blink)
