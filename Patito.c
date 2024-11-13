#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

int geexbox;


graficos()
{
	int gdriver = DETECT, gmode, errorcode, i, j, k;

	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		return(1);

	}
	return(0);
}


pinta()
{
  setfillstyle(1,0x01);
  bar(0,0,640,480);
  setfillstyle(1,0x0B);
  bar(0,0,22,22);
    setfillstyle(1,0x0B);
  bar(200,200,222,222);
  setfillstyle(1,0x0B);
  bar(400,400,444,468);
pieslice(88,88,0,360,8);
  getch();
return(0);
}


cuadrados()
{
int ciclo,tecla,x=0,y=0;
while (ciclo!=84)
{
  setfillstyle(1,0x0F);
  bar(x,y,x+22,y+22);
  delay(22);
  setfillstyle(1,0x00);
  bar(x,y,x+22,y+22);
  y++;
  x++;
  if(kbhit())
    {
    tecla=getch();
    ciclo=tecla;
    printf ("%i",tecla);
    }
  if(y==480)
    {
    y=-22;
    }
  if(y==-23)
    {
    y=479;
    }
  if(x==640)
    {
    x=-22;
    }
  if(x==-23)
    {
    x=639;
    }
}
line(0,0,getmaxx(),getmaxy());
getch();
return(0);
}


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

textcolor(0x0F); gotoxy(16,24);  printf (" ÜÜÜÜÜÜÜ  Ü    Ü  Ü  ÜÜÜÜÜ  ÜÜÜÜ   ÜÜÜÜ    Ü     Ü    \n"); 
textcolor(0x09); gotoxy(16,25); cprintf ("    Û     Û    Û  Û  Û      Û   Û  Û   Û   ßÛ   Ûß    \n"); 
textcolor(0x0B); gotoxy(16,26); cprintf ("    Û     Û    Û  Û  Û      ÛÜÜÜß  ÛÜÜÜß    ßÛ Ûß     \n"); 
textcolor(0x0A); gotoxy(16,27); cprintf ("    Û     ÛßßßßÛ  Û  Ûßßßß  ÛÛ     ÛÛ        ßÛß      \n"); 
textcolor(0x0E); gotoxy(16,28); cprintf ("    Û     Û    Û  Û  Û      Û Û    Û Û       Ûß       \n"); 
textcolor(0x0C); gotoxy(16,29); cprintf ("    Û     Û    Û  Û  ÛÜÜÜÜ  Û  Û   Û  Û     Ûß        \n");

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
  printf("    °°°°±±±±²²²²ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ²²²²±±±±°°°°");
  }

textcolor(0x0C);
textbackground(0x00);
gotoxy(7,2);    cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
gotoxy(7,3);    cprintf("º       Armagedon en C por Thierry Joseph Valery Garcia Greiner        º");
gotoxy(7,4);    cprintf("º                                                                      º");
gotoxy(7,5);    cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");

gotoxy(7,8);    cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
gotoxy(7,9);    cprintf("º Modo de video          CGA      º");
gotoxy(7,10);   cprintf("º Compatible             EGA      º");
gotoxy(7,11);   cprintf("º                        VGA      º");
gotoxy(7,12);   cprintf("º                                 º");
gotoxy(7,13);   cprintf("º Compatibilidad SVGA Activada    º");
gotoxy(7,14);   cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");

gotoxy(44,8);    cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
gotoxy(44,9);    cprintf("º Entradas            Teclado     º");
gotoxy(44,10);   cprintf("º Detectadas          Raton       º");
gotoxy(44,11);   cprintf("º                                 º");
gotoxy(44,12);   cprintf("º                                 º");
gotoxy(44,13);   cprintf("º                                 º");
gotoxy(44,14);   cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");

if(kbhit())
  {
  getch();
  }

getch();
return(0);
}


main()
{
Geexbox();
Thierry();
Inicio();
graficos();
pinta();
return(0);
}

