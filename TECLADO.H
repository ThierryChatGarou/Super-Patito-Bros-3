#ifndef __TECLADO_H
#define __TECLADO_H

#include <dos.h>

#define SI 1
#define NO 0

unsigned char tecla[128]; 			// Aqui esta el estado de las teclas
char HayIntTeclado=NO;					// Para saber si esta instala nuestra rutina

void interrupt(*Anterior9h)();	// Aqui se guardan los vectores antiguos

// Prototipos de funciones
void InstalaTeclado(void);
void DesinstalaTeclado(void);
void interrupt IntTeclado(void);

/****************************************************************************/
/* 												IMPLEMENTACION DE FUNCIONES       								*/
/****************************************************************************/

// Instala la nueva interrupcion 9h
void InstalaTeclado(void)
{
	int i;

	// Borramos buffer del teclado
	for(i=0; i<128; i++) tecla[i]=NO;

	Anterior9h=getvect(0x09); 	// Guardamos en Anterior9h los vectores
	setvect(0x09, IntTeclado); 	// y la sustituimos por la nueva

	HayIntTeclado=SI;
}

// Desinstala nuestra rutina de la interrupcion 9h y restaura la original
void DesinstalaTeclado(void)
{
	if(HayIntTeclado)  setvect(0x09, Anterior9h);
	HayIntTeclado=NO;
}

// Nuestra nueva rutina de interrupcion
void interrupt IntTeclado(void)
{
	asm in al, 0x60         // Leemos un byte del puerto 60h
	asm mov bl, al          // bl=al
	asm and bl, 01111111b   // Borramos bit numero 7 de bl
	asm and al, 10000000b   // Borramos todos lo bits de al menos el 7

	asm cmp al, 128         // ¨Esta activado el bit 7?
	asm je TECLA_SOLTADA    // Entonces esta tecla se ha soltado

	tecla[_BL]=SI;        	// Tecla pulsada
	asm jmp FIN_RUTINA      // Vamos al final de nuestra rutina

TECLA_SOLTADA:            // Tecla soltada...
	tecla[_BL]=NO;        	// Metemos el valor 0 en el lugar correspondiente

FIN_RUTINA:
	asm mov al, 20h         // Enviamos el byte 20h al puerto 20h para
	asm out 20h, al         // que sepa que hemos terminado
}

#endif

