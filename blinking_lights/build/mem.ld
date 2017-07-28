stack_base = 0x20001FFF;

ENTRY(reset_handler)

MEMORY
{
	FLASH (RX)   : ORIGIN = 0x08000000, LENGTH = 128K
	RAM   (WAIL) : ORIGIN = 0x20000000, LENGTH = 8K
}

SECTIONS
{
	.text :
	{
		KEEP(*(.isr_vectors))
		*(.text*)
		*(.rodata)
	} > FLASH

	lma_data_start  = .;
	.data : AT(lma_data_start)
	{	va_data_start = .;
		*(.data*)
		va_data_end   = .;
	} > RAM

	.bss :
	{
		va_bss_start = .;
		*(.bss*)
		va_bss_end   = .;
	} > RAM
}
