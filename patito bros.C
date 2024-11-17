///////////////////////////////////////////
//     Thierry Garcia Greiner            //
//     Super Patito Bros en C            //
///////////////////////////////////////////

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
#include<process.h>
#include<bios.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<graphics.h>
#include"teclas.h"
#include"teclado.h"

int patito,nivel=0,escena=0,mundo=0,seguir=1,vidas=4,estado=1,tiempo=0,volar=22,monedas=0,puntos=0,npato[8],patox[8],patoy[8],nsalta[4],saltax[4],saltay[4],nseguidor[8],seguidorx[8],seguidory[8],npeligro[4],peligrox[4],peligroy[4],nchamp[4],champx[4],champy[4],nmonedas[4],monedax[4],moneday[4],monealt[4],cajamone=0,invensible=0,i,j,x,y,dir=1,paso=1,teclaso=0,sec=0,t_huevo,t_moneda=-88,ciclo=0,jugar=0;
float vx=0,vy=0,saltavx[4],saltavy[4],peligrovx[4],peligrovy[4];

int niv0[30][40],niv1[30][40],niv2[30][40],niv3[30][40],paisaje[30][40];



int pausa0 [16][16]={
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
10,11,15,15,15,11,11,11,11,15,11,11,11,15,11,11,
10,11,15,0 ,0 ,15,11,11,11,15,0 ,11,11,15,0 ,11,
10,11,15,0 ,11,15,0 ,11,15,0 ,15,11,11,15,0 ,11,
10,11,15,15,15,11,0 ,11,15,15,15,0 ,11,15,0 ,11,
10,11,15,0 ,0 ,0 ,11,15,11,0 ,0 ,15,11,15,0 ,11,
10,11,15,0 ,11,11,11,15,0 ,11,11,15,0 ,11,15,15,
10,11,11,0 ,11,11,11,11,0 ,11,11,11,0 ,11,11,0 ,
10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
};

int pausa1 [16][16]={
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,
15,11,11,15,15,15,11,11,11,15,11,11,11,11,11,10,
15,0 ,15,11,0 ,0 ,0 ,11,11,15,0 ,11,11,11,11,10,
15,0 ,15,0 ,11,11,11,11,15,11,15,11,11,11,11,10,
15,0 ,11,15,15,11,11,11,15,15,15,0 ,11,11,11,10,
15,0 ,11,11,0 ,15,11,15,11,0 ,0 ,15,11,11,11,10,
11,0 ,15,15,15,11,0 ,15,0 ,11,11,15,0 ,11,11,10,
0 ,11,11,0 ,0 ,0 ,11,11,0 ,11,11,11,0 ,11,11,10,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
};


int moneda0 [16][16]={
11,11,11,11,11,0 ,0 ,0 ,0 ,0 ,0 ,11,11,11,11,11,
11,11,0 ,0 ,0 ,14,14,14,14,14,14,0 ,0 ,0 ,11,11,
11,0 ,0 ,14,14,14,14,14,14,14,14,14,14,0 ,0 ,11,
11,0 ,14,14,14,14,15,15,15,6 ,14,14,14,14,0 ,11,
11,0 ,14,14,14,14,15,14,14,6 ,14,14,14,14,0 ,11,
0 ,14,14,14,14,14,15,14,14,6 ,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,15,14,14,6 ,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,15,14,14,6 ,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,15,14,14,6 ,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,15,14,14,6 ,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,15,14,14,6 ,14,14,14,14,14,0 ,
11,0 ,14,14,14,14,15,14,14,6 ,14,14,14,14,0 ,11,
11,0 ,14,14,14,14,15,6 ,6 ,6 ,14,14,14,14,0 ,11,
11,0 ,0 ,14,14,14,14,14,14,14,14,14,14,0 ,0 ,11,
11,11,0 ,0 ,0 ,14,14,14,14,14,14,0 ,0 ,0 ,11,11,
11,11,11,11,11,0 ,0 ,0 ,0 ,0 ,0 ,11,11,11,11,11,
};


int disparo0[16][16]={
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,13,22,22,22,22,13,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,13,13,13,22,22,22,22,22,22,
22,22,22,22,22,22,22,13,15,13,22,15,22,22,22,22,
22,22,13,22,15,22,13,15,15,13,13,22,22,22,22,22,
22,22,22,13,22,15,13,15,15,15,13,22,22,22,22,22,
22,22,13,13,13,15,15,15,15,15,13,13,22,22,22,22,
13,15,15,15,15,15,15,15,15,15,15,13,13,13,13,22,
22,22,13,13,22,13,13,15,15,15,15,15,15,13,13,22,
22,22,22,22,13,13,13,15,15,15,13,13,13,13,22,22,
22,22,22,13,13,13,15,13,15,13,15,13,22,13,22,22,
22,22,13,13,13,13,13,13,15,13,13,13,13,13,22,22,
22,13,22,22,22,22,13,13,15,22,13,13,13,22,22,22,
22,22,22,22,22,22,22,13,15,13,22,22,13,22,22,22,
22,22,22,22,22,22,22,22,13,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
};


int pinguinorojo0 [16][16]={
22,22,22,22,22,22,22,4 ,4 ,4 ,22,22,22,22,22,22,
22,22,22,22,22,22,4 ,4 ,4 ,15,4 ,22,22,22,22,22,
22,22,22,22,22,4 ,4 ,4 ,15,4 ,14,14,14,22,22,22,
22,22,22,22,22,4 ,4 ,4 ,4 ,14,14,14,14,14,22,22,
22,22,22,22,22,22,4 ,4 ,4 ,4 ,4 ,22,22,22,22,22,
22,22,22,22,22,4 ,4 ,4 ,4 ,4 ,4 ,4 ,22,22,22,22,
22,22,22,22,4 ,4 ,4 ,8 ,4 ,8 ,4 ,15,22,22,22,22,
22,22,22,22,4 ,4 ,4 ,8 ,4 ,4 ,8 ,15,15,22,22,22,
22,22,22,4 ,4 ,4 ,4 ,8 ,4 ,4 ,8 ,15,15,22,22,22,
22,22,22,4 ,4 ,4 ,4 ,8 ,4 ,4 ,8 ,15,15,22,22,22,
22,22,22,4 ,4 ,4 ,8 ,4 ,4 ,8 ,15,15,15,22,22,22,
22,22,22,4 ,4 ,4 ,8 ,4 ,4 ,8 ,15,15,15,22,22,22,
22,22,22,4 ,4 ,4 ,4 ,8 ,8 ,15,15,15,22,22,22,22,
22,22,4 ,4 ,4 ,4 ,4 ,4 ,4 ,15,15,15,22,22,22,22,
22,22,4 ,4 ,4 ,4 ,4 ,14,14,15,15,22,22,22,22,22,
22,22,22,22,22,14,14,14,14,14,14,14,22,22,22,22,
};


int pinguinorojo1 [16][16]={
22,22,22,22,22,22,22,4 ,4 ,4 ,22,22,22,22,22,22,
22,22,22,22,22,22,4 ,4 ,4 ,15,4 ,22,22,22,22,22,
22,22,22,22,22,4 ,4 ,4 ,15,4 ,14,14,14,22,22,22,
22,22,22,22,22,4 ,4 ,4 ,4 ,14,14,14,14,14,22,22,
22,22,22,22,22,22,4 ,4 ,4 ,4 ,4 ,22,22,22,22,22,
22,22,22,22,22,4 ,4 ,4 ,4 ,8 ,8 ,4 ,22,22,22,22,
22,22,22,22,4 ,4 ,4 ,4 ,4 ,4 ,4 ,8 ,8 ,22,22,22,
22,4 ,8 ,8 ,4 ,4 ,4 ,4 ,4 ,8 ,8 ,4 ,4 ,8 ,8 ,22,
4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,8 ,8 ,4 ,4 ,8 ,
22,4 ,8 ,8 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,15,15,8 ,8 ,22,
22,22,22,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,15,15,22,22,22,
22,22,22,4 ,4 ,4 ,4 ,4 ,4 ,4 ,15,15,15,22,22,22,
22,22,14,4 ,4 ,4 ,4 ,4 ,4 ,4 ,15,15,14,22,22,22,
22,22,14,14,4 ,4 ,4 ,4 ,4 ,4 ,8 ,14,14,14,22,22,
22,22,22,14,14,14,4 ,4 ,4 ,8 ,14,14,14,22,22,22,
22,22,22,22,14,14,14,4 ,14,14,14,14,22,22,22,22,
};


int pinguinorojo2 [16][16]={
22,22,22,22,22,22,4 ,4 ,4 ,22,22,22,22,22,22,22,
22,22,22,22,22,4 ,15,4 ,4 ,4 ,22,22,22,22,22,22,
22,22,22,14,14,14,4 ,15,4 ,4 ,4 ,22,22,22,22,22,
22,22,14,14,14,14,14,4 ,4 ,4 ,4 ,22,22,22,22,22,
22,22,22,22,22,4 ,4 ,4 ,4 ,4 ,22,22,22,22,22,22,
22,22,22,22,4 ,4 ,4 ,4 ,4 ,4 ,4 ,22,22,22,22,22,
22,22,22,22,15,4 ,8 ,4 ,8 ,4 ,4 ,4 ,22,22,22,22,
22,22,22,15,15,8 ,4 ,4 ,8 ,4 ,4 ,4 ,22,22,22,22,
22,22,22,15,15,8 ,4 ,4 ,8 ,4 ,4 ,4 ,4 ,22,22,22,
22,22,22,15,15,8 ,4 ,4 ,8 ,4 ,4 ,4 ,4 ,22,22,22,
22,22,22,15,15,15,8 ,4 ,4 ,8 ,4 ,4 ,4 ,22,22,22,
22,22,22,15,15,15,8 ,4 ,4 ,8 ,4 ,4 ,4 ,22,22,22,
22,22,22,22,15,15,15,8 ,8 ,4 ,4 ,4 ,4 ,22,22,22,
22,22,22,22,15,15,15,4 ,4 ,4 ,4 ,4 ,4 ,4 ,22,22,
22,22,22,22,22,15,15,14,14,4 ,4 ,4 ,4 ,4 ,22,22,
22,22,22,22,14,14,14,14,14,14,14,22,22,22,22,22,
};


int pinguinorojo3 [16][16]={
22,22,22,22,22,22,4 ,4 ,4 ,22,22,22,22,22,22,22,
22,22,22,22,22,4 ,15,4 ,4 ,4 ,22,22,22,22,22,22,
22,22,22,14,14,14,4 ,15,4 ,4 ,4 ,22,22,22,22,22,
22,22,14,14,14,14,14,4 ,4 ,4 ,4 ,22,22,22,22,22,
22,22,22,22,22,4 ,4 ,4 ,4 ,4 ,22,22,22,22,22,22,
22,22,22,22,4 ,8 ,8 ,4 ,4 ,4 ,4 ,22,22,22,22,22,
22,22,22,8 ,8 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,22,22,22,22,
22,8 ,8 ,4 ,4 ,8 ,8 ,4 ,4 ,4 ,4 ,4 ,8 ,8 ,4 ,22,
8 ,4 ,4 ,8 ,8 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,
22,8 ,8 ,15,15,4 ,4 ,4 ,4 ,4 ,4 ,4 ,8 ,8 ,4 ,22,
22,22,22,15,15,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,22,22,22,
22,22,22,15,15,15,4 ,4 ,4 ,4 ,4 ,4 ,4 ,22,22,22,
22,22,22,14,15,15,4 ,4 ,4 ,4 ,4 ,4 ,4 ,14,22,22,
22,22,14,14,14,8 ,4 ,4 ,4 ,4 ,4 ,4 ,14,14,22,22,
22,22,22,14,14,14,8 ,4 ,4 ,4 ,14,14,14,22,22,22,
22,22,22,22,14,14,14,14,4 ,14,14,14,22,22,22,22,
};


int pinguino0 [16][16]={
22,22,22,22,22,22,22,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,15,0 ,22,22,22,22,22,
22,22,22,22,22,0 ,0 ,0 ,15,0 ,14,14,14,22,22,22,
22,22,22,22,22,0 ,0 ,0 ,0 ,14,14,14,14,14,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,0 ,0 ,22,22,22,22,22,
22,22,22,22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,22,22,
22,22,22,22,0 ,0 ,0 ,8 ,0 ,8 ,0 ,15,22,22,22,22,
22,22,22,22,0 ,0 ,0 ,8 ,0 ,0 ,8 ,15,15,22,22,22,
22,22,22,0 ,0 ,0 ,0 ,8 ,0 ,0 ,8 ,15,15,22,22,22,
22,22,22,0 ,0 ,0 ,0 ,8 ,0 ,0 ,8 ,15,15,22,22,22,
22,22,22,0 ,0 ,0 ,8 ,0 ,0 ,8 ,15,15,15,22,22,22,
22,22,22,0 ,0 ,0 ,8 ,0 ,0 ,8 ,15,15,15,22,22,22,
22,22,22,0 ,0 ,0 ,0 ,8 ,8 ,15,15,15,22,22,22,22,
22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,22,22,22,22,
22,22,0 ,0 ,0 ,0 ,0 ,14,14,15,15,22,22,22,22,22,
22,22,22,22,22,14,14,14,14,14,14,14,22,22,22,22,
};


int pinguino1 [16][16]={
22,22,22,22,22,22,22,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,15,0 ,22,22,22,22,22,
22,22,22,22,22,0 ,0 ,0 ,15,0 ,14,14,14,22,22,22,
22,22,22,22,22,0 ,0 ,0 ,0 ,14,14,14,14,14,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,0 ,0 ,22,22,22,22,22,
22,22,22,22,22,0 ,0 ,0 ,0 ,8 ,8 ,0 ,22,22,22,22,
22,22,22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,8 ,8 ,22,22,22,
22,0 ,8 ,8 ,0 ,0 ,0 ,0 ,0 ,8 ,8 ,0 ,0 ,8 ,8 ,22,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,8 ,8 ,0 ,0 ,8 ,
22,0 ,8 ,8 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,8 ,8 ,22,
22,22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,22,22,22,
22,22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,22,22,22,
22,22,14,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,14,22,22,22,
22,22,14,14,0 ,0 ,0 ,0 ,0 ,0 ,8 ,14,14,14,22,22,
22,22,22,14,14,14,0 ,0 ,0 ,8 ,14,14,14,22,22,22,
22,22,22,22,14,14,14,0 ,14,14,14,14,22,22,22,22,
};


