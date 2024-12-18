#ifndef _PATITO2_H
#define _PATITO2_H

int bloque0(int i2, int j2, int T);
int bloque_ventana(int i2, int j2, int T);
void r_cristalroto();
void c_cristalroto(int i, int j);
void refcristalroto(int n);
void dibcristalroto();
void r_pato();
void c_pato(int i, int j);
void movpato();
void dibpatos();
void elipato(int i);
void posicion_pato();
void refpato();
void pisar_pato();
void pato_mata();
void patofuera();
void r_salta();
void c_salta(int i, int j);
void movsalta();
void dibsalta();
void elisalta(int i);
void posicion_salta();
void refsalta();
void pisar_salta();
void salta_mata();
void saltafuera();
void r_seguidor();
void c_seguidor(int i, int j);
void movseguidor();
void dibseguidor();
void eliseguidor(int i);
void posicion_seguidor();
void refseguidor();
void pisar_seguidor();
void seguidor_mata();
void seguidorfuera();
void r_peligro();
void c_peligro(int i, int j);
void movpeligro();
void dibpeligro();
void elipeligro(int i);
void posicion_peligro();
void refpeligro();
void pisar_peligro();
void peligro_mata();
void peligrofuera();
void r_bala();
void c_bala(int i, int j,int velx,int vely, int T);
void elibala(int i);
void movbala();
void posicion_bala();
void refbala();
void dibbala();
void pisar_bala();
void balafuera();
void bala_mata();
void r_tortuga();
void c_tortuga(int i, int j, int T);
void movtortuga();
void dibtortugas();
void elitortuga(int i);
void posicion_tortuga();
void reftortuga();
void pisar_tortuga();
void tortuga_mata();
void tortugafuera();
void bloque_caja0_calavera();
void bloque_caja4_moneda();
void bloque_caja4_10monedas();
void bloque_caja4_champinon();
void bloque_caja4_vida();
void bloque_caja4_calavera();
void bloque_madera_moneda();
void bloque_madera_champinon();
void bloque_madera_vida();
void bloque_hielo_champinon();
void bloque_hielo_vida();
void cristal0_10monedas();
void cristal0_champinon();
void cristal4_10monedas();
void cristal4_champinon();
void cielo_duro_moneda();
void cielo_champinon();
void estrellas_champinon();
void estrellas_vida();
void golpear_bloque(int i, int j);
void kill_npc(int i, int j);
void kick_tortuga(int i, int j);
void obtener_segundos();
void ajuste_FPS();
void detectarblq();
void cargar_configuracion();
void cargar_enemigos();
void ayuda_mundo();
void presentacion();

#endif
