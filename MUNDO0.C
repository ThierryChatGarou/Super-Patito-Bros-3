extern int ciclo,tiempo,t_volar,retraso,x,y,o,p,invensible,dir,nivel,escena,vidas,mundo,monedas,estado,nadando,jugar,t_huevo,npato[8],sec,t_moneda,paisaje[30][40],niv1[30][40];
extern float vx,vy;
extern unsigned char tecla[128];

#include"teclas.h"

//=========================================================================================================
//==                                            niveles                                                  ==
//=========================================================================================================


mundo0()
{
ciclo=0;
tiempo=0;
invensible=0;
x=32;
y=32;
vx=0;
vy=0;
fondomundo();
panel();

while(ciclo<1)
  {
////////operaciones del los bloques

  refbloquemundo();  //actualizar bloques
  //refbloques();  //actualizar bloques

  if(paisaje[y/16][x/16]>=32 &&  paisaje[y/16][x/16]<64 && (y%16)==0 && (x%16)==0 ) //detener en bloque de nivel
    {
    vx=0.0;
    vy=0.0;
    }

  if((x%16)!=0)
    {
    if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]<32 && paisaje[(y+16-(y%16))/16][(x+16-(x%16))/16]<32)  //limite del bloque de abajo
      {
      vy=0;
      y=y-(y%16);
      }
    }
  else
    {
    if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]<32)  //limite del bloque de abajo
      {
      vy=0;
      y=y-(y%16);
      }
    }

  if(paisaje[(y-(y%16))/16][(x+16-(x%16))/16]<32 && (y%16)==0 ) //limite de bloque derecho   nota: (y%16)==0 es para que si se golpea un bloque por abajo no se cumpla
    {
    vx=0.0;
    x=x-(x%16);
    }
  else if(paisaje[(y-(y%16))/16][(x-(x%16))/16]<32 && (y%16)==0 ) //limite de bloque izquierdo
    {
    vx=0.0;
    x=x+16-(x%16);
    }

  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]<32)  //limite de arriba
    {
    vy=0;
    y=y+16-(y%16);
    }
  else if((paisaje[(y-(y%16))/16][(x+16-(x%16))/16]<32) && x%16!=0)
    {
    vy=0;
    y=y+16-(y%16);
    }

////////teclado

  if(tecla[KEY_CUR_ATRAS])  //izquierda 75
    {
    vx=-4.0;
    dir=-1;
    }
  if(tecla[KEY_CUR_ADELANTE])  //derecha 77
    {
    dir=1;
    vx=4.0;
    }
  if(tecla[KEY_CUR_ARRIBA])  //arriba
    {
    vy=-4.0;
    }
  if(tecla[KEY_CUR_ABAJO])  //abajo
    {
    vy=4.0;
    }
  if(tecla[KEY_ENTER])  //Enter
    {
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==32)  //nivel 0
      {
      ciclo=1;
      abrir(0,0);
      abrir(0,1);
      abrir(0,2);
      abrir(0,3);
      abrircielo(0,0);
      abrircielo(0,1);
      abrircielo(0,2);
      abrircielo(0,3);
      x=16;
      y=384;
      vx=0;
      vy=0;
      tiempo=400;
      nivel=0;
      escena=0;
      }
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==33)  //nivel 1
      {
      ciclo=1;
      abrir(1,0);
      abrir(1,1);
      abrir(1,2);
      abrir(1,3);
      abrircielo(1,0);
      abrircielo(1,1);
      abrircielo(1,2);
      abrircielo(1,3);
      x=16;
      y=384;
      vx=0;
      vy=0;
      tiempo=400;
      nivel=1;
      escena=0;
      }
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==34)  //nivel 2
      {
      ciclo=1;
      abrir(2,0);
      abrir(2,1);
      abrir(2,2);
      abrir(2,3);
      abrircielo(2,0);
      abrircielo(2,1);
      abrircielo(2,2);
      abrircielo(2,3);
      x=16;
      y=32;
      vx=0;
      vy=0;
      tiempo=400;
      nivel=2;
      escena=0;
      }
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==35)  //nivel 3
      {
      ciclo=1;
      abrir(3,0);
      abrir(3,1);
      abrir(3,2);
      abrir(3,3);
      abrircielo(3,0);
      abrircielo(3,1);
      abrircielo(3,2);
      abrircielo(3,3);
      x=16;
      y=336;
      vx=0;
      vy=0;
      tiempo=400;
      nivel=3;
      escena=0;
      }
    }
  if(tecla[KEY_F4])  //Alt+F4 salir
    {
    DesinstalaTeclado();
    closegraph();
    exit (2);
    }
  if(tecla[KEY_F1])  //F1 ayuda 
    {
    //ayuda(); esta ayuda es dentro del juego
    }
  if(tecla[KEY_F2])  //editor de nivel
    {
    editornivel();
    abrir(0,-88);  //para recargar el mundo
    fondomundo();
    }
  if(tecla[KEY_F3])
    {
    //presentacion();
    //menu();
    }
  if(tecla[KEY_NUM_MAS])
    {
    if(retraso>1)
      {
      retraso--;
      }
    }
  if(tecla[KEY_NUM_MENOS])
    {
    if(retraso<48)
      {
      retraso++;
      }
    }
  if(vx>4)  //limite de velocidad
    {
    vx=4;
    }
  if(vy>4)  //limite de velocidad (gravedad)
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


