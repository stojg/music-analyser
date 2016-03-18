cmake_minimum_required(VERSION 3.2)
project(music-analyser)

set(ENV{PATH} "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Users/stojg/go1.6/bin:/Users/stojg/Code/golang/bin:/Users/stojg/bin:/Users/stojg/go1.6/bin:/Users/stojg/Code/golang/bin:/Users/stojg/bin")
set(PLATFORMIO_CMD "/usr/local/bin/platformio")

include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/variants/standard")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/cores/arduino")
include_directories("$ENV{HOME}/Code/music-analyser/lib/FastLED")
include_directories("$ENV{HOME}/Code/music-analyser/lib/FastLED/lib8tion")
include_directories("$ENV{HOME}/Code/music-analyser/lib/FastLED/platforms/arm/common")
include_directories("$ENV{HOME}/Code/music-analyser/lib/FastLED/platforms/arm/d21")
include_directories("$ENV{HOME}/Code/music-analyser/lib/FastLED/platforms/arm/k20")
include_directories("$ENV{HOME}/Code/music-analyser/lib/FastLED/platforms/arm/kl26")
include_directories("$ENV{HOME}/Code/music-analyser/lib/FastLED/platforms/arm/nrf51")
include_directories("$ENV{HOME}/Code/music-analyser/lib/FastLED/platforms/arm/sam")
include_directories("$ENV{HOME}/Code/music-analyser/lib/FastLED/platforms/arm/stm32")
include_directories("$ENV{HOME}/Code/music-analyser/lib/FastLED/platforms/avr")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Audio/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Bridge/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/EEPROM")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Esplora/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Ethernet/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Firmata")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/GSM/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/HID")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Keyboard/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/LiquidCrystal/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Mouse/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/RobotIRremote/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Robot_Control/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Robot_Motor/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/SD/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/SPI")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Scheduler/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Servo/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/SoftwareSerial")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/SpacebrewYun/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Stepper/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/TFT/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Temboo/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/USBHost/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/WiFi/src")
include_directories("$ENV{HOME}/.platformio/packages/framework-arduinoavr/libraries/Wire")
include_directories("$ENV{HOME}/.platformio/packages/toolchain-atmelavr/avr/include")
include_directories("$ENV{HOME}/.platformio/packages/toolchain-atmelavr/bfd/include")
include_directories("$ENV{HOME}/.platformio/packages/toolchain-atmelavr/lib/gcc/avr/4.8.1/include")
include_directories("$ENV{HOME}/.platformio/packages/toolchain-atmelavr/lib/gcc/avr/4.8.1/include-fixed")

add_definitions(-DF_CPU=16000000L)
add_definitions(-DARDUINO_ARCH_AVR)
add_definitions(-DARDUINO_AVR_UNO)
add_definitions(-DARDUINO=10607)
add_definitions(-DPLATFORMIO=020804)
add_definitions(-D__AVR_ATmega328P__)

add_custom_target(
    PLATFORMIO_BUILD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOAD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_CLEAN ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target clean
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_PROGRAM ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target program
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOADFS ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target uploadfs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPDATE_ALL ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion update
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

#
# To enable code auto-completion, please specify path
# to main source file (*.c, *.cpp) and uncomment line below
#
add_executable(music-analyser src/main.cpp)
