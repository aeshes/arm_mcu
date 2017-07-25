_stack_base = 0x20002000;

ENTRY(main)

MEMORY
{
	FLASH (RX)   : ORIGIN = 0x08000000, LENGTH = 128K
	SRAM  (WAIL) : ORIGIN = 0x20000000, LENGTH = 8K
}

SECTIONS
{
	.text : { *(.text*) } > FLASH
	.bss  : { *(.bss*)  } > SRAM
}