////////interaccion de los bloques

  if(vidas==-1) //si perdiste
    {
    //perder();
    vidas=4;
    }
  if(x>=624) //si llega a la orilla derecha pasar al siguiente mundo
    {
    ciclo=1;
    mundo++;
    }
  else if(x<=0) //si llega a la orilla izquierda pasar al anterior mundo
    {
    ciclo=1;
    mundo--;
    }

  x=x+vx;
  y=y+vy;

  verestado();  //verificar el estado de pato y dibujarlo segun el estado

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);
}
return(0);
}



//==============================================================================================
//==                                     Nivel 0                                              ==
//==============================================================================================


escena00()
{
ciclo=0;
nadando=0;
act_fondo(0);
act_cielo(0);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_pato(4,24);
c_pato(22,24);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  //bloque_cristal();  //cristal golpe por abajo
  //bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  //agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  //bloque_agua();
  bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  //dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(0);
return(0);
}


escena01()  /////////////realiza los cambios peligrosos aqui, si resultan exitosos modifica la primera escena
{
ciclo=0;
nadando=0;
act_fondo(1);
act_cielo(1);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_pato(14,23);
npato[0]=-1;

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida

 ////////especial si golpea 18,21 (cristal0) que aparesca un poder0 en 18,20
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==14)  //golpe por abajo
    {
    if((y-(y%16))/16 == 21 && (x-(x%16))/16 == 18)
      {
      y=y+16-(y%16);
      vy=-vy;
      paisaje[(y-16-(y%16))/16][(x-(x%16))/16]=5;  //caja5
      bloque(x-(x%16),y-16-(y%16),5);
      paisaje[(y-32-(y%16))/16][(x-(x%16))/16]=36;  //poder0
      bloque(x-(x%16),y-32-(y%16),36);
      }
    }
  if(paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==14)
    {
    if((y-(y%16))/16 == 21 && (x+15-((x+15)%16))/16 == 18)
      {
      y=y+16-(y%16);
      vy=-vy;
      paisaje[(y-16-(y%16))/16][(x+15-((x+15)%16))/16]=5;  //caja5
      bloque(x+15-((x+15)%16),y-16-(y%16),5);
      paisaje[(y-32-(y%16))/16][(x+15-((x+15)%16))/16]=36;  //poder0
      bloque(x+15-((x+15)%16),y-32-(y%16),36);
      }
    }

  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  //agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  //bloque_agua();
  bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  //mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(1);
return(0);
}


escena02()
{
ciclo=0;
nadando=0;
act_fondo(2);
act_cielo(2);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_pato(13,24);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  cielo_vida();  //cielo cyan con moneda
  cielo_moneda();  //cielo cyan con vida

////////Especial  crear patos saliendo de la tuberia
if(tiempo%22==0 && sec%22==0)
  {
  c_pato(18,22);
  }
if(tiempo%28==0 && sec%22==0)
  {
  c_pato(25,17);
  }

////////especial para entrar a tuberia en 25,17 y 26,17
  if(tecla[KEY_ALT] || tecla[KEY_CUR_ARRIBA])  //arriba
    {
    if(((y-(y%16))/16 == 17) && ((x-(x%16))/16 == 26))
      {
      ciclo=1;
      escena=20;  //escena secreta
      }
    else if(((y-(y%16))/16 == 17) && ((x-(x%16))/16 == 25))
      {
      ciclo=1;
      escena=20;  //escena secreta
      }
    }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  //agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  //bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(2);
return(0);
}


