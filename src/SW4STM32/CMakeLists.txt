add_library(Startup OBJECT
    startup_stm32f746xx.s
)
set(CPU_FLAGS "-x assembler-with-cpp ${CPU_FLAGS}")
