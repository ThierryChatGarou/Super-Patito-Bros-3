#include<stdio.h>
#include<dir.h>
#include<time.h>
#include"graphics.h"
#include"teclas.h"

extern int botonraton,ratonx,ratony;
extern int x,y,ciclo,nivel,escena,vidas,estado,jugar,debug,tiempo,mostrar_FPS,dirx;
extern float vx,vy;
extern unsigned char tecla[128];

extern int npato[8],patox[8],patoy[8],nsalta[4],saltax[4],saltay[4],nseguidor[8],seguidorx[8],seguidory[8],npeligro[4],peligrox[4],peligroy[4],nmina[8],minax[8],minay[8],ntortuga[8],tortugax[8],tortugay[8],nbala[8],balax[8],balay[8];

extern struct palettetype paleta;

clock_t start, end;

int grabar_animacion=0;
int cambios_por_segundo_paleta=4;  //se estima que la pc puede cambiar 2 veces la paleta por segundo, la funcion test_velocidad_paleta() determina el valor real
FILE *pres;  //archivo para grabar animacion

//esta funcion tiene un problema para corregir,aveces no carga bien las imagenes, parece que el tamano tiene que ser multiplo de 4 en x
//pero aun asi la funcion es estable y segura de usar
void bmp16(int i, int j, char *nombrearchivo, char cambiar_paleta)  //ejemplo: bmp16(0,0,"Dibujo.bmp",1);
{
FILE *archivo;
int n,m,bmp_largo,bmp_ancho;
unsigned char dato,a,b;
char colores_paleta[16][3];
archivo = fopen(nombrearchivo,"rb");
if (archivo!=NULL)
  {
  for(n=0;n<18;n++)  //omitir 18 bytes
    {
    (void) getc(archivo);
    }
//los siguientes 4 bytes son el largo de la imagen siendo:
//  LSB               MSB        en este orden
// 0-255 0-255 0-255 0-255
//como el orden esta invertido uso esta forma de leer los primeros 16 bits (2 bytes), del tamano.
  bmp_largo=getc(archivo);
  bmp_largo= bmp_largo + 0x100 * (getc(archivo));
  (void) getc(archivo);  //omitir 2 bytes
  (void) getc(archivo);
  bmp_ancho=getc(archivo);
  bmp_ancho=bmp_ancho + 0x100 *(getc(archivo));
  (void) getc(archivo);
  (void) getc(archivo);
  for(n=0;n<28;n++)  //omitir 28 bytes
    {
    (void) getc(archivo);
    }
  for(m=0;m<16;m++)  //leer 64 bytes de paleta
    {
    for(n=0;n<3;n++)
      {
      colores_paleta[m][n]=getc(archivo)/4;  //escala de 0 a 64
      }
    (void) getc(archivo); //omitir un byte
    }
  if(cambiar_paleta==1)
    {
    for(n=0;n<16;n++)
      {
      setrgbpalette(paleta.colors[n], colores_paleta[n][2], colores_paleta[n][1] ,colores_paleta[n][0]);
      }
    for(m=bmp_ancho-1;m>=0;m--)
      {
      for(n=0;n<(bmp_largo/2);n++)
        {
        dato=getc(archivo);
        a=dato & 0xf0;
        a=dato>>4;  //11110000
        b=dato &0x0f;  //00001111
        putpixel(i+n*2,j+m,a);
        putpixel(i+n*2+1,j+m,b);
        }
      }
    }
  else
    {
    for(m=bmp_ancho-1;m>=0;m--)
      {
      for(n=0;n<(bmp_largo/2);n++)
        {
        dato=getc(archivo);
        a=dato & 0xf0;
        a=dato>>4;  //11110000
        b=dato &0x0f;  //00001111
        switch(a)
          {
          case 0:
          putpixel(i+n*2,j+m,0);
          break;
          case 4:
          putpixel(i+n*2,j+m,1);
          break;
          case 2:
          putpixel(i+n*2,j+m,2);
          break;
          case 6:
          putpixel(i+n*2,j+m,3);
          break;
          case 1:
          putpixel(i+n*2,j+m,4);
          break;
          case 5:
          putpixel(i+n*2,j+m,5);
          break;
          case 3:
          putpixel(i+n*2,j+m,6);
          break;
          case 7:
          putpixel(i+n*2,j+m,7);
          break;
          case 8:
          putpixel(i+n*2,j+m,8);
          break;
          case 12:
          putpixel(i+n*2,j+m,9);
          break;
          case 10:
          putpixel(i+n*2,j+m,10);
          break;
          case 14:
          putpixel(i+n*2,j+m,11);
          break;
          case 9:
          putpixel(i+n*2,j+m,12);
          break;
          case 13:
          putpixel(i+n*2,j+m,13);
          break;
          case 11:
          putpixel(i+n*2,j+m,14);
          break;
          case 15:
          putpixel(i+n*2,j+m,15);
          break;
          }
        switch(b)
          {
          case 0:
          putpixel(i+n*2+1,j+m,0);
          break;
          case 4:
          putpixel(i+n*2+1,j+m,1);
          break;
          case 2:
          putpixel(i+n*2+1,j+m,2);
          break;
          case 6:
          putpixel(i+n*2+1,j+m,3);
          break;
          case 1:
          putpixel(i+n*2+1,j+m,4);
          break;
          case 5:
          putpixel(i+n*2+1,j+m,5);
          break;
          case 3:
          putpixel(i+n*2+1,j+m,6);
          break;
          case 7:
          putpixel(i+n*2+1,j+m,7);
          break;
          case 8:
          putpixel(i+n*2+1,j+m,8);
          break;
          case 12:
          putpixel(i+n*2+1,j+m,9);
          break;
          case 10:
          putpixel(i+n*2+1,j+m,10);
          break;
          case 14:
          putpixel(i+n*2+1,j+m,11);
          break;
          case 9:
          putpixel(i+n*2+1,j+m,12);
          break;
          case 13:
          putpixel(i+n*2+1,j+m,13);
          break;
          case 11:
          putpixel(i+n*2+1,j+m,14);
          break;
          case 15:
          putpixel(i+n*2+1,j+m,15);
          break;
          }
        }
      }
    }
  if (fclose(archivo)!=0)
    {
    gotoxy(1,1);
    printf( "Problemas al cerrar el archivo BMP\n" );
    }
  }
}


