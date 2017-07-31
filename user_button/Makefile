# Processor type
PTYPE = STM32F10X_MD_VL

# Tool path
TOOLROOT=/usr/bin

# Library path
LIBROOT=./include

# Tools
CC=$(TOOLROOT)/arm-none-eabi-gcc
LD=$(TOOLROOT)/arm-none-eabi-ld
AR=$(TOOLROOT)/arm-none-eabi-ar
AS=$(TOOLROOT)/arm-none-eabi-as

# Code paths
DEVICE=$(LIBROOT)
CORE=$(LIBROOT)
PERIPH=$(LIBROOT)

# Compilation flags
CFLAGS+= -mcpu=cortex-m3 -mthumb

# Startup code
STARTUP = startup.o

# Object files
OBJS= startup.o main.o
OBJS+= system_stm32f10x.o stm32f10x_gpio.o stm32f10x_rcc.o

all: main

main: $(OBJS)
	$(LD) -T mem.ld $(OBJS) -o main.elf
	arm-none-eabi-objcopy main.elf main.bin -O binary

boot.o: boot.S
	$(AS) boot.S -o boot.o

startup.o: startup.c
	$(CC) -c $(CFLAGS) startup.c

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

stm32f10x_rcc.o: $(PERIPH)/stm32f10x_rcc.c
	$(CC) -c $(CFLAGS) $(PERIPH)/stm32f10x_rcc.c

stm32f10x_gpio.o: $(PERIPH)/stm32f10x_gpio.c
	$(CC) -c $(CFLAGS) $(PERIPH)/stm32f10x_gpio.c

system_stm32f10x.o: $(DEVICE)/system_stm32f10x.c
	$(CC) -c $(CFLAGS) $(DEVICE)/system_stm32f10x.c

install: main.bin
	st-flash erase
	st-flash write main.bin 0x08000000
clean:
	rm -rf *.o main.elf main.bin