int pinguino2 [16][16]={
22,22,22,22,22,22,0 ,0 ,0 ,22,22,22,22,22,22,22,
22,22,22,22,22,0 ,15,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,14,14,14,0 ,15,0 ,0 ,0 ,22,22,22,22,22,
22,22,14,14,14,14,14,0 ,0 ,0 ,0 ,22,22,22,22,22,
22,22,22,22,22,0 ,0 ,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,22,22,22,
22,22,22,22,15,0 ,8 ,0 ,8 ,0 ,0 ,0 ,22,22,22,22,
22,22,22,15,15,8 ,0 ,0 ,8 ,0 ,0 ,0 ,22,22,22,22,
22,22,22,15,15,8 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,22,22,22,
22,22,22,15,15,8 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,22,22,22,
22,22,22,15,15,15,8 ,0 ,0 ,8 ,0 ,0 ,0 ,22,22,22,
22,22,22,15,15,15,8 ,0 ,0 ,8 ,0 ,0 ,0 ,22,22,22,
22,22,22,22,15,15,15,8 ,8 ,0 ,0 ,0 ,0 ,22,22,22,
22,22,22,22,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,
22,22,22,22,22,15,15,14,14,0 ,0 ,0 ,0 ,0 ,22,22,
22,22,22,22,14,14,14,14,14,14,14,22,22,22,22,22,
};


int pinguino3 [16][16]={
22,22,22,22,22,22,0 ,0 ,0 ,22,22,22,22,22,22,22,
22,22,22,22,22,0 ,15,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,14,14,14,0 ,15,0 ,0 ,0 ,22,22,22,22,22,
22,22,14,14,14,14,14,0 ,0 ,0 ,0 ,22,22,22,22,22,
22,22,22,22,22,0 ,0 ,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,0 ,8 ,8 ,0 ,0 ,0 ,0 ,22,22,22,22,22,
22,22,22,8 ,8 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,22,22,
22,8 ,8 ,0 ,0 ,8 ,8 ,0 ,0 ,0 ,0 ,0 ,8 ,8 ,0 ,22,
8 ,0 ,0 ,8 ,8 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
22,8 ,8 ,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,8 ,8 ,0 ,22,
22,22,22,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,22,
22,22,22,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,22,
22,22,22,14,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,14,22,22,
22,22,14,14,14,8 ,0 ,0 ,0 ,0 ,0 ,0 ,14,14,22,22,
22,22,22,14,14,14,8 ,0 ,0 ,0 ,14,14,14,22,22,22,
22,22,22,22,14,14,14,14,0 ,14,14,14,22,22,22,22,
};


int pato0 [16][16]={
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,0 ,0 ,14,14,14,14,0 ,0 ,22,22,22,22,
22,22,22,0 ,0 ,0 ,14,14,14,14,0 ,0 ,0 ,22,22,22,
22,22,22,22,0 ,14,0 ,14,14,0 ,14,0 ,22,22,22,22,
22,22,22,0 ,14,15,15,0 ,0 ,15,15,14,0 ,22,22,22,
22,0 ,0 ,14,15,15,15,14,14,15,15,15,14,0 ,0 ,22,
0 ,14,14,14,14,14,0 ,14,14,0 ,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,14,14,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,14,14,14,0 ,
22,0 ,0 ,14,14,14,14,14,14,14,14,14,14,0 ,0 ,22,
22,22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,22,
22,22,22,22,0 ,0 ,15,15,15,15,0 ,0 ,22,22,22,22,
22,22,0 ,0 ,0 ,15,15,15,15,15,15,0 ,0 ,0 ,22,22,
22,0 ,0 ,0 ,0 ,0 ,15,15,15,15,0 ,0 ,0 ,0 ,0 ,22,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};


/*int pato1 [16][16]={
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,0 ,0 ,14,14,14,14,0 ,0 ,22,22,22,22,
22,22,22,0 ,0 ,0 ,14,14,14,14,0 ,0 ,0 ,22,22,22,
22,22,22,22,0 ,14,0 ,14,14,0 ,14,0 ,22,22,22,22,
22,22,22,0 ,14,15,15,0 ,0 ,15,15,14,0 ,22,22,22,
22,0 ,0 ,14,15,15,15,14,14,15,15,15,14,0 ,0 ,22,
0 ,14,14,14,14,14,0 ,14,14,0 ,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,14,14,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,14,14,14,0 ,
22,0 ,0 ,14,14,14,14,14,14,14,14,14,14,0 ,0 ,22,
22,22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,22,
22,22,22,22,0 ,0 ,15,15,15,15,0 ,0 ,22,22,22,22,
22,22,0 ,0 ,0 ,15,15,15,15,15,15,15,0 ,22,22,22,
22,0 ,0 ,0 ,0 ,0 ,15,15,15,15,15,0 ,0 ,0 ,22,22,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,0 ,0 ,0 ,0 ,0 ,22,
};

int pato2 [16][16]={
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,0 ,0 ,14,14,14,14,0 ,0 ,22,22,22,22,
22,22,22,0 ,0 ,0 ,14,14,14,14,0 ,0 ,0 ,22,22,22,
22,22,22,22,0 ,14,0 ,14,14,0 ,14,0 ,22,22,22,22,
22,22,22,0 ,14,15,15,0 ,0 ,15,15,14,0 ,22,22,22,
22,0 ,0 ,14,15,15,15,14,14,15,15,15,14,0 ,0 ,22,
0 ,14,14,14,14,14,0 ,14,14,0 ,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,14,14,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,14,14,14,0 ,
22,0 ,0 ,14,14,14,14,14,14,14,14,14,14,0 ,0 ,22,
22,22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,22,
22,22,22,22,0 ,0 ,15,15,15,15,0 ,0 ,22,22,22,22,
22,22,0 ,0 ,0 ,15,15,15,15,15,15,0 ,0 ,0 ,22,22,
22,0 ,0 ,0 ,0 ,0 ,15,15,15,15,0 ,0 ,0 ,0 ,0 ,22,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int pato3 [16][16]={
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,0 ,0 ,14,14,14,14,0 ,0 ,22,22,22,22,
22,22,22,0 ,0 ,0 ,14,14,14,14,0 ,0 ,0 ,22,22,22,
22,22,22,22,0 ,14,0 ,14,14,0 ,14,0 ,22,22,22,22,
22,22,22,0 ,14,15,15,0 ,0 ,15,15,14,0 ,22,22,22,
22,0 ,0 ,14,15,15,15,14,14,15,15,15,14,0 ,0 ,22,
0 ,14,14,14,14,14,0 ,14,14,0 ,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,14,14,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,14,14,14,0 ,
22,0 ,0 ,14,14,14,14,14,14,14,14,14,14,0 ,0 ,22,
22,22,22,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,22,22,
22,22,22,22,0 ,0 ,15,15,15,15,0 ,0 ,22,22,22,22,
22,22,22,0 ,15,15,15,15,15,15,15,0 ,0 ,0 ,22,22,
22,22,0 ,0 ,0 ,15,15,15,15,15,0 ,0 ,0 ,0 ,0 ,22,
22,0 ,0 ,0 ,0 ,0 ,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};*/

int patito0 [16][16]={
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,22,0 ,14,14,14,14,0 ,22,22,22,22,22,
22,22,22,22,0 ,14,0 ,14,14,0 ,14,0 ,22,22,22,22,
22,22,22,0 ,14,14,14,14,14,14,14,14,0 ,22,22,22,
22,22,22,0 ,14,14,0 ,0 ,0 ,0 ,14,14,0 ,22,22,22,
22,22,22,22,0 ,14,14,14,14,14,14,0 ,22,22,22,22,
22,22,22,22,22,0 ,0 ,0 ,0 ,0 ,0 ,22,22,22,22,22,
22,22,22,22,22,22,0 ,15,15,0 ,22,22,22,22,22,22,
22,22,22,22,22,0 ,15,15,15,15,0 ,22,22,22,22,22,
22,22,22,22,0 ,0 ,0 ,15,15,0 ,0 ,0 ,22,22,22,22,
};

int huevo [16][16]={
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,22,0 ,0 ,22,22,22,22,22,22,22,
22,22,22,22,22,22,0 ,15,15,0 ,22,22,22,22,22,22,
22,22,22,22,22,0 ,15,15,0 ,15,0 ,22,22,22,22,22,
22,22,22,22,22,0 ,15,0 ,15,15,0 ,22,22,22,22,22,
22,22,22,22,0 ,15,0 ,15,15,15,15,0 ,22,22,22,22,
22,22,22,22,0 ,15,15,0 ,15,15,7 ,0 ,22,22,22,22,
22,22,22,22,0 ,15,15,15,15,15,7 ,0 ,22,22,22,22,
22,22,22,22,0 ,15,15,15,15,7 ,7 ,0 ,22,22,22,22,
22,22,22,22,22,0 ,15,15,15,7 ,0 ,22,22,22,22,22,
22,22,22,22,22,0 ,15,15,7 ,7 ,0 ,22,22,22,22,22,
22,22,22,22,22,22,0 ,7 ,7 ,0 ,22,22,22,22,22,22,
22,22,22,22,22,22,22,0 ,0 ,22,22,22,22,22,22,22,
};

int champi0 [16][16]={
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,0 ,0 ,12,15,15,12,0 ,0 ,22,22,22,22,
22,22,22,0 ,12,12,12,15,15,12,12,12,0 ,22,22,22,
22,22,0 ,15,15,15,15,15,15,15,12,12,15,0 ,22,22,
22,0 ,12,15,15,15,15,12,12,15,15,15,15,12,0 ,22,
22,0 ,12,12,15,15,12,12,12,12,15,15,12,12,0 ,22,
0 ,12,12,12,15,15,12,12,12,12,15,15,12,12,12,0 ,
0 ,12,12,15,15,15,15,12,12,15,15,15,15,12,12,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,0 ,
0 ,0 ,0 ,15,15,15,0 ,15,15,0 ,15,15,15,0 ,0 ,0 ,
22,22,0 ,15,15,15,0 ,15,15,0 ,15,15,15,0 ,22,22,
22,22,0 ,15,15,15,15,15,15,15,15,15,15,0 ,22,22,
22,22,0 ,15,15,15,15,15,15,15,15,15,15,0 ,22,22,
22,22,22,0 ,15,15,15,15,15,15,15,15,0 ,22,22,22,
};

int champi4 [16][16]={
22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,
22,22,22,22,22,22,0 ,0 ,0 ,0 ,22,22,22,22,22,22,
22,22,22,22,0 ,0 ,15,10,10,15,0 ,0 ,22,22,22,22,
22,22,22,0 ,15,15,15,10,10,15,15,15,0 ,22,22,22,
22,22,0 ,10,10,10,10,10,10,10,15,15,10,0 ,22,22,
22,0 ,15,10,10,10,10,15,15,10,10,10,10,15,0 ,22,
22,0 ,15,15,10,10,15,15,15,15,10,10,15,15,0 ,22,
0 ,15,15,15,10,10,15,15,15,15,10,10,15,15,15,0 ,
0 ,15,15,10,10,10,10,15,15,10,10,10,10,15,15,0 ,
0 ,10,10,10,10,10,10,10,10,10,10,10,10,10,10,0 ,
0 ,10,10,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,10,10,0 ,
0 ,0 ,0 ,10,10,10,0 ,10,10,0 ,10,10,10,0 ,0 ,0 ,
22,22,0 ,10,10,10,0 ,10,10,0 ,10,10,10,0 ,22,22,
22,22,0 ,10,10,10,10,10,10,10,10,10,10,0 ,22,22,
22,22,0 ,10,10,10,10,10,10,10,10,10,10,0 ,22,22,
22,22,22,0 ,10,10,10,10,10,10,10,10,0 ,22,22,22,
};



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


Patito()
{
textcolor(0x0B);
textbackground(0x00);
clrscr();
gotoxy(20,24); cprintf ("    TTT    T  ");
gotoxy(20,25); cprintf ("    T  T   T  ");
gotoxy(20,26); cprintf ("    TTT   T T ");
gotoxy(20,27); cprintf ("    T     TTT ");
gotoxy(20,28); cprintf ("    T    T   T");

textcolor(0x0F);
gotoxy(34,24); cprintf (" TTTTT ");
gotoxy(34,25); cprintf ("   T   ");
gotoxy(34,26); cprintf ("   T   ");
gotoxy(34,27); cprintf ("   T   ");
gotoxy(34,28); cprintf ("   T   ");

textcolor(0x0B);
gotoxy(41,24); cprintf ("T");
gotoxy(41,25); cprintf ("T");
gotoxy(41,26); cprintf ("T");
gotoxy(41,27); cprintf ("T");
gotoxy(41,28); cprintf ("T");

textcolor(0x0F);
gotoxy(42,24); cprintf (" TTTTT ");
gotoxy(42,25); cprintf ("   T   ");
gotoxy(42,26); cprintf ("   T   ");
gotoxy(42,27); cprintf ("   T   ");
gotoxy(42,28); cprintf ("   T   ");

textcolor(0x0B);
gotoxy(49,24); cprintf (" TT   ");
gotoxy(49,25); cprintf ("T  T  ");
gotoxy(49,26); cprintf ("T  T  ");
gotoxy(49,27); cprintf ("T  T  ");
gotoxy(49,28); cprintf (" TT   ");

gotoxy(1,50);
for (patito=0;patito<22;patito++)
  {
  delay(40);
  if(kbhit())
    {
    patito=40;
    }
  }
for (patito=0;patito<30;patito++)
  {
  printf("\n");
  delay(40);
  if(kbhit())
    {
    patito=40;
    }
  }
return(0);
}


