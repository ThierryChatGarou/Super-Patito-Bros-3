#include<stdio.h>
#include<graphics.h>

extern struct palettetype paleta;

//esta funcion tiene muchos problemas para corregir,aveces no carga bien las imagenes, porque el tamano tiene que ser multiplo de 4 en x
//pero aun asi la funcion es estable y segura de usar
void bmp16(int i, int j, char *nombrearchivo)
{
FILE *archivo;
int n,m,bmp_largo,bmp_ancho;
unsigned char dato,a,b;
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
  for(n=0;n<92;n++)
    {
    (void) getc(archivo);
    }
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
  if (fclose(archivo)!=0)
    {
    gotoxy(1,1);
    printf( "Problemas al cerrar el archivo\n" );
    }
  }
}


void bmp24(int i, int j, char *nombrearchivo)
{
FILE *archivo;
int n,m,bmp_largo,bmp_ancho;
unsigned char a,b,c;
archivo = fopen(nombrearchivo,"rb");
if (archivo!=NULL)
  {
  for(n=0;n<54;n++)  //omitir 54 bytes
    {
    (void) getc(archivo);
    }
  for(m=479;m>=0;m--)
    {
    for(n=0;n<640;n++)
      {
      if(feof(archivo)==0)
        {
        a=getc(archivo);
        b=getc(archivo);
        c=getc(archivo);
        putpixel(n+i,m+j,RealColor(a+b*0x100+c*0x10000));
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
setrgbpalette(paleta.colors[0], 0, 0 ,0);
setrgbpalette(paleta.colors[1], 0, 0 ,42);
setrgbpalette(paleta.colors[2], 0, 42,0);
setrgbpalette(paleta.colors[3], 0, 42,42);
setrgbpalette(paleta.colors[4],42, 0,0);
setrgbpalette(paleta.colors[5],42, 0,40);
setrgbpalette(paleta.colors[6],44,20, 0);
setrgbpalette(paleta.colors[7],42,42,42);
setrgbpalette(paleta.colors[8],21,21,21);
setrgbpalette(paleta.colors[9],20,20, 63);
setrgbpalette(paleta.colors[10],20,63,20);
setrgbpalette(paleta.colors[11],20,63,63);
setrgbpalette(paleta.colors[12],63,20,20);
setrgbpalette(paleta.colors[13],63,20,63);
setrgbpalette(paleta.colors[14],63,63,20);
setrgbpalette(paleta.colors[15],63,63,63);
}