escena03()
{
ciclo=0;
nadando=0;
act_fondo(3);
act_cielo(3);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_pato(4,24);
c_salta(15,24);
c_pato(18,24);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  //posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  //bloque_cristal();  //cristal golpe por abajo
  //bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////Especial  crear patos saliendo de la tuberia
if(tiempo%8==0 && sec%22==0)
  {
  c_pato(18,22);
  }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  bloque_nota0();  //nota0
  bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  //agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  //bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  //tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  //champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  //movchamp();  //mover champiñones
  //mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  //refchamp();
  refpato();
  //refseguidor();
  refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  //dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  //dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(3);
return(0);
}



//==============================================================================================
//==                                     Nivel 1                                              ==
//==============================================================================================


escena10()
{
ciclo=0;
nadando=0;
act_fondo(0);
act_cielo(0);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  //bloque_cristal();  //cristal golpe por abajo
  //bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////Especial  crear patos saliendo de la tuberia
if((x-(x%16))/16 < 27)  //aparecer patos segun la posicion del patito
  {
  if(tiempo%8==0 && sec%22==0)
    {
    c_pato(15,19);
    }
  }
else
{
  if(tiempo%14==0 && sec%22==0)
    {
    c_pato(29,19);
    }
}

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  //agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  //bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  //mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  //dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(0);
return(0);
}


escena11()
{
ciclo=0;
nadando=0;
act_fondo(1);
act_cielo(1);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_pato(24,23);
npato[0]=-1;

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida

 ////////especial si golpea 12,22 (cristal0) que aparesca un poder0 en 12,21
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==14)  //golpe por abajo
    {
    if(((y-(y%16))/16 == 22) && ((x-(x%16))/16 == 12))
      {
      y=y+16-(y%16);
      vy=-vy;
      paisaje[(y-16-(y%16))/16][(x-(x%16))/16]=5;  //caja5
      bloque(x-(x%16),y-16-(y%16),5);
      paisaje[(y-32-(y%16))/16][(x-(x%16))/16]=36;  //poder0
      bloque(x-(x%16),y-32-(y%16),36);
      }
    }
  if((paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==14) && x%16!=0)
    {
    if((y-(y%16))/16==22 && (x+16-(x%16))/16==12)
      {
      y=y+16-(y%16);
      vy=-vy;
      paisaje[(y-16-(y%16))/16][(x+16-(x%16))/16]=5;  //caja5
      bloque(x+16-(x%16),y-16-(y%16),5);
      paisaje[(y-32-(y%16))/16][(x+16-(x%16))/16]=36;  //poder0
      bloque(x+16-(x%16),y-32-(y%16),36);
      }
    }

////////especial para entrar a tuberia en 11,15 y 12,15
  if(tecla[KEY_CUR_ABAJO])  //abajo
    {
    if(((y-(y%16))/16 == 15) && ((x-(x%16))/16 == 12))
      {
      ciclo=1;
      escena=20;  //escena secreta
      }
    else if(((y-(y%16))/16 == 15) && ((x-(x%16))/16 == 11))
      {
      ciclo=1;
      escena=20;  //escena secreta
      }
    }

  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(1);
return(0);
}


escena12()
{
ciclo=0;
nadando=0;
act_fondo(2);
act_cielo(2);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_pato(22,23);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  //bloque_moneda0();  //monedas
  bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////Especial  crear patos saliendo de la tuberia
if(tiempo%28==0 && sec%22==0)
  {
  c_pato(8,14);
  }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  NITRO_mata();  //no toques la nitroglicerina
  fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(2);
return(0);
}


escena13()
{
ciclo=0;
nadando=0;
act_fondo(3);
act_cielo(3);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  bloque_caja0_vida();  //caja0 con vida

 ////////especial si golpea 27,20 (cristal0) que aparesca un poder0 en 27,19
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==14)  //golpe por abajo
    {
    if((y-(y%16))/16 == 20 && (x-(x%16))/16 == 27)
      {
      y=y+16-(y%16);
      vy=-vy;
      paisaje[(y-16-(y%16))/16][(x-(x%16))/16]=5;  //caja5
      bloque(x-(x%16),y-16-(y%16),5);
      paisaje[(y-32-(y%16))/16][(x-(x%16))/16]=36;  //poder0
      bloque(x-(x%16),y-32-(y%16),36);
      }
    }
  if(paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==14)
    {
    if((y-(y%16))/16 == 20 && (x+15-((x+15)%16))/16 == 27)
      {
      y=y+16-(y%16);
      vy=-vy;
      paisaje[(y-16-(y%16))/16][(x+15-((x+15)%16))/16]=5;  //caja5
      bloque(x+15-((x+15)%16),y-16-(y%16),5);
      paisaje[(y-32-(y%16))/16][(x+15-((x+15)%16))/16]=36;  //poder0
      bloque(x+15-((x+15)%16),y-32-(y%16),36);
      }
    }

  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  cielo_moneda();  //cielo cyan con vida