Thierry()
{
textbackground(0x00);
clrscr();

textcolor(0x0F); gotoxy(16,24); cprintf (" ÜÜÜÜÜÜÜ  Ü    Ü  Ü  ÜÜÜÜÜ  ÜÜÜÜ   ÜÜÜÜ    Ü     Ü    \n");
textcolor(0x09); gotoxy(16,25); cprintf ("    Û     Û    Û  Û  Û      Û   Û  Û   Û   ฿Û   Û฿    \n");
textcolor(0x0B); gotoxy(16,26); cprintf ("    Û     Û    Û  Û  Û      ÛÜÜÜ฿  ÛÜÜÜ฿    ฿Û Û฿     \n");
textcolor(0x0A); gotoxy(16,27); cprintf ("    Û     Û฿฿฿฿Û  Û  Û฿฿฿฿  ÛÛ     ÛÛ        ฿Û฿      \n");
textcolor(0x0E); gotoxy(16,28); cprintf ("    Û     Û    Û  Û  Û      Û Û    Û Û       Û฿       \n");
textcolor(0x0C); gotoxy(16,29); cprintf ("    Û     Û    Û  Û  ÛÜÜÜÜ  Û  Û   Û  Û     Û฿        \n");

gotoxy(1,50);
for (patito=0;patito<22;patito++)
  {
  delay(40);
  if(kbhit())
    {
    patito=40;
    }
  }
for (patito=0;patito<30;patito++)
  {
  printf("\n");
  delay(40);
  if(kbhit())
    {
    patito=40;
    }
  }
return(0);
}


Inicio()
{
textcolor(0x01);
textbackground(0x00);
clrscr();

for (patito=0;patito<50;patito++)
  {
  printf("    ฐฐฐฐฑฑฑฑฒฒฒฒÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛฒฒฒฒฑฑฑฑฐฐฐฐ");
  }

textcolor(0x0C);
textbackground(0x00);
gotoxy(7,2);    cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
gotoxy(7,3);    cprintf("บ     Patito bros en C por Thierry Joseph Valery Garcia Greiner        บ");
gotoxy(7,4);    cprintf("บ                                                                      บ");
gotoxy(7,5);    cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");

gotoxy(7,8);    cprintf("ษอออออออออออออออออออออออออออออออออป");
gotoxy(7,9);    cprintf("บ Modo de video       VGA         บ");
gotoxy(7,10);   cprintf("บ Compatible                      บ");
gotoxy(7,11);   cprintf("บ                                 บ");
gotoxy(7,12);   cprintf("บ         Detectado               บ");
gotoxy(7,13);   cprintf("บ                                 บ");
gotoxy(7,14);   cprintf("บ                                 บ");
gotoxy(7,15);   cprintf("บ                                 บ");
gotoxy(7,16);   cprintf("บ                                 บ");
gotoxy(7,17);   cprintf("บ                                 บ");
gotoxy(7,18);   cprintf("บ                                 บ");
gotoxy(7,19);   cprintf("บ                                 บ");
gotoxy(7,20);   cprintf("บ                                 บ");
gotoxy(7,21);   cprintf("ศอออออออออออออออออออออออออออออออออผ");

gotoxy(44,8);    cprintf("ษอออออออออออออออออออออออออออออออออป");
gotoxy(44,9);    cprintf("บ Entradas                        บ");
gotoxy(44,10);   cprintf("บ Detectadas                      บ");
gotoxy(44,11);   cprintf("บ                                 บ");
gotoxy(44,12);   cprintf("บ                                 บ");
gotoxy(44,13);   cprintf("บ                                 บ");
gotoxy(44,14);   cprintf("บ                                 บ");
gotoxy(44,15);   cprintf("บ                                 บ");
gotoxy(44,16);   cprintf("บ                                 บ");
gotoxy(44,17);   cprintf("บ                                 บ");
gotoxy(44,18);   cprintf("บ                                 บ");
gotoxy(44,19);   cprintf("บ                                 บ");
gotoxy(44,20);   cprintf("บ                                 บ");
gotoxy(44,21);   cprintf("ศอออออออออออออออออออออออออออออออออผ");
return(0);
}


