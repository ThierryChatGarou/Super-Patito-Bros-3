extern int paisaje[30][40];
extern unsigned char tecla[128];

#include<stdio.h>
#include<dos.h>
#include"teclas.h"

int botonraton=0,ratonx,ratony;
char palabra[128];
union REGS entrada,salida;


void mostrar_raton()
{
entrada.x.ax=0x01;
int86(0x33,&entrada,&salida);
}


void ocultar_raton()  //esta me la invente, pudiera no ser valida la funcion
{
entrada.x.ax=0x00;
int86(0x33,&entrada,&salida);
}


void estado_boton_posicion()
{
entrada.x.ax=0x03;
int86(0x33,&entrada,&salida);
botonraton=salida.x.bx;
ratonx=salida.x.cx;
ratony=salida.x.dx;
}


void fondoeditor()
{
int i,j;
for(j=0;j<30;j++)
  {
  for(i=0;i<40;i++)
    {
    bloque_editor(i*16,j*16,paisaje[j][i]);
    }
  }
}


void abrir_editor(char nombrearchivo[128])
{
FILE *archivo;
int i,j;

archivo = fopen(nombrearchivo,"rb");

if (archivo==NULL)
  {
  gotoxy(1,1);
  printf( "No se puede abrir el archivo %s",nombrearchivo);
  tomarletra();
  DesinstalaTeclado();
  closegraph();
  exit( 1 );
  }

for(j=0;j<30;j++)
  {
  for(i=0;i<40;i++)
    {
    fscanf(archivo,"%d,",&paisaje[j][i]);
    }
  (void) getc(archivo);  //para el retorno
  }

if (fclose(archivo)!=0)
  {
  gotoxy(1,1);
  printf( "Problemas al cerrar el archivo\n" );
  tomarletra();
  }
}


void abrir_archivo(char nombrearchivo[128])
{
FILE *archivo;
int i,j;

archivo = fopen(nombrearchivo,"rb");

if(archivo==NULL)
  {
  gotoxy(1,1);
  printf( "No se puede abrir el archivo %s",nombrearchivo);
  tomarletra();
  gotoxy(1,1);
  printf( "                               ");
  }
else
  {
  for(j=0;j<26;j++)
    {
    for(i=0;i<40;i++)
      {
      fscanf(archivo,"%d,",&paisaje[j][i]);
      }
    (void) getc(archivo);  //para el retorno
    }
  if (fclose(archivo)!=0)
    {
    gotoxy(1,1);
    printf( "Problemas al cerrar el archivo\n" );
    tomarletra();
    }
  }
}


void guardar_archivo(char nombrearchivo[128])
{
FILE *archivo;
int i,j;

archivo = fopen(nombrearchivo,"w+");

if (archivo==NULL)
  {
  gotoxy(1,1);
  printf( "No se puede crear el archivo %s",nombrearchivo);
  tomarletra();
  DesinstalaTeclado();
  closegraph();
  exit( 1 );
  }

for(j=0;j<26;j++)
  {
  for(i=0;i<40;i++)
    {
    if(paisaje[j][i]<10)
      {
      fprintf(archivo," ");
      }
    fprintf(archivo,"%d,",paisaje[j][i]);
    }
  fprintf(archivo,"\n");
  }
for(j=26;j<30;j++)  //para que no guarde el fondo del escenario
  {
  for(i=0;i<40;i++)
    {
    fprintf(archivo,"64,");
    }
  fprintf(archivo,"\n");
  }

if (fclose(archivo)!=0)
  {
  gotoxy(1,1);
  printf( "Problemas al cerrar el archivo\n" );
  tomarletra();
  }
}


int tomarletra()  //igual que el getch()
{
int n,ltr,bucle=1;
while(bucle==1)
  {
  for(n=0;n<128;n++)
    {
    if(tecla[n]==1)
      {
      ltr=tecla[n];
      bucle=0;
      }
    while(tecla[n]==1)  //atorar aqui hasta que se suelte la tecla
      {
      }
    }
  }
return ltr;
}