void paleta_predeterminada()
{
setrgbpalette(paleta.colors[0], 0, 0, 0);
setrgbpalette(paleta.colors[1], 0, 0,42);
setrgbpalette(paleta.colors[2], 0,42, 0);
setrgbpalette(paleta.colors[3], 0,42,42);
setrgbpalette(paleta.colors[4],42, 0, 0);
setrgbpalette(paleta.colors[5],42, 0,40);
setrgbpalette(paleta.colors[6],44,20, 0);
setrgbpalette(paleta.colors[7],42,42,42);
setrgbpalette(paleta.colors[8],21,21,21);
setrgbpalette(paleta.colors[9],21,21, 63);
setrgbpalette(paleta.colors[10],20,63,20);
setrgbpalette(paleta.colors[11],20,63,63);
setrgbpalette(paleta.colors[12],63,20,20);
setrgbpalette(paleta.colors[13],63,20,63);
setrgbpalette(paleta.colors[14],63,63,20);
setrgbpalette(paleta.colors[15],63,63,63);
}


void paleta_negra()
{
int n;
for(n=0;n<16;n++)
  {
  setrgbpalette(paleta.colors[n], 0, 0, 0);
  }
}


void oscurecer_paleta(int numero_de_cambios)  //Ej: 4 20 50
{
int n;
float lum=1.0,cambio_de_luz;
cambio_de_luz=1.0/numero_de_cambios;
for(n=0;n<numero_de_cambios;n++)
  {
  lum=lum-cambio_de_luz;
  setrgbpalette(paleta.colors[0], 0, 0, 0);
  setrgbpalette(paleta.colors[1], 0, 0,42*lum);
  setrgbpalette(paleta.colors[2], 0,42*lum, 0);
  setrgbpalette(paleta.colors[3], 0,42*lum,42*lum);
  setrgbpalette(paleta.colors[4],42*lum, 0, 0);
  setrgbpalette(paleta.colors[5],42*lum, 0,40*lum);
  setrgbpalette(paleta.colors[6],44*lum,20*lum, 0);
  setrgbpalette(paleta.colors[7],42*lum,42*lum,42*lum);
  setrgbpalette(paleta.colors[8],21*lum,21*lum,21*lum);
  setrgbpalette(paleta.colors[9],21*lum,21*lum, 63*lum);
  setrgbpalette(paleta.colors[10],20*lum,63*lum,20*lum);
  setrgbpalette(paleta.colors[11],20*lum,63*lum,63*lum);
  setrgbpalette(paleta.colors[12],63*lum,20*lum,20*lum);
  setrgbpalette(paleta.colors[13],63*lum,20*lum,63*lum);
  setrgbpalette(paleta.colors[14],63*lum,63*lum,20*lum);
  setrgbpalette(paleta.colors[15],63*lum,63*lum,63*lum);
  //delay(80);  //para los emuladores como ntvdm y dosbox
  }
}


void blanquear_paleta(int numero_de_cambios)  //Ej: 4 20 50
{
int n;
float lum=0.0,cambio_de_luz;
cambio_de_luz=1.0/numero_de_cambios;
for(n=0;n<numero_de_cambios;n++)
  {
  lum=lum+cambio_de_luz;
  setrgbpalette(paleta.colors[0],   63*lum,   63*lum,   63*lum);
  setrgbpalette(paleta.colors[1],   63*lum,   63*lum,42+21*lum);
  setrgbpalette(paleta.colors[2],   63*lum,42+21*lum,   63*lum);
  setrgbpalette(paleta.colors[3],   63*lum,42+21*lum,42+21*lum);
  setrgbpalette(paleta.colors[4],42+21*lum,   63*lum,   63*lum);
  setrgbpalette(paleta.colors[5],42+21*lum,   63*lum,40+23*lum);
  setrgbpalette(paleta.colors[6],44+19*lum,20+43*lum,   63*lum);
  setrgbpalette(paleta.colors[7],42+21*lum,42+21*lum,42+21*lum);
  setrgbpalette(paleta.colors[8],21+42*lum,21+42*lum,21+42*lum);
  setrgbpalette(paleta.colors[9],21+42*lum,21+42*lum,       63);
  setrgbpalette(paleta.colors[10],20+43*lum,       63,20+43*lum);
  setrgbpalette(paleta.colors[11],20+43*lum,       63,       63);
  setrgbpalette(paleta.colors[12],       63,20+43*lum,20+43*lum);
  setrgbpalette(paleta.colors[13],       63,20+43*lum,       63);
  setrgbpalette(paleta.colors[14],       63,       63,20+43*lum);
  setrgbpalette(paleta.colors[15],       63,       63,       63);
  //delay(80);  //para los emuladores como ntvdm y dosbox
  }
}


