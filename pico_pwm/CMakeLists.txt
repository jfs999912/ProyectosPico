cmake_minimum_required(VERSION 3.13)

# 1. Importar el SDK ANTES del project()
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico_pwm)

# 2. Inicializar el SDK INMEDIATAMENTE DESPUÉS del project()
pico_sdk_init()

# 3. Crear el ejecutable
add_executable(pico_pwm main.c)

# 4. Enlazar las librerías (incluyendo hardware_pwm)
target_link_libraries(pico_pwm pico_stdlib hardware_pwm)

# 5. Generar los archivos .uf2 y .bin (ahora sí reconocerá el comando)
pico_add_extra_outputs(pico_pwm)