////////Especial  crear patos saliendo de la tuberia
if(tiempo%14==0 && sec%22==0)
  {
  c_pato(21,8);
  }
if(tiempo%12==0 && sec%22==0)
  {
  c_salta(21,8);
  }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  cielo_abajo();  //flujo de aire hacia abajo
  cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  //refseguidor();
  refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(3);
return(0);
}




//==============================================================================================
//==                                     Nivel 2                                              ==
//==============================================================================================


escena20()
{
ciclo=0;
nadando=0;
act_fondo(0);
act_cielo(0);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_seguidor(6,24);
c_pato(8,24);
c_pato(22,24);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  //bloque_cristal();  //cristal golpe por abajo
  //bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////Especial  crear patos saliendo de la tuberia
if(tiempo%8==0 && sec%22==0)
  {
  c_pato(5,22);
  }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  agua_abajo();  //flujo de agua hacia abajo
  agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  //mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  //dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(0);
return(0);
}


escena21()
{
ciclo=0;
nadando=0;
act_fondo(1);
act_cielo(1);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_pato(16,23);
npato[0]=-1;

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  bloque_caja0_vida();  //caja0 con vida

////////Especial crear patos saliendo de la tuberia
if(tiempo%8==0 && sec%22==0)
  {
  c_pato(11,2);
  }
if(tiempo%12==0 && sec%22==0)
  {
  c_pato(29,2);
  }
  if(tiempo%10==0 && sec%22==0)
  {
  c_pato(33,9);
  }
if(tiempo%10==0 && sec%22==0)
  {
  c_pato(15,13);
  }

  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  //bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);
}
guardar_fondo(1);
return(0);
}


escena22()
{
ciclo=0;
nadando=0;
act_fondo(2);
act_cielo(2);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_pato(13,24);
c_salta(20,14);
c_mina(14,14);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  cielo_moneda();  //cielo cyan con vida

////////especial nivel secreto al caerse en el hoyo
    if(y>=448)
      {
      ciclo=1;
      escena=20;  //escena secreta
      }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  agua_abajo();  //flujo de agua hacia abajo
  agua_arriba();  //flujo de agua hacia arriba
  agua_izquierda();  //flujo de agua hacia izquierda
  agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  //refseguidor();
  refsalta();
  //refpeligro();
  refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(2);
return(0);
}


escena23()
{
ciclo=0;
nadando=0;
act_fondo(3);
act_cielo(3);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_mina(38,20);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  //posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  //posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida

 ////////especial si golpea 17,4 (cristal0) que aparesca un poder0 en 17,3
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==14)  //golpe por abajo
    {
    if((y-(y%16))/16 == 4 && (x-(x%16))/16 == 17)
      {
      y=y+16-(y%16);
      vy=-vy;
      paisaje[(y-16-(y%16))/16][(x-(x%16))/16]=5;  //caja5
      bloque(x-(x%16),y-16-(y%16),5);
      paisaje[(y-32-(y%16))/16][(x-(x%16))/16]=36;  //poder0
      bloque(x-(x%16),y-32-(y%16),36);
      }
    }
  if(paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==14)
    {
    if((y-(y%16))/16 == 4 && (x+15-((x+15)%16))/16 == 17)
      {
      y=y+16-(y%16);
      vy=-vy;
      paisaje[(y-16-(y%16))/16][(x+15-((x+15)%16))/16]=5;  //caja5
      bloque(x+15-((x+15)%16),y-16-(y%16),5);
      paisaje[(y-32-(y%16))/16][(x+15-((x+15)%16))/16]=36;  //poder0
      bloque(x+15-((x+15)%16),y-32-(y%16),36);
      }
    }

  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  //tocar_champinon();  //tocar champiñon
  //pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  //pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  //patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  //champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  //movchamp();  //mover champiñones
  //mdemone();  //saltar monedas, generalmente es utilizado
  //movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  //refchamp();
  //refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  //dibchamp();  //dibujar champiñones
  //dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);
}

