#ifndef _EDITOR_H
#define _EDITOR_H



void botones_editor(int i2, int j2, int T);
void mostrar_raton();
void ocultar_raton();
void estado_boton_posicion();
void fondoeditor(int n);
void abrir_editor(char *nombrearchivo);
void abrir_archivo(char nombrearchivo[128]);
void guardar_archivo(char *nombrearchivo);
int tomarletra();
void escan(int i, int j);
void ayuda_editor();
void editornivel();

#endif