int verificar_archivo(char *file_name)
  {
/*  struct ffblk ffblk;
  int file_error;
  file_error = findfirst(file_name,&ffblk,0);
  if(file_error != 0)
    {
    printf("No se encuentra el archivo: %s\n",file_name);
    }
  return file_error;*/
return 0;  //quitar
  }


void verificar_existencia()
{
int file_error=0,advertir=0,tecla_presionada=0;
file_error=verificar_archivo("0.TIC");
if(file_error!=0)
  {
  printf("Es necesario para aparecer enemigos en algunos mapas.\n");
  file_error=0;
  advertir++;
  }
file_error=verificar_archivo("0.TXT");
if(file_error!=0)
  {
  printf("Es necesario para cargar el mapa del mundo.\n");
  file_error=0;
  advertir++;
  }
file_error+=verificar_archivo("-2-0.TXT");
file_error+=verificar_archivo("-2-1.TXT");
file_error+=verificar_archivo("-2-2.TXT");
file_error+=verificar_archivo("-2-20.TXT");
file_error+=verificar_archivo("-2-3.TXT");
file_error+=verificar_archivo("-2-0.TIM");
file_error+=verificar_archivo("-2-3.TIM");
file_error+=verificar_archivo("-2-2.TIM");
file_error+=verificar_archivo("-2-1.TIM");
file_error+=verificar_archivo("-2-20.TIM");
file_error+=verificar_archivo("0-0.TXT");
file_error+=verificar_archivo("0-1.TXT");
file_error+=verificar_archivo("0-2.TXT");
file_error+=verificar_archivo("0-20.TXT");
file_error+=verificar_archivo("0-3.TXT");
file_error+=verificar_archivo("0-0.TIM");
file_error+=verificar_archivo("0-3.TIM");
file_error+=verificar_archivo("0-2.TIM");
file_error+=verificar_archivo("0-1.TIM");
file_error+=verificar_archivo("0-20.TIM");
file_error+=verificar_archivo("1-0.TXT");
file_error+=verificar_archivo("1-1.TXT");
file_error+=verificar_archivo("1-2.TXT");
file_error+=verificar_archivo("1-20.TXT");
file_error+=verificar_archivo("1-3.TXT");
file_error+=verificar_archivo("1-0.TIM");
file_error+=verificar_archivo("1-1.TIM");
file_error+=verificar_archivo("1-2.TIM");
file_error+=verificar_archivo("1-20.TIM");
file_error+=verificar_archivo("1-3.TIM");
file_error+=verificar_archivo("2-0.TXT");
file_error+=verificar_archivo("2-1.TXT");
file_error+=verificar_archivo("2-2.TXT");
file_error+=verificar_archivo("2-20.TXT");
file_error+=verificar_archivo("2-3.TXT");
file_error+=verificar_archivo("2-0.TIM");
file_error+=verificar_archivo("2-1.TIM");
file_error+=verificar_archivo("2-2.TIM");
file_error+=verificar_archivo("2-20.TIM");
file_error+=verificar_archivo("2-3.TIM");
file_error+=verificar_archivo("3-0.TXT");
file_error+=verificar_archivo("3-1.TXT");
file_error+=verificar_archivo("3-2.TXT");
file_error+=verificar_archivo("3-20.TXT");
file_error+=verificar_archivo("3-3.TXT");
file_error+=verificar_archivo("3-0.TIM");
file_error+=verificar_archivo("3-1.TIM");
file_error+=verificar_archivo("3-2.TIM");
file_error+=verificar_archivo("3-20.TIM");
file_error+=verificar_archivo("3-3.TIM");
file_error+=verificar_archivo("4-0.TIM");
file_error+=verificar_archivo("4-0.TXT");
file_error+=verificar_archivo("4-1.TIM");
file_error+=verificar_archivo("4-1.TXT");
file_error+=verificar_archivo("4-2.TIM");
file_error+=verificar_archivo("4-2.TXT");
file_error+=verificar_archivo("4-20.TIM");
file_error+=verificar_archivo("4-20.TXT");
file_error+=verificar_archivo("4-3.TIM");
file_error+=verificar_archivo("4-3.TXT");
file_error+=verificar_archivo("5-0.TIM");
file_error+=verificar_archivo("5-0.TXT");
file_error+=verificar_archivo("5-1.TIM");
file_error+=verificar_archivo("5-1.TXT");
file_error+=verificar_archivo("5-2.TIM");
file_error+=verificar_archivo("5-2.TXT");
file_error+=verificar_archivo("5-20.TIM");
file_error+=verificar_archivo("5-20.TXT");
file_error+=verificar_archivo("5-3.TIM");
file_error+=verificar_archivo("5-3.TXT");
file_error+=verificar_archivo("6-0.TIM");
file_error+=verificar_archivo("6-0.TXT");
file_error+=verificar_archivo("6-1.TIM");
file_error+=verificar_archivo("6-1.TXT");
file_error+=verificar_archivo("6-2.TIM");
file_error+=verificar_archivo("6-2.TXT");
file_error+=verificar_archivo("6-20.TIM");
file_error+=verificar_archivo("6-20.TXT");
file_error+=verificar_archivo("6-3.TIM");
file_error+=verificar_archivo("6-3.TXT");
file_error+=verificar_archivo("7-0.TIM");
file_error+=verificar_archivo("7-0.TXT");
file_error+=verificar_archivo("7-1.TIM");
file_error+=verificar_archivo("7-1.TXT");
file_error+=verificar_archivo("7-2.TIM");
file_error+=verificar_archivo("7-2.TXT");
file_error+=verificar_archivo("7-20.TIM");
file_error+=verificar_archivo("7-20.TXT");
file_error+=verificar_archivo("7-3.TIM");
file_error+=verificar_archivo("7-3.TXT");
file_error+=verificar_archivo("8-0.TIM");
file_error+=verificar_archivo("8-0.TXT");
file_error+=verificar_archivo("8-1.TIM");
file_error+=verificar_archivo("8-1.TXT");
file_error+=verificar_archivo("8-2.TIM");
file_error+=verificar_archivo("8-2.TXT");
file_error+=verificar_archivo("8-20.TIM");
file_error+=verificar_archivo("8-20.TXT");
file_error+=verificar_archivo("8-3.TIM");
file_error+=verificar_archivo("8-3.TXT");
file_error+=verificar_archivo("9-0.TIM");
file_error+=verificar_archivo("9-0.TXT");
file_error+=verificar_archivo("9-1.TIM");
file_error+=verificar_archivo("9-1.TXT");
file_error+=verificar_archivo("9-2.TIM");
file_error+=verificar_archivo("9-2.TXT");
file_error+=verificar_archivo("9-20.TIM");
file_error+=verificar_archivo("9-20.TXT");
file_error+=verificar_archivo("9-3.TIM");
file_error+=verificar_archivo("9-3.TXT");
file_error+=verificar_archivo("Present.TXT");
file_error+=verificar_archivo("Present.TIM");
file_error+=verificar_archivo("anim.txt");
if(file_error!=0)
  {
  printf("Es necesario para cargar los mapas del juego.\n");
  file_error=0;
  advertir++;
  }
file_error+=verificar_archivo("editor0.txt");
file_error+=verificar_archivo("editor1.txt");
file_error+=verificar_archivo("editor2.txt");
file_error+=verificar_archivo("editor00.txt");
file_error+=verificar_archivo("editor01.txt");
file_error+=verificar_archivo("editor10.txt");
file_error+=verificar_archivo("editor11.txt");
if(file_error!=0)
  {
  printf("Es necesario para poder usar el editor.\n");
  file_error=0;
  advertir++;
  }
file_error+=verificar_archivo("Egavga.bgi");
if(file_error!=0)
  {
  printf("Es la libreria grafica, necesaria para poder iniciar el juego.\n");
  file_error=0;
  advertir++;
  }
file_error+=verificar_archivo("PATITO.EXE");
if(file_error!=0)
  {
  printf("Puede que el ejecutable tenga un nombre diferente y que el problema no sea grave\n");
  file_error=0;
  }
file_error+=verificar_archivo("MOUSE.COM");
if(file_error!=0)
  {
  printf("Es el driver del raton, el problema no es grave.\n");
  file_error=0;
  }
file_error+=verificar_archivo("Patito16.bmp");
file_error+=verificar_archivo("teclado.bmp");
file_error+=verificar_archivo("teclado2.bmp");
file_error+=verificar_archivo("Formas.bmp");
file_error+=verificar_archivo("Avanza.bmp");
if(file_error!=0)
  {
  printf("Son las imagenes que se cargan dentro del juego.\n");
  file_error=0;
  advertir++;
  }
file_error+=verificar_archivo("Patito1.C");
file_error+=verificar_archivo("Patito2.C");
file_error+=verificar_archivo("Patito3.C");
file_error+=verificar_archivo("editor.c");
file_error+=verificar_archivo("MUNDO0.C");
file_error+=verificar_archivo("patito.C");
file_error+=verificar_archivo("teclas.h");
file_error+=verificar_archivo("teclado.h");
if(file_error!=0)
  {
  printf("Nota: los archivos de c๓digo fuente no estแn presentes. Pero no impide el funcionamiento del juego.\n");
  file_error=0;
  }
if(advertir>=6)
  {
  clrscr();
  gotoxy(2,4);    cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
  gotoxy(2,5);    cprintf("บ Error: Faltan muchos archivos necesarios para el funcionamiento del juego. บ");
  gotoxy(2,6);    cprintf("บ                                                                            บ");
  gotoxy(2,7);    cprintf("บ -Es posible que lo estes ejecutando desde un acceso directo.               บ");
  gotoxy(2,8);    cprintf("บ -o ejecutando desde una carpeta comprimida o archivo ZIP.                  บ");
  gotoxy(2,9);    cprintf("บ -o que los archivos se hayan borrado o da๑ado.                             บ");
  gotoxy(2,10);   cprintf("บ                                                                            บ");
  gotoxy(2,11);   cprintf("บ Debe ejecutarse el juego en la misma carpeta que contiene los archivos     บ");
  gotoxy(2,12);   cprintf("บ *.TXT *.TIC *.TIM *.BMP Egavga.BGI Entre otros.                            บ");
  gotoxy(2,13);   cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
  printf("");
  }
if(advertir!=0)
  {
  textcolor(0x0F);
  textbackground(0x01);
  gotoxy(1,48);   cprintf("                 Presiona ENTER para intentar ejecutar el juego.                ");
  gotoxy(1,49);   cprintf("                             Presiona ESC para salir.                           ");
  while(tecla_presionada!=27 && tecla_presionada!=13)
    {
    tecla_presionada=getch();
    }
  if(tecla_presionada==27)
    {
    exit(1);
    }
  }
}