guardar_fondo(3);
return(0);
}



//==============================================================================================
//==                                     Nivel 3                                              ==
//==============================================================================================


escena30()
{
ciclo=0;
nadando=0;
act_fondo(0);
act_cielo(0);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_peligro(24,21);
//c_pato(22,24);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  //posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  //agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  //bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  //pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  //pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  //patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  //mdemone();  //saltar monedas, generalmente es utilizado
  //movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  //refpato();
  //refseguidor();
  //refsalta();
  refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  //dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);
}

guardar_fondo(0);
return(0);
}


escena31()
{
ciclo=0;
nadando=0;
act_fondo(1);
act_cielo(1);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
c_pato(26,14);
c_salta(37,24);

////////especial  bloques falsos
bloque(24*16,7*16,11);
bloque(25*16,7*16,11);
bloque(26*16,7*16,11);
bloque(27*16,7*16,11);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////Especial  crear patos saliendo de la tuberia
if(tiempo%22==0 && sec%22==0)
  {
  c_peligro(8,20);
  }

////////especial para entrar a tuberia en 29,13 y 29,14
  if(tecla[KEY_CUR_ADELANTE])  //derecha
    {
    if(((y-(y%16))/16 == 13) && ((x-(x%16))/16 == 29))
      {
      ciclo=1;
      escena=20;
      }
    else if(((y-(y%16))/16 == 14) && ((x-(x%16))/16 == 29))
      {
      ciclo=1;
      escena=20;
      }
    }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  //agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  //bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  pisar_salta();  //pisar saltador
  pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  fuego4_mata();  //no teques el fuego
  pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  salta_mata();  //saltador mata cuando los tocas
  peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  saltafuera();  //verificar si un saltador se salio de la pantalla
  peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  movpato();  //mover patos
  //movseguidor();  //mover seguidor
  movsalta();  //mover saltador
  movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  refpato();
  //refseguidor();
  refsalta();
  refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  dibsalta();  //dibujar saltador
  dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(1);
return(0);
}


escena32()
{
ciclo=0;
nadando=0;
act_fondo(2);
act_cielo(2);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
//c_pato(4,24);
//c_pato(22,24);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  //posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  //posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////Especial  crear patos saliendo de la tuberia
if(tiempo%22==0 && sec%22==0)
  {
  c_peligro(33,4);
  }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  //tocar_champinon();  //tocar champiñon
  //pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  fuego4_mata();  //no teques el fuego
  //pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  //patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  peligrofuera();  //verificar si un peligroso se salio de la pantalla
  //champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  //movchamp();  //mover champiñones
  //mdemone();  //saltar monedas, generalmente es utilizado
  //movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  //refchamp();
  //refpato();
  //refseguidor();
  //refsalta();
  refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  //dibchamp();  //dibujar champiñones
  //dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(2);
return(0);
}


escena33()
{
ciclo=0;
nadando=0;
act_fondo(3);
act_cielo(3);
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
//c_pato(4,24);
//c_pato(22,24);

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  //posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
 //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  //pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  //pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  //patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  //movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refchamp();
  //refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibchamp();  //dibujar champiñones
  //dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
guardar_fondo(3);
return(0);
}



//==========================================================================
//==                         Niveles Especiales                           ==
//==========================================================================

