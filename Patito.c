#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

int geexbox;
int paisaje[30][40]={43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,4 ,4 ,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,4 ,4 ,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,15,15,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,14,14,14,14,4 ,14,14,4 ,14,14,14,14,14,43,43,43,43,10,10,10,10,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,9 ,9 ,9 ,9 ,43,43,43,25,26,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,4 ,4 ,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,4 ,4 ,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,8 ,43,43,8 ,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,9 ,9 ,9 ,9 ,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,24,43,43,43,43,7 ,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,14,14,14,23,43,43,7 ,7 ,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,15,15,43,43,43,43,43,43,43,43,43,14,43,43,43,43,43,43,7 ,7 ,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,43,43,7 ,7 ,7 ,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		     43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43};

int piso0 [16][16]={  //revisar colores
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
14,15,15,15,15,14,14,14,14,15,15,15,15,14,14,14,
14,14,15,15,15,15,14,14,14,14,15,15,15,15,14,14,
14,0 ,0 ,0 ,14,14,14,14,14,0 ,0 ,0 ,14,14,14,14,
14,14,0 ,0 ,0 ,0 ,14,14,14,14,0 ,0 ,0 ,0 ,14,14,
14,14,14,14,0 ,0 ,0 ,0 ,14,14,14,14,0 ,0 ,0 ,14,
14,14,14,14,14,14,0 ,0 ,0 ,0 ,14,14,14,0 ,0 ,0 ,
0 ,14,14,14,14,14,14,14,0 ,0 ,0 ,14,14,14,0 ,0 ,
0 ,0 ,0 ,14,14,14,14,14,14,0 ,0 ,0 ,14,14,14,14,
14,14,0 ,0 ,14,14,14,14,14,14,0 ,0 ,0 ,14,14,14,
14,14,14,0 ,0 ,0 ,14,14,14,14,14,0 ,0 ,0 ,0 ,14,
};

int caja0 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,0 ,14,14,14,14,14,14,14,14,14,14,0 ,14,0 ,
0 ,14,14,14,15,15,15,15,15,15,15,14,14,14,14,0 ,
0 ,14,14,15,15,15,15,15,15,15,15,15,14,14,14,0 ,
0 ,14,14,15,15,15,0 ,0 ,0 ,0 ,15,15,0 ,14,14,0 ,
0 ,14,14,14,0 ,0 ,0 ,14,14,15,15,15,0 ,14,14,0 ,
0 ,14,14,14,14,14,14,15,15,15,15,0 ,0 ,14,14,0 ,
0 ,14,14,14,14,14,14,15,15,15,0 ,0 ,14,14,14,0 ,
0 ,14,14,14,14,14,14,14,0 ,0 ,0 ,14,14,14,14,0 ,
0 ,14,14,14,14,14,14,15,15,15,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,14,15,15,15,0 ,14,14,14,14,0 ,
0 ,14,14,14,14,14,14,14,0 ,0 ,0 ,14,14,14,14,0 ,
0 ,14,0 ,14,14,14,14,14,14,14,14,14,14,0 ,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int caja1 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,0 ,14,14,14,14,14,14,14,14,14,14,0 ,14,0 ,
0 ,14,14,14,14,14,14,15,15,15,15,15,15,15,14,0 ,
0 ,14,14,14,14,14,15,15,15,15,15,15,15,15,15,0 ,
0 ,14,14,14,14,14,15,15,15,0 ,0 ,0 ,0 ,15,15,0 ,
0 ,14,14,14,14,14,14,0 ,0 ,0 ,14,14,15,15,15,0 ,
0 ,14,14,14,14,14,14,14,14,14,15,15,15,15,0 ,0 ,
0 ,14,14,14,14,14,14,14,14,14,15,15,15,0 ,0 ,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,0 ,0 ,0 ,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,15,15,15,14,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,15,15,15,0 ,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,0 ,0 ,0 ,14,0 ,
0 ,14,0 ,14,14,14,14,14,14,14,14,14,14,0 ,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int caja2 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,0 ,14,14,14,14,14,14,14,14,14,14,0 ,14,0 ,
0 ,15,14,14,14,14,14,14,14,14,14,14,15,15,15,0 ,
0 ,15,15,14,14,14,14,14,14,14,14,15,15,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,15,15,15,0 ,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,14,0 ,0 ,0 ,0 ,
0 ,15,0 ,0 ,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,0 ,0 ,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,0 ,14,14,14,14,14,14,14,14,14,14,0 ,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int caja3 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,0 ,14,14,14,14,14,14,14,14,14,14,0 ,14,0 ,
0 ,15,15,15,15,15,14,14,14,14,14,14,14,14,14,0 ,
0 ,15,15,15,15,15,15,14,14,14,14,14,14,14,14,0 ,
0 ,0 ,0 ,0 ,0 ,15,15,0 ,14,14,14,14,14,14,14,0 ,
0 ,0 ,14,14,15,15,15,0 ,14,14,14,14,14,14,14,0 ,
0 ,14,15,15,15,15,0 ,0 ,14,14,14,14,14,14,14,0 ,
0 ,14,15,15,15,0 ,0 ,14,14,14,14,14,14,14,14,0 ,
0 ,14,14,0 ,0 ,0 ,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,15,15,15,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,15,15,15,0 ,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,14,0 ,0 ,0 ,14,14,14,14,14,14,14,14,14,0 ,
0 ,14,0 ,14,14,14,14,14,14,14,14,14,14,0 ,14,0 ,
0 ,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int nube [16][16]={
11,11,11,0 ,0 ,0 ,0 ,11,11,0 ,0 ,0 ,0 ,11,11,11,
11,11,0 ,15,15,15,15,0 ,0 ,15,15,15,15,0 ,11,11,
11,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,11,
11,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,11,
11,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,11,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,15,15,15,15,0 ,15,15,15,15,0 ,15,15,15,15,0 ,
11,0 ,15,15,15,15,0 ,0 ,0 ,0 ,15,15,15,15,0 ,11,
11,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,11,
11,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,11,
11,11,0 ,15,15,15,15,0 ,0 ,15,15,15,15,0 ,11,11,
11,11,11,0 ,0 ,0 ,0 ,11,11,0 ,0 ,0 ,0 ,11,11,11,
};

