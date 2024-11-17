#ifndef __TECLADO_H
#define __TECLADO_H

#include "patito.h"
#include <dos.h>

char Tecladoinstalado=0;  //Para saber si esta instalada nuestra rutina

#ifdef MSDOS
unsigned char tecla[128];  //Aqui esta el vector que contiene el estado de las teclas.
void interrupt(*Anterior9h)();	//Aqui se guardan los vectores antiguos
#else
#include "teclas.h"
unsigned char tecla[256];  //128 for MSDOS and 256 for Windows
#endif // MSDOS


//Prototipos de funciones
void InstalaTeclado(void);
void DesinstalaTeclado(void);
#ifdef MSDOS
void interrupt IntTeclado(void);
#endif // MSDOS

/*#ifdef MSDOS
inline int keypressed(int k)
{
return tecla[k];
}
#else
inline int keypressed(int k)
{
return GetAsyncKeyState(k);
}
#endif*/

//Se instala la nueva interrupcion 9h
void InstalaTeclado(void)
{
int i;

//Borramos el buffer del teclado
for(i=0; i<128; i++)  ///DEBUG: this might need to be changed or Windows (to 256)
  {
  tecla[i]=0;
  }
#ifdef MSDOS
Anterior9h=getvect(0x09);  //Guardamos en Anterior9h los vectores
setvect(0x09, IntTeclado);  //y la sustituimos por la nueva
Tecladoinstalado=1;
#endif // MSDOS
}

//Desinstala nuestra rutina de la interrupcion 9h y restaura la original
void DesinstalaTeclado(void)
{
#ifdef MSDOS
/*if(Tecladoinstalado)  setvect(0x09, Anterior9h);
Tecladoinstalado=0;*/
#endif // MSDOS
}

//Rutina de interrupciones
#ifndef MSDOS
void IntTeclado(void)
{
int i;
/*
tecla[KEY_CONTROL]=(GetKeyState ( KEY_CONTROL ) & 0x80) ? 1 : 0;
tecla[KEY_ESPACIO]=(GetKeyState ( KEY_ESPACIO ) & 0x80) ? 1 : 0;
tecla[KEY_F1]=(GetKeyState ( KEY_F1 ) & 0x80) ? 1 : 0;
tecla[KEY_F2]=(GetKeyState ( KEY_F2 ) & 0x80) ? 1 : 0;
tecla[KEY_F3]=(GetKeyState ( KEY_F3 ) & 0x80) ? 1 : 0;
tecla[KEY_F4]=(GetKeyState ( KEY_F4 ) & 0x80) ? 1 : 0;
tecla[KEY_F11]=(GetKeyState ( KEY_F11 ) & 0x80) ? 1 : 0;
tecla[KEY_F12]=(GetKeyState ( KEY_F12 ) & 0x80) ? 1 : 0;
tecla[KEY_ENTER]=(GetKeyState ( KEY_ENTER ) & 0x80) ? 1 : 0;
tecla[KEY_CUR_ADELANTE]=(GetKeyState ( KEY_CUR_ADELANTE ) & 0x80) ? 1 : 0;
tecla[KEY_CUR_ATRAS]=(GetKeyState ( KEY_CUR_ATRAS ) & 0x80) ? 1 : 0;
tecla[KEY_CUR_ARRIBA]=(GetKeyState ( KEY_CUR_ARRIBA ) & 0x80) ? 1 : 0;
tecla[KEY_CUR_ABAJO]=(GetKeyState ( KEY_CUR_ABAJO ) & 0x80) ? 1 : 0;
tecla[KEY_ESC]=(GetKeyState ( KEY_ESC ) & 0x80) ? 1 : 0;
*/
GetKeyboardState(tecla);
for(i=0; i<256; i++)
  {
  tecla[i]= (tecla[i]& 0x80) ? 1 : 0;
  }
/*int i;
for(i=0; i<128; i++)
  {
  tecla[i]=GetKeyState ( i ) & 0x80;
//tecla[i]=GetAsyncKeyState(i);
  }*/
}


#else


void interrupt IntTeclado(void)
{
asm in al, 0x60  //Leemos un byte del puerto 60h
asm mov bl, al  //bl=al
asm and bl, 01111111b  //Borramos bit numero 7 de bl
asm and al, 10000000b  //Borramos todos lo bits de al menos el 7

asm cmp al, 128  //Esta activado el bit 7?
asm je TECLA_SOLTADA  //Entonces esta tecla se ha soltado

tecla[_BL]=1;  //Tecla pulsada
asm jmp FIN_RUTINA  //Vamos al final de nuestra rutina

TECLA_SOLTADA:  //Tecla soltada...
tecla[_BL]=0;  //Metemos el valor 0 en el lugar correspondiente

FIN_RUTINA:
asm mov al, 20h  //Enviamos el byte 20h al puerto 20h para
asm out 20h, al  //que sepa que hemos terminado
}

#endif // MSDOS

#endif