escena0_20()
{
ciclo=0;
nadando=0;
//act_fondo(1);  //no se usa, ya que se esta usando la funcion abrir()
//nota: abrir() carga el archivo se carga directamente a paisaje[]
abrir(nivel,escena);  //se supone que es lo mismo que abrir(0,20);
abrircielo(nivel,escena);
convertbloqmon();
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
vx=0.0;
vy=0.0;
x=80;
y=32;

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  //posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  //posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  //bloque_moneda0();  //monedas
  bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////especial para entrar a tuberia en 36,4 y 37,4
  if(tecla[KEY_ALT] || tecla[KEY_CUR_ARRIBA])  //arriba
    {
    if(((y-(y%16))/16 == 4) && ((x-(x%16))/16 == 37))
      {
      ciclo=1;
      escena=2;
      }
    else if(((y-(y%16))/16 == 4) && ((x-(x%16))/16 == 36))
      {
      ciclo=1;
      escena=2;
      }
    }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  //agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  //bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  //tocar_champinon();  //tocar champiñon
  //pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  //pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  //patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  //champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  //movchamp();  //mover champiñones
  //mdemone();  //saltar monedas, generalmente es utilizado
  //movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

//no uso la funcion control(), ya que modifique algunas cosas
  if(monedas>=100) //por cada 100 monedas aumentar una vida
    {
    monedas=0;
    vidas++;
    }
  if(x>=624) //si llega a la orilla derecha pasar a la siguiente escena
    {
    x=2;
    }
  else if(x<=0) //si llega a la orilla izquierda pasar a la anterior escena
    {
    x=608;
    }
  else if(y>=464) //caida
    {
    ciclo=1;
    estado=1;
    vidas--;
    //t_huevo=tiempo-4; //parece no ser necesario
    jugar=0;
    }
  else if(tiempo==0) //tiempo terminado
    {
    estado=0;
    t_huevo=tiempo-4;
    }
  if(t_moneda==tiempo)
    {
    convertir();
    t_moneda=-88;
    }
  if(sec%4==0)  //usado para poder volar cada 4 cuadros
    {
    t_volar=0;
    }

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  //refchamp();
  //refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  //dibchamp();  //dibujar champiñones
  //dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
vx=0.0;
vy=0.0;
x=200;
y=352;
return(0);
}


escena1_20()
{
ciclo=0;
nadando=0;
//act_fondo(1);  //no se usa, ya que se esta usando la funcion abrir()
//nota: abrir() carga el archivo se carga directamente a paisaje[]
abrir(nivel,escena);  //se supone que es lo mismo que abrir(1,20);
abrircielo(nivel,escena);
convertbloqmon();
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
vx=0.0;
vy=0.0;
x=320;
y=32;

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  //posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  //posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  //bloque_cristal();  //cristal golpe por abajo
  //bloque_moneda0();  //monedas
  bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////especial para entrar a tuberia en 4,22 y 4,23
  if(tecla[KEY_CUR_ATRAS])  //izquierda
    {
    if(((y-(y%16))/16 == 22) && ((x-(x%16))/16 == 4))
      {
      ciclo=1;
      escena=2;
      }
    else if(((y-(y%16))/16 == 23) && ((x-(x%16))/16 == 4))
      {
      ciclo=1;
      escena=2;
      }
    }

////////especial para entrar a tuberia en 35,22 y 35,23
  if(tecla[KEY_CUR_ADELANTE])  //derecha
    {
    if(((y-(y%16))/16 == 22) && ((x-(x%16))/16 == 35))
      {
      ciclo=1;
      escena=2;
      }
    else if(((y-(y%16))/16 == 23) && ((x-(x%16))/16 == 35))
      {
      ciclo=1;
      escena=2;
      }
    }


////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  //agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  //bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  //tocar_champinon();  //tocar champiñon
  //pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  //pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  //patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  //champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  //movchamp();  //mover champiñones
  //mdemone();  //saltar monedas, generalmente es utilizado
  //movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

//no uso la funcion control(), ya que modifique algunas cosas
  if(monedas>=100) //por cada 100 monedas aumentar una vida
    {
    monedas=0;
    vidas++;
    }
  if(x>=624) //si llega a la orilla derecha pasar a la siguiente escena
    {
    x=2;
    }
  else if(x<=0) //si llega a la orilla izquierda pasar a la anterior escena
    {
    x=608;
    }
  else if(y>=464) //caida
    {
    ciclo=1;
    estado=1;
    vidas--;
    //t_huevo=tiempo-4; //parece no ser necesario
    jugar=0;
    }
  else if(tiempo==0) //tiempo terminado
    {
    estado=0;
    t_huevo=tiempo-4;
    }
  if(t_moneda==tiempo)
    {
    convertir();
    t_moneda=-88;
    }
  if(sec%4==0)  //usado para poder volar cada 4 cuadros
    {
    t_volar=0;
    }

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  //refchamp();
  //refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  //dibchamp();  //dibujar champiñones
  //dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  //dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
x=344;
y=80;
vx=0.0;
vy=0.0;
escena=1;

//Especial regenerar monedas y poder

niv1[16][8]=35;
niv1[16][9]=35;
niv1[16][10]=35;
niv1[20][7]=35;
niv1[20][8]=35;
niv1[20][9]=35;
niv1[18][4]=35;
niv1[18][5]=35;
niv1[18][6]=35;
niv1[22][11]=14;
niv1[22][12]=14;
niv1[21][12]=75;

return(0);
}


