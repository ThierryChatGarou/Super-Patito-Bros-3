#ifndef _PATITO_H
#define _PATITO_H

#ifndef __WIN32__
#define MSDOS
#endif

#ifdef MSDOS
void render_opengl_windows();
void wait_foreground();
#endif

void Patito();
void Thierry();
void Inicio();
void errorgraficos();
void detectargraficos();
void iniciargraficos();
void abrir(int nivel,int escena);
void abrircielo(int nivel,int escena);
void r_mina();
void r_champ();
void rmonedas();
void c_mina(int i, int j);
void c_champ(int i, int j, int T);
void cmoneda(int i, int j);
void movmina();
void movchamp();
void dibmina();
void dibchamp();
void elichamp(int i);
void elimina(int i);
void posicion_champ();
void posicion_mina();
void posicion_disparo();
void refchamp();
void refmina();
void mdemone();
void convertir();
void convertbloqmon();
void act_cielo(int T);
void act_fondo(int T);
void guardar_fondo(int T);
void fondo();
void fondomundo();
void refbloques();
void refbloquemundo();
void tinvensible();
void bloque_poder0();
void bloque_caja0_moneda();
void bloque_caja0_10monedas();
void bloque_caja0_champinon();
void bloque_caja0_vida();
void estrella_moneda();
void cielo_vida();
void cielo_moneda();
void cristal0_moneda();
void cristal4_moneda();
void cristal0_vida();
void cristal4_vida();
void bloque_cristal();
void bloque_moneda0();
void bloque_moneda4();
void bloque_nota0();
void bloque_saltar();
void cielo_abajo();
void cielo_arriba();
void cielo_izquierda();
void cielo_derecha();
void agua();
void agua_abajo();
void agua_arriba();
void agua_izquierda();
void agua_derecha();
void bloque_agua();
void eliNITRO(int i, int j);
void NITRO_mata();
void fuego4_mata();
void tocar_champinon();
void mina_mata();
void bloque_cuadrado0();
void bloque_cuadrado1();
void panel();
void panelnumerico();
void verestado();
void ayuda();
void pausa();
void segundos();
void champifuera();
void r_disparo();
void c_disparo();
void elidisparo(int i);
void movdisparo();
void dibdisparo();
void refdisparo();
void disparofuera();
void disparo_mata();
void control();
void bloques_solidos();
void sistema_colisiones();
void teclado();
int main();


#endif