int cristal0 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,14,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,14,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,14,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,14,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,14,14,14,14,14,0 ,15,15,0 ,14,14,14,14,14,0 ,
0 ,14,14,14,14,14,0 ,15,15,0 ,14,14,14,14,14,0 ,
0 ,15,15,14,14,14,0 ,15,15,0 ,15,15,14,14,14,0 ,
0 ,14,14,14,14,14,0 ,15,15,0 ,15,15,14,14,14,0 ,
0 ,14,14,14,14,14,0 ,15,15,0 ,14,14,14,14,14,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int cristal1 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,14,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,14,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,14,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,14,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,14,14,14,14,14,0 ,15,15,0 ,14,14,15,15,15,0 ,
0 ,14,14,14,14,14,0 ,15,15,0 ,14,15,15,15,15,0 ,
0 ,15,15,14,14,14,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,14,14,14,14,14,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,14,14,14,14,14,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int cristal2 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,14,15,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,14,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,14,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,14,14,14,14,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,14,14,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,14,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,14,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,14,14,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,14,14,14,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int cristal3 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,14,14,14,14,14,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,14,14,14,14,14,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,14,14,14,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,14,14,14,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,14,14,14,14,14,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int cristal4 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,0 ,
0 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,0 ,
0 ,15,15,3 ,3 ,3 ,0 ,15,15,0 ,15,15,3 ,3 ,3 ,0 ,
0 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,15,15,3 ,3 ,3 ,0 ,
0 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int cristal5 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,3 ,3 ,15,15,15,0 ,
0 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,3 ,15,15,15,15,0 ,
0 ,15,15,3 ,3 ,3 ,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,3 ,3 ,3 ,3 ,3 ,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int cristal6 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,15,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,3 ,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,3 ,3 ,3 ,3 ,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,3 ,3 ,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,3 ,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,3 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,3 ,3 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,3 ,3 ,3 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int cristal7 [16][16]={
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,0 ,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,3 ,3 ,3 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,3 ,3 ,3 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,3 ,3 ,3 ,3 ,3 ,0 ,
0 ,15,15,15,15,15,0 ,15,15,0 ,15,15,15,15,15,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
};

