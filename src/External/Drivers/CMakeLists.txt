add_library(Drivers OBJECT
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c
    STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.c
    BSP/STM32746G-Discovery/stm32746g_discovery.c
    BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c
)

include_common_directories(Drivers)
