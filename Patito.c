#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

int geexbox;
//Nombre de las tarjetas de video soportadas
char *dname[] = {"Requiere deteccion",
                 "CGA",
                 "MCGA",
                 "EGA",
                 "EGA 64K",
                 "EGA mono",                      /* EGA monocromo */
                 "IBM 8514",
                 "Hercules mono",                /* Hercules monocromo */
                 "AT&T 6300 PC",
                 "VGA",
                 "IBM 3270 PC"         };


Geexbox()
{
textcolor(0x0B);
textbackground(0x00);
clrscr();
gotoxy(1,24);
printf ("         ooooo                     \n");
printf ("        G*   *Go                   \n");
printf ("       G           oG**Go  oG**Go  \n");
printf ("       G    ***G   GooooG  GooooG  \n");
printf ("       *o     oG   G       G       \n");
printf ("        *GoooG*G   *GooG*  *GooG*  \n");

textcolor(0x0C);
gotoxy(35,24); cprintf ("oo     o  "); 
gotoxy(35,25); cprintf (" Go  oG*  ");
gotoxy(35,26); cprintf ("  *Go*    ");
gotoxy(35,27); cprintf ("  oGGo    ");
gotoxy(35,28); cprintf (" oG  Go   ");
gotoxy(35,29); cprintf ("G*    *G  ");

textcolor(0x0B);
gotoxy(45,24); cprintf ("o               ");
gotoxy(45,25); cprintf ("G               ");
gotoxy(45,26); cprintf ("Go***o  oG**Go  ");
gotoxy(45,27); cprintf ("G    *G G    G  ");
gotoxy(45,28); cprintf ("G    oG G    G  ");
gotoxy(45,29); cprintf ("G*ooo*  *GooG*  ");

textcolor(0x0C);
gotoxy(61,24); cprintf ("oo     o  ");
gotoxy(61,25); cprintf (" Go  oG*  ");
gotoxy(61,26); cprintf ("  *Go*    ");
gotoxy(61,27); cprintf ("  oGGo    ");
gotoxy(61,28); cprintf (" oG  Go   ");
gotoxy(61,29); cprintf ("G*    *G  ");

gotoxy(1,50);
for (geexbox=0;geexbox<22;geexbox++)
  {
  delay(40);
  if(kbhit())
    {
    geexbox=40;
    }
  }
for (geexbox=0;geexbox<30;geexbox++)
  {
  printf("\n");
  delay(40);
  if(kbhit())
    {
    geexbox=40;
    }
  }
return(0);
}


Thierry()
{
textbackground(0x00);
clrscr();

textcolor(0x0F); gotoxy(16,24); cprintf (" �������  �    �  �  �����  ����   ����    �     �    \n"); 
textcolor(0x09); gotoxy(16,25); cprintf ("    �     �    �  �  �      �   �  �   �   ��   ��    \n"); 
textcolor(0x0B); gotoxy(16,26); cprintf ("    �     �    �  �  �      �����  �����    �� ��     \n"); 
textcolor(0x0A); gotoxy(16,27); cprintf ("    �     ������  �  �����  ��     ��        ���      \n"); 
textcolor(0x0E); gotoxy(16,28); cprintf ("    �     �    �  �  �      � �    � �       ��       \n"); 
textcolor(0x0C); gotoxy(16,29); cprintf ("    �     �    �  �  �����  �  �   �  �     ��        \n");

gotoxy(1,50);
for (geexbox=0;geexbox<22;geexbox++)
  {
  delay(40);
  if(kbhit())
    {
    geexbox=40;
    }
  }
for (geexbox=0;geexbox<30;geexbox++)
  {
  printf("\n");
  delay(40);
  if(kbhit())
    {
    geexbox=40;
    }
  }
return(0);
}


