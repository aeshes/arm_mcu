#define STM32F10X_MD_VL

#include <stm32f10x.h>
#include <system_stm32f10x.h>
#include <system_stm32f10x.c>

extern unsigned long stack_base;
extern unsigned long lma_data_start;
extern unsigned long va_data_start;
extern unsigned long va_data_end;
extern unsigned long va_bss_start;
extern unsigned long va_bss_end;

extern int main(void);

void reset_handler(void)
{
	unsigned long *src, *dst;

	src = &lma_data_start;
	dst = &va_data_start;

	while (dst < &va_data_end)
		*dst++ = *src++;

	dst = &va_bss_start;
	while (dst < &va_bss_end)
		*dst++ = 0;

	SystemInit();
	main();
}

void default_handler(void)
{
	while (1)
	{
		/* Eternal loop */
	}
}

void SysTick_Handler(void)
 __attribute__((weak, alias("default_handler")));

__attribute__ ((section(".isr_vectors")))
void (* const interrupt_vector_table[])(void) =
{
	(void *) &stack_base,
	reset_handler,
	default_handler,
	default_handler,
	default_handler,
	default_handler,
	default_handler,
	0,
	0,
	0,
	0,
	default_handler,
	default_handler,
	0,
	default_handler,
	SysTick_Handler
};