int poder0 [16][16]={
11,11,11,11,11,0 ,0 ,0 ,0 ,0 ,0 ,11,11,11,11,11,
11,11,11,0 ,0 ,11,11,1 ,1 ,1 ,1 ,0 ,0 ,11,11,11,
11,11,0 ,11,11,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,11,11,
11,0 ,11,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,11,
11,0 ,11,1 ,1 ,0 ,11,11,11,11,11,0 ,1 ,1 ,0 ,11,
0 ,11,1 ,1 ,1 ,0 ,11,11,0 ,0 ,11,0 ,1 ,1 ,1 ,0 ,
0 ,11,1 ,1 ,1 ,0 ,11,11,0 ,0 ,11,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,11,11,11,11,11,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,11,11,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,11,11,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0 ,
0 ,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0 ,
};

int poder1 [16][16]={
11,11,11,11,11,0 ,0 ,0 ,0 ,0 ,0 ,11,11,11,11,11,
11,11,11,0 ,0 ,11,11,1 ,1 ,1 ,1 ,0 ,0 ,11,11,11,
11,11,0 ,11,11,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,11,11,
11,0 ,11,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,11,
11,0 ,11,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,11,
0 ,11,1 ,1 ,1 ,0 ,1 ,1 ,0 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,
0 ,11,1 ,1 ,1 ,0 ,1 ,1 ,0 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0 ,
0 ,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0 ,
};

int poder2 [16][16]={
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,11,11,11,11,
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0 ,
0 ,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0 ,
};

int poder4 [16][16]={
11,11,11,11,11,0 ,0 ,0 ,0 ,0 ,0 ,11,11,11,11,11,
11,11,11,0 ,0 ,11,11,1 ,1 ,1 ,1 ,0 ,0 ,11,11,11,
11,11,0 ,11,11,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,11,11,
11,0 ,11,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,11,
11,0 ,11,1 ,1 ,0 ,11,11,11,11,11,0 ,1 ,1 ,0 ,11,
0 ,11,1 ,1 ,1 ,0 ,11,11,0 ,0 ,11,0 ,1 ,1 ,1 ,0 ,
0 ,11,1 ,1 ,1 ,0 ,11,11,0 ,0 ,11,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,11,11,11,11,11,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,11,11,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,11,11,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
};

int poder5 [16][16]={
11,11,11,11,11,0 ,0 ,0 ,0 ,0 ,0 ,11,11,11,11,11,
11,11,11,0 ,0 ,11,11,1 ,1 ,1 ,1 ,0 ,0 ,11,11,11,
11,11,0 ,11,11,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,11,11,
11,0 ,11,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,11,
11,0 ,11,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,11,
0 ,11,1 ,1 ,1 ,0 ,1 ,1 ,0 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,
0 ,11,1 ,1 ,1 ,0 ,1 ,1 ,0 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
};

int poder6 [16][16]={
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,11,11,11,11,
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
};

int nota0 [16][16]={
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
0 ,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,0 ,0 ,0 ,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,0 ,
0 ,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,0 ,
0 ,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,15,0 ,
0 ,15,15,15,15,0 ,0 ,0 ,0 ,15,15,15,15,15,15,0 ,
0 ,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,0 ,
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
};

int nota1 [16][16]={
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
0 ,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,0 ,
0 ,15,15,15,15,15,15,15,15,15,0 ,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,0 ,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,0 ,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,0 ,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,0 ,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,0 ,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,0 ,0 ,0 ,0 ,15,15,15,15,0 ,
0 ,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,15,0 ,
0 ,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,15,0 ,
0 ,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,0 ,0 ,0 ,0 ,15,15,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,0 ,
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
};

int nota2 [16][16]={
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
0 ,0 ,15,15,15,15,15,15,15,15,15,0 ,15,15,0 ,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,0 ,0 ,0 ,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,0 ,
0 ,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,0 ,
0 ,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,15,0 ,
0 ,15,15,15,15,0 ,0 ,0 ,0 ,15,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,0 ,
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
};

int nota3 [16][16]={
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
0 ,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,0 ,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,0 ,0 ,0 ,0 ,15,15,0 ,
0 ,15,15,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,15,15,0 ,
0 ,15,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,0 ,
0 ,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,15,15,0 ,
0 ,15,15,15,15,15,0 ,0 ,0 ,0 ,15,15,15,15,15,0 ,
0 ,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0 ,
0 ,0 ,15,15,15,15,15,15,15,15,15,15,15,15,0 ,0 ,
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
};