errorgraficos()
{
  gotoxy(7,4);    cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
  gotoxy(7,5);    cprintf("บ                      Prueba lo siguiente:                            บ");
  gotoxy(7,6);    cprintf("บ                                                                      บ");
  gotoxy(7,7);    cprintf("บ 1 Instala el archivo Egavga.bgi en tu sistema.                       บ");
  gotoxy(7,8);    cprintf("บ 2 Copia el archivo Egavga.bgi que se encuentra en la carpeta BGI     บ");
  gotoxy(7,9);    cprintf("บ   de tu carpeta de instalacion de Turbo C++ o en la carpeta donde se บ");
  gotoxy(7,10);   cprintf("บ   encuentra el programa Patito bros.exe                              บ");
  gotoxy(7,11);   cprintf("บ 3 Aumenta la capacidad de memoria para el programa                   บ");
  gotoxy(7,12);   cprintf("บ 4 Si lo est s ejecutando desde codigo fuente y marca falta de        บ");
  gotoxy(7,13);   cprintf("บ   memoria, cambia la generacion del codigo (desde turbo c) en el     บ");
  gotoxy(7,14);   cprintf("บ   menu \"Options -> Compiler -> Code generation\" y en la parte que    บ");
  gotoxy(7,15);   cprintf("บ   dice \"Model\" selecciona la opciขn \"Huge\" y presiona \"OK\"           บ");
  gotoxy(7,16);   cprintf("บ   Problemas: Thierry_2222@hotmail.com                                บ");
  gotoxy(7,17);   cprintf("บ                                                                      บ");
  gotoxy(7,18);   cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
  gotoxy(7,20);   cprintf("Presiona un tecla para salir.");
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


abrir(int nivel,int escena)
{
FILE *archivo;
int letra,num=0,x2,y2,cif=10;

switch (nivel)
  {
  case 0:
    switch (escena)
      {
      case 0:
        archivo = fopen("0-0.txt","rb");
      break;
      case 1:
        archivo = fopen("0-1.txt","rb");
      break;
      case 2:
        archivo = fopen("0-2.txt","rb");
      break;
      case 3:
        archivo = fopen("0-3.txt","rb");
      break;
      case 20:  //escena secreta
        archivo = fopen("0-20.txt","rb");
      break;
      default:
        archivo = fopen("0.txt","rb");
      break;
      }
  break;
  case 1:
    switch (escena)
      {
      case 0:
        archivo = fopen("1-0.txt","rb");
      break;
      case 1:
        archivo = fopen("1-1.txt","rb");
      break;
      case 2:
        archivo = fopen("1-2.txt","rb");
      break;
      case 3:
        archivo = fopen("1-3.txt","rb");
      break;
      case 20:  //escena secreta
        archivo = fopen("1-20.txt","rb");
      break;
      default:
        archivo = fopen("0.txt","rb");
      break;
      }
  break;
  case 2:
    switch (escena)
      {
      case 0:
        archivo = fopen("2-0.txt","rb");
      break;
      case 1:
        archivo = fopen("2-1.txt","rb");
      break;
      case 2:
        archivo = fopen("2-2.txt","rb");
      break;
      case 3:
        archivo = fopen("2-3.txt","rb");
      break;
      case 20:  //escena secreta
        archivo = fopen("2-20.txt","rb");
      break;
      default:
        archivo = fopen("0.txt","rb");
      break;
      }
  break;
  case 3:
    switch (escena)
      {
      case 0:
        archivo = fopen("3-0.txt","rb");
      break;
      case 1:
        archivo = fopen("3-1.txt","rb");
      break;
      case 2:
        archivo = fopen("3-2.txt","rb");
      break;
      case 3:
        archivo = fopen("3-3.txt","rb");
      break;
      case 20:  //escena secreta
        archivo = fopen("3-20.txt","rb");
      break;
      default:
        archivo = fopen("0.txt","rb");
      break;
      }
  break;
  }

if (archivo==NULL)
  {
  printf( "No se puede abrir el archivo nivel%i-%i.txt para el mapa del nivel %i escena %i",nivel,escena,nivel,escena);
  getch();
  DesinstalaTeclado();
  exit( 1 );
  }

switch (escena)
  {
  case 0:
    y2=0;
    while(y2<30)
      {
      x2=0;
      while(x2<40)
        {
        if (feof(archivo)==0)
          {
          letra=getc(archivo);
          if(letra==44)
            {
            x2++;
            num=0;
            cif=100;
            }
          else if(letra=='\n')
            {
            num=0;
            cif=100;
            }
          else if(letra==32)
            {
            num=num/10;
            }
          else
            {
            letra=letra-48;
            letra=letra*cif;
            num=num+letra;
            }
          if(cif==1)
            {
            //printf(" %i",num);
            niv0[y2][x2]=num;
            }
          cif=cif/10;
          }
        else
          {
          x2=40;
          y2=30;
          gotoxy(1,1);
          printf( "Error al cargar paisaje\n" );
          }
        }
        y2++;
      }
  break;
  case 1:
    y2=0;
    while(y2<30)
      {
      x2=0;
      while(x2<40)
        {
        if (feof(archivo)==0)
          {
          letra=getc(archivo);
          if(letra==44)
            {
            x2++;
            num=0;
            cif=100;
            }
          else if(letra=='\n')
            {
            num=0;
            cif=100;
            }
          else if(letra==32)
            {
            num=num/10;
            }
          else
            {
            letra=letra-48;
            letra=letra*cif;
            num=num+letra;
            }
          if(cif==1)
            {
            //printf(" %i",num);
            niv1[y2][x2]=num;
            }
          cif=cif/10;
          }
        else
          {
          x2=40;
          y2=30;
          gotoxy(1,1);
          printf( "Error al cargar paisaje\n" );
          }
        }
        y2++;
      }
  break;
  case 2:
    y2=0;
    while(y2<30)
      {
      x2=0;
      while(x2<40)
        {
        if (feof(archivo)==0)
          {
          letra=getc(archivo);
          if(letra==44)
            {
            x2++;
            num=0;
            cif=100;
            }
          else if(letra=='\n')
            {
            num=0;
            cif=100;
            }
          else if(letra==32)
            {
            num=num/10;
            }
          else
            {
            letra=letra-48;
            letra=letra*cif;
            num=num+letra;
            }
          if(cif==1)
            {
            //printf(" %i",num);
            niv2[y2][x2]=num;
            }
          cif=cif/10;
          }
        else
          {
          x2=40;
          y2=30;
          gotoxy(1,1);
          printf( "Error al cargar paisaje\n" );
          }
        }
        y2++;
      }
  break;
  case 3:
    y2=0;
    while(y2<30)
      {
      x2=0;
      while(x2<40)
        {
        if (feof(archivo)==0)
          {
          letra=getc(archivo);
          if(letra==44)
            {
            x2++;
            num=0;
            cif=100;
            }
          else if(letra=='\n')
            {
            num=0;
            cif=100;
            }
          else if(letra==32)
            {
            num=num/10;
            }
          else
            {
            letra=letra-48;
            letra=letra*cif;
            num=num+letra;
            }
          if(cif==1)
            {
            //printf(" %i",num);
            niv3[y2][x2]=num;
            }
          cif=cif/10;
          }
        else
          {
          x2=40;
          y2=30;
          gotoxy(1,1);
          printf( "Error al cargar paisaje\n" );
          }
        }
        y2++;
      }
  break;
  default:
    y2=0;
    while(y2<30)
      {
      x2=0;
      while(x2<40)
        {
        if (feof(archivo)==0)
          {
          letra=getc(archivo);
          if(letra==44)
            {
            x2++;
            num=0;
            cif=100;
            }
          else if(letra=='\n')
            {
            num=0;
            cif=100;
            }
          else if(letra==32)
            {
            num=num/10;
            }
          else
            {
            letra=letra-48;
            letra=letra*cif;
            num=num+letra;
            }
          if(cif==1)
            {
            //printf(" %i",num);
            paisaje[y2][x2]=num;
            }
          cif=cif/10;
          }
        else
          {
          x2=40;
          y2=30;
          gotoxy(1,1);
          printf( "Error al cargar paisaje\n" );
          }
        }
        y2++;
      }
  break;
  }


if (fclose(archivo)!=0)
  {
  gotoxy(1,1);
  printf( "Problemas al cerrar el archivo\n" );
  }
return (0);
}


r_pato()  //resetear patos
{
int x2;
for(x2=0;x2<8;x2++)
  {
  npato[x2]=0;
  }
for(x2=0;x2<8;x2++)
  {
  patox[x2]=0;
  }
for(x2=0;x2<8;x2++)
  {
  patoy[x2]=0;
  }
}


r_seguidor()  //resetear seguidores
{
int x2;
for(x2=0;x2<8;x2++)
  {
  nseguidor[x2]=0;
  }
for(x2=0;x2<8;x2++)
  {
  seguidorx[x2]=0;
  }
for(x2=0;x2<8;x2++)
  {
  seguidory[x2]=0;
  }
}


r_salta()  //resetear saltadores
{
int x2;
for(x2=0;x2<4;x2++)
  {
  nsalta[x2]=0;
  }
for(x2=0;x2<4;x2++)
  {
  saltax[x2]=0;
  }
for(x2=0;x2<4;x2++)
  {
  saltay[x2]=0;
  }
for(x2=0;x2<4;x2++)
  {
  saltavy[x2]=0.0;
  }
for(x2=0;x2<4;x2++)
  {
  saltavx[x2]=0.0;
  }
}


r_peligro()  //resetear patos seguidores y saltadores
{
int x2;
for(x2=0;x2<4;x2++)
  {
  npeligro[x2]=0;
  }
for(x2=0;x2<4;x2++)
  {
  peligrox[x2]=0;
  }
for(x2=0;x2<4;x2++)
  {
  peligroy[x2]=0;
  }
for(x2=0;x2<4;x2++)
  {
  peligrovy[x2]=0.0;
  }
for(x2=0;x2<4;x2++)
  {
  peligrovx[x2]=0.0;
  }
}


r_champ()  //resetear champi๑ones
{
int x2;
for(x2=0;x2<4;x2++)
  {
  nchamp[x2]=0;
  }
for(x2=0;x2<4;x2++)
  {
  champx[x2]=0;
  }
for(x2=0;x2<4;x2++)
  {
  champy[x2]=0;
  }
}


rmonedas()  //resetear monedas
{
int x2;
for(x2=0;x2<4;x2++)
  {
  nmonedas[x2]=0;
  }
for(x2=0;x2<4;x2++)
  {
  monedax[x2]=0;
  }
for(x2=0;x2<4;x2++)
  {
  moneday[x2]=0;
  }
}


c_pato(int x2, int y2)
{
int n,p=0;
for(n=0;n<8;n++)
  {
  if(npato[n]==0)
    {
    p=n;
    npato[n]=1;
    n=8;
    }
  }
x2=x2*16;
y2=y2*16;
patox[p]=x2;
patoy[p]=y2;
}


c_seguidor(int x2, int y2)
{
int n,p=0;
for(n=0;n<8;n++)
  {
  if(nseguidor[n]==0)
    {
    p=n;
    nseguidor[n]=1;
    n=8;
    }
  }
x2=x2*16;
y2=y2*16;
seguidorx[p]=x2;
seguidory[p]=y2;
}


c_salta(int x2, int y2)
{
int n,p=0;
for(n=0;n<4;n++)
  {
  if(nsalta[n]==0)
    {
    p=n;
    nsalta[n]=1;
    n=4;
    }
  }
x2=x2*16;
y2=y2*16;
saltax[p]=x2;
saltay[p]=y2;
}


c_peligro(int x2, int y2)
{
int n,p=0;
for(n=0;n<4;n++)
  {
  if(npeligro[n]==0)
    {
    p=n;
    npeligro[n]=1;
    n=4;
    }
  }
x2=x2*16;
y2=y2*16;
peligrox[p]=x2;
peligroy[p]=y2;
}


c_champ(int x2, int y2, int T)
{
int n,p=0;
if(T<5)
{
for(n=0;n<4;n++)
  {
  if(nchamp[n]==0)
    {
    p=n;
    nchamp[n]=T;
    n=4;
    }
  }
x2=x2*16;
y2=y2*16;
champx[p]=x2;
champy[p]=y2;
}
}


cmoneda(int x2, int y2)
{
int n,p;
for(n=0;n<4;n++)
  {
  if(nmonedas[n]==0)
    {
    p=n;
    nmonedas[n]=1;
    n=4;
    }
  }
x2=x2*16;
y2=y2*16;
monedax[p]=x2;
moneday[p]=y2;
}


movpato()
{
int n;
for(n=0;n<8;n++)
  {
  if(npato[n]!=0)
    {
    if(npato[n]==1)  //determinar sentido
      {
      patox[n]++;
      }
    if(npato[n]==-1)  //determinar sentido
      {
      patox[n]--;
      }
    if((patox[n]%16)!=0)
      {
      if(paisaje[(patoy[n]+16-(patoy[n]%16))/16][(patox[n]-(patox[n]%16))/16]>=32 && paisaje[(patoy[n]+16-(patoy[n]%16))/16][(patox[n]+16-(patox[n]%16))/16]>=32)  //gravedad verificando si el bloque de abajo a la izquierda o el bloque de abajo a la derecha es aire
        {
        patoy[n]=patoy[n]+4;
        }
      else
        {
        patoy[n]=patoy[n]-(patoy[n]%16);
        }
      }
    else
      {
      if(paisaje[(patoy[n]+16-(patoy[n]%16))/16][(patox[n]-(patox[n]%16))/16]>=32)  //gravedad verificando si el bloque de abajo a la izquierda es aire
        {
        patoy[n]=patoy[n]+4;
        }
      else
        {
        patoy[n]=patoy[n]-(patoy[n]%16);
        }
      }
    if(paisaje[(patoy[n]-(patoy[n]%16))/16][(patox[n]+16-(patox[n]%16))/16]<32) //limite de bloque derecho
      {
      npato[n]=-1;
      patox[n]=patox[n]-(patox[n]%16);
      }
    else if(paisaje[(patoy[n]-(patoy[n]%16))/16][(patox[n]-(patox[n]%16))/16]<32) //limite de bloque izquierdo
      {
      npato[n]=1;
      patox[n]=patox[n]+16-(patox[n]%16);
      }
    }
  }
}


movseguidor()
{
int n;
for(n=0;n<8;n++)
  {
  if(nseguidor[n]!=0)
    {
    if(nseguidor[n]==1)  //determinar sentido
      {
      seguidorx[n]++;
      }
    if(nseguidor[n]==-1)  //determinar sentido
      {
      seguidorx[n]--;
      }
    if((seguidorx[n]%16)!=0)
      {
      if(paisaje[(seguidory[n]+16-(seguidory[n]%16))/16][(seguidorx[n]-(seguidorx[n]%16))/16]>=32 && paisaje[(seguidory[n]+16-(seguidory[n]%16))/16][(seguidorx[n]+16-(seguidorx[n]%16))/16]>=32)  //gravedad verificando si el bloque de abajo a la izquierda o el bloque de abajo a la derecha es aire
        {
        seguidory[n]=seguidory[n]+4;
        }
      else
        {
        seguidory[n]=seguidory[n]-(seguidory[n]%16);
        }
      }
    else
      {
      if(paisaje[(seguidory[n]+16-(seguidory[n]%16))/16][(seguidorx[n]-(seguidorx[n]%16))/16]>=32)  //gravedad verificando si el bloque de abajo a la izquierda es aire
        {
        seguidory[n]=seguidory[n]+4;
        }
      else
        {
        seguidory[n]=seguidory[n]-(seguidory[n]%16);
        }
      }
    if(sec%80==0) //seguir a patito  
      {
      if(seguidorx[n]>x)  
        {
        nseguidor[n]=-1;
        }
      else if(seguidorx[n]<x)       
        {
        nseguidor[n]=1;
        }
      }
    if(paisaje[(seguidory[n]-(seguidory[n]%16))/16][(seguidorx[n]+16-(seguidorx[n]%16))/16]<32) //limite de bloque derecho
      {
      nseguidor[n]=-1;
      seguidorx[n]=seguidorx[n]-(seguidorx[n]%16);
      }
    else if(paisaje[(seguidory[n]-(seguidory[n]%16))/16][(seguidorx[n]-(seguidorx[n]%16))/16]<32) //limite de bloque izquierdo
      {
      nseguidor[n]=1;
      seguidorx[n]=seguidorx[n]+16-(seguidorx[n]%16);
      }
    }
  }
}


movsalta()
{
int n;
for(n=0;n<4;n++)
  {
  if(nsalta[n]!=0)
    {
    if(nsalta[n]==1)  //determinar sentido
      {
      saltax[n]++;
      }
    if(nsalta[n]==-1)  //determinar sentido
      {
      saltax[n]--;
      }
    if((saltax[n]%16)!=0)
      {
      if(paisaje[(saltay[n]+16-(saltay[n]%16))/16][(saltax[n]-(saltax[n]%16))/16]>=32 && paisaje[(saltay[n]+16-(saltay[n]%16))/16][(saltax[n]+16-(saltax[n]%16))/16]>=32)  //gravedad verificando si el bloque de abajo a la izquierda o el bloque de abajo a la derecha es aire
        {
        saltavy[n]=saltavy[n]+0.5;
        }
      else
        {
        saltavy[n]=-4.0;
        saltay[n]=saltay[n]-(saltay[n]%16);
        }
      }
    else
      {
      if(paisaje[(saltay[n]+16-(saltay[n]%16))/16][(saltax[n]-(saltax[n]%16))/16]>=32)  //gravedad verificando si el bloque de abajo a la izquierda es aire
        {
        saltavy[n]=saltavy[n]+0.5;
        }
      else
        {
        saltavy[n]=-4.0;
        saltay[n]=saltay[n]-(saltay[n]%16);
        }
      }
    if(paisaje[(saltay[n]-(saltay[n]%16))/16][(saltax[n]+16-(saltax[n]%16))/16]<32) //limite de bloque derecho
      {
      nsalta[n]=-1;
      saltax[n]=saltax[n]-(saltax[n]%16);
      }
    else if(paisaje[(saltay[n]-(saltay[n]%16))/16][(saltax[n]-(saltax[n]%16))/16]<32) //limite de bloque izquierdo
      {
      nsalta[n]=1;
      saltax[n]=saltax[n]+16-(saltax[n]%16);
      }
    saltay[n]=saltay[n]+saltavy[n];
    saltax[n]=saltax[n]+saltavx[n];
    }
  }
}


movpeligro()
{
int n;
for(n=0;n<4;n++)
  {
  if(npeligro[n]!=0)
    {
    if(npeligro[n]==1)  //determinar sentido
      {
      peligrox[n]++;
      }
    if(npeligro[n]==-1)  //determinar sentido
      {
      peligrox[n]--;
      }
    if((peligrox[n]%16)!=0)
      {
      if(paisaje[(peligroy[n]+16-(peligroy[n]%16))/16][(peligrox[n]-(peligrox[n]%16))/16]>=32 && paisaje[(peligroy[n]+16-(peligroy[n]%16))/16][(peligrox[n]+16-(peligrox[n]%16))/16]>=32)  //gravedad verificando si el bloque de abajo a la izquierda o el bloque de abajo a la derecha es aire
        {
        peligrovy[n]=peligrovy[n]+0.5;
        }
      else
        {
        peligrovy[n]=-4.0;
        peligroy[n]=peligroy[n]-(peligroy[n]%16);
        }
      }
    else
      {
      if(paisaje[(peligroy[n]+16-(peligroy[n]%16))/16][(peligrox[n]-(peligrox[n]%16))/16]>=32)  //gravedad verificando si el bloque de abajo a la izquierda es aire
        {
        peligrovy[n]=peligrovy[n]+0.5;
        }
      else
        {
        peligrovy[n]=-4.0;
        peligroy[n]=peligroy[n]-(peligroy[n]%16);
        }
      }
    if(sec%80==0) //seguir a patito  
      {
      if(peligrox[n]>x)  
        {
        npeligro[n]=-1;
        }
      else if(peligrox[n]<x)       
        {
        npeligro[n]=1;
        }
      }
    if(paisaje[(peligroy[n]-(peligroy[n]%16))/16][(peligrox[n]+16-(peligrox[n]%16))/16]<32) //limite de bloque derecho    
      {
      npeligro[n]=-1;
      peligrox[n]=peligrox[n]-(peligrox[n]%16);
      }
    else if(paisaje[(peligroy[n]-(peligroy[n]%16))/16][(peligrox[n]-(peligrox[n]%16))/16]<32) //limite de bloque izquierdo       
      {
      npeligro[n]=1;
      peligrox[n]=peligrox[n]+16-(peligrox[n]%16);
      }
    peligroy[n]=peligroy[n]+peligrovy[n];
    peligrox[n]=peligrox[n]+peligrovx[n];
    }
  }
}


movchamp()
{
int n;
for(n=0;n<4;n++)
  {
  if(nchamp[n]!=0)
    {

    if(nchamp[n]>0)  //determinar sentido
      {
      champx[n]++;
      }
    if(nchamp[n]<0)  //determinar sentido
      {
      champx[n]--;
      }
    if((champx[n]%16)!=0)
      {
      if(paisaje[(champy[n]+16-(champy[n]%16))/16][(champx[n]-(champx[n]%16))/16]>=32 && paisaje[(champy[n]+16-(champy[n]%16))/16][(champx[n]+16-(champx[n]%16))/16]>=32)  //gravedad verificando si el bloque de abajo a la izquierda o el bloque de abajo a la derecha es aire
        {
        champy[n]=champy[n]+4;
        }
      else
        {
        champy[n]=champy[n]-(champy[n]%16);
        }
      }
    else
      {
      if(paisaje[(champy[n]+16-(champy[n]%16))/16][(champx[n]-(champx[n]%16))/16]>=32)  //gravedad verificando si el bloque de abajo a la izquierda es aire
        {
        champy[n]=champy[n]+4;
        }
      else
        {
        champy[n]=champy[n]-(champy[n]%16);
        }
      }
    if(paisaje[(champy[n]-(champy[n]%16))/16][(champx[n]+16-(champx[n]%16))/16]<32) //limite de bloque derecho
      {
      nchamp[n]=-nchamp[n];
      champx[n]=champx[n]-(champx[n]%16);
      }
    else if(paisaje[(champy[n]-(champy[n]%16))/16][(champx[n]-(champx[n]%16))/16]<32) //limite de bloque izquierdo
      {
      nchamp[n]=-nchamp[n];
      champx[n]=champx[n]+16-(champx[n]%16);
      }
    }
  }
}


dibpatos()
{
int n;
for(n=0;n<8;n++)
  {
  if(npato[n]!=0)
    {
    for(j=0;j<16;j++)
      {
      for(i=0;i<16;i++)
        {
        if(pato0[j][i]!=22)
          {
          putpixel(patox[n]+i,patoy[n]+j,pato0[j][i]);
          }
        }
      }
    }
  }
}


dibseguidor()
{
int n;
for(n=0;n<8;n++)
  {
  if(nseguidor[n]!=0)
    {
    for(j=0;j<16;j++)
      {
      for(i=0;i<16;i++)
        {
        if(pato0[j][i]!=22)
          {
          putpixel(seguidorx[n]+i,seguidory[n]+j,pato0[j][i]);
          }
        }
      }
    }
  }
}


dibsalta()
{
int n;
for(n=0;n<4;n++)
  {
  if(nsalta[n]!=0)
    {
    for(j=0;j<16;j++)
      {
      for(i=0;i<16;i++)
        {
        if(pato0[j][i]!=22)
          {
          putpixel(saltax[n]+i,saltay[n]+j,pato0[j][i]);
          }
        }
      }
    }
  }
}


dibpeligro()
{
int n;
for(n=0;n<4;n++)
  {
  if(npeligro[n]!=0)
    {
    for(j=0;j<16;j++)
      {
      for(i=0;i<16;i++)
        {
        if(pato0[j][i]!=22)
          {
          putpixel(peligrox[n]+i,peligroy[n]+j,pato0[j][i]);
          }
        }
      }
    }
  }
}


dibchamp()
{
int n;
for(n=0;n<4;n++)
  {
  if(nchamp[n]!=0)
    {
    switch (nchamp[n])
      {
      case -4:
        for(j=0;j<16;j++)
          {
          for(i=0;i<16;i++)
            {
            if(champi4[j][i]!=22)
              {
              putpixel(champx[n]+i,champy[n]+j,champi4[j][i]);
              }
            }
          }
      break;
      case -1:
        for(j=0;j<16;j++)
          {
          for(i=0;i<16;i++)
            {
            if(champi0[j][i]!=22)
              {
              putpixel(champx[n]+i,champy[n]+j,champi0[j][i]);
              }
            }
          }
      break;
      case 1:
        for(j=0;j<16;j++)
          {
          for(i=0;i<16;i++)
            {
            if(champi4[j][i]!=22)
              {
              putpixel(champx[n]+i,champy[n]+j,champi0[j][i]);
              }
            }
          }
      break;
      case 4:
        for(j=0;j<16;j++)
          {
          for(i=0;i<16;i++)
            {
            if(champi4[j][i]!=22)
              {
              putpixel(champx[n]+i,champy[n]+j,champi4[j][i]);
              }
            }
          }
      break;
      }
    }
  }
}


elichamp(int x2)
{
nchamp[x2]=0;
champx[x2]=0;
champy[x2]=0;
}


elipato(int x2)
{
npato[x2]=0;
patox[x2]=0;
patoy[x2]=0;
}


eliseguidor(int x2)
{
nseguidor[x2]=0;
seguidorx[x2]=0;
seguidory[x2]=0;
}


elisalta(int x2)
{
nsalta[x2]=0;
saltax[x2]=0;
saltay[x2]=0;
saltavx[x2]=0.0;
saltavy[x2]=0.0;
}


elipeligro(int x2)
{
npeligro[x2]=0;
peligrox[x2]=0;
peligroy[x2]=0;
peligrovx[x2]=0.0;
peligrovy[x2]=0.0;
}


refchamp()
{
int n;
for(n=0;n<4;n++)
  {
  if(nchamp[n]!=0)
    {
    bloque(champx[n]-(champx[n]%16),champy[n]-(champy[n]%16),paisaje[(champy[n]-(champy[n]%16))/16][(champx[n]-(champx[n]%16))/16]);  //actualizar arriba a la izquierda
    bloque(champx[n]-(champx[n]%16)+16,champy[n]-(champy[n]%16),paisaje[(champy[n]-(champy[n]%16))/16][(champx[n]+16-(champx[n]%16))/16]);  //actualizar arriba a la derecha
    }
  }
}


refpato()
{
int n;
for(n=0;n<8;n++)
  {
  if(npato[n]!=0)
    {
    bloque(patox[n]-(patox[n]%16),patoy[n]-(patoy[n]%16),paisaje[(patoy[n]-(patoy[n]%16))/16][(patox[n]-(patox[n]%16))/16]);  //actualizar arriba a la izquierda
    bloque(patox[n]-(patox[n]%16)+16,patoy[n]-(patoy[n]%16),paisaje[(patoy[n]-(patoy[n]%16))/16][(patox[n]+16-(patox[n]%16))/16]);  //actualizar arriba a la derecha
    }
  }
}


refseguidor()
{
int n;
for(n=0;n<8;n++)
  {
  if(nseguidor[n]!=0)
    {
    bloque(seguidorx[n]-(seguidorx[n]%16),seguidory[n]-(seguidory[n]%16),paisaje[(seguidory[n]-(seguidory[n]%16))/16][(seguidorx[n]-(seguidorx[n]%16))/16]);  //actualizar arriba a la izquierda
    bloque(seguidorx[n]-(seguidorx[n]%16)+16,seguidory[n]-(seguidory[n]%16),paisaje[(seguidory[n]-(seguidory[n]%16))/16][(seguidorx[n]+16-(seguidorx[n]%16))/16]);  //actualizar arriba a la derecha
    }
  }
}


refsalta()
{
int n;
for(n=0;n<4;n++)
  {
  if(nsalta[n]!=0)
    {
    if((saltax[n]%16)!=0)  // comprobar que bloques necesitan actualizarse
      {
      bloque(saltax[n]-(saltax[n]%16),saltay[n]-(saltay[n]%16),paisaje[(saltay[n]-(saltay[n]%16))/16][(saltax[n]-(saltax[n]%16))/16]);  //actualizar bloque que esta arriba a la izquierda
      bloque(saltax[n]-(saltax[n]%16)+16,saltay[n]-(saltay[n]%16),paisaje[(saltay[n]-(saltay[n]%16))/16][(saltax[n]+16-(saltax[n]%16))/16]);  //actualizar bloque que esta arriba a la derecha
      if((saltay[n]%16)!=0)
        {
        bloque(saltax[n]-(saltax[n]%16),saltay[n]-(saltay[n]%16)+16,paisaje[(saltay[n]+16-(saltay[n]%16))/16][(saltax[n]-(saltax[n]%16))/16]);  //actualizar bloque que esta abajo a la izquierda
        bloque(saltax[n]-(saltax[n]%16)+16,saltay[n]-(saltay[n]%16)+16,paisaje[(saltay[n]+16-(saltay[n]%16))/16][(saltax[n]+16-(saltax[n]%16))/16]);  //actualizar bloque que esta abajo a la derecha
        }
      }
    else if((saltay[n]%16)!=0)
      {
      bloque(saltax[n]-(saltax[n]%16),saltay[n]-(saltay[n]%16),paisaje[(saltay[n]-(saltay[n]%16))/16][(saltax[n]-(saltax[n]%16))/16]);  //actualizar bloque que esta arriba a la izquierda
      bloque(saltax[n]-(saltax[n]%16),saltay[n]-(saltay[n]%16)+16,paisaje[(saltay[n]+16-(saltay[n]%16))/16][(saltax[n]-(saltax[n]%16))/16]);  //actualizar bloque que esta abajo a la izquierda
      }
    }
  }
}


refpeligro()
{
int n;
for(n=0;n<4;n++)
  {
  if(npeligro[n]!=0)
    {
    if((peligrox[n]%16)!=0)  // comprobar que bloques necesitan actualizarse
      {
      bloque(peligrox[n]-(peligrox[n]%16),peligroy[n]-(peligroy[n]%16),paisaje[(peligroy[n]-(peligroy[n]%16))/16][(peligrox[n]-(peligrox[n]%16))/16]);  //actualizar bloque que esta arriba a la izquierda
      bloque(peligrox[n]-(peligrox[n]%16)+16,peligroy[n]-(peligroy[n]%16),paisaje[(peligroy[n]-(peligroy[n]%16))/16][(peligrox[n]+16-(peligrox[n]%16))/16]);  //actualizar bloque que esta arriba a la derecha
      if((peligroy[n]%16)!=0)
        {
        bloque(peligrox[n]-(peligrox[n]%16),peligroy[n]-(peligroy[n]%16)+16,paisaje[(peligroy[n]+16-(peligroy[n]%16))/16][(peligrox[n]-(peligrox[n]%16))/16]);  //actualizar bloque que esta abajo a la izquierda
        bloque(peligrox[n]-(peligrox[n]%16)+16,peligroy[n]-(peligroy[n]%16)+16,paisaje[(peligroy[n]+16-(peligroy[n]%16))/16][(peligrox[n]+16-(peligrox[n]%16))/16]);  //actualizar bloque que esta abajo a la derecha
        }
      }
    else if((peligroy[n]%16)!=0)
      {
      bloque(peligrox[n]-(peligrox[n]%16),peligroy[n]-(peligroy[n]%16),paisaje[(peligroy[n]-(peligroy[n]%16))/16][(peligrox[n]-(peligrox[n]%16))/16]);  //actualizar bloque que esta arriba a la izquierda
      bloque(peligrox[n]-(peligrox[n]%16),peligroy[n]-(peligroy[n]%16)+16,paisaje[(peligroy[n]+16-(peligroy[n]%16))/16][(peligrox[n]-(peligrox[n]%16))/16]);  //actualizar bloque que esta abajo a la izquierda
      }
    }
  }
}


mdemone()  //mover dibujar eliminar moneda
{
int n;
for(n=0;n<4;n++)
  {
  if(nmonedas[n]!=0)
    {
    bloque(monedax[n]-(monedax[n]%16),moneday[n]-(moneday[n]%16),paisaje[(moneday[n]-(moneday[n]%16))/16][(monedax[n]-(monedax[n]%16))/16]);
    bloque(monedax[n]-(monedax[n]%16),moneday[n]+16-(moneday[n]%16),paisaje[(moneday[n]+16-(moneday[n]%16))/16][(monedax[n]-(monedax[n]%16))/16]);
    if(monealt[n]>-32)
      {
      monealt[n]=monealt[n]-4;
      moneday[n]=moneday[n]-4;
      for(j=0;j<16;j++)
        {
        for(i=0;i<16;i++)
          {
	  putpixel(monedax[n]+i,moneday[n]+j,moneda0[j][i]);
          }
        }
      }
    else if(monealt[n]>-64)
      {
      monealt[n]=monealt[n]-4;
      moneday[n]=moneday[n]+4;
      for(j=0;j<16;j++)
        {
        for(i=0;i<16;i++)
          {
	  putpixel(monedax[n]+i,moneday[n]+j,moneda0[j][i]);
          }
        }
      }
    else
      {
      nmonedas[n]=0;
      monealt[n]=0;
      moneday[n]=0;
      monedax[n]=0;
      }
    }  
  }
}


convert()  //convertir bloques y monedas
{
t_moneda=tiempo-44;
for(j=0;j<30;j++)
  {
  for(i=0;i<40;i++)
    {
    if(paisaje[j][i]==14)
      {
      paisaje[j][i]=35;
      bloque(i*16,j*16,35);
      }
    else if(paisaje[j][i]==15)
      {
      paisaje[j][i]=34;
      bloque(i*16,j*16,34);
      }
    else if(paisaje[j][i]==34)
      {
      paisaje[j][i]=15;
      bloque(i*16,j*16,15);
      }
    else if(paisaje[j][i]==35)
      {
      paisaje[j][i]=14;
      bloque(i*16,j*16,14);
      }
    }
  }
}


act_fondo(int T)
{
int x2,y2;
switch (T)
  {
  case 0:
    for(y2=0;y2<30;y2++)
      {
      for(x2=0;x2<40;x2++)
        {
        paisaje[y2][x2]=niv0[y2][x2];
        }
      }
  break;
  case 1:
    for(y2=0;y2<30;y2++)
      {
      for(x2=0;x2<40;x2++)
        {
        paisaje[y2][x2]=niv1[y2][x2];
        }
      }
  break;
  case 2:
    for(y2=0;y2<30;y2++)
      {
      for(x2=0;x2<40;x2++)
        {
        paisaje[y2][x2]=niv2[y2][x2];
        }
      }
  break;
  case 3:
    for(y2=0;y2<30;y2++)
      {
      for(x2=0;x2<40;x2++)
        {
        paisaje[y2][x2]=niv3[y2][x2];
        }
      }
  break;
  }
}


guardar_fondo(int T)
{
int x2,y2;
switch (T)
  {
  case 0:
    for(y2=0;y2<30;y2++)
      {
      for(x2=0;x2<40;x2++)
        {
        niv0[y2][x2]=paisaje[y2][x2];
        }
      }
  break;
  case 1:
    for(y2=0;y2<30;y2++)
      {
      for(x2=0;x2<40;x2++)
        {
        niv1[y2][x2]=paisaje[y2][x2];
        }
      }
  break;
  case 2:
    for(y2=0;y2<30;y2++)
      {
      for(x2=0;x2<40;x2++)
        {
        niv2[y2][x2]=paisaje[y2][x2];
        }
      }
  break;
  case 3:
    for(y2=0;y2<30;y2++)
      {
      for(x2=0;x2<40;x2++)
        {
        niv3[y2][x2]=paisaje[y2][x2];
        }
      }
  break;
  }
}


fondo()
{
int x2,y2;
for(y2=0;y2<30;y2++)
  {
  for(x2=0;x2<40;x2++)
    {
    bloque(x2*16,y2*16,paisaje[y2][x2]);
    }
  }
}

fondomundo()  //aguas fondomundo() no es lo mismo que fondo() por bloque() y bloque0()
{
int x2,y2;
for(y2=0;y2<30;y2++)
  {
  for(x2=0;x2<40;x2++)
    {
    bloque0(x2*16,y2*16,paisaje[y2][x2]);
    }
  }
}


refbloques()  //actualizar bloques
{
                 //el modulo es para que aparesca el bloque alineado a los demas
  if((x%16)!=0)  // comprobar que bloques necesitan actualizarse
    {
    bloque(x-(x%16),y-(y%16),paisaje[(y-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta arriba a la izquierda
    bloque(x-(x%16)+16,y-(y%16),paisaje[(y-(y%16))/16][(x+16-(x%16))/16]);  //actualizar bloque que esta arriba a la derecha
    if((y%16)!=0)
      {
      bloque(x-(x%16),y-(y%16)+16,paisaje[(y+16-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta abajo a la izquierda
      bloque(x-(x%16)+16,y-(y%16)+16,paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]);  //actualizar bloque que esta abajo a la derecha
      }
    }
  else if((y%16)!=0)
    {
    bloque(x-(x%16),y-(y%16),paisaje[(y-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta arriba a la izquierda
    bloque(x-(x%16),y-(y%16)+16,paisaje[(y+16-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta abajo a la izquierda
    }
}


refbloquemundo()  //actualizar bloques
{
                 //el modulo es para que aparesca el bloque alineado a los demas
  if((x%16)!=0)  // comprobar que bloques necesitan actualizarse
    {
    bloque0(x-(x%16),y-(y%16),paisaje[(y-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta arriba a la izquierda
    bloque0(x-(x%16)+16,y-(y%16),paisaje[(y-(y%16))/16][(x+16-(x%16))/16]);  //actualizar bloque que esta arriba a la derecha
    if((y%16)!=0)
      {
      bloque0(x-(x%16),y-(y%16)+16,paisaje[(y+16-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta abajo a la izquierda
      bloque0(x-(x%16)+16,y-(y%16)+16,paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]);  //actualizar bloque que esta abajo a la derecha
      }
    }
  else if((y%16)!=0)
    {
    bloque0(x-(x%16),y-(y%16),paisaje[(y-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta arriba a la izquierda
    bloque0(x-(x%16),y-(y%16)+16,paisaje[(y+16-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta abajo a la izquierda
    }
}


tinvensible()
{
if(invensible!=0)
  {
  invensible--;
  }
}


bloque_poder0()  //poder0
{
if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==36)  //poder0
  {
  if(vy>4) //velocidad de ruptura
    {
    vy=-vy+2.0;
    y=y+16-(y%16);
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=37;  //poder2
    bloque(x-(x%16),y-(y%16),37);
    convert();
    }
  else
    {
    vy=0;
    y=y-(y%16);
    }
  if(tecla[KEY_CUR_ARRIBA])  //18432
    {
      vy=-8;
    }
  }
else if((paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==36) && x%16!=0)  //poder0
  {
  if(vy>4) //velocidad de ruptura
    {
    vy=-vy+2.0;
    y=y+16-(y%16);
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=37;  //poder2
    bloque(x+16-(x%16),y-(y%16),37);
    convert();
    }
  else
    {
    vy=0;
    y=y-(y%16);
    }
  if(tecla[KEY_CUR_ARRIBA]) //18432
    {
      vy=-8;
    }
  }
if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==36 && (y%16)==0 ) //limite derecho de poder0
{
vx=0.0;
x=x-(x%16);
}
else if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==36 && (y%16)==0 ) //limite izquierdo de poder0
{
vx=0.0;
x=x+16-(x%16);
}
if(t_moneda==tiempo)
  {
  convert();
  t_moneda=-88;
  }
}


bloque_caja0_moneda()  //caja0 con moneda
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==1) //caja0 con moneda
    {
    vy=-vy;
    puntos=puntos+40;
    monedas++;
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=5;  //caja5
    bloque(x-(x%16),y-(y%16),5);
    cmoneda((x-(x%16))/16,(y-16-(y%16))/16);
    }
  else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==1 && x%16!=0)
    {
    vy=-vy;
    puntos=puntos+40;
    monedas++;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=5;
    bloque(x+16-(x%16),y-(y%16),5);
    cmoneda((x+16-(x%16))/16,(y-16-(y%16))/16);
    }
}


bloque_caja0_10monedas()  //caja0 con 10 momedas
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==2) //caja0 con 10 monedas
    {
    vy=-vy;
    y=y+16-(y%16);  //para que el bloque no entre en la caja al pegar por abajo y no realize mal conteo de las monedas
    cajamone++;
    monedas++;
    puntos=puntos+40;
    cmoneda((x-(x%16))/16,(y-32-(y%16))/16);  //deberia ser (y-16-(y%16))/16 pero el -32 es para compensar el error del conteo de las monedas
    if(cajamone>=10)
      {
      paisaje[(y-16-(y%16))/16][(x-(x%16))/16]=5;  //caja5 el mismo error y se corrige a y-16-(y%16)
      bloque(x-(x%16),y-16-(y%16),5);  //el mismo error y se corrige a y-16-(y%16)
      cajamone=0;
      }
    }
  else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==2 && x%16!=0)
    {
    vy=-vy;
    y=y+16-(y%16);  //para que el bloque no entre en la caja al pegar por abajo y no realize mal conteo de las monedas
    cajamone++;
    monedas++;
    puntos=puntos+40;
    cmoneda((x+16-(x%16))/16,(y-32-(y%16))/16);  //deberia ser (y-16-(y%16))/16 pero el -32 es para compensar el error del conteo de las monedas
    if(cajamone>=10)
      {
      paisaje[(y-16-(y%16))/16][(x+16-(x%16))/16]=5;  //el mismo error y se corrige a y-16-(y%16)
      bloque(x+16-(x%16),y-16-(y%16),5);  //el mismo error y se corrige a y-16-(y%16)
      cajamone=0;
      }
    }
}


bloque_caja0_champinon()  //caja0 con champi๑on
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==3)  //caja0 con champi๑on
    {
    vy=-vy;
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=5;  //caja5
    bloque(x-(x%16),y-(y%16),5);
    c_champ((x-(x%16))/16,(y-16-(y%16))/16,1);
    }
  else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==3 && x%16!=0)
    {
    vy=-vy;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=5;
    bloque(x+16-(x%16),y-(y%16),5);
    c_champ((x+16-(x%16))/16,(y-16-(y%16))/16,1);
    }
}


bloque_caja0_vida()  //caja0 con vida
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==4)  //caja0 con vida
    {
    vy=-vy;
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=5;  //caja5
    bloque(x-(x%16),y-(y%16),5);
    c_champ((x-(x%16))/16,(y-16-(y%16))/16,4);
    }
  else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==4 && x%16!=0)
    {
    vy=-vy;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=5;
    bloque(x+16-(x%16),y-(y%16),5);
    c_champ((x+16-(x%16))/16,(y-16-(y%16))/16,4);
    }
}


estrella_moneda()  //estrellas con moneda
{
if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==51) //estrellas con moneda
  {
  if(vy<=0)
    {
    vy=-vy;
    puntos=puntos+40;
    monedas++;
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=5;  //caja5
    bloque(x-(x%16),y-(y%16),5);
    cmoneda((x-(x%16))/16,(y-16-(y%16))/16);
    }
  }
else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==51 && x%16!=0)
  {
  if(vy<=0)
    {
    vy=-vy;
    puntos=puntos+40;
    monedas++;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=5;
    bloque(x+16-(x%16),y-(y%16),5);
    cmoneda((x+16-(x%16))/16,(y-16-(y%16))/16);
    }
  }
}


cielo_vida()  //cielo cyan con vida
{
if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==32)  //cielo cyan con vida
  {
  if(vy<=0)
    {
    vy=-vy;
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=5;  //caja5
    bloque(x-(x%16),y-(y%16),5);
    c_champ((x-(x%16))/16,(y-16-(y%16))/16,4);
    }
  }
else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==32 && x%16!=0)
  {
  if(vy<=0)
    {
    vy=-vy;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=5;
    bloque(x+16-(x%16),y-(y%16),5);
    c_champ((x+16-(x%16))/16,(y-16-(y%16))/16,4);
    }
  }
}


cielo_moneda()  //cielo cyan con moneda
{
if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==33) //cielo cyan con moneda
  {
  if(vy<=0)
    {
    vy=-vy;
    puntos=puntos+40;
    monedas++;
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=5;  //caja5
    bloque(x-(x%16),y-(y%16),5);
    cmoneda((x-(x%16))/16,(y-16-(y%16))/16);
    }
  }
else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==33 && x%16!=0)
  {
  if(vy<=0)
    {
    vy=-vy;
    puntos=puntos+40;
    monedas++;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=5;
    bloque(x+16-(x%16),y-(y%16),5);
    cmoneda((x+16-(x%16))/16,(y-16-(y%16))/16);
    }
  }
}


cristal0_moneda()  //cristal con moneda
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==16) //cristal con moneda
    {
    vy=-vy;
    puntos=puntos+40;
    monedas++;
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=5;  //caja5
    bloque(x-(x%16),y-(y%16),5);
    cmoneda((x-(x%16))/16,(y-16-(y%16))/16);
    }
  else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==16 && x%16!=0)
    {
    vy=-vy;
    puntos=puntos+40;
    monedas++;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=5;
    bloque(x+16-(x%16),y-(y%16),5);
    cmoneda((x+16-(x%16))/16,(y-16-(y%16))/16);
    }
}


