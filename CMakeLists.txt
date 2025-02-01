# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Microcontrolador_Interrupcoes_tarefa C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Microcontrolador_Interrupcoes_tarefa Microcontrolador_Interrupcoes_tarefa.c
    ./lib/animacao_0.c
    ./lib/animacao_1.c 
    ./lib/animacao_2.c
    ./lib/animacao_3.c 
    ./lib/animacao_4.c 
    ./lib/animacao_5.c 
    ./lib/animacao_6.c
    ./lib/animacao_7.c 
    ./lib/animacao_8.c
    ./lib/animacao_9.c
    
    )

pico_set_program_name(Microcontrolador_Interrupcoes_tarefa "Microcontrolador_Interrupcoes_tarefa")
pico_set_program_version(Microcontrolador_Interrupcoes_tarefa "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Microcontrolador_Interrupcoes_tarefa 1)
pico_enable_stdio_usb(Microcontrolador_Interrupcoes_tarefa 1)

# Gera o arquivo de cabeçalho .pio.h a partir do código PIO
pico_generate_pio_header(Microcontrolador_Interrupcoes_tarefa ${CMAKE_CURRENT_LIST_DIR}/pio_matrix.pio)

# Add the standard library to the build
target_link_libraries(Microcontrolador_Interrupcoes_tarefa
    pico_stdlib
    hardware_pio
    hardware_adc
    
    )

# Add the standard include files to the build
target_include_directories(Microcontrolador_Interrupcoes_tarefa PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(Microcontrolador_Interrupcoes_tarefa 
        
        )

pico_add_extra_outputs(Microcontrolador_Interrupcoes_tarefa)

