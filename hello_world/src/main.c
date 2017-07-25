#define STM32F10X_LD

#include <stm32f10x.h>

int i = 0;
int off = 5;

void inc(void)
{
	i += off;
}

int main(void)
{
	while (1) inc();
}
