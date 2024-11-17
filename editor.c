extern int paisaje[30][40],colorcielo[30][40];
extern unsigned char tecla[128];

#include<stdio.h>
#include<dos.h>
#include"teclas.h"

int botonraton=0,ratonx,ratony;
char palabra[128];
union REGS entrada,salida;

int flechaarriba [16][16]={
7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,0 ,
7 ,15,15,15,15,15,15,15,15,15,15,15,15,15,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,10,10,10,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,10,10,10,10,10,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,10,10,10,10,10,10,10,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int flechaabajo [16][16]={
7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,0 ,
7 ,15,15,15,15,15,15,15,15,15,15,15,15,15,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,10,10,10,10,10,10,10,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,10,10,10,10,10,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,10,10,10,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,10,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,15,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,8 ,0 ,
7 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};


void botones_editor(int i2, int j2, int T)
{
int i,j;
switch (T)
  {
  case 0:
    for(j=0;j<16;j++)
      {
      for(i=0;i<16;i++)
        {
        putpixel(i+i2,j+j2,flechaarriba[j][i]);
        }
      }
  break;
  case 1:
    for(j=0;j<16;j++)
      {
      for(i=0;i<16;i++)
        {
        putpixel(i+i2,j+j2,flechaabajo[j][i]);
        }
      }
  break;
  }
}

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


void fondoeditor(int n)  //0 para escena, 1 para mundo, 2 para fondo
{
int i,j;
if(n==0)
  {
  for(j=0;j<30;j++)
    {
    for(i=0;i<40;i++)
      {
      bloque_editor(i*16,j*16,paisaje[j][i]);
      }
    }
  botones_editor(464,416,0);  //flecha arriba
  botones_editor(464,464,1);  //flecha abajo
  }
else if(n==1)
  {
  for(j=0;j<30;j++)
    {
    for(i=0;i<40;i++)
      {
      bloque0(i*16,j*16,paisaje[j][i]);
      }
    }
  }
else if(n==2)
  {
  for(j=0;j<30;j++)
    {
    for(i=0;i<40;i++)
      {
      setfillstyle(1,paisaje[j][i]);
      bar(i*16,j*16,i*16+15,j*16+15);
      }
    }
  }
texto(4,416,15,1,"bloques");
texto(32,432,15,0,"izq");
texto(8,448,15,0,"der");
texto(532,416,15,1,"F1 ayuda");
texto(532,424,15,1,"F2 guardar");
texto(532,432,15,1,"F3 abrir");
texto(532,440,15,1,"F5 actualizar");
texto(532,448,15,1,"1 nivel");
texto(532,456,15,1,"2 mundo");
texto(532,464,15,1,"3 fondo");
texto(532,472,15,1,"ESC salir");
}


void abrir_editor(char *nombrearchivo)
{
FILE *archivo;
int i,j,n;

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

for(j=0;j<26;j++)  //no leer la primera parte del archivo
  {
  for(i=0;i<40;i++)
    {
    fscanf(archivo,"%d,",&n);
    }
  (void) getc(archivo);  //para el retorno
  }

for(j=26;j<30;j++)
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


void guardar_archivo(char *nombrearchivo)
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


void ayuda_editor()
{
c_ventana(12,4,28,14);
texto(216,72,2,10,"Super Patito Bros 3");
texto(216,80,4,1,"Editor de niveles");
texto(216,96,11,0,"F1 Abrir esta ayuda");
texto(216,104,11,0,"F2 Guardar archivo");
texto(216,112,11,0,"F3 Abrir archivo");
texto(216,120,11,0,"F5 Actualizar");
texto(216,128,11,0,"1 cambiar a edicion de nivel");
texto(216,136,11,0,"2 cambiar a edicion de mundo");
texto(216,144,11,0,"3 cambiar a edicion de fondo");
texto(216,152,11,0,"ESC salir");
texto(208,184,10,1,"Presiona una tecla para empezar");
bloque_editor(1*16,27*16,3);
bloque_editor(2*16,28*16,75);
setcolor(10);
line(24,352,24,432);
line(64,368,40,448);
texto(8,330,1,15,"Bloques seleccionados");
texto(2,346,1,15,"boton izquierdo");
texto(48,360,1,15,"boton derecho");
line(64,416,80,400);
line(80,400,448,400);
line(448,400,464,416);
line(264,400,280,320);
texto(200,312,1,15,"Selecciona aqui los bloques");
line(480,346,472,420);
line(480,346,472,468);
texto(440,338,1,15,"Cambia de pagina");
tomarletra();  //igual que el getch()
fondoeditor(0);
}


void editornivel()  //funcion principal del editor de mapas
{
int bloqizq,bloqder,tipofondo=0,i,j,pagina=0;
for(j=0;j<26;j++)  //poner en negro todo
  {
  for(i=0;i<40;i++)
    {
    paisaje[j][i]=64;
    colorcielo[j][i]=0;
    }
  }
abrir_editor("editor0.txt");
fondoeditor(0);
ayuda_editor();

mostrar_raton();
while(tecla[KEY_ESC]!=1)
  {
  estado_boton_posicion();
  if(botonraton==1)  //boton izquierdo
    {
    if(ratony<416)  //lado de dibujo
      {
      paisaje[(ratony-(ratony%16))/16][(ratonx-(ratonx%16))/16]=bloqizq;
      if(tipofondo==0)
        {
        bloque_editor(ratonx-(ratonx%16),ratony-(ratony%16),bloqizq);
        }
      else if(tipofondo==1)
        {
        bloque0(ratonx-(ratonx%16),ratony-(ratony%16),bloqizq);
        }
      else if(tipofondo==2)
        {
        setfillstyle(1,bloqizq);
        bar(ratonx-(ratonx%16),ratony-(ratony%16),ratonx-(ratonx%16)+15,ratony-(ratony%16)+15);
        }
      }
    else if(ratonx>=64 && ratonx<464)  //lado de muestras
      {
      bloqizq=paisaje[(ratony-(ratony%16))/16][(ratonx-(ratonx%16))/16];
      paisaje[27][1]=bloqizq;
      if(tipofondo==0)
        {
        bloque_editor(16,432,bloqizq);
        }
      else if(tipofondo==1)
        {
        bloque0(16,432,bloqizq);
        }
      else if(tipofondo==2)
        {
        setfillstyle(1,bloqizq);
        bar(16,432,32,448);
        }
      }
    }
  if(botonraton==2)  //boton derecho
    {
    if(ratony<416)  //lado de dibujo
      {
      paisaje[(ratony-(ratony%16))/16][(ratonx-(ratonx%16))/16]=bloqder;
      if(tipofondo==0)
        {
        bloque_editor(ratonx-(ratonx%16),ratony-(ratony%16),bloqder);
        }
      else if(tipofondo==1)
        {
        bloque0(ratonx-(ratonx%16),ratony-(ratony%16),bloqder);
        }
      else if(tipofondo==2)
        {
        setfillstyle(1,bloqder);
        bar(ratonx-(ratonx%16),ratony-(ratony%16),ratonx-(ratonx%16)+15,ratony-(ratony%16)+15);
        }
      }
    else if(ratonx>=64 && ratonx<464)  //lado de muestras
      {
      bloqder=paisaje[(ratony-(ratony%16))/16][(ratonx-(ratonx%16))/16];
      paisaje[28][2]=bloqder;
      if(tipofondo==0)
        {
        bloque_editor(32,448,bloqder);
        }
      else if(tipofondo==1)
        {
        bloque0(32,448,bloqder);
        }
      else if(tipofondo==2)
        {
        setfillstyle(1,bloqder);
        bar(32,448,48,464);
        }
      }
    }
  if(botonraton==1 || botonraton==2)  //botones tipo flecha para cambio de pagina
    {
    if(ratonx>=464 && ratonx<480)
      {
      if(ratony>=416 && ratony<432)  //flecha arriba
        {
        if(pagina==-1)
          {
          abrir_editor("editor01.txt");
          fondoeditor(0);
          pagina=1;
          }
        else if(pagina==0)
          {
          abrir_editor("editor00.txt");
          fondoeditor(0);
          pagina=-1;
          }
        else if(pagina==1)
          {
          abrir_editor("editor0.txt");
          fondoeditor(0);
          pagina=0;
          }
        }
      if(ratony>=464 && ratony<480)  //flecha abajo
        {
        if(pagina==-1)
          {
          abrir_editor("editor0.txt");
          fondoeditor(0);
          pagina=0;
          }
        else if(pagina==0)
          {
          abrir_editor("editor01.txt");
          fondoeditor(0);
          pagina=1;
          }
        else if(pagina==1)
          {
          abrir_editor("editor00.txt");
          fondoeditor(0);
          pagina=-1;
          }
        }
      }
    }
  if(tecla[KEY_F1])  //si se presiona F2, abrir menu para guardar.
    {
    ayuda_editor();
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
    fondoeditor(tipofondo);
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
    fondoeditor(tipofondo);
    }
  if(tecla[KEY_F4])  //Alt+F4 salir
    {
    DesinstalaTeclado();
    closegraph();
    exit (2);
    }
  if(tecla[KEY_F5])  //si se presiona F5, actualizar
    {
    fondoeditor(tipofondo);  //0 para escena, 1 para mundo, 2 para fondo
    }
  if(tecla[KEY_1])  //cambiar a edicion de escena
    {
    tipofondo=0;
    abrir_editor("editor0.txt");
    fondoeditor(0);
    }
  if(tecla[KEY_2])  //cambiar a edicion de mundo
    {
    tipofondo=1;
    abrir_editor("editor1.txt");
    fondoeditor(1);
    }
  if(tecla[KEY_3])  //cambiar a edicion de fondo
    {
    tipofondo=2;
    abrir_editor("editor2.txt");
    fondoeditor(2);
    }
  }
ocultar_raton();
while(tecla[KEY_ESC]==1)
  {
  }
}