#include<stdio.h>
#include<dir.h>
#include<graphics.h>

extern struct palettetype paleta;

//esta funcion tiene un problema para corregir,aveces no carga bien las imagenes, porque el tamano tiene que ser multiplo de 4 en x
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
    printf( "Problemas al cerrar el archivo\n" );
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
  delay(80);  //para los emuladores como ntvdm y dosbox
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
  delay(80);  //para los emuladores como ntvdm y dosbox
  }
}


int verificar_archivo(char *file_name)
  {
  struct ffblk ffblk;
  int file_error;
  file_error = findfirst(file_name,&ffblk,0);
  if(file_error != 0)
    {
    printf("No se encuentra el archivo: %s\n",file_name);
    }
  return file_error;
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
file_error+=verificar_archivo("DIBUJAR.C");
file_error+=verificar_archivo("DIBUJAR2.C");
file_error+=verificar_archivo("DIBUJAR3.C");
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
