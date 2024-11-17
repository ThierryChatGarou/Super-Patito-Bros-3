#ifndef _PATITO1_H
#define _PATITO1_H

int bloque(int i2, int j2, int T);
int bloque_editor(int i2, int j2, int T);
void texto(int i2, int j2, int colorfondo,int colortexto, char *txt);
void c_explosion_chica(int i, int j);
void r_explosionc();
void refexplosionc(int m);
void transicion_explosionc(int m);
void dibexplosion_chica();
void c_golpe(int i, int j);
void refgolpe(int n);
void dibgolpe();
void c_ventana(int i1, int j1, int i2, int j2);

#endif