int madera [16][16]={
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
0 ,0 ,15,15,15,15,6 ,6 ,6 ,6 ,6 ,15,15,15,0 ,0 ,
0 ,15,15,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,15,15,0 ,
0 ,15,6 ,0 ,0 ,0 ,0 ,6 ,6 ,6 ,6 ,0 ,0 ,6 ,15,0 ,
0 ,15,6 ,6 ,6 ,6 ,0 ,0 ,0 ,0 ,6 ,6 ,0 ,6 ,6 ,0 ,
0 ,15,6 ,6 ,6 ,6 ,6 ,6 ,6 ,0 ,6 ,6 ,6 ,0 ,6 ,0 ,
0 ,15,6 ,0 ,0 ,0 ,6 ,6 ,6 ,0 ,0 ,6 ,6 ,0 ,6 ,0 ,
0 ,15,6 ,6 ,0 ,0 ,0 ,6 ,6 ,6 ,0 ,6 ,6 ,0 ,6 ,0 ,
0 ,15,6 ,6 ,6 ,6 ,0 ,0 ,6 ,6 ,0 ,6 ,6 ,0 ,6 ,0 ,
0 ,15,6 ,6 ,6 ,6 ,6 ,0 ,6 ,6 ,0 ,6 ,6 ,0 ,6 ,0 ,
0 ,15,6 ,6 ,6 ,6 ,0 ,6 ,6 ,6 ,0 ,6 ,6 ,0 ,6 ,0 ,
0 ,15,6 ,6 ,6 ,0 ,0 ,6 ,6 ,0 ,0 ,6 ,0 ,0 ,6 ,0 ,
0 ,6 ,6 ,0 ,0 ,0 ,6 ,6 ,6 ,0 ,6 ,6 ,0 ,6 ,6 ,0 ,
0 ,6 ,6 ,6 ,6 ,6 ,6 ,0 ,0 ,6 ,6 ,0 ,0 ,6 ,6 ,0 ,
0 ,0 ,6 ,6 ,6 ,0 ,0 ,0 ,6 ,6 ,0 ,0 ,6 ,6 ,0 ,0 ,
11,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,
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

int moneda2 [16][16]={
15,15,15,15,15,15,15,0 ,0 ,15,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,0 ,14,14,0 ,15,15,15,15,15,15,
15,15,15,15,15,15,15,0 ,0 ,15,15,15,15,15,15,15,
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
gotoxy(7,3);    cprintf("�    nombre juego en C por Thierry Joseph Valery Garcia Greiner        �");
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


bloque(int i, int j, int T)
{
int x,y;

switch (T)
  {
  case 0:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,piso0[y][x]);
	}
      }
  break;
  case 1:

  break;
  case 2:  //patito
  break;
  case 3:
  break;
  case 4:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,caja0[y][x]);
	}
      }
  break;
  case 5:
  break;
  case 6:
  break;
  case 7:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,madera[y][x]);
	}
      }
  break;
  case 8:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,nota0[y][x]);
	}
      }
  break;
  case 9:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,moneda0[y][x]);
	}
      }
  break;
  case 10:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,nube[y][x]);
	}
      }
  break;
  case 11:
  break;
  case 12:
  break;
  case 13:
  break;
  case 14:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,cristal0[y][x]);
	}
      }
  break;
  case 15:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,cristal4[y][x]);
	}
      }
  break;
  case 16:
  break;
  case 17:
  break;
  case 18:
  break;
  case 19:
  break;
  case 20:
  break;
  case 21:
  break;
  case 22:
  break;
  case 23:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,poder0[y][x]);
	}
      }
  break;
  case 24:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,poder2[y][x]);
	}
      }
  break;
  case 25:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,poder4[y][x]);
	}
      }
  break;
  case 26:
    for(y=0;y<16;y++)
      {
      for(x=0;x<16;x++)
	{
	putpixel(x+i,y+j,poder6[y][x]);
	}
      }
  break;
  case 27:
  break;
  case 28:
  break;
  case 29:
  break;
  case 30:
  break;
  case 31:
  break;
  case 32:
    setfillstyle(1,0);
    bar(i,j,i+15,j+15);  //15 es para que no borre un pixel de la siguiente figura
  break;
  case 33:
    setfillstyle(1,1);
    bar(i,j,i+15,j+15);
  break;
  case 34:
    setfillstyle(1,2);
    bar(i,j,i+15,j+15);
  break;
  case 35:
    setfillstyle(1,3);
    bar(i,j,i+15,j+15);
  break;
  case 36:
    setfillstyle(1,4);
    bar(i,j,i+15,j+15);
  break;
  case 37:
    setfillstyle(1,5);
    bar(i,j,i+15,j+15);
  break;
  case 38:
    setfillstyle(1,6);
    bar(i,j,i+15,j+15);
  break;
  case 39:
    setfillstyle(1,7);
    bar(i,j,i+15,j+15);
  break;
  case 40:
    setfillstyle(1,8);
    bar(i,j,i+15,j+15);
  break;
  case 41:
    setfillstyle(1,9);
    bar(i,j,i+15,j+15);
  break;
  case 42:
    setfillstyle(1,10);
    bar(i,j,i+15,j+15);
  break;
  case 43:
    setfillstyle(1,11);
    bar(i,j,i+15,j+15);
  break;
  case 44:
    setfillstyle(1,12);
    bar(i,j,i+15,j+15);
  break;
  case 45:
    setfillstyle(1,13);
    bar(i,j,i+15,j+15);
  break;
  case 46:
    setfillstyle(1,14);
    bar(i,j,i+15,j+15);
  break;
  case 47:
    setfillstyle(1,15);
    bar(i,j,i+15,j+15);
  break;
  default:
  break;
  }