Inicio()
{
textcolor(0x01);
textbackground(0x00);
clrscr();

for (geexbox=0;geexbox<50;geexbox++)
  {
  printf("    ���������������������������������������������������������������۲�����������");
  }

textcolor(0x0C);
textbackground(0x00);
gotoxy(7,2);    cprintf("����������������������������������������������������������������������ͻ");
gotoxy(7,3);    cprintf("�       Armagedon en C por Thierry Joseph Valery Garcia Greiner        �");
gotoxy(7,4);    cprintf("�                                                                      �");
gotoxy(7,5);    cprintf("����������������������������������������������������������������������ͼ");

gotoxy(7,8);    cprintf("���������������������������������ͻ");
gotoxy(7,9);    cprintf("� Modo de video     CGA           �");
gotoxy(7,10);   cprintf("� Compatible        MCGA          �");
gotoxy(7,11);   cprintf("�                   EGA           �");
gotoxy(7,12);   cprintf("�                   EGA 64K       �");
gotoxy(7,13);   cprintf("�                   EGA mono      �");
gotoxy(7,14);   cprintf("�                   IBM 8514      �");
gotoxy(7,15);   cprintf("�                   Hercules mono �");
gotoxy(7,16);   cprintf("�                   AT&T 6300 PC  �");
gotoxy(7,17);   cprintf("�                   VGA           �");
gotoxy(7,18);   cprintf("�                   IBM 3270 PC   �");
gotoxy(7,19);   cprintf("�                                 �");
gotoxy(7,20);   cprintf("� Compatibilidad SVGA Activada    �");
gotoxy(7,21);   cprintf("���������������������������������ͼ");

gotoxy(44,8);    cprintf("���������������������������������ͻ");
gotoxy(44,9);    cprintf("� Entradas            Teclado     �");
gotoxy(44,10);   cprintf("� Detectadas          Raton       �");
gotoxy(44,11);   cprintf("�                                 �");
gotoxy(44,12);   cprintf("�                                 �");
gotoxy(44,13);   cprintf("�                                 �");
gotoxy(44,14);   cprintf("�                                 �");
gotoxy(44,15);   cprintf("�                                 �");
gotoxy(44,16);   cprintf("�                                 �");
gotoxy(44,17);   cprintf("�                                 �");
gotoxy(44,18);   cprintf("�                                 �");
gotoxy(44,19);   cprintf("�                                 �");
gotoxy(44,20);   cprintf("�                                 �");
gotoxy(44,21);   cprintf("���������������������������������ͼ");
return(0);
}


errorgraficos()
{
  gotoxy(7,4);    cprintf("����������������������������������������������������������������������ͻ");
  gotoxy(7,5);    cprintf("�                      Prueba lo siguiente:                            �");
  gotoxy(7,6);    cprintf("�                                                                      �");
  gotoxy(7,7);    cprintf("� 1 Instala el archivo Egavga.bgi en tu sistema.                       �");
  gotoxy(7,8);    cprintf("� 2 Copia el archivo Egavga.bgi que se encuentra en la carpeta BGI     �");
  gotoxy(7,9);    cprintf("�   de tu carpeta de instalacion de Turbo C++ en la carpeta donde se   �");
  gotoxy(7,10);   cprintf("�   encuentra el archivo Armegueddon.exe                               �");
  gotoxy(7,11);   cprintf("�                                                                      �");
  gotoxy(7,12);   cprintf("����������������������������������������������������������������������ͼ");
  gotoxy(7,13);   cprintf("Presiona un tecla para salir.");
  getch();
  return(0);
}


detectargraficos()
{
//devuelve el valor de la informacion del hardware detectado
int gdriver,gmode,errorcode;

//detectar driver de graficos y modo
detectgraph(&gdriver, &gmode);

//leer resultado de la deteccion de graficos
errorcode=graphresult();
if (errorcode != grOk)  //Si ocurre un error
  {
  clrscr();
  gotoxy(7,1);    printf("Error al cargar el driver de graficos: ");
  gotoxy(7,2);    printf("%s", grapherrormsg(errorcode));
  errorgraficos();
  exit(1);
  }
textcolor(0x0F);
gotoxy(9,12);   cprintf("%s",dname[gdriver]);
return(0);
}


iniciargraficos()
{
int gdriver = DETECT, gmode, errorcode;

initgraph(&gdriver, &gmode, "");
errorcode = graphresult();
if (errorcode != grOk)  //Si ocurre un error
  {
  clrscr();
  gotoxy(7,1);    printf("Error al cargar el driver de graficos: ");
  gotoxy(7,2);    printf("%s", grapherrormsg(errorcode));
  errorgraficos();
  exit(1);
  }
return(0);
}


juego()
{
int x=0,y=0;
int paisaje[30][40]={0 ,11,11,11,11,11,11,11,11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 };

for(y=0;y<10;y++)
  {
  for(x=0;x<10;x++)
    {
    setfillstyle(1,paisaje[y][x]);  //se invierte x y y con el array
    bar(x*16,y*16,x*16+16,y*16+16);
    }
  }
getch();
return(0);
}


main()
{
Geexbox();
Thierry();
Inicio();
detectargraficos();

if(kbhit())  //si se presiono una tecla para omitir la presentacion, pedir que se presione una vez mas una tecla para iniciar el juego
  {
  getch();
  }

getch();
iniciargraficos();
juego();
closegraph();
return(0);
}

