.cpu cortex-m3
.thumb

.word 0x20002000	@ Stack base
.word main + 1 		@ Reset vector
.word hang		@ Eternal loop



.thumb_func
hang:	b .

/*.global hang*/