void panel_debug_mundo()
  {
  int bucle=0;
  char coord[80],txtnivel[7],txtescena[7],txtvidas[7],txtestado[7];  //7 es el m{aximo numero int con signo

  int btn_debugx=328,btn_debugy=96;
  int btn_FPSx=328,btn_FPSy=112;
  int btn_nivelmasx=328,btn_nivelmasy=144;
  int btn_nivelmenosx=296,btn_nivelmenosy=144;
  int btn_escenamasx=328,btn_escenamasy=160;
  int btn_escenamenosx=296,btn_escenamenosy=160;
  int btn_irx=312,btn_iry=180;
  int btn_vidasmasx=328,btn_vidasmasy=200;
  int btn_vidasmenosx=296,btn_vidasmenosy=200;
  int btn_estadomasx=328,btn_estadomasy=216;
  int btn_estadomenosx=296,btn_estadomenosy=216;

  mostrar_raton();
  c_ventana(8,4,32,16);
  texto(232,72,2,10,"Panel debug mundo");

  texto(200,100,11,0,"Modo debug:");
  if(debug==1)
    {
    botones_editor(btn_debugx,btn_debugy,2);
    }
  else
    {
    botones_editor(btn_debugx,btn_debugy,3);
    }

  texto(200,116,11,0,"Mostrar FPS:");
  if(mostrar_FPS==1)
    {
    botones_editor(btn_FPSx,btn_FPSy,2);
    }
  else
    {
    botones_editor(btn_FPSx,btn_FPSy,3);
    }

  setcolor(1);
  line(184,130,456,130);
  line(184,130,184,198);
  line(456,130,456,198);
  line(184,198,456,198);
  texto(232,132,11,0,"Teletransporte:");
  texto(200,148,11,0,"Nivel:");
  texto(200,164,11,0,"Escena:");
  botones_editor(btn_nivelmasx,btn_nivelmasy,4);
  botones_editor(btn_nivelmenosx,btn_nivelmenosy,5);
  botones_editor(btn_escenamasx,btn_escenamasy,4);
  botones_editor(btn_escenamenosx,btn_escenamenosy,5);
  botones_editor(btn_irx,btn_iry,6);

  texto(200,204,11,0,"Vidas:");
  botones_editor(btn_vidasmasx,btn_vidasmasy,4);
  botones_editor(btn_vidasmenosx,btn_vidasmenosy,5);

  texto(200,220,11,0,"Estado:");
  botones_editor(btn_estadomasx,btn_estadomasy,4);
  botones_editor(btn_estadomenosx,btn_estadomenosy,5);

  setfillstyle(1,0);
  bar(0,0,88,8);
  sprintf(coord,"x=%d",x);
  texto(0,0,2,10,coord);
  sprintf(coord,"y=%d",y);
  texto(48,0,2,10,coord);

  while(bucle==0)
    {
    estado_boton_posicion();
    setfillstyle(1,0);
    bar(0,8,168,16);
    sprintf(coord,"ratonx=%d",ratonx);
    texto(0,8,2,10,coord);
    sprintf(coord,"ratony=%d",ratony);
    texto(88,8,2,10,coord);

    if(botonraton==1)
      {
      if(ratonx>=btn_debugx && ratonx<btn_debugx+15 && ratony>=btn_debugy && ratony<btn_debugy+15)  //checkbox debug
        {
        if(debug==1)
          {
          debug=0;
          botones_editor(btn_debugx,btn_debugy,3);
          }
        else
          {
          debug=1;
          botones_editor(btn_debugx,btn_debugy,2);
          }
        }
      if(ratonx>=btn_FPSx && ratonx<btn_FPSx+15 && ratony>=btn_FPSy && ratony<btn_FPSy+15)  //checkbox mostrar FPS y delay
        {
        if(mostrar_FPS==1)
          {
          mostrar_FPS=0;
          botones_editor(btn_FPSx,btn_FPSy,3);
          }
        else
          {
          mostrar_FPS=1;
          botones_editor(btn_FPSx,btn_FPSy,2);
          }
        }
      if(ratonx>=btn_nivelmasx && ratonx<btn_nivelmasx+15 && ratony>=btn_nivelmasy && ratony<btn_nivelmasy+15)  //boton aumentar nivel
        {
        if(nivel<10)
          {
          nivel++;
          }
        }
      if(ratonx>=btn_nivelmenosx && ratonx<btn_nivelmenosx+15 && ratony>=btn_nivelmenosy && ratony<btn_nivelmenosy+15)  //boton disminuir nivel
        {
        if(nivel>-2)
          {
          nivel--;
          }
        }
      if(ratonx>=btn_escenamasx && ratonx<btn_escenamasx+15 && ratony>=btn_escenamasy && ratony<btn_escenamasy+15)  //boton aumentar escena
        {
        if(escena<99)
          {
          escena++;
          }
        }
      if(ratonx>=btn_escenamenosx && ratonx<btn_escenamenosx+15 && ratony>=btn_escenamenosy && ratony<btn_escenamenosy+15)  //boton disminuir escena
        {
        if(escena>-2)
          {
          escena--;
          }
        }
      if(ratonx>=btn_irx && ratonx<btn_irx+15 && ratony>=btn_iry && ratony<btn_iry+15)  //boton ir
        {
        bucle=2;
        ciclo=1;
        tiempo=2000;
        abrir(nivel,0);
        abrir(nivel,1);
        abrir(nivel,2);
        abrir(nivel,3);
        abrircielo(nivel,0);
        abrircielo(nivel,1);
        abrircielo(nivel,2);
        abrircielo(nivel,3);
        }
      if(ratonx>=btn_vidasmasx && ratonx<btn_vidasmasx+15 && ratony>=btn_vidasmasy && ratony<btn_vidasmasy+15)
        {
        if(vidas<99)
          {
          vidas++;
          }
        }
      if(ratonx>=btn_vidasmenosx && ratonx<btn_vidasmenosx+15 && ratony>=btn_vidasmenosy && ratony<btn_vidasmenosy+15)
        {
        if(vidas>0)
          {
          vidas--;
          }
        }
      if(ratonx>=btn_estadomasx && ratonx<btn_estadomasx+15 && ratony>=btn_estadomasy && ratony<btn_estadomasy+15)
        {
        if(estado<9)
          {
          estado++;
          }
        }
      if(ratonx>=btn_estadomenosx && ratonx<btn_estadomenosx+15 && ratony>=btn_estadomenosy && ratony<btn_estadomenosy+15)
        {
        if(estado>0)
          {
          estado--;
          }
        }

      while(botonraton!=0)  //esperar a soltar el boton
        {
        estado_boton_posicion();
        }
      }

    setfillstyle(1,15);
    bar(272,148,288,156);
    bar(272,164,288,172);
    sprintf(txtnivel,"%d",nivel);
    sprintf(txtescena,"%d",escena);
    texto(272,148,11,0,txtnivel);
    texto(272,164,11,0,txtescena);

    bar(272,204,296,212);
    sprintf(txtvidas,"%d",vidas);
    texto(272,204,11,0,txtvidas);

    bar(272,220,288,228);
    sprintf(txtestado,"%d",estado);
    texto(272,220,11,0,txtestado);

    if(tecla[KEY_ESC])  //salir
      {
      bucle=1;
      }
    delay(20);
    }
  ocultar_raton();
  if(bucle!=2)  //cuando bucle==2 no es necesario actualizar el fondo
    {
    fondomundo();
    }
  }


