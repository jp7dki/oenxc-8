cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(Pico_ePaper_Code)
pico_sdk_init()

set(FAMILY RP2040 CACHE INTERNAL "")
set(FAMILY_MCU RP2040 CACHE INTERNAL "")
set(CMAKE_BUILD_TYPE Debug)


# add a compilation subdirectory
add_subdirectory(fatfs)

# add a header directory
include_directories(fatfs)

include_directories(epd PRIVATE ${CMAKE_CURRENT_LIST_DIR})

# generate an executable file
add_executable(epd 
main.c
msc_disks.c
usb_descriptors.c
BME280.c
EPD_GDEY029T94.c
gps.c
)

# enable usb output, disable uart output
pico_enable_stdio_usb(epd 1)
pico_enable_stdio_uart(epd 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(epd)

target_link_libraries(epd pico_stdlib pico_multicore hardware_spi hardware_i2c tinyusb_device tinyusb_board hardware_flash hardware_sync hardware_rtc hardware_i2c fatfs)

pico_set_binary_type(epd copy_to_ram)