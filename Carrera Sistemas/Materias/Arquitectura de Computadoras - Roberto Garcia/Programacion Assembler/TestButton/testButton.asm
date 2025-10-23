#INCLUDE <p16f84a.inc>
ORG 0X00

;Configuracion de los puertos del PIC
BSF STATUS, RP0
BSF TRISA, 0 ; Entrada Info
BCF TRISA, 1 ; Salida Led
BSF TRISB, 5 ; Entrada Info
BCF TRISB, 6 ; Salida Led
BCF STATUS, RP0

overflows EQU 0x20
preesc EQU 0x21
tmr0 EQU 0x22

;Codigo
checkButtons:
	;Check button TRISA
	BTFSC PORTA,0 ;Si boton apretado hace la instruccion de abajo sino no
	CALL prenderLedA
	BTFSS PORTA,0 ;Si boton NO esta apretado hace la instruccion de abajo sino no
	BCF PORTA,1 ;Apagar Led
	
	;Check button TRISB
	BTFSC PORTB,5 ;Si boton apretado hace la instruccion de abajo sino no
	CALL manejarLedB
	GOTO checkButtons

prenderLedA:
	BSF PORTA,1 ;Prender Led
	return
manejarLedB:
	BSF PORTB,6
	CALL delay2Segundos
	BCF PORTB,6 ;Apagar Led
	return
	
delay2Segundos:
	MOVLW d'30'
	MOVWF overflows
delayOverflow:
	MOVLW d'255'
	MOVWF preesc
delayPreesc:
	MOVLW d'255'
	MOVWF tmr0
delayTmr0:
	DECFSZ tmr0,f
	GOTO delayTmr0
	DECFSZ preesc,f
	GOTO delayPreesc
	DECFSZ overflows,f
	GOTO delayOverflow
	return

END