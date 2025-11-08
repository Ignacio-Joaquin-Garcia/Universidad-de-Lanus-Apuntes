;Garcia Ignacio Joaquin - DNI:46940086 - Comision Jueves Turno Tarde
#include <p16f84a.inc>
ORG 0X00

BSF STATUS, RP0
	BCF TRISA,1
	BSF TRISA,3
	MOVLW b'00000000'
	MOVWF TRISB
BCF STATUS,RP0

contador EQU 0X20
repeticiones EQU 0X21
repeticiones2 EQU 0X22
repeticiones3 EQU 0X23
repeticiones4 EQU 0X24
	MOVLW d'9'
	MOVWF contador
CLRF PORTA
CLRF PORTB

bucleMain:
	BTFSS PORTA,3
		GOTO bucleMain
empezarBomba:
	MOVF contador,w
	CALL tablaDisplay
	MOVWF PORTB
	BSF PORTA, 1
	CALL delayCorto
	BCF PORTA, 1

	CALL delayLargo
	DECFSZ contador,f		
		GOTO empezarBomba
	MOVF contador,w ; 
	CALL tablaDisplay
	MOVWF PORTB
	GOTO explosion

delayCorto:
	MOVLW d'75'
	MOVWF repeticiones2
	MOVLW d'255'
	MOVWF repeticiones
delayCortoRep:
	DECFSZ repeticiones,f
		GOTO delayCortoRep
	DECFSZ repeticiones2,f
		GOTO delayCortoRep
	RETURN

delayLargo:
	MOVLW d'2'
	MOVWF repeticiones3
delayCortoL2:
	MOVLW d'255'
	MOVWF repeticiones2
delayCortoL:
	MOVLW d'255'
	MOVWF repeticiones
delayCortoRepL:
	DECFSZ repeticiones,f
		GOTO delayCortoRepL
	DECFSZ repeticiones2,f
		GOTO delayCortoL
	DECFSZ repeticiones3,f
		GOTO delayCortoL2
	RETURN

tablaDisplay:
	ADDWF PCL,F
	RETLW B'00111111' ;0	
	RETLW B'00000110' ;1
	RETLW B'01011011' ;2
	RETLW B'01001111' ;3
	RETLW B'01100110' ;4
	RETLW B'01101101' ;5
	RETLW B'01111101' ;6
	RETLW B'00000111' ;7
	RETLW B'01111111' ;8
	RETLW B'01101111' ;9

explosion:
	BSF PORTB, 7
	MOVLW d'8'
	MOVWF repeticiones4
mantenerExplosion:
	CALL delayLargo
	DECFSZ repeticiones4
		GOTO mantenerExplosion
	BCF PORTB, 7
END