return (0);
}


fondo()
{
int x,y;
for(y=0;y<30;y++)
  {
  for(x=0;x<40;x++)
    {
      bloque(x*16,y*16,paisaje[y][x]);
    }
  }
}


juego()
{
int ciclo=0,tecla,x=0,y=0;
float vx=0,vy=0;
fondo();
while(ciclo<1)
  {
  tecla=0;
			     //el modulo es para que aparesca el bloque alineado a los demas
  if((x%16)!=0)  // comprobar que bloques necesitan actualizarse
    {
    bloque(x-(x%16),y-(y%16),paisaje[(y-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta arriba a la izquierda
    bloque(x-(x%16)+16,y-(y%16),paisaje[(y-(y%16))/16][(x+16-(x%16))/16]);  //actualizar bloque que esta arriba a la derecha
    if((y%16)!=0)
      {
      bloque(x-(x%16),y-(y%16)+16,paisaje[(y+16-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta abajo a la izquierda
      bloque(x-(x%16)+16,y-(y%16)+16,paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]);  //actualizar bloque que esta abajo a la izquierda
      }
    }
  else if((y%16)!=0)
    {
    bloque(x-(x%16),y-(y%16),paisaje[(y-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta arriba a la izquierda
    bloque(x-(x%16),y-(y%16)+16,paisaje[(y+16-(y%16))/16][(x-(x%16))/16]);  //actualizar bloque que esta abajo a la izquierda
    }

  if(kbhit())
    {
    tecla=getch();
    }
  if(tecla=='\0')  //ninguna tecla
    {
    gotoxy(1,1);
    printf(" no tecla vx=%f  vy=%f   ",vx,vy);
    if(vx<0)  //disminuir la velocidad
      {
      vx=vx+0.125;
      }
    else if(vx>0)
      {
      vx=vx-0.125;
      }
    if(vy<0)  //disminuir la velocidad
      {
      vy=vy+0.125;
      }
    else if(vy>0)
      {
      vy=vy-0.125;
      }
    }
  if(tecla==75)  //izquierda
    {
    vx=vx-0.5;
    }
  if(tecla==77)  //derecha
    {
    vx=vx+0.5;
    }
  if(tecla==80)  //arriba
    {
    vy=vy+0.5;
    }
  if(tecla==72)  //abajo
    {
    vy=vy-0.5;
    }
  if(tecla==27)  //esc
    {
    ciclo=1;
    }
  if(vx>4)  //limite de velocidad
    {
    vx=4;
    }
  if(vy>4)  //limite de velocidad
    {
    vy=4;
    }
  if(vx<-4)  //limite de velocidad
    {
    vx=-4;
    }
  if(vy<-4)  //limite de velocidad
    {
    vy=-4;
    }

  x=x+vx;
  y=y+vy;

  setfillstyle(1,15);
  bar(x,y,x+15,y+15);
  delay(16);
  }
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