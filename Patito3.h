#ifndef _PATITO3_H
#define _PATITO3_H

void bmp16(int i, int j, char *nombrearchivo, char cambiar_paleta);
void paleta_predeterminada();
void paleta_negra();
void oscurecer_paleta(int numero_de_cambios);
void blanquear_paleta(int numero_de_cambios);
int verificar_archivo(char *file_name);
void verificar_existencia();
void panel_debug_mundo();
void panel_debug_nivel();
void capturar_animacion();
void test_velocidad_paleta();

#endif
