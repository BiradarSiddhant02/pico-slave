cmake_minimum_required(VERSION 3.21)

include(src/pico_sdk_import.cmake)

project(pico-signal-slave)

pico_sdk_init()

add_executable(signal-slave
    src/main.c
    src/slave.c
    src/slave.h
)



target_include_directories(signal-slave PRIVATE src)  # Include src/ directory for header files

target_link_libraries(signal-slave pico_stdlib hardware_spi)

pico_enable_stdio_usb(signal-slave 1)
pico_enable_stdio_uart(signal-slave 0)

pico_add_extra_outputs(signal-slave)