escena2_20()
{
ciclo=0;
nadando=0;
//act_fondo(1);  //no se usa, ya que se esta usando la funcion abrir()
//nota: abrir() carga el archivo se carga directamente a paisaje[]
abrir(nivel,escena);  //se supone que es lo mismo que abrir(2,20);
abrircielo(nivel,escena);
convertbloqmon();
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
vx=0.0;
vy=0.0;
x=80;
y=32;

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  //posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  //posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  //bloque_cristal();  //cristal golpe por abajo
  //bloque_moneda0();  //monedas
  bloque_moneda4();  //monedas
  //estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////especial para entrar a tuberia en 36,4 y 37,4
  if(tecla[KEY_ALT] || tecla[KEY_CUR_ARRIBA])  //arriba
    {
    if(((y-(y%16))/16 == 4) && ((x-(x%16))/16 == 37))
      {
      ciclo=1;
      escena=2;
      }
    else if(((y-(y%16))/16 == 4) && ((x-(x%16))/16 == 36))
      {
      ciclo=1;
      escena=2;
      }
    }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  //bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
 //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  //agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  //bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  //tocar_champinon();  //tocar champiñon
  //pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  //pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  //patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  //champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  //movchamp();  //mover champiñones
  //mdemone();  //saltar monedas, generalmente es utilizado
  //movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

//no uso la funcion control(), ya que modifique algunas cosas
  if(monedas>=100) //por cada 100 monedas aumentar una vida
    {
    monedas=0;
    vidas++;
    }
  if(x>=624) //si llega a la orilla derecha pasar a la siguiente escena
    {
    x=2;
    }
  else if(x<=0) //si llega a la orilla izquierda pasar a la anterior escena
    {
    x=608;
    }
  else if(y>=464) //caida
    {
    ciclo=1;
    estado=1;
    vidas--;
    //t_huevo=tiempo-4; //parece no ser necesario
    jugar=0;
    }
  else if(tiempo==0) //tiempo terminado
    {
    estado=0;
    t_huevo=tiempo-4;
    }
  if(t_moneda==tiempo)
    {
    convertir();
    t_moneda=-88;
    }
  if(sec%4==0)  //usado para poder volar cada 4 cuadros
    {
    t_volar=0;
    }

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  //refchamp();
  //refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  //dibchamp();  //dibujar champiñones
  //dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  //dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}
vx=0.0;
vy=0.0;
x=200;
y=352;
return(0);
}


escena3_20()
{
ciclo=0;
nadando=0;
//act_fondo(1);  //no se usa, ya que se esta usando la funcion abrir()
//nota: abrir() carga el archivo se carga directamente a paisaje[]
abrir(nivel,escena);  //se supone que es lo mismo que abrir(3,20);
abrircielo(nivel,escena);
convertbloqmon();
fondo();
panel();
r_champ();
rmonedas();
r_pato();
r_seguidor();
r_salta();
r_peligro();
r_mina();
r_disparo();
r_explosionc();
r_cristalroto();
r_bala();
r_tortuga();
vx=0.0;
vy=0.0;
x=90;
y=302;

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;

  //posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  //posicion_pato();  //guardar las coordenadas anteriores de los patos
  //posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  //posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  //posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida

 ////////especial si golpea 17,9 (cristal0) que aparesca un poder0 en 17,8
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==14)  //golpe por abajo
    {
    if(((y-(y%16))/16 == 9) && ((x-(x%16))/16 == 17))
      {
      y=y+16-(y%16);
      vy=-vy;
      paisaje[(y-16-(y%16))/16][(x-(x%16))/16]=5;  //caja5
      bloque(x-(x%16),y-16-(y%16),5);
      paisaje[(y-32-(y%16))/16][(x-(x%16))/16]=36;  //poder0
      bloque(x-(x%16),y-32-(y%16),36);
      }
    }
  if((paisaje[(y-(y%16))/16][(x+16-(x%16))/16]==14) && x%16!=0)
    {
    if((y-(y%16))/16==9 && (x+16-(x%16))/16==17)
      {
      y=y+16-(y%16);
      vy=-vy;
      paisaje[(y-16-(y%16))/16][(x+16-(x%16))/16]=5;  //caja5
      bloque(x+16-(x%16),y-16-(y%16),5);
      paisaje[(y-32-(y%16))/16][(x+16-(x%16))/16]=36;  //poder0
      bloque(x+16-(x%16),y-32-(y%16),36);
      }
    }

  //cristal0_moneda();  //cristal0 con moneda
  //cristal4_moneda();  //cristal4 con moneda
  //cristal0_vida();  //cristal0 con vida
  //cristal4_vida();  //cristal4 con vida
  bloque_cristal();  //cristal golpe por abajo
  bloque_moneda0();  //monedas
  //bloque_moneda4();  //monedas
  estrella_moneda();  //Estrella con moneda
  //cielo_vida();  //cielo cyan con moneda
  //cielo_moneda();  //cielo cyan con vida