cristal4_moneda()  //cristal con moneda
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==17) //cristal con moneda
    {
    vy=-vy;
    puntos=puntos+40;
    monedas++;
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=5;  //caja5
    bloque(x-(x%16),y-(y%16),5);
    cmoneda((x-(x%16))/16,(y-16-(y%16))/16);
    }
  else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==17 && x%16!=0)
    {
    vy=-vy;
    puntos=puntos+40;
    monedas++;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=5;
    bloque(x+16-(x%16),y-(y%16),5);
    cmoneda((x+16-(x%16))/16,(y-16-(y%16))/16);
    }
}


cristal0_vida()  //cristal0 con vida
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==18)  //cristal0 con vida
    {
    vy=-vy;
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=5;  //caja5
    bloque(x-(x%16),y-(y%16),5);
    c_champ((x-(x%16))/16,(y-16-(y%16))/16,4);
    }
  else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==18 && x%16!=0)
    {
    vy=-vy;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=5;
    bloque(x+16-(x%16),y-(y%16),5);
    c_champ((x+16-(x%16))/16,(y-16-(y%16))/16,4);
    }
}


cristal4_vida()  //cristal4 con vida
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==19)  //cristal0 con vida
    {
    vy=-vy;
    paisaje[(y-(y%16))/16][(x-(x%16))/16]=5;  //caja5
    bloque(x-(x%16),y-(y%16),5);
    c_champ((x-(x%16))/16,(y-16-(y%16))/16,4);
    }
  else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==19 && x%16!=0)
    {
    vy=-vy;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=5;
    bloque(x+16-(x%16),y-(y%16),5);
    c_champ((x+16-(x%16))/16,(y-16-(y%16))/16,4);
    }
}


