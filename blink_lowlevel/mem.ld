MEMORY
{
    ROM(RX)  : ORIGIN = 0x08000000, LENGTH = 128K
    RAM(RWX) : ORIGIN = 0x20000000, LENGTH = 8K
}

_stack_base = ORIGIN(RAM) + LENGTH(RAM);
_boot_checksum = 0 - (_stack_base + main + 1 + (hang + 1) * 5);

SECTIONS
{
    .text : { *(.text*) } > ROM
    .bss  : { *(.bss*) } > RAM
}