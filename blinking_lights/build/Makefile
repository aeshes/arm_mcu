# Processor type
PTYPE = STM32F10X_MD_VL

# Tool path
TOOLROOT=/usr/bin

# Library path
LIBROOT=/usr/stm32

# Tools
CC=$(TOOLROOT)/arm-none-eabi-gcc
LD=$(TOOLROOT)/arm-none-eabi-ld
AR=$(TOOLROOT)/arm-none-eabi-ar
AS=$(TOOLROOT)/arm-none-eabi-as

# Code paths
DEVICE=$(LIBROOT)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
CORE=$(LIBROOT)/Libraries/CMSIS/CM3/CoreSupport
PERIPH=$(LIBROOT)/Libraries/STM32F10x_StdPeriph_Driver

# Compilation flags
CFLAGS+= -mcpu=cortex-m3 -mthumb
CFLAGS+= -I$(DEVICE) -I$(CORE) -I$(PERIPH)/inc -I$(PERIPH)/src
CFLAGS+= -D"assert_param(expr)=((void)0)"
#CFLAGS+= -D$(PTYPE)

# Startup code
STARTUP = startup.o

# Object files
OBJS= $(STARTUP) main.o
#OBJS+= stm32f10x_gpio.o stm32f10x_rcc.o 

all: main

main: startup.o main.o
	$(LD) -T mem.ld $(OBJS) -o main.elf
	arm-none-eabi-objcopy main.elf main.bin -O binary

boot.o: boot.S
	$(AS) boot.S -o boot.o

startup.o: startup.c
	$(CC) -c $(CFLAGS) startup.c

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

install: main.bin
	st-flash erase
	st-flash write main.bin 0x08000000
clean:
	rm -rf *.o main.elf main.bin