void panel_debug_nivel()
  {
  int bucle=0;
  char coord[80],txtnivel[7],txtescena[7],txtvidas[7],txtestado[7];

  int btn_debugx=328,btn_debugy=96;
  int btn_FPSx=328,btn_FPSy=112;
  int btn_nivelmasx=328,btn_nivelmasy=144;
  int btn_nivelmenosx=296,btn_nivelmenosy=144;
  int btn_escenamasx=328,btn_escenamasy=160;
  int btn_escenamenosx=296,btn_escenamenosy=160;
  int btn_irx=312,btn_iry=180;
  int btn_vidasmasx=328,btn_vidasmasy=200;
  int btn_vidasmenosx=296,btn_vidasmenosy=200;
  int btn_estadomasx=328,btn_estadomasy=216;
  int btn_estadomenosx=296,btn_estadomenosy=216;
  int btn_grabarx=312,btn_grabary=248;

  mostrar_raton();
  c_ventana(8,4,32,16);
  texto(232,72,2,10,"Panel debug mundo");

  texto(200,100,11,0,"Modo debug:");
  if(debug==1)
    {
    botones_editor(btn_debugx,btn_debugy,2);
    }
  else
    {
    botones_editor(btn_debugx,btn_debugy,3);
    }

  texto(200,116,11,0,"Mostrar FPS:");
  if(mostrar_FPS==1)
    {
    botones_editor(btn_FPSx,btn_FPSy,2);
    }
  else
    {
    botones_editor(btn_FPSx,btn_FPSy,3);
    }

  setcolor(1);
  line(184,130,456,130);
  line(184,130,184,198);
  line(456,130,456,198);
  line(184,198,456,198);
  texto(232,132,11,0,"Teletransporte:");
  texto(200,148,11,0,"Nivel:");
  texto(200,164,11,0,"Escena:");
  botones_editor(btn_nivelmasx,btn_nivelmasy,4);
  botones_editor(btn_nivelmenosx,btn_nivelmenosy,5);
  botones_editor(btn_escenamasx,btn_escenamasy,4);
  botones_editor(btn_escenamenosx,btn_escenamenosy,5);
  botones_editor(btn_irx,btn_iry,6);

  texto(200,204,11,0,"Vidas:");
  botones_editor(btn_vidasmasx,btn_vidasmasy,4);
  botones_editor(btn_vidasmenosx,btn_vidasmenosy,5);

  texto(200,220,11,0,"Estado:");
  botones_editor(btn_estadomasx,btn_estadomasy,4);
  botones_editor(btn_estadomenosx,btn_estadomenosy,5);

  texto(200,252,11,0,"Grabar:");
  botones_editor(btn_grabarx,btn_grabary,6);

  setfillstyle(1,0);
  bar(0,0,88,8);
  sprintf(coord,"x=%d",x);
  texto(0,0,2,10,coord);
  sprintf(coord,"y=%d",y);
  texto(48,0,2,10,coord);

  while(bucle==0)
    {
    estado_boton_posicion();
    setfillstyle(1,0);
    bar(0,8,168,16);
    sprintf(coord,"ratonx=%d",ratonx);
    texto(0,8,2,10,coord);
    sprintf(coord,"ratony=%d",ratony);
    texto(88,8,2,10,coord);

    if(botonraton==1)
      {
      if(ratonx>=btn_debugx && ratonx<btn_debugx+15 && ratony>=btn_debugy && ratony<btn_debugy+15)  //checkbox debug
        {
        if(debug==1)
          {
          debug=0;
          botones_editor(btn_debugx,btn_debugy,3);
          }
        else
          {
          debug=1;
          botones_editor(btn_debugx,btn_debugy,2);
          }
        }
      if(ratonx>=btn_FPSx && ratonx<btn_FPSx+15 && ratony>=btn_FPSy && ratony<btn_FPSy+15)  //checkbox mostrar FPS y delay
        {
        if(mostrar_FPS==1)
          {
          mostrar_FPS=0;
          botones_editor(btn_FPSx,btn_FPSy,3);
          }
        else
          {
          mostrar_FPS=1;
          botones_editor(btn_FPSx,btn_FPSy,2);
          }
        }
      if(ratonx>=btn_nivelmasx && ratonx<btn_nivelmasx+15 && ratony>=btn_nivelmasy && ratony<btn_nivelmasy+15)  //boton aumentar nivel
        {
        if(nivel<10)
          {
          nivel++;
          }
        }
      if(ratonx>=btn_nivelmenosx && ratonx<btn_nivelmenosx+15 && ratony>=btn_nivelmenosy && ratony<btn_nivelmenosy+15)  //boton disminuir nivel
        {
        if(nivel>-2)
          {
          nivel--;
          }
        }
      if(ratonx>=btn_escenamasx && ratonx<btn_escenamasx+15 && ratony>=btn_escenamasy && ratony<btn_escenamasy+15)  //boton aumentar escena
        {
        if(escena<99)
          {
          escena++;
          }
        }
      if(ratonx>=btn_escenamenosx && ratonx<btn_escenamenosx+15 && ratony>=btn_escenamenosy && ratony<btn_escenamenosy+15)  //boton disminuir escena
        {
        if(escena>-2)
          {
          escena--;
          }
        }
      if(ratonx>=btn_irx && ratonx<btn_irx+15 && ratony>=btn_iry && ratony<btn_iry+15)  //boton ir
        {
        bucle=2;
        ciclo=1;
        abrir(nivel,0);
        abrir(nivel,1);
        abrir(nivel,2);
        abrir(nivel,3);
        abrircielo(nivel,0);
        abrircielo(nivel,1);
        abrircielo(nivel,2);
        abrircielo(nivel,3);
        }
      if(ratonx>=btn_vidasmasx && ratonx<btn_vidasmasx+15 && ratony>=btn_vidasmasy && ratony<btn_vidasmasy+15)
        {
        if(vidas<99)
          {
          vidas++;
          }
        }
      if(ratonx>=btn_vidasmenosx && ratonx<btn_vidasmenosx+15 && ratony>=btn_vidasmenosy && ratony<btn_vidasmenosy+15)
        {
        if(vidas>0)
          {
          vidas--;
          }
        }
      if(ratonx>=btn_estadomasx && ratonx<btn_estadomasx+15 && ratony>=btn_estadomasy && ratony<btn_estadomasy+15)
        {
        if(estado<9)
          {
          estado++;
          }
        }
      if(ratonx>=btn_estadomenosx && ratonx<btn_estadomenosx+15 && ratony>=btn_estadomenosy && ratony<btn_estadomenosy+15)
        {
        if(estado>0)
          {
          estado--;
          }
        }
      if(ratonx>=btn_grabarx && ratonx<btn_grabarx+15 && ratony>=btn_grabary && ratony<btn_grabary+15)
        {
        if(grabar_animacion==0)
          {
          pres = fopen("anim.txt","w+");
          if(pres!=NULL)
            {
            texto(0,16,0,15,"Se ha iniciado la grabacion de la animacion");
            grabar_animacion=1;
            }
          else
            {
            gotoxy(1,3);
            printf("Problema al crear el archivo para animacion anim.txt\n");
            }
          }
        else
          {
          grabar_animacion=0;
          texto(0,16,0,15,"Se ha terminado la grabacion de la animacion");
          if (fclose(pres)!=0)
            {
            gotoxy(1,3);
            printf( "Problema al cerrar el archivo de animacion anim.txt\n" );
            }
          }
        }

      while(botonraton!=0)  //esperar a soltar el boton
        {
        estado_boton_posicion();
        }
      }

    setfillstyle(1,15);
    bar(272,148,288,156);
    bar(272,164,288,172);
    sprintf(txtnivel,"%d",nivel);
    sprintf(txtescena,"%d",escena);
    texto(272,148,11,0,txtnivel);
    texto(272,164,11,0,txtescena);

    bar(272,204,296,212);
    sprintf(txtvidas,"%d",vidas);
    texto(272,204,11,0,txtvidas);

    bar(272,220,288,228);
    sprintf(txtestado,"%d",estado);
    texto(272,220,11,0,txtestado);

    //setfillstyle(1,1);

    if(tecla[KEY_ESC])  //salir
      {
      bucle=1;
      }
    delay(20);
    }
  ocultar_raton();
  if(bucle!=2)  //cuando bucle==2 no es necesario actualizar el fondo
    {
    fondo();
    }
  }


