arm-none-eabi-as ./src/startup.s -o ./build/startup.o
arm-none-eabi-gcc ./src/main.c -o ./build/main.o -I ./src/include/device -I ./src/include/core --specs=nosys.specs -mthumb -mcpu=cortex-m3 -O0 -c
pause