////////especial para entrar a tuberia en 35,19 y 36,19
  if(tecla[KEY_ALT] || tecla[KEY_CUR_ARRIBA])  //arriba
    {
    if(((y-(y%16))/16 == 19) && ((x-(x%16))/16 == 35))
      {
      ciclo=1;
      escena=2;
      }
    else if(((y-(y%16))/16 == 19) && ((x-(x%16))/16 == 36))
      {
      ciclo=1;
      escena=2;
      }
    }

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  bloque_poder0();  //poder0
  //bloque_nota0();  //nota0
  //bloque_saltar();  //bloque para saltar muy alto
  //cielo_abajo();  //flujo de aire hacia abajo
  //cielo_arriba();  //flujo de aire hacia arriba
  //cielo_izquierda();  //flujo de aire hacia la izquierda
  //cielo_derecha();  //flujo de aire hacia la derecha
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  //bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  //tocar_champinon();  //tocar champiñon
  //pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  //pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  //NITRO_mata();  //no toques la nitroglicerina
  //fuego4_mata();  //no teques el fuego
  //pato_mata();  //pato mata cuando los tocas
  //seguidor_mata();  //seguidor mata cuando los tocas
  //salta_mata();  //saltador mata cuando los tocas
  //peligro_mata();  //peligroso mata cuando los tocas
  //mina_mata(); //mina mata
  //bala_mata();  //las balas matan
  //tortuga_mata();  //tortuga mata cuando los tocas

  //patofuera();  //verificar si un pato se salio de la pantalla
  //seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  //saltafuera();  //verificar si un saltador se salio de la pantalla
  //peligrofuera();  //verificar si un peligroso se salio de la pantalla
  //champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  //balafuera();  //verificar si una bala se salio de la pantalla
  //tortugafuera();  //verificar si una tortuga se salio de la pantalla

  //movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  //movpato();  //mover patos
  //movseguidor();  //mover seguidor
  //movsalta();  //mover saltador
  //movpeligro();  //mover peligroso
  //movmina();  //mover las minas
  movdisparo();  //mover disparo
  //movbala();  //mover las balas
  //movtortuga();  //mover tortugas

////////teclado y otros
  teclado();

//no uso la funcion control(), ya que modifique algunas cosas
  if(monedas>=100) //por cada 100 monedas aumentar una vida
    {
    monedas=0;
    vidas++;
    }
  if(x>=624) //si llega a la orilla derecha pasar a la siguiente escena
    {
    x=2;
    }
  else if(x<=0) //si llega a la orilla izquierda pasar a la anterior escena
    {
    x=608;
    }
  else if(y>=464) //caida
    {
    ciclo=1;
    estado=1;
    vidas--;
    //t_huevo=tiempo-4; //parece no ser necesario
    jugar=0;
    }
  else if(tiempo==0) //tiempo terminado
    {
    estado=0;
    t_huevo=tiempo-4;
    }
  if(t_moneda==tiempo)
    {
    convertir();
    t_moneda=-88;
    }
  if(sec%4==0)  //usado para poder volar cada 4 cuadros
    {
    t_volar=0;
    }

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  //refchamp();
  //refpato();
  //refseguidor();
  //refsalta();
  //refpeligro();
  //refmina();
  refdisparo();
  //refbala();
  //reftortuga();

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  //dibchamp();  //dibujar champiñones
  //dibpatos();  //dibujar patos
  //dibseguidor();  //dibujar seguidor
  //dibsalta();  //dibujar saltador
  //dibpeligro();  //dibujar peligroso
  //dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  //dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  delay(retraso);

}

vx=0.0;
vy=0.0;
x=504;
y=336;
return(0);
}