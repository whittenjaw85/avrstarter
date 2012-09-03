#include <avr/io.h>

#define mp r16
#define d1 r17
#define d2 r18

.section .text
;Device: ATTiny85
;Hello World Program


.org 0x0000
rjmp main
reti	;INT_VECTOR_1
reti	;INT_VECTOR_2
reti	;INT_VECTOR_3
reti	;INT_VECTOR_4
reti	;INT_VECTOR_5
reti	;INT_VECTOR_6
reti	;INT_VECTOR_7
reti	;INT_VECTOR_8
reti	;INT_VECTOR_9
reti	;INT_VECTOR_10
reti	;INT_VECTOR_11
reti	;INT_VECTOR_12
reti	;INT_VECTOR_13
reti	;INT_VECTOR_14
reti	;INT_VECTOR_15

.global main 
main:
    ldi mp, 0xFF
    out _SFR_IO_ADDR(DDRB), mp
    nop		    ;synchronization
loop:
    sbi _SFR_IO_ADDR(PORTB), 4
    rcall delay
    cbi _SFR_IO_ADDR(PORTB), 4
    rcall delay
    rjmp loop
delay:
    ldi d1, 0xFF
d_loop1:
    ldi d2, 0xFF
d_loop2:
    dec d2
    brne d_loop2
    dec d1
    brne d_loop1
    ret