bloque_cristal()  //cristal golpe por abajo
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==14 || paisaje[(y-(y%16))/16][(x-(x%16))/16]==15)  //cristal golpe por abajo
    {
    if(estado>1)
      {
      vy=vy+4;
      paisaje[(y-(y%16))/16][(x-(x%16))/16]=75;
      bloque(x-(x%16),y-(y%16),75);
      }  
    else
      {
      y=y+16-(y%16);
      vy=-vy;
      }
    }
  else if((paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==14 || paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==15) && x%16!=0)
    {
    if(estado>1)
      {
      vy=vy+4;
      paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=75;
      bloque(x+16-(x%16),y-(y%16),75);
      }  
    else
      {
      y=y+16-(y%16);
      vy=-vy;
      }
    }
}


bloque_moneda0()  //monedas de oro
{
  if(paisaje[(y-16-(y%16))/16][(x-16-(x%16))/16]==35)  //moneda arriba izquierda
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y-16-(y%16))/16][(x-16-(x%16))/16]=75;
    bloque(x-16-(x%16),y-16-(y%16),75);
    }
  if(paisaje[(y-16-(y%16))/16][(x-(x%16))/16]==35)  //moneda arriba centro
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y-16-(y%16))/16][(x-(x%16))/16]=75;
    bloque(x-(x%16),y-16-(y%16),75);
    }
  if(paisaje[(y-16-(y%16))/16][(x+16-(x%16))/16]==35)  //moneda arriba derecha
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y-16-(y%16))/16][(x+16-(x%16))/16]=75;
    bloque(x+16-(x%16),y-16-(y%16),75);
    }
  if(paisaje[(y-(y%16))/16][(x-16-(x%16))/16]==35)  //moneda centro izquierda
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y-(y%16))/16][(x-16-(x%16))/16]=75;
    bloque(x-16-(x%16),y-(y%16),75); 
    }
  if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==35)  //moneda centro derecha
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=75;
    bloque(x+16-(x%16),y-(y%16),75);
    }
  if(paisaje[(y+16-(y%16))/16][(x-16-(x%16))/16]==35)  //moneda abajo izquierda
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y+16-(y%16))/16][(x-16-(x%16))/16]=75;
    bloque(x-16-(x%16),y+16-(y%16),75);
    }
  if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==35)  //moneda abajo centro
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y+16-(y%16))/16][(x-(x%16))/16]=75;
    bloque(x-(x%16),y+16-(y%16),75);
    }
  if(paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==35)  //moneda abajo derecha
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]=75;
    bloque(x+16-(x%16),y+16-(y%16),75);
    }
}


