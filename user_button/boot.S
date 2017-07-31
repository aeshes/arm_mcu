.cpu cortex-m3
.thumb

.word stack_base	@ Stack base
.word ResetHandler 	@ Reset vector
.word hang		@ Eternal loop



.thumb_func
hang:	b .

/*.global hang*/