void escan(int i, int j)  //igual que el escanf, lo hago porque no quiere funcionar el #@%! scanf ni desinstalando mi rutina del teclado.
{
char letra,presionado=0,n=0;

palabra[0]='\0';
while(tecla[KEY_ENTER]==0)
  {
  while(tecla[KEY_A])
    {
    letra='A';
    presionado=1;
    }
  while(tecla[KEY_B])
    {
    letra='B';
    presionado=1;
    }
  while(tecla[KEY_C])
    {
    letra='C';
    presionado=1;
    }
  while(tecla[KEY_D])
    {
    letra='D';
    presionado=1;
    }
  while(tecla[KEY_E])
    {
    letra='E';
    presionado=1;
    }
  while(tecla[KEY_F])
    {
    letra='F';
    presionado=1;
    }
  while(tecla[KEY_G])
    {
    letra='G';
    presionado=1;
    }
  while(tecla[KEY_H])
    {
    letra='H';
    presionado=1;
    }
  while(tecla[KEY_I])
    {
    letra='I';
    presionado=1;
    }
  while(tecla[KEY_J])
    {
    letra='J';
    presionado=1;
    }
  while(tecla[KEY_K])
    {
    letra='K';
    presionado=1;
    }
  while(tecla[KEY_L])
    {
    letra='L';
    presionado=1;
    }
  while(tecla[KEY_M])
    {
    letra='M';
    presionado=1;
    }
  while(tecla[KEY_N])
    {
    letra='N';
    presionado=1;
    }
  while(tecla[KEY_O])
    {
    letra='O';
    presionado=1;
    }
  while(tecla[KEY_P])
    {
    letra='P';
    presionado=1;
    }
  while(tecla[KEY_Q])
    {
    letra='Q';
    presionado=1;
    }
  while(tecla[KEY_R])
    {
    letra='R';
    presionado=1;
    }
  while(tecla[KEY_S])
    {
    letra='S';
    presionado=1;
    }
  while(tecla[KEY_T])
    {
    letra='T';
    presionado=1;
    }
  while(tecla[KEY_U])
    {
    letra='U';
    presionado=1;
    }
  while(tecla[KEY_V])
    {
    letra='V';
    presionado=1;
    }
  while(tecla[KEY_W])
    {
    letra='W';
    presionado=1;
    }
  while(tecla[KEY_X])
    {
    letra='X';
    presionado=1;
    }
  while(tecla[KEY_Y])
    {
    letra='Y';
    presionado=1;
    }
  while(tecla[KEY_Z])
    {
    letra='Z';
    presionado=1;
    }
  while(tecla[KEY_1])
    {
    letra='1';
    presionado=1;
    }
  while(tecla[KEY_2])
    {
    letra='2';
    presionado=1;
    }
  while(tecla[KEY_3])
    {
    letra='3';
    presionado=1;
    }
  while(tecla[KEY_4])
    {
    letra='4';
    presionado=1;
    }
  while(tecla[KEY_5])
    {
    letra='5';
    presionado=1;
    }
  while(tecla[KEY_6])
    {
    letra='6';
    presionado=1;
    }
  while(tecla[KEY_7])
    {
    letra='7';
    presionado=1;
    }
  while(tecla[KEY_8])
    {
    letra='8';
    presionado=1;
    }
  while(tecla[KEY_9])
    {
    letra='9';
    presionado=1;
    }
  while(tecla[KEY_0])
    {
    letra='0';
    presionado=1;
    }
  while(tecla[KEY_PUNTO])
    {
    letra='.';
    presionado=1;
    }
  while(tecla[KEY_STRICH])
    {
    letra='-';
    presionado=1;
    }
  if(tecla[KEY_BACKSPACE])
    {
    while(tecla[KEY_BACKSPACE])  //atorar aqui hasta que se suelte esa tecla
      {
      }
    if(n>0)  //para no escribir en valores fuera de lo normal
      {
      n--;
      }
    }

  if(presionado)
    {
    palabra[n]=letra;
    gotoxy(i+n,j);
    printf("%c",letra);
    if(n<127)  //para no escribir en valores fuera de lo normal
      {
      n++;
      }
    presionado=0;
    }
  }
palabra[n]='\0';
}


void editornivel()  //funcion principal del editor de mapas
{
char nombre[128]="editor.txt";
int bloq;
abrir_editor(nombre);
InstalaTeclado();
fondoeditor();

texto(16,16,2,10,"Super Patito Bros 3");
texto(16,24,2,15,"Editor de niveles");
texto(16,32,1,15,"F2 Guardar archivo");
texto(16,40,1,15,"F3 Abrir archivo");
texto(16,48,1,15,"F5 actualizar");

mostrar_raton();
while(tecla[KEY_ESC]!=1)
  {
  estado_boton_posicion();
  if(botonraton==1)  //boton izquierdo
    {
    if(ratony<416)  //lado de dibujo
      {
      paisaje[(ratony-(ratony%16))/16][(ratonx-(ratonx%16))/16]=bloq;
      bloque_editor(ratonx-(ratonx%16),ratony-(ratony%16),bloq);
      }
    else  //lado de muestras
      {
      bloq=paisaje[(ratony-(ratony%16))/16][(ratonx-(ratonx%16))/16];
      }
    }
  if(tecla[KEY_F2])  //si se presiona F2, abrir menu para guardar.
    {
    //crear_ventana();
    gotoxy(6,8);
    printf("Menu de guardado");
    gotoxy(6,9);
    printf("Escribe el nombre del archivo:");
    escan(6,10);
    gotoxy(6,11);
    printf("Se guardo como %s",palabra);
    guardar_archivo(palabra);
    tomarletra();  //igual que el getch()
    fondoeditor();
    }
  if(tecla[KEY_F3])  //si se presiona F3, abrir
    {
    //crear_ventana();
    gotoxy(6,8);
    printf("Menu de abrir");
    gotoxy(6,9);
    printf("Escribe el nombre del archivo:");
    escan(6,10);
    gotoxy(6,11);
    printf("Abriendo %s",palabra);
    abrir_archivo(palabra);
    fondoeditor();
    }
  if(tecla[KEY_F5])  //si se presiona F5, actualizar
    {
    fondoeditor();
    }
  }
ocultar_raton();
DesinstalaTeclado();
}