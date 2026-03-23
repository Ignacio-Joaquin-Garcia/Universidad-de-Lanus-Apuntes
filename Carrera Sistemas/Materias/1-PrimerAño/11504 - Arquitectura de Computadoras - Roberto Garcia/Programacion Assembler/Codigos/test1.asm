#include <p16f84a.inc>

ORG 0x0000	;Configuramos donde la primera instruccion
bsf STATUS, RP0  ;Configuracion de registros Especiales (TRISA)
movlw b'00000000' ; Todo Salidas del trisA
movwf TRISA
movlw b'10000000'
movwf TRISB


bcf STATUS, RP0 ; Volvemos al flujo normal
movlw b'00001000'
movwf PORTA
movlw b'10000000'
movwf PORTB
END