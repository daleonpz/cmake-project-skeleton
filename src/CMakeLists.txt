function(include_common_directories target_name)
    target_include_directories(${target_name} PRIVATE
            ${CMAKE_SOURCE_DIR}/src/External/Drivers/CMSIS/Device/ST/STM32F7xx/Include/
            ${CMAKE_SOURCE_DIR}/src/External/Drivers/STM32F7xx_HAL_Driver/Inc/
            ${CMAKE_SOURCE_DIR}/src/External/Drivers/BSP/STM32746G-Discovery/
            ${CMAKE_SOURCE_DIR}/src/External/Drivers/BSP/Components/Common
            ${CMAKE_SOURCE_DIR}/src/External/Drivers/BSP/Components
            ${CMAKE_SOURCE_DIR}/src/External/Middlewares/ST/STemWin/inc/
            ${CMAKE_SOURCE_DIR}/src/External/Utilities
            ${CMAKE_SOURCE_DIR}/src/External/Utilities/Fonts
            ${CMAKE_SOURCE_DIR}/src/Core/Inc
            ${CMAKE_SOURCE_DIR}/src/External/STemWin/Target
            ${CMAKE_SOURCE_DIR}/src/External/Drivers/CMSIS/Include/
        )
endfunction()

add_subdirectory(Core)
add_subdirectory(External)
add_subdirectory(SW4STM32)
