add_executable(Core
    Src/main.c
    Src/stm32f7xx_it.c
    Src/system_stm32f7xx.c
)

include_common_directories(Core)

target_link_libraries(Core PRIVATE
    $<TARGET_OBJECTS:STemWin>
    $<TARGET_OBJECTS:Middlewares>
    $<TARGET_OBJECTS:Drivers>
    $<TARGET_OBJECTS:Startup>
    ${CMAKE_CURRENT_SOURCE_DIR}/../External/Middlewares/ST/STemWin/Lib/STemWin_CM7_wc32.a
)

target_linker_map(Core)

# Apply unconditional private flags here
list(APPEND Core_private_compile_flags
	"-Wno-unknown-pragmas"
)

apply_supported_compiler_flags(C Core PRIVATE Core_private_compile_flags)

##################
# Add Custom Commands #
##################

add_custom_command(
    TARGET Core 
    POST_BUILD
    COMMAND ${SIZE} $<TARGET_FILE:Core>
)

add_custom_command(
    TARGET Core
    POST_BUILD
    COMMAND ${OBJCOPY} -O ihex $<TARGET_FILE:Core> Core.hex
    COMMAND ${OBJCOPY} -O binary $<TARGET_FILE:Core> Core.bin
    COMMENT "Building core.hex and core.bin"
)