void capturar_animacion()
{
int n,t_ctrl;
if(grabar_animacion==1)
  {

  //fprintf(pres,"%c,%c,%c,%c,",tecla[KEY_CUR_ATRAS],tecla[KEY_CUR_ADELANTE],tecla[KEY_CUR_ARRIBA],tecla[KEY_CUR_ABAJO]);
  //fprintf(pres,"%c,%c,%c,",tecla[KEY_CONTROL],tecla[KEY_ESPACIO],tecla[KEY_DELETE]);

  //fprintf(pres,"%d,%d,%1.1f,%1.1f,%d,%d,%d,",x,y,vx,vy,dirx,estado,t_ctrl);

  if(tecla[KEY_CONTROL])
    {
    t_ctrl=1;
    }
  else
    {
    t_ctrl=0;
    }
  fprintf(pres,"%d,%d,%1.1f,%1.1f,%d,%d,%d,",x,y,vx,vy,dirx,estado,t_ctrl);
  for(n=0;n<8;n++)
    {
    if(npato[n]!=0)
      {
      fprintf(pres,"C0,%d,%d,%d,%d,",n,npato[n],patox[n],patoy[n]);
      }
    if(nseguidor[n]!=0)
      {
      fprintf(pres,"C1,%d,%d,%d,%d,",n,nseguidor[n],seguidorx[n],seguidory[n]);
      }
    }
  for(n=0;n<4;n++)
    {
    if(nsalta[n]!=0)
      {
      fprintf(pres,"C2,%d,%d,%d,%d,",n,nsalta[n],saltax[n],saltay[n]);
      }
    if(npeligro[n]!=0)
      {
      fprintf(pres,"C3,%d,%d,%d,%d,",n,npeligro[n],peligrox[n],peligroy[n]);
      }
    }
  for(n=0;n<8;n++)
    {
    if(nmina[n]!=0)
      {
      fprintf(pres,"C4,%d,%d,%d,%d,",n,nmina[n],minax[n],minay[n]);
      }
    if(ntortuga[n]!=0)
      {
      fprintf(pres,"C5,%d,%d,%d,%d,",n,ntortuga[n],tortugax[n],tortugay[n]);
      }
    if(nbala[n]!=0)
      {
      fprintf(pres,"C6,%d,%d,%d,%d,",n,nbala[n],balax[n],balay[n]);
      }
    }
  fprintf(pres,"\n");
  }
}


void test_velocidad_paleta()  //es necesario el test si se quiere buenos efectos en cualquier PC y emulador
{
int n=0;
start = clock();
//gotoxy(1,1);
//printf("Probando velocidad de cambio de paleta.\n");
while((end-start)<=28)  //18.2 ticks por segundo, se hace una prueba de 1.5 segundos
  {
  paleta_predeterminada();
  end = clock();
  n++;
  //printf("El tiempo fue: %lu\n",(end-start));
  }
cambios_por_segundo_paleta=n/1.5;  //1.5 es el numero de segundos de la prueba
//printf("se lograron %d cambios en %lu ticks\n",n,(end - start));
//printf("cambios por segundo de la paleta: %d\n",cambios_por_segundo_paleta);
}