bloque_moneda4()  //monedas de platino
{
  if(paisaje[(y-16-(y%16))/16][(x-16-(x%16))/16]==34)  //moneda arriba izquierda
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y-16-(y%16))/16][(x-16-(x%16))/16]=64;
    bloque(x-16-(x%16),y-16-(y%16),64);
    }
  if(paisaje[(y-16-(y%16))/16][(x-(x%16))/16]==34)  //moneda arriba centro
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y-16-(y%16))/16][(x-(x%16))/16]=64;
    bloque(x-(x%16),y-16-(y%16),64);
    }
  if(paisaje[(y-16-(y%16))/16][(x+16-(x%16))/16]==34)  //moneda arriba derecha
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y-16-(y%16))/16][(x+16-(x%16))/16]=64;
    bloque(x+16-(x%16),y-16-(y%16),64);
    }
  if(paisaje[(y-(y%16))/16][(x-16-(x%16))/16]==34)  //moneda centro izquierda
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y-(y%16))/16][(x-16-(x%16))/16]=64;
    bloque(x-16-(x%16),y-(y%16),64); 
    }
  if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==34)  //moneda centro derecha
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=64;
    bloque(x+16-(x%16),y-(y%16),64);
    }
  if(paisaje[(y+16-(y%16))/16][(x-16-(x%16))/16]==34)  //moneda abajo izquierda
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y+16-(y%16))/16][(x-16-(x%16))/16]=64;
    bloque(x-16-(x%16),y+16-(y%16),64);
    }
  if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==34)  //moneda abajo centro
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y+16-(y%16))/16][(x-(x%16))/16]=64;
    bloque(x-(x%16),y+16-(y%16),64);
    }
  if(paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==34)  //moneda abajo derecha
    {
    monedas++;
    puntos=puntos+10;
    paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]=64;
    bloque(x+16-(x%16),y+16-(y%16),64);
    }
}


bloque_nota0()  //nota0
{
  if((x%16)!=0)  //nota0  (muy pesado)
    {
    if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==40 || paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==40)  //rebote por arriba
      {
      vy=-6;
      if(tecla[KEY_CUR_ARRIBA])
        {
        vy=-10.0;
        }
      }
    }
  else
  {
    if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==40)  //rebote por arriba
      {
      vy=-6;
      if(tecla[KEY_CUR_ARRIBA])
        {
        vy=-10.0;
        }
      }
  }
  if((x%16)!=0)  //dar chance a equivocarse por un bloque
    {
    if(paisaje[(y+32-(y%16))/16][(x-(x%16))/16]==40 || paisaje[(y+32-(y%16))/16][(x+16-(x%16))/16]==40)
      {
      if(vy<=0)
        {
        if(tecla[KEY_CUR_ARRIBA])
          {
          vy=-10.0;
          }
        }
      }
    }
  else
  {
    if(paisaje[(y+32-(y%16))/16][(x-(x%16))/16]==40)
      {
      if(vy<=0)
        {
        if(tecla[KEY_CUR_ARRIBA])
          {
          vy=-10.0;
          }
        }
      }
  }
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==40)  //rebote por abajo
    {
    y=y-(y%16);
    vy=-vy+4.0;
    }
  else if((paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==40) && x%16!=0)
    {
    y=y-(y%16);
    vy=-vy+4.0;
    }
  if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==40) //rebote derecho de nota0
    {
    vx=-vx-4.0;
    x=x-(x%16);
    }
  else if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==40) //rebote izquierdo de nota 0
    {
    vx=-vx+4.0;
    x=x+16-(x%16);
    }
}


bloque_saltar()  //bloque para saltar muy alto
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==68 || paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==68)  //saltar
    {
    vy=vy-8.0;
    }
}


cielo_abajo()  //flujo de aire hacia abajo
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==53 || paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==53)
    {
    vy=vy+1.0;
    }
}


cielo_arriba()  //flujo de aire hacia arriba
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==54 || paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==54)
    {
    vy=vy-1.0;
    }
}


cielo_izquierda()  //flujo de aire hacia la izquierda
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==55 || paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==55)
    {
    vx=vx-1.0;
    }
}


cielo_derecha()  //flujo de aire hacia la derecha
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==56 || paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==56)
    {
    vx=vx+1.0;
    }
}


agua_abajo()  //flujo de agua hacia abajo
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==57 || paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==57)
    {
    vy=vy+0.5;
    }
}


agua_arriba()  //flujo de agua hacia arriba
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==58 || paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==58)
    {
    vy=vy-1.0;
    }
}


agua_izquierda()  //flujo de agua hacia izquierda
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==59 || paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==59)
    {
    vx=vx-1.0;
    }
}


agua_derecha()  //flujo de agua hacia derecha
{
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==60 || paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==60)
    {
    vx=vx+1.0;
    }
}


bloque_agua()  
{
if((x%16)!=0)
  {
  if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]<32 || paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]<32)  //verificar si hay bloques solidos
    {
    vy=vy+0.5;
    }
  }
else
  {
  if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]<32)  //verificar si hay bloques solidos
    {
    vy=vy+0.5;
    }
  }
if((x%16)!=0)
  {
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==49 && paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==49)
    {
    if(tecla[KEY_CUR_ARRIBA])  //saltar 72
      {
      vy=-2.0;
      }
    vy=vy+0.0625;
    vy=vy-0.5;
    if(vy>2.0)  //aumentar viscocidad segun velocidad
      {
      vy=vy-0.25;
      }
    else if(vy<-2.0)
      {
      vy=vy+0.25;
      }
    if(vx>2.0)
      {
      vx=vx-0.25;
      }
    else if(vx<-2.0)
      {
      vx=vx+0.25;
      }
    }
  }
else
  {
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==49)
    {
    if(tecla[KEY_CUR_ARRIBA])  //saltar 72
      {
      vy=-2.0;
      }
    vy=vy+0.0625;
    vy=vy-0.5;
    if(vy>2.0)  //aumentar viscocidad segun velocidad
      {
      vy=vy-0.25;
      }
    else if(vy<-2.0)
      {
      vy=vy+0.25;
      }
    if(vx>2.0)
      {
      vx=vx-0.25;
      }
    else if(vx<-2.0)
      {
      vx=vx+0.25;
      }
    }
  }
if((x%16)!=0)
  {
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==50 && paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==50)
    {
    if(tecla[KEY_CUR_ARRIBA])  //saltar 72
      {
      vy=-8.0;
      }
    vy=vy+0.0625;
    vy=vy-0.5;
    if(vy>2.0)  //aumentar viscocidad segun velocidad
      {
      vy=vy-0.25;
      }
    else if(vy<-2.0)
      {
      vy=vy+0.25;
      }
    if(vx>2.0)
      {
      vx=vx-0.25;
      }
    else if(vx<-2.0)
      {
      vx=vx+0.25;
      }
    }
  }
else
  {
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==50)
    {
    if(tecla[KEY_CUR_ARRIBA])  //saltar 72
      {
      vy=-8.0;
      }
    vy=vy+0.0625;
    vy=vy-0.5;
    if(vy>2.0)  //aumentar viscocidad segun velocidad
      {
      vy=vy-0.25;
      }
    else if(vy<-2.0)
      {
      vy=vy+0.25;
      }
    if(vx>2.0)
      {
      vx=vx-0.25;
      }
    else if(vx<-2.0)
      {
      vx=vx+0.25;
      }
    }
  }
}


NITRO_mata()  //no toques la nitroglicerina
{
if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==48)
  {
  paisaje[(y-(y%16))/16][(x-(x%16))/16]=75;
  bloque(x-(x%16),y-(y%16),75);
  if(invensible==0)
    {
    estado--;
    invensible=222;
    t_huevo=tiempo-4;  //solo es necesario si su estado es 0
    }
  }
else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==48 && x%16!=0)
  {
  paisaje[(y-(y%16))/16][(x+16-(x%16))/16]=75;
  bloque(x+16-(x%16),y-(y%16),75);
  if(invensible==0)
    {
    estado--;
    invensible=222;
    t_huevo=tiempo-4;  //solo es necesario si su estado es 0
    }
  }
}


fuego4_mata()  //no toques el fuego
{
if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==52)
  {
  if(invensible==0)
    {
    estado--;
    invensible=222;
    t_huevo=tiempo-4;  //solo es necesario si su estado es 0
    }
  }
else if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==52 && x%16!=0)
  {
  if(invensible==0)
    {
    estado--;
    invensible=222;
    t_huevo=tiempo-4;  //solo es necesario si su estado es 0
    }
  }
}


tocar_champinon()  //tocar champi๑on
{
  for(i=0;i<4;i++)
    {
    if(nchamp[i]!=0)
      {
      if(((x-(x%16))/16)==((champx[i]-(champx[i]%16))/16))
        {
        if(((y-(y%16))/16)==((champy[i]-(champy[i]%16))/16))
          {
          switch(nchamp[i])
            {
            case -4:
              elichamp(i);
              vidas++;
              puntos=puntos+100;
            break;
            case -1:
              elichamp(i);
              estado++;
              puntos=puntos+100;
            break;
            case 1:
              elichamp(i);
              estado++;
              puntos=puntos+100;
            break;
            case 4:
              elichamp(i);
              vidas++;
              puntos=puntos+100;
            break;
            }

          }
        }
      }
    }
}


pisar_pato()  //pisar pato
{
  for(i=0;i<8;i++)  //pisar pato
    {
    if(npato[i]!=0)
      {
      if(x-(x%16)==patox[i]-(patox[i]%16) || x-(x%16)==patox[i]+16-(patox[i]%16))
        {
        if(y+16-(y%16)==patoy[i]-(patoy[i]%16))  //+16 para cuando este arriba del pato en -16 sea -16+16=0 y se cumpla
          {
          vy=-2;
          elipato(i);
          puntos=puntos+100;
          }
        }
      }
    }
}


pisar_seguidor()  //pisar seguidor
{
  for(i=0;i<8;i++)  //pisar seguidor
    {
    if(nseguidor[i]!=0)
      {
      if(x-(x%16)==seguidorx[i]-(seguidorx[i]%16) || x-(x%16)==seguidorx[i]+16-(seguidorx[i]%16))
        {
        if(y+16-(y%16)==seguidory[i]-(seguidory[i]%16))  //+16 para cuando este arriba del seguidor en -16 sea -16+16=0 y se cumpla
          {
          vy=-2;
          eliseguidor(i);
          puntos=puntos+100;
          }
        }
      }
    }
}


pisar_salta()  //pisar saltadores
{
  for(i=0;i<4;i++)  //pisar saltadores
    {
    if(nsalta[i]!=0)
      {
      if(x-(x%16)==saltax[i]-(saltax[i]%16) || x-(x%16)==saltax[i]+16-(saltax[i]%16))
        {
        if(y+16-(y%16)==saltay[i]-(saltay[i]%16))  //+16 para cuando este arriba del saltador en -16 sea -16+16=0 y se cumpla
          {
          vy=-2;
          elisalta(i);
          puntos=puntos+100;
          }
        }
      }
    }
}


pisar_peligro()  //pisar patos peligrosos
{
  for(i=0;i<4;i++)  //pisar patos peligrosos
    {
    if(npeligro[i]!=0)
      {
      if(x-(x%16)==peligrox[i]-(peligrox[i]%16) || x-(x%16)==peligrox[i]+16-(peligrox[i]%16))
        {
        if(y+16-(y%16)==peligroy[i]-(peligroy[i]%16))  //+16 para cuando este arriba del peligroso en -16 sea -16+16=0 y se cumpla
          {
          vy=-2;
          elipeligro(i);
          puntos=puntos+100;
          }
        }
      }
    }
}


pato_mata()  //pato mata cuando los tocas
{
  for(i=0;i<8;i++)  //pato mata
    {
    if(npato[i]!=0)
      {
      if(x<=patox[i]+16 && x>=patox[i]-16)
        {
        if(y-(y%16)==patoy[i]-(patoy[i]%16))
          {
          if(invensible==0)
            {
            estado--;
            invensible=222;
            t_huevo=tiempo-4;  //solo es necesario si su estado es 0
            }
          }
        }
      }
    }
}


seguidor_mata()  //seguidor mata cuando los tocas
{
  for(i=0;i<8;i++)  //seguidor mata
    {
    if(nseguidor[i]!=0)
      {
      if(x<=seguidorx[i]+16 && x>=seguidorx[i]-16)
        {
        if(y-(y%16)==seguidory[i]-(seguidory[i]%16))
          {
          if(invensible==0)
            {
            estado--;
            invensible=222;
            t_huevo=tiempo-4;  //solo es necesario si su estado es 0
            }
          }
        }
      }
    }
}


salta_mata()  //saltador mata cuando los tocas
{
  for(i=0;i<4;i++)  //saltador mata
    {
    if(nsalta[i]!=0)
      {
      if(x<=saltax[i]+16 && x>=saltax[i]-16)
        {
        if(y-(y%16)==saltay[i]-(saltay[i]%16))
          {
          if(invensible==0)
            {
            estado--;
            invensible=222;
            t_huevo=tiempo-4;  //solo es necesario si su estado es 0
            }
          }
        }
      }
    }
}


peligro_mata()  //peligroso mata cuando los tocas
{
  for(i=0;i<4;i++)  //peligroso mata
    {
    if(npeligro[i]!=0)
      {
      if(x<=peligrox[i]+16 && x>=peligrox[i]-16)
        {
        if(y-(y%16)==peligroy[i]-(peligroy[i]%16))
          {
          if(invensible==0)
            {
            estado--;
            invensible=222;
            t_huevo=tiempo-4;  //solo es necesario si su estado es 0
            }
          }
        }
      }
    }
}


bloque_cuadrado0()  //puedes pararte sobre el bloque pero no golpearlo por abajo  (pesado)
{
  if((x%16)!=0)
    {
    if((paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==41 || paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==42 || paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==43) && (paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==41 || paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==42 || paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==43))  //gravedad verificando si el bloque de abajo a la izquierda o el bloque de abajo a la derecha es bloque cuadrado 
      {
      if(vy>0)  //determinar si esta cayendo o saltando
        {
        vy=0;
        y=y-(y%16);
        }
      }
    }
  else
    {
    if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==41 || paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==42 || paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==43)  //gravedad verificando si el bloque de abajo a la izquierda es bloque cuadrado 
      {
      if(vy>0)  //determinar si esta cayendo o saltando
        {
        vy=0;
        y=y-(y%16);
        }
      }
    }
  if(tecla[KEY_CUR_ARRIBA])  //saltar
    {
    if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==42 || (paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==42 && x%16!=0))  //bloque cuadrado
      {
      vy=-8.0;
      }
    }
}


bloque_cuadrado1()  //puedes pararte sobre el bloque pero no golpearlo por abajo  (pesado)
{
  if((x%16)!=0)
    {
    if((paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==44 || paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==45 || paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==46) && (paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==44 || paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==45 || paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==46))  //gravedad verificando si el bloque de abajo a la izquierda o el bloque de abajo a la derecha es bloque cuadrado 
      {
      if(vy>0)  //determinar si esta cayendo o saltando
        {
        vy=0;
        y=y-(y%16);
        }
      }
    }
  else
    {
    if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==44 || paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==45 || paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==46)  //gravedad verificando si el bloque de abajo a la izquierda es bloque cuadrado 
      {
      if(vy>0)  //determinar si esta cayendo o saltando
        {
        vy=0;
        y=y-(y%16);
        }
      }
    }
  if(tecla[KEY_CUR_ARRIBA])  //saltar
    {
    if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]==45 || (paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]==45 && x%16!=0))  //bloque cuadrado
      {
      vy=-8.0;
      }
    }
}


panel()
{
  line(0,416,639,416);
  line(0,416,0,479);
  line(0,479,639,479);
  line(639,416,639,479);
}


panelnumerico()
{
  int n;
  gotoxy(4,28);
  printf("Nivel %d-%d ",nivel,escena);
  gotoxy(4,29);
  printf("Vidas %d   ",vidas);
  gotoxy(15,28);
  for(n=0;n<volar;n++)
    {
    printf("฿");
    }
  for(n=volar;n<22;n++)
    {
    printf(" ");
    }
  gotoxy(15,29);
  printf("Puntos %d  ",puntos);
  gotoxy(40,28);
  printf("monedas %d  ",monedas);
  gotoxy(40,29);
  printf("Tiempo %d  ",tiempo);
}


verestado()  //verificar el estado de pato y dibujarlo segun el estado
{
  switch(estado)
    {
    case 0:  //perdiste una vida
      for(j=0;j<16;j++)
        {
        for(i=0;i<16;i++)
          {
          if(huevo[j][i]!=22)
            {
            putpixel(x+i,y+j,huevo[j][i]);
            }
          }
        }
      if(t_huevo==tiempo)  //esperar 4 segundos antes de terminar el nivel
        {
        estado++;
        vidas--;
        ciclo=1;
        jugar=0;
        }
      //musiquita y pantalla de perder
    break;
    case 1:
      for(j=0;j<16;j++)
        {
        for(i=0;i<16;i++)
          {
          if(patito0[j][i]!=22)
            {
            putpixel(x+i,y+j,patito0[j][i]);
            }
          }
        }
    break;
    case 2:
      for(j=0;j<16;j++)
        {
        for(i=0;i<16;i++)
          {
          if(pato0[j][i]!=22)
            {
            putpixel(x+i,y+j,pato0[j][i]);
            }
          }
        }
    break;
    case 3:
      if(vx==0)
        {
        paso=1;
        }
      else
        {
        if((x%8)<=3)
          {
        paso=1;
          }
        else if ((x%8)>=4)
          {
        paso=-1;
          }
        }
      if(dir>0)
        {
        if(paso==1)
          {
          for(j=0;j<16;j++)
            {
            for(i=0;i<16;i++)
              {
              if(pinguino0[j][i]!=22)
                {
                putpixel(x+i,y+j,pinguino0[j][i]);
                }
              }
            }
          }
        if(paso==-1)
          {
          for(j=0;j<16;j++)
            {
            for(i=0;i<16;i++)
              {
              if(pinguino1[j][i]!=22)
                {
                putpixel(x+i,y+j,pinguino1[j][i]);
                }
              }
            }
          }
        }
      if(dir<0)
        {
        if(paso==1)
          {
          for(j=0;j<16;j++)
            {
            for(i=0;i<16;i++)
              {
              if(pinguino2[j][i]!=22)
                {
                putpixel(x+i,y+j,pinguino2[j][i]);
                }
              }
            }
          }
        if(paso==-1)
          {
          for(j=0;j<16;j++)
            {
            for(i=0;i<16;i++)
              {
              if(pinguino3[j][i]!=22)
                {
                putpixel(x+i,y+j,pinguino3[j][i]);
                }
              }
            }
          }
        }
    break;
    case 4:
      if(vx==0)
        {
        paso=1;
        }
      else
        {
        if((x%8)<=3)
          {
        paso=1;
          }
        else if ((x%8)>=4)
          {
        paso=-1;
          }
        }
      if(dir>0)
        {
        if(paso==1)
          {
          for(j=0;j<16;j++)
            {
            for(i=0;i<16;i++)
              {
              if(pinguinorojo0[j][i]!=22)
                {
                putpixel(x+i,y+j,pinguinorojo0[j][i]);
                }
              }
            }
          }
        if(paso==-1)
          {
          for(j=0;j<16;j++)
            {
            for(i=0;i<16;i++)
              {
              if(pinguinorojo1[j][i]!=22)
                {
                putpixel(x+i,y+j,pinguinorojo1[j][i]);
                }
              }
            }
          }
        }
      if(dir<0)
        {
        if(paso==1)
          {
          for(j=0;j<16;j++)
            {
            for(i=0;i<16;i++)
              {
              if(pinguinorojo2[j][i]!=22)
                {
                putpixel(x+i,y+j,pinguinorojo2[j][i]);
                }
              }
            }
          }
        if(paso==-1)
          {
          for(j=0;j<16;j++)
            {
            for(i=0;i<16;i++)
              {
              if(pinguinorojo3[j][i]!=22)
                {
                putpixel(x+i,y+j,pinguinorojo3[j][i]);
                }
              }
            }
          }
        }
    break;
    case 5:
    vidas++;
    estado--;
    break;
    }
}

ayuda()
{
setfillstyle(1,0);  //azul claro
bar(40,8,624,336);
gotoxy(24,2);
printf("AYUDA DE SUPER PATITO BROS");
gotoxy(8,5);
printf("Û Uso del teclado para jugar:");
gotoxy(8,7);
printf("- Usa las flechas en tu teclado para desplazarte");
gotoxy(8,8);
printf("la flecha de arriba es la de saltar.");
gotoxy(8,9);
printf("- F1 como te abras dado cuenta es para abrir este menu de ayuda");
gotoxy(8,10);
printf("- Enter es para pausar y despausar el juego");
gotoxy(8,11);
printf("- ESC es para salir del juego y abrir un menu");
gotoxy(8,12);
printf("- Alt+F4 es para salir del juego sin ningun aviso");
gotoxy(8,15);
printf("Û Como se juega?:");
gotoxy(8,17);
printf("- Avanza siempre hacia la derecha pasando los obstaculos,");
gotoxy(8,18);
printf("al llegar a la orrila derecha de la pantalla pasaras ala siguente escena");
gotoxy(20,21);
printf("PRESIONA CUALQUIER TECLA PARA CONTINUAR");
bioskey(0);  //funciona igual que getch(); pero getch(); no funciona
fondo();
panel();
}


pausa()
{
int x2,y2;
for(y2=0;y2<16;y2++)
  {
  for(x2=0;x2<16;x2++)
    {
    putpixel(x2+304,y2+208,pausa0[y2][x2]);
    }
  }
for(y2=0;y2<16;y2++)
  {
  for(x2=0;x2<16;x2++)
    {
    putpixel(x2+320,y2+208,pausa1[y2][x2]);
    }
  }
delay(200);
while(!tecla[KEY_ENTER])
  {
  }
fondo();
panel();
}


segundos()
{
sec++;
if(sec%22==0)  //realizar un conteo del tiempo del juego
  {
  sec=0;
  tiempo--;
  if(tiempo==0)
    {
    estado=0;
    }
  if(tiempo%2==0)  //para volar
    {
    volar++;
    if(volar>22)
      {
      volar=22;
      }
    }
  }
}


patofuera()
{
int n;
for(n=0;n<8;n++)
  {
  if(patox[n]>=624) //si llega a la orilla derecha eliminar pato
    {
    elipato(n);
    }
  else if(patox[n]<=0) //si llega a la orilla izquierda eliminar pato
    {
    elipato(n);
    }
  else if(patoy[n]>=464) //caida
    {
    elipato(n);
    }
  }
}


seguidorfuera()
{
int n;
for(n=0;n<8;n++)
  {
  if(seguidorx[n]>=624) //si llega a la orilla derecha eliminar seguidor
    {
    eliseguidor(n);
    }
  else if(seguidorx[n]<=0) //si llega a la orilla izquierda eliminar seguidor
    {
    eliseguidor(n);
    }
  else if(seguidory[n]>=464) //caida
    {
    eliseguidor(n);
    }
  }
}


saltafuera()
{
int n;
for(n=0;n<4;n++)
  {
  if(saltax[n]>=624) //si llega a la orilla derecha eliminar saltador
    {
    elisalta(n);
    }
  else if(saltax[n]<=0) //si llega a la orilla izquierda eliminar saltador
    {
    elisalta(n);
    }
  else if(saltay[n]>=464) //caida
    {
    elisalta(n);
    }
  }
}


peligrofuera()
{
int n;
for(n=0;n<4;n++)
  {
  if(peligrox[n]>=624) //si llega a la orilla derecha eliminar peligroso
    {
    elipeligro(n);
    }
  else if(peligrox[n]<=0) //si llega a la orilla izquierda eliminar peligroso
    {
    elipeligro(n);
    }
  else if(peligroy[n]>=464) //caida
    {
    elipeligro(n);
    }
  }
}


champifuera()
{
int n;
for(n=0;n<4;n++)
  {
  if(champx[n]>=624) //si llega a la orilla derecha eliminar champi๑on
    {
    elichamp(n);
    }
  else if(champx[n]<=-4) //si llega a la orilla izquierda eliminar champi๑on
    {
    elichamp(n);
    }
  else if(champy[n]>=464) //caida
    {
    elichamp(n);
    }
  }
}


teclado()
{
teclaso=0;
  if(teclaso == 0);
    {
    if(vx<0)  //disminuir la velocidad
      {
      vx=vx+0.0625;
      }
    else if(vx>0)
      {
      vx=vx-0.0625;
      }
   /* if(vy<0)  //disminuir la velocidad (no se requiere)
      {
      vy=vy+0.125;
      }
    else if(vy>0)
      {
      vy=vy-0.125;
      }*/
    }
  if(tecla[KEY_CUR_ATRAS])  //izquierda 75
    {
    vx=vx-0.5;
    dir=-1;
    }
  if(tecla[KEY_CUR_ADELANTE])  //derecha 77
    {
    dir=1;
    if(vx<1 && vx>=0)  //esto no deberia existir pero hay problemas para avanzar a la derecha
      {
      vx=vx+1.0;
      }
    vx=vx+0.5;
    }
  if(tecla[KEY_ESPACIO])  //espacio volar 32
    {
    if(volar>0)
      {
      volar--;
      vy=-4.0;
      }
    }
  if(tecla[KEY_CUR_ARRIBA])  //saltar 72
    {
    if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]<32 || (paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]<32 && x%16!=0))  //bloques en general
      {
      vy=-8.0;
      }
    }
  if(tecla[KEY_ENTER])  //enter pausar el juego
    {
    pausa();
    }
  if(tecla[KEY_DELETE])  //suprimir  truco: elimina patos
    {
    r_pato();
    r_seguidor();
    r_salta();
    r_peligro();
    }
  if(tecla[KEY_F4])  //Alt+F4 salir
    {
    DesinstalaTeclado();
    exit (2);
    }
  if(tecla[KEY_F1])  //F1 ayuda 
    {
    ayuda();
    }
  if(tecla[KEY_ESC])  //esc 27
    {
    //menu();
    }
  if(vx>4)  //limite de velocidad
    {
    vx=4;
    }
  if(vy>8)  //limite de velocidad (gravedad)
    {
    vy=8;
    }
  if(vx<-4)  //limite de velocidad
    {
    vx=-4;
    }
  /*if(vy<-4)  //limite de velocidad (no requiere)
    {
    vy=-4;
    }*/
}



main()
{
textmode(64);  //C4350
Patito();
Thierry();
Inicio();
//memoria();
detectargraficos();

if(kbhit())  //si se presiono una tecla para omitir la presentacion, pedir que se presione una vez mas una tecla para iniciar el juego
  {
  getch();
  }

getch();
iniciargraficos();
InstalaTeclado();
randomize();

while(seguir!=0)
  {
    abrir(0,-88);
    mundo0();
    jugar=1;
  while(jugar!=0)
    {
    switch (nivel)
      {
      case 0:
        switch (escena)
          {
          case 0:
            escena00();
            break;
          case 1:
            escena01();
          break;
          case 2:
            escena02();
          break;
          case 3:
            escena03();
          break;
          case 20:
            escena0_20();
          break;
          default:
            jugar=0;
          break;
          }
      break;
      case 1:
        switch (escena)
          {
          case 0:
            escena10();
            break;
          case 1:
            escena11();
          break;
          case 2:
            escena12();
          break;
          case 3:
            escena13();
          break;
          case 20:
            escena1_20();
          break;
          default:
            jugar=0;
          break;
          }
      break;
      case 2:
        switch (escena)
          {
          case 0:
            escena20();
            break;
          case 1:
            escena21();
          break;
          case 2:
            escena22();
          break;
          case 3:
            escena23();
          break;
          case 20:
            escena2_20();
          break;
          default:
            jugar=0;
          break;
          }
      break;
      case 3:
        switch (escena)
          {
          case 0:
            escena30();
            break;
          case 1:
            escena31();
          break;
          case 2:
            escena32();
          break;
          case 3:
            escena33();
          break;
          case 20:
            escena3_20();
          break;
          default:
            jugar=0;
          break;
          }
      break;
      default:
      break;
      }
    }
  }
DesinstalaTeclado();
closegraph();
return(0);
}