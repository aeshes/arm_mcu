.cpu cortex-m3
.thumb

.word _stack_base
.word main
.word hang
.word hang

.thumb_func
hang: b .

.global hang
