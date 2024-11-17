extern int ciclo,tiempo,volar,t_volar,retraso,x,y,o,p,invensible,tiempo_invensible,dirx,nivel,escena,vidas,mundo,monedas,estado,nadando,jugar,t_huevo,cambios_por_segundo_paleta,npato[8],nsalta[4],sec,t_moneda,CPS,paisaje[30][40],niv1[30][40],blq[400],npc[10];
extern float vx,vy;
extern long puntos;
extern int npato[8],patox[8],patoy[8],nsalta[4],saltax[4],saltay[4],nseguidor[8],seguidorx[8],seguidory[8],npeligro[4],peligrox[4],peligroy[4],nmina[8],minax[8],minay[8],ntortuga[8],tortugax[8],tortugay[8],nbala[8],balax[8],balay[8];
extern float tortugavx[8];
extern unsigned char tecla[128];

int x_mundo=32,y_mundo=32;
int avance_tutorial[6];

//debug
extern int patoo[8],patop[8];

#include<stdio.h>
#include"teclas.h"

//=========================================================================================================
//==                                            niveles                                                  ==
//=========================================================================================================


mundo0()
{
char e1,e2,e3,e4;
ciclo=0;
tiempo=0;
invensible=0;
t_moneda=-88;
volar=22;
nadando=0;
x=x_mundo;
y=y_mundo;
vx=0;
vy=0;
fondomundo();
panel();
texto(532,424,0,15,"F1 Ayuda");
texto(532,432,0,15,"F2 Editor");
texto(532,448,0,13,"F4 Salir");
obtener_segundos();  //guardar el tiempo del segundo actual

while(ciclo<1)
  {
////////operaciones del los bloques
  refbloquemundo();  //actualizar bloques

////////deteccion de bloques solidos
  if(paisaje[(y-(y%16))/16][(x-(x%16))/16]<32)  //detecion de solidos para la esquina izquierda superior
    {
    e1=1;
    }
  else
    {
    e1=0;
    }
  if(paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]<32)  //detecion de solidos para la esquina derecha superior
    {
    e2=1;
    }
  else
    {
    e2=0;
    }
  if(paisaje[(y+16-(y%16))/16][(x-(x%16))/16]<32)  //detecion de solidos para la esquina izquierda inferior
    {
    e3=1;
    }
  else
    {
    e3=0;
    }
  if(paisaje[(y+16-(y%16))/16][(x+15-((x+15)%16))/16]<32)  //detecion de solidos para la esquina derecha inferior
    {
    e4=1;
    }
  else
    {
    e4=0;
    }

  if(e1==1 && e2==0 && e3==1 && e4==0)
    {
    vx=0.0;
    x=x+16-(x%16);
    }
  if(e1==0 && e2==0 && e3==1 && e4==1)
    {
    vy=0.0;
    y=y-(y%16);
    }
  if(e1==0 && e2==1 && e3==0 && e4==1)
    {
    vx=0.0;
    x=x-(x%16);
    }
  if(e1==1 && e2==1 && e3==0 && e4==0)
    {
    vy=-vy;
    y=y+16-(y%16);
    }
  if(e1==1 && e2==0 && e3==0 && e4==0)
    {
    if(vy<=0)
      {
      if((x%16)<=(y%16))
        {
        vy=-vy;
        y=y+16-(y%16);
        }
      else
        {
        vx=0.0;
        x=x+16-(x%16);
        }
      }
    else
      {
      vx=0.0;
      x=x+16-(x%16);
      }
    }
  if(e1==0 && e2==1 && e3==0 && e4==0)
    {
    if(vy<=0)
      {
      if((x%16)>=(15-(y%16)))
        {
        vy=-vy;
        y=y+16-(y%16);
        }
      else
        {
        vx=0.0;
        x=x-(x%16);
        }
      }
    else
      {
      vx=0.0;
      x=x-(x%16);
      }
    }
  if(e1==0 && e2==0 && e3==1 && e4==0)
    {
    if(vy>=0)
      {
      if((15-(x%16))>=(y%16))
        {
        vy=0.0;
        y=y-(y%16);
        }
      else
        {
        vx=0.0;
        x=x+16-(x%16);
        }
      }
    else
      {
      vx=0.0;
      x=x+16-(x%16);
      }
    }
  if(e1==0 && e2==0 && e3==0 && e4==1)
    {
    if(vy>=0)
      {
      if((x%16)>=(y%16))
        {
        vy=0.0;
        y=y-(y%16);
        }
      else
        {
        vx=0.0;
        x=x-(x%16);
        }
      }
    else
      {
      vx=0.0;
      x=x-(x%16);
      }
    }
  if(e1==1 && e2==1 && e3==1 && e4==0)
    {
    vy=-vy;
    y=y+16-(y%16);
    vx=0.0;
    x=x+16-(x%16);
    }
  if(e1==1 && e2==1 && e3==0 && e4==1)
    {
    vy=-vy;
    y=y+16-(y%16);
    vx=0.0;
    x=x-(x%16);
    }
  if(e1==1 && e2==0 && e3==1 && e4==1)
    {
    vy=0.0;
    y=y-(y%16);
    vx=0.0;
    x=x+16-(x%16);
    }
  if(e1==0 && e2==1 && e3==1 && e4==1)
    {
    vy=0.0;
    y=y-(y%16);
    vx=0.0;
    x=x-(x%16);
    }
  if(e1==1 && e2==0 && e3==0 && e4==1)
    {
    if(vx<0.0)
      {
      y=y-(y%16);
      x=x+16-(x%16);
      }
    else
      {
      y=y+16-(y%16);
      x=x-(x%16);
      }
    vy=0.0;
    vx=0.0;
    }
  if(e1==0 && e2==1 && e3==1 && e4==0)
    {
    if(vx>0.0)
      {
      y=y-(y%16);
      x=x-(x%16);
      }
    else
      {
      y=y+16-(y%16);
      x=x+16-(x%16);
      }
    vy=0.0;
    vx=0.0;
    }

////////teclado
  if(tecla[KEY_CUR_ATRAS])  //izquierda 75
    {
    vx=-4.0;
    dirx=-1;
    }
  if(tecla[KEY_CUR_ADELANTE])  //derecha 77
    {
    dirx=1;
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

  if(vx<0)  //disminuir la velocidad x
    {
    vx=vx+1.0;
    }
  else if(vx>0)
    {
    vx=vx-1.0;
    }
  if(vy<0)  //disminuir la velocidad y
    {
    vy=vy+1.0;
    }
  else if(vy>0)
    {
    vy=vy-1.0;
    }

  if(tecla[KEY_F11])  ////////////////////////////test
    {
      ciclo=1;
      abrir(-2,0);
      abrir(-2,1);
      abrir(-2,2);
      abrir(-2,3);
      abrircielo(-2,0);
      abrircielo(-2,1);
      abrircielo(-2,2);
      abrircielo(-2,3);
      x=16;
      y=384;
      vx=0;
      vy=0;
      tiempo=8000;
      nivel=-2;
      escena=0;
      avance_tutorial[0]=0;
      avance_tutorial[1]=0;
      avance_tutorial[2]=0;
      avance_tutorial[3]=0;
      avance_tutorial[4]=0;
      avance_tutorial[5]=0;
    }
  if(tecla[KEY_F10])  ////////////////////////////test
    {
#ifdef MSDOS
      ciclo=1;
      x=16;
      y=32;
      vx=0;
      vy=0;
      tiempo=400;
      nivel=-3;
      escena=20;
      cargar_configuracion();
      escena_presentacion();// esto no va aqui, solo es temporal
      nivel=0;  //esto tampoco va
      escena=0;
#endif // MSDOS
    }

  if(tecla[KEY_F12])  //panel debug mundo
    {
    x_mundo=x;
    y_mundo=y;
    panel_debug_mundo();
    }

  if(tecla[KEY_ENTER])  //Enter
    {
    x_mundo=x;
    y_mundo=y;
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==32 || paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==32 || paisaje[(y+15-((y+15)%16))/16][(x-(x%16))/16]==32 || paisaje[(y+15-((y+15)%16))/16][(x+15-((x+15)%16))/16]==32)  //nivel 0
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
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==33 || paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==33 || paisaje[(y+15-((y+15)%16))/16][(x-(x%16))/16]==33 || paisaje[(y+15-((y+15)%16))/16][(x+15-((x+15)%16))/16]==33)  //nivel 1
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
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==34 || paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==34 || paisaje[(y+15-((y+15)%16))/16][(x-(x%16))/16]==34 || paisaje[(y+15-((y+15)%16))/16][(x+15-((x+15)%16))/16]==34)  //nivel 2
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
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==35 || paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==35 || paisaje[(y+15-((y+15)%16))/16][(x-(x%16))/16]==35 || paisaje[(y+15-((y+15)%16))/16][(x+15-((x+15)%16))/16]==35)  //nivel 3
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
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==36 || paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==36 || paisaje[(y+15-((y+15)%16))/16][(x-(x%16))/16]==36 || paisaje[(y+15-((y+15)%16))/16][(x+15-((x+15)%16))/16]==36)  //nivel 4
      {
      ciclo=1;
      abrir(4,0);
      abrir(4,1);
      abrir(4,2);
      abrir(4,3);
      abrircielo(4,0);
      abrircielo(4,1);
      abrircielo(4,2);
      abrircielo(4,3);
      nivel=4;
      escena=0;
      cargar_configuracion();
      }
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==37 || paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==37 || paisaje[(y+15-((y+15)%16))/16][(x-(x%16))/16]==37 || paisaje[(y+15-((y+15)%16))/16][(x+15-((x+15)%16))/16]==37)  //nivel 4
      {
      ciclo=1;
      abrir(5,0);
      abrir(5,1);
      abrir(5,2);
      abrir(5,3);
      abrircielo(5,0);
      abrircielo(5,1);
      abrircielo(5,2);
      abrircielo(5,3);
      nivel=5;
      escena=0;
      cargar_configuracion();
      }
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==38 || paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==38 || paisaje[(y+15-((y+15)%16))/16][(x-(x%16))/16]==38 || paisaje[(y+15-((y+15)%16))/16][(x+15-((x+15)%16))/16]==38)  //nivel 4
      {
      ciclo=1;
      abrir(6,0);
      abrir(6,1);
      abrir(6,2);
      abrir(6,3);
      abrircielo(6,0);
      abrircielo(6,1);
      abrircielo(6,2);
      abrircielo(6,3);
      nivel=6;
      escena=0;
      cargar_configuracion();
      }
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==39 || paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==39 || paisaje[(y+15-((y+15)%16))/16][(x-(x%16))/16]==39 || paisaje[(y+15-((y+15)%16))/16][(x+15-((x+15)%16))/16]==39)  //nivel 4
      {
      ciclo=1;
      abrir(7,0);
      abrir(7,1);
      abrir(7,2);
      abrir(7,3);
      abrircielo(7,0);
      abrircielo(7,1);
      abrircielo(7,2);
      abrircielo(7,3);
      nivel=7;
      escena=0;
      cargar_configuracion();
      }
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==40 || paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==40 || paisaje[(y+15-((y+15)%16))/16][(x-(x%16))/16]==40 || paisaje[(y+15-((y+15)%16))/16][(x+15-((x+15)%16))/16]==40)  //nivel 4
      {
      ciclo=1;
      abrir(8,0);
      abrir(8,1);
      abrir(8,2);
      abrir(8,3);
      abrircielo(8,0);
      abrircielo(8,1);
      abrircielo(8,2);
      abrircielo(8,3);
      nivel=8;
      escena=0;
      cargar_configuracion();
      }
    if(paisaje[(y-(y%16))/16][(x-(x%16))/16]==41 || paisaje[(y-(y%16))/16][(x+15-((x+15)%16))/16]==41 || paisaje[(y+15-((y+15)%16))/16][(x-(x%16))/16]==41 || paisaje[(y+15-((y+15)%16))/16][(x+15-((x+15)%16))/16]==41)  //nivel 4
      {
      ciclo=1;
      abrir(9,0);
      abrir(9,1);
      abrir(9,2);
      abrir(9,3);
      abrircielo(9,0);
      abrircielo(9,1);
      abrircielo(9,2);
      abrircielo(9,3);
      nivel=9;
      escena=0;
      cargar_configuracion();
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
#ifndef MSDOS
    while(tecla[KEY_F1])
    {
    delay(retraso);
    render_opengl_windows();
    }
#endif // MSDOS
    ayuda_mundo();
    }
  if(tecla[KEY_F2])  //editor de nivel
    {
#ifndef MSDOS
    while(tecla[KEY_F2])
    {
    render_opengl_windows();
    }
#endif // MSDOS
    editornivel();
    abrir(0,-88);  //para recargar el mundo
    fondomundo();
    obtener_segundos();
    }
  if(tecla[KEY_F3])
    {
    presentacion();
    fondomundo();
    //menu();
    }
/*  if(vx>4)  //limite de velocidad
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
*/

////////interaccion de los bloques

  if(vidas==-1) //si perdiste
    {
    //perder();
    vidas=4;
    }
  if(x>=624) //si llega a la orilla derecha pasar al otro lado
    {
    x=2;
    }
  else if(x<=0) //si llega a la orilla izquierda pasar al otro lado
    {
    x=622;
    }
  if(y>=416) //si llega a la orilla derecha pasar al otro lado
    {
    y=2;
    }
  else if(y<=0) //si llega a la orilla izquierda pasar al otro lado
    {
    y=414;
    }

  x=x+vx;
  y=y+vy;

  verestado();  //verificar el estado de pato y dibujarlo segun el estado

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();  //agilizar deteccion de coliciones en algunos bloques

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(0);
return(0);
}


escena01()
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida

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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
if(tiempo%22==0 && sec%CPS==0)
  {
  c_pato(18,22);
  }
if(tiempo%28==0 && sec%CPS==0)
  {
  c_pato(25,17);
  }

////////especial para entrar a tuberia en 25,17 y 26,17
  if(tecla[KEY_CUR_ARRIBA])  //arriba
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
if(tiempo%8==0 && sec%CPS==0)
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual

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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
  if(tiempo%8==0 && sec%CPS==0)
    {
    c_pato(15,19);
    }
  }
else
{
  if(tiempo%14==0 && sec%CPS==0)
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida

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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
if(tiempo%28==0 && sec%CPS==0)
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
  fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual

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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida

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
if(tiempo%14==0 && sec%CPS==0)
  {
  c_pato(21,8);
  }
if(tiempo%12==0 && sec%CPS==0)
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
if(tiempo%8==0 && sec%CPS==0)
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida

////////Especial crear patos saliendo de la tuberia
if(tiempo%8==0 && sec%CPS==0)
  {
  c_pato(11,2);
  }
if(tiempo%12==0 && sec%CPS==0)
  {
  c_pato(29,2);
  }
  if(tiempo%10==0 && sec%CPS==0)
  {
  c_pato(33,9);
  }
if(tiempo%10==0 && sec%CPS==0)
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
  fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida

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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
c_pato(26,14);
c_salta(37,24);
npato[0]=-1;
nsalta[0]=-1;

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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
if(tiempo%22==0 && sec%CPS==0)
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
      vx=0.0;
      vy=0.0;
      x=90;
      y=302;
      }
    else if(((y-(y%16))/16 == 14) && ((x-(x%16))/16 == 29))
      {
      ciclo=1;
      escena=20;
      vx=0.0;
      vy=0.0;
      x=90;
      y=302;
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
  fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  //posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  //posicion_bala();  //guardar las coordenadas anteriores de las balas
  //posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas

  tinvensible();  //tiempo de inmunidad
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
if(tiempo%22==0 && sec%CPS==0)
  {
  c_peligro(25,4);
  }

////////especial para entrar a tuberia en 23,21 y 24,21
  if(tecla[KEY_CUR_ABAJO])  //abajo
    {
    if(((y-(y%16))/16 == 21) && ((x-(x%16))/16 == 23))
      {
      ciclo=1;
      escena=20;
      vx=0.0;
      vy=0.0;
      x=568;
      y=304;
      }
    else if(((y-(y%16))/16 == 21) && ((x-(x%16))/16 == 24))
      {
      ciclo=1;
      escena=20;
      vx=0.0;
      vy=0.0;
      x=568;
      y=304;
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
  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  //agua_abajo();  //flujo de agua hacia abajo
  //agua_arriba();  //flujo de agua hacia arriba
  //agua_izquierda();  //flujo de agua hacia izquierda
  //agua_derecha();  //flujo de agua hacia derecha
  bloque_agua();
  //bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)

////////funciones para enemigos y peligros
  tocar_champinon();  //tocar champiñon
  //pisar_pato();  //pisar pato
  //pisar_seguidor();  //pisar seguidor
  //pisar_salta();  //pisar saltador
  pisar_peligro();  //pisar peligroso
  //pisar_bala();  //pisar las balas
  //pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  NITRO_mata();  //no toques la nitroglicerina
  fuego4_mata();  //no toques el fuego
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
  dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibcristalroto();  //efectos al romper un cristal
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  //dibbala();  //dibujar balas de cañones
  //dibtortugas();  //dibujar tortugas

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(3);
return(0);
}




//==============================================================================================
//==                      Bloques con funciones automaticas                                   ==
//==============================================================================================


void inicializar_escena()
{
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
cargar_enemigos();
detectarblq();  //detectar los tipos de bloque que existen en el escenario
obtener_segundos();  //guardar el tiempo del segundo actual
}


void coordenadas_viejas()
 {
  posicion_champ();  //guardar las coordenadas anteriores de los champiñones
  if(npc[0]==1)  posicion_pato();  //guardar las coordenadas anteriores de los patos
  if(npc[1]==1)  posicion_seguidor();  //guardar las coordenadas anteriores de los patos seguidores
  if(npc[2]==1)  posicion_salta();  //guardar las coordenadas anteriores de los patos saltadores
  if(npc[3]==1)  posicion_peligro();  //guardar las coordenadas anteriores de los patos saltadores seguidores
  if(npc[4]==1)  posicion_mina();  //guardar las coordenadas anteriores de las minas
  posicion_disparo();  //guardar las coordenadas anteriores de los disparos
  posicion_bala();  //guardar las coordenadas anteriores de las balas
  if(npc[5]==1)  posicion_tortuga();  //guardar las coordenadas anteriores de las tortugas
 }


void funcion_bloques1()  //normalmente estos bloques solo alteran posicion, no velocidad
  {
  sistema_colisiones();
  if(blq[201]==1)  bloque_caja0_moneda();  //caja0 con moneda
  if(blq[202]==1)  bloque_caja0_10monedas();  //caja0 con 10 momedas
  if(blq[203]==1)  bloque_caja0_champinon();  //caja0 con champiñon
  if(blq[204]==1)  bloque_caja0_vida();  //caja0 con vida
  if(blq[191]==1)  bloque_caja0_calavera();  //caja0 con calavera
  if(blq[190]==1)  bloque_caja4_moneda();  //caja4 con moneda
  if(blq[189]==1)  bloque_caja4_10monedas();  //caja4 con 10 momedas
  if(blq[188]==1)  bloque_caja4_champinon();  //caja4 con champiñon
  if(blq[187]==1)  bloque_caja4_vida();  //caja4 con vida
  if(blq[185]==1)  bloque_caja4_calavera();  //caja4 con calavera
  if(blq[180]==1)  bloque_madera_moneda();  //madera con moneda
  if(blq[179]==1)  bloque_madera_champinon();  //madera con champiñon
  if(blq[178]==1)  bloque_madera_vida();  //madera con vida
  if(blq[175]==1)  bloque_hielo_champinon();  //hielo con champiñon
  if(blq[174]==1)  bloque_hielo_vida();  //hielo con vida
  if(blq[170]==1)  cristal0_10monedas();  //cristal amarillo con 10 monedas
  if(blq[169]==1)  cristal0_champinon();  //cristal amarillo con champiñon
  if(blq[163]==1)  cristal4_10monedas();  //cristal verde con 10 monedas
  if(blq[162]==1)  cristal4_champinon();  //cristal verde con champiñon
  if(blq[156]==1)  cielo_duro_moneda();  //cielo duro con moneda
  if(blq[261]==1)  cielo_champinon();  //cielo con champiñon
  if(blq[262]==1)  estrellas_champinon();  //estrellas con champiñon
  if(blq[263]==1)  estrellas_vida();  //estrellas con vida
  if(blq[216]==1)  cristal0_moneda();  //cristal0 con moneda
  if(blq[217]==1)  cristal4_moneda();  //cristal4 con moneda
  if(blq[218]==1)  cristal0_vida();  //cristal0 con vida
  if(blq[219]==1)  cristal4_vida();  //cristal4 con vida
  if(blq[214]==1 || blq[215]==1 || blq[234]==1 || blq[235]==1)  bloque_cristal();  //cristal golpe por abajo
  if(blq[235]==1 || blq[214]==1)  bloque_moneda0();  //monedas
  if(blq[234]==1 || blq[215]==1)  bloque_moneda4();  //monedas
  if(blq[251]==1)  estrella_moneda();  //Estrella con moneda
  if(blq[232]==1)  cielo_vida();  //cielo cyan con moneda
  if(blq[233]==1)  cielo_moneda();  //cielo cyan con vida
  }


void funcion_bloques2()
  {
  if(blq[236]==1 || blq[238]==1)  bloque_poder0();  //poder0
  if(blq[240]==1)  bloque_nota0();  //nota0
  if(blq[300]==1)  bloque_saltar();  //bloque para saltar muy alto
  if(blq[253]==1)  cielo_abajo();  //flujo de aire hacia abajo
  if(blq[254]==1)  cielo_arriba();  //flujo de aire hacia arriba
  if(blq[255]==1)  cielo_izquierda();  //flujo de aire hacia la izquierda
  if(blq[256]==1)  cielo_derecha();  //flujo de aire hacia la derecha
  if(blq[257]==1 || blq[258]==1 || blq[259]==1 || blq[260]==1 || blq[273]==1)  agua();  //habilitar si se usa cualquier tipo de bloque con agua
  if(blq[257]==1)  agua_abajo();  //flujo de agua hacia abajo
  if(blq[258]==1)  agua_arriba();  //flujo de agua hacia arriba
  if(blq[259]==1)  agua_izquierda();  //flujo de agua hacia izquierda
  if(blq[260]==1)  agua_derecha();  //flujo de agua hacia derecha
  if(blq[257]==1 || blq[258]==1 || blq[259]==1 || blq[260]==1 || blq[273]==1)  bloque_agua();
  if(blq[241]==1 || blq[242]==1 || blq[243]==1)  bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
  if(blq[244]==1 || blq[245]==1 || blq[246]==1)  bloque_cuadrado1();  //pisarlos pero no golpearlos  (blanco 15)
  }


void funcion_objetos()  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos
  {
  tocar_champinon();  //tocar champiñon
  if(npc[0]==1)  pisar_pato();  //pisar pato
  if(npc[1]==1)  pisar_seguidor();  //pisar seguidor
  if(npc[2]==1)  pisar_salta();  //pisar saltador
  if(npc[3]==1)  pisar_peligro();  //pisar peligroso
  pisar_bala();  //pisar las balas
  if(npc[5]==1)  pisar_tortuga();  //pisar tortuga

  disparo_mata();  //Disparos que matan patos
  if(blq[248]==1)  NITRO_mata();  //no toques la nitroglicerina
  if(blq[252]==1)  fuego4_mata();  //no toques el fuego
  if(npc[0]==1)  pato_mata();  //pato mata cuando los tocas
  if(npc[1]==1)  seguidor_mata();  //seguidor mata cuando los tocas
  if(npc[2]==1)  salta_mata();  //saltador mata cuando los tocas
  if(npc[3]==1)  peligro_mata();  //peligroso mata cuando los tocas
  if(npc[4]==1)  mina_mata(); //mina mata
  bala_mata();  //las balas matan
  if(npc[5]==1)  tortuga_mata();  //tortuga mata cuando los tocas

  if(npc[0]==1)  patofuera();  //verificar si un pato se salio de la pantalla
  if(npc[1]==1)  seguidorfuera();  //verificar si un seguidor se salio de la pantalla
  if(npc[2]==1)  saltafuera();  //verificar si un saltador se salio de la pantalla
  if(npc[3]==1)  peligrofuera();  //verificar si un peligroso se salio de la pantalla
  champifuera();  //verificar si un champiñon se salio de la pantalla
  disparofuera();  //verificar si un disparo se salio de la pantalla
  balafuera();  //verificar si una bala se salio de la pantalla
  if(npc[5]==1)  tortugafuera();  //verificar si una tortuga se salio de la pantalla

  movchamp();  //mover champiñones
  mdemone();  //saltar monedas, generalmente es utilizado
  if(npc[0]==1)  movpato();  //mover patos
  if(npc[1]==1)  movseguidor();  //mover seguidor
  if(npc[2]==1)  movsalta();  //mover saltador
  if(npc[3]==1)  movpeligro();  //mover peligroso
  if(npc[4]==1)  movmina();  //mover las minas
  movdisparo();  //mover disparo
  movbala();  //mover las balas
  if(npc[5]==1)  movtortuga();  //mover tortugas
  }


void refrescar_bloques()
  {
  refchamp();
  if(npc[0]==1)  refpato();
  if(npc[1]==1)  refseguidor();
  if(npc[2]==1)  refsalta();
  if(npc[3]==1)  refpeligro();
  if(npc[4]==1)  refmina();
  refdisparo();
  refbala();
  if(npc[5]==1)  reftortuga();
  }


void dibujar_objetos()
  {
  dibchamp();  //dibujar champiñones
  if(npc[0]==1)  dibpatos();  //dibujar patos
  if(npc[1]==1)  dibseguidor();  //dibujar seguidor
  if(npc[2]==1)  dibsalta();  //dibujar saltador
  if(npc[3]==1)  dibpeligro();  //dibujar peligroso
  if(npc[4]==1)  dibmina();  //dibujar minas
  dibdisparo();  //dibujar disparo
  if(blq[214]==1 || blq[215]==1 || blq[234]==1 || blq[235]==1)  dibcristalroto();  //efectos al romper un cristal
  if(blq[248]==1 || npc[4]==1)  dibexplosion_chica();  //para dibujar explosiones chicas, activar junto con minas, TNTs y NITROS
  dibgolpe();  //utilizado para los disparos, generalmente muy utilizado
  dibbala();  //dibujar balas de cañones
  if(npc[5]==1)  dibtortugas();  //dibujar tortugas
  }



//==============================================================================================
//==                                           Nivel 4                                        ==
//==============================================================================================


escena40()
{
ciclo=0;
nadando=0;
act_fondo(0);
act_cielo(0);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(0);
return(0);
}


escena41()
{
ciclo=0;
nadando=0;
act_fondo(1);
act_cielo(1);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(1);
return(0);
}


escena42()
{
ciclo=0;
nadando=0;
act_fondo(2);
act_cielo(2);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(2);
return(0);
}


escena43()
{
ciclo=0;
nadando=0;
act_fondo(3);
act_cielo(3);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(3);
return(0);
}




//==============================================================================================
//==                                           Nivel 5                                        ==
//==============================================================================================



escena50()
{
ciclo=0;
nadando=0;
act_fondo(0);
act_cielo(0);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(0);
return(0);
}


escena51()
{
ciclo=0;
nadando=0;
act_fondo(1);
act_cielo(1);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(1);
return(0);
}


escena52()
{
ciclo=0;
nadando=0;
act_fondo(2);
act_cielo(2);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(2);
return(0);
}


escena53()
{
ciclo=0;
nadando=0;
act_fondo(3);
act_cielo(3);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(3);
return(0);
}




//==============================================================================================
//==                                           Nivel 6                                        ==
//==============================================================================================



escena60()
{
ciclo=0;
nadando=0;
act_fondo(0);
act_cielo(0);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(0);
return(0);
}


escena61()
{
ciclo=0;
nadando=0;
act_fondo(1);
act_cielo(1);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos

  bloques_solidos();

//inicio debug balas
if((tiempo+0)%8==0 && sec%CPS==0)
  {
    c_bala(10,60,2,0,1);
  }
if((tiempo+1)%8==0 && sec%CPS==0)
  {
    c_bala(10,60,2,0,2);
  }
if((tiempo+2)%8==0 && sec%CPS==0)
  {
    c_bala(10,60,2,0,3);
  }
if((tiempo+3)%8==0 && sec%CPS==0)
  {
    c_bala(620,80,-2,1,1);
  }
if((tiempo+4)%8==0 && sec%CPS==0)
  {
    c_bala(620,120,-2,1,2);
  }
if((tiempo+5)%8==0 && sec%CPS==0)
  {
    c_bala(620,200,-2,0,3);
  }
//fin debug balas


////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(1);
return(0);
}


escena62()
{
ciclo=0;
nadando=0;
act_fondo(2);
act_cielo(2);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(2);
return(0);
}


escena63()
{
ciclo=0;
nadando=0;
act_fondo(3);
act_cielo(3);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(3);
return(0);
}




//==============================================================================================
//==                                           Nivel 7                                        ==
//==============================================================================================


escena70()
{
ciclo=0;
nadando=0;
act_fondo(0);
act_cielo(0);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(0);
return(0);
}


escena71()
{
ciclo=0;
nadando=0;
act_fondo(1);
act_cielo(1);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(1);
return(0);
}


escena72()
{
ciclo=0;
nadando=0;
act_fondo(2);
act_cielo(2);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(2);
return(0);
}


escena73()
{
ciclo=0;
nadando=0;
act_fondo(3);
act_cielo(3);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(3);
return(0);
}



//==============================================================================================
//==                                           Nivel 8                                        ==
//==============================================================================================


escena80()
{
ciclo=0;
nadando=0;
act_fondo(0);
act_cielo(0);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(0);
return(0);
}


escena81()
{
ciclo=0;
nadando=0;
act_fondo(1);
act_cielo(1);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(1);
return(0);
}


escena82()
{
ciclo=0;
nadando=0;
act_fondo(2);
act_cielo(2);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(2);
return(0);
}


escena83()
{
ciclo=0;
nadando=0;
act_fondo(3);
act_cielo(3);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(3);
return(0);
}



//==============================================================================================
//==                                           Nivel 9                                        ==
//==============================================================================================



escena90()
{
ciclo=0;
nadando=0;
act_fondo(0);
act_cielo(0);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(0);
return(0);
}


escena91()
{
ciclo=0;
nadando=0;
act_fondo(1);
act_cielo(1);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(1);
return(0);
}


escena92()
{
ciclo=0;
nadando=0;
act_fondo(2);
act_cielo(2);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(2);
return(0);
}


escena93()
{
ciclo=0;
nadando=0;
act_fondo(3);
act_cielo(3);
inicializar_escena();

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////teclado y otros
  teclado();

  control();  //controla cambios de escenario, monedas, tiempo, conversion de bloques y vuelo.

////////Conviertiendo velocidad en posicion personaje principal
  x=x+vx;
  y=y+vy;

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario

  segundos();  //realizar un conteo del tiempo del juego

  panelnumerico();  //actualizar datos numericos del panel

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
  if(tecla[KEY_CUR_ARRIBA])  //arriba
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
  //fuego4_mata();  //no toques el fuego
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
    x=622;
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
  //fuego4_mata();  //no toques el fuego
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
    x=622;
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
x=344;
y=80;
vx=0.0;
vy=0.0;
escena=1;

//Especial regenerar monedas y poder
if(t_moneda>0)
 {
 convertir();
 }
t_moneda=-88;

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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
  if(tecla[KEY_CUR_ARRIBA])  //arriba
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
  //fuego4_mata();  //no toques el fuego
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
    x=622;
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
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
obtener_segundos();  //guardar el tiempo del segundo actual

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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida

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

////////especial para entrar a tuberia en 35,18 y 36,18
  if(tecla[KEY_CUR_ARRIBA])  //arriba
    {
    if(((y-(y%16))/16 == 18) && ((x-(x%16))/16 == 35))
      {
      ciclo=1;
      escena=2;
      vx=0.0;
      vy=0.0;
      x=376;
      y=336;
      }
    else if(((y-(y%16))/16 == 18) && ((x-(x%16))/16 == 36))
      {
      ciclo=1;
      escena=2;
      vx=0.0;
      vy=0.0;
      x=376;
      y=336;
      }
    }

////////especial para entrar a tuberia en 5,18 y 6,18
  if(tecla[KEY_CUR_ARRIBA])  //arriba
    {
    if(((y-(y%16))/16 == 18) && ((x-(x%16))/16 == 5))
      {
      ciclo=1;
      escena=1;
      vx=0.0;
      vy=0.0;
      x=464;
      y=224;
      }
    else if(((y-(y%16))/16 == 18) && ((x-(x%16))/16 == 6))
      {
      ciclo=1;
      escena=1;
      vx=0.0;
      vy=0.0;
      x=464;
      y=224;
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
  //fuego4_mata();  //no toques el fuego
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
    x=622;
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}

return(0);
}


//==============================================================================================
//==                                     Tutorial                                             ==
//==============================================================================================


tutorial0()
{
if(avance_tutorial[0]==0)  //solo ejecutar la primera vez
  {
  oscurecer_paleta(cambios_por_segundo_paleta*2);
  setfillstyle(1,0);
  bar(0,0,639,479);
  texto(120,8,0,15,"Bienvenido al tutorial de Super Patito Bros 3");
  bmp16(16,16,"Teclado.bmp",0);
  bmp16(80,300,"Formas.bmp",0);
  texto(120,464,0,15,"Presiona una tecla para empezar");
  paleta_predeterminada();
  tomarletra();
  }
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
obtener_segundos();  //guardar el tiempo del segundo actual

//texto(int i2, int j2, int colorfondo,int colortexto, char *txt)
//setfillstyle(1,11);
//bar(80,16,530,32);


fondo();

bmp16(540,200,"Avanza.bmp",0);

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
  sistema_colisiones();

////////interaccion de los bloques
  bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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

////////Especial tutorial0
  if(avance_tutorial[0]==0)  //solo ejecutar la primera vez
    {
    if(avance_tutorial[1]==0)
      {
      if(x>40 && x<80)
        {
        //setfillstyle(1,11);
        //bar(80,16,530,24);
        texto(80,200,0,15,"Toma las monedas te pueden servir en un futuro");
        avance_tutorial[1]=1;
        }
      }
    if(avance_tutorial[2]==0)
      {
      if(x>230 && x<340 && y>360 && estado==1)
        {
        //setfillstyle(1,11);
        //bar(80,16,530,24);
        texto(80,216,0,15,"Nececitas crecer para poder romper los bloques");
        avance_tutorial[2]=1;
        }
      }
    if(avance_tutorial[3]==0)
      {
      if(x>60 && x<440 && y<240 && avance_tutorial[4]==0)
        {
        //setfillstyle(1,11);
        //bar(80,16,530,24);
        texto(80,136,0,15,"Anda... Puedes comerte los letreros si quieres");
        avance_tutorial[3]=1;
        }
      }
    if(avance_tutorial[4]==0)
      {
      if(x>200 && estado==2)  //x>200 por si entras al tutorial siendo grande
        {
        setfillstyle(1,0);
        bar(80,200,448,208);
        bar(80,216,448,224);
        bar(80,136,448,144);
        texto(80,8,0,15,"¡Bien Hecho! Ahora puedes romper los bloques amarillos");
        avance_tutorial[4]=1;
        }
      }
    if(avance_tutorial[5]==0)
      {
      if(y<96)
        {
        texto(80,16,0,15,"Has demostrado ser capas de volar ¡Muy bien!");
        avance_tutorial[5]=1;
        }
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
  bloque_cuadrado0();  //pisarlos pero no golpearlos  (azul claro 9)
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(0);
avance_tutorial[0]=1;
return(0);
}


tutorial1()
{
avance_tutorial[1]=0;
avance_tutorial[2]=0;
avance_tutorial[3]=0;
avance_tutorial[4]=0;
avance_tutorial[5]=0;
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
obtener_segundos();  //guardar el tiempo del segundo actual
c_pato(14,23);
npato[0]=-1;

if(avance_tutorial[0]==1)
  {
  texto(120,8,0,15,"Ahora pongamos un enemigo:");
  texto(120,16,0,15,"Para vencerlo simplemente pisalo");
  }

while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {gotoxy(1,1); printf("x=%d   y=%d   ",x,y);
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida

 ////////especial si golpea 18,21 (cristal0) que aparesca un poder0 en 18,20
  if(avance_tutorial[1]==0)
    {
    if(npato[0]==0)  //pato no existe
      {
      texto(120,24,0,15,"¡Bien hecho!");
      avance_tutorial[1]=1;
      }
    }
  if(avance_tutorial[2]==1)
    {
    texto(32,32,0,15,"Ese poder te permite convertir bloques en monedas y monedas en bloques");
    avance_tutorial[2]=2;
    }
  if(avance_tutorial[3]==0)
    {
    if(x>160 && x<460 && y<256)
      {
      texto(120,40,0,15,"Solo en unas pocas tuberias se puede entrar");
      texto(120,48,0,15,"Algunas tuberias tienen un flujo de aire potente");
      avance_tutorial[3]=1;
      }
    }

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
      avance_tutorial[2]=1;
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
      avance_tutorial[2]=1;
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(1);
return(0);
}


tutorial2()
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
if(tiempo%22==0 && sec%CPS==0)
  {
  c_pato(18,22);
  }
if(tiempo%28==0 && sec%CPS==0)
  {
  c_pato(25,17);
  }

////////especial para entrar a tuberia en 25,17 y 26,17
  if(tecla[KEY_CUR_ARRIBA])  //arriba
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(2);
return(0);
}


tutorial3()
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
obtener_segundos();  //guardar el tiempo del segundo actual
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
  sistema_colisiones();

////////interaccion de los bloques
  //bloque_caja0_moneda();  //caja0 con moneda
  //bloque_caja0_10monedas();  //caja0 con 10 momedas
  //bloque_caja0_champinon();  //caja0 con champiñon
  //bloque_caja0_vida();  //caja0 con vida
  //bloque_caja0_calavera();  //caja0 con calavera
  //bloque_caja4_moneda();  //caja4 con moneda
  //bloque_caja4_10monedas();  //caja4 con 10 momedas
  //bloque_caja4_champinon();  //caja4 con champiñon
  //bloque_caja4_vida();  //caja4 con vida
  //bloque_caja4_calavera();  //caja4 con calavera
  //bloque_madera_moneda();  //madera con moneda
  //bloque_madera_champinon();  //madera con champiñon
  //bloque_madera_vida();  //madera con vida
  //bloque_hielo_champinon();  //hielo con champiñon
  //bloque_hielo_vida();  //hielo con vida
  //cristal0_10monedas();  //cristal amarillo con 10 monedas
  //cristal0_champinon();  //cristal amarillo con champiñon
  //cristal4_10monedas();  //cristal verde con 10 monedas
  //cristal4_champinon();  //cristal verde con champiñon
  //cielo_duro_moneda();  //cielo duro con moneda
  //cielo_champinon();  //cielo con champiñon
  //estrellas_champinon();  //estrellas con champiñon
  //estrellas_vida();  //estrellas con vida
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
if(tiempo%8==0 && sec%CPS==0)
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
  //fuego4_mata();  //no toques el fuego
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

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
guardar_fondo(3);
return(0);
}


escena_presentacion()
{
FILE *archivo;  //archivo de animacion
int n,i,p_disparando,selector=0,selectory=320,selector_pressionado_a=0,selector_pressionado_b=0;
char T;
ciclo=0;
nadando=0;
wait_foreground();  //Esperar a que se active la ventana antes de empezar el juego para evitar errores gr ficos
paleta_negra();
abrir(-3,20);
abrircielo(-3,20);
guardar_fondo(0);  //guardar una copia original antes de modificarla
fondo();
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
for(i=0;i<8;i++)  //debe tener una velocidad "virtual" para que se dibuje en el sentido correcto
  {
  tortugavx[i]=1.0;
  }
detectarblq();  //detectar los tipos de bloque que existen en el escenario
obtener_segundos();  //guardar el tiempo del segundo actual
x=-200;  //para que no borre el pedazo de pantalla al iniciar se pone negativo (fuera de la pantalla)
y=-200;
tiempo=400;
bmp16(140,0,"patito16.bmp",0);

//texto(240,20,0,15,"Super Patito Bros 3 en lenguaje C");
//texto(220,48,2,10,"Thierry Joseph Valery Garcia Greiner");
//texto(240,64,0,14,"Programado usando Turbo C 3.0");
//texto(220,80,1,11,"Presiona Enter para empezar");
paleta_predeterminada();

archivo = fopen("anim.txt","rb");
if(archivo==NULL)
  {
  gotoxy(1,1);
  printf( "Error: No se puede abrir el archivo de animacion anim.txt");
  tomarletra();
  DesinstalaTeclado();
  closegraph();
  exit( 1 );
  }
while(ciclo<1)  //ciclo del juego, cada ciclo sera un cuadro diferente de los movimientos existentes, es decir un cambio de posicion de cada objeto
  {
////////Guardando las coordenadas anteriores
  o=x;
  p=y;
  coordenadas_viejas();

  tinvensible();  //tiempo de inmunidad

////////interaccion de los bloques
  funcion_bloques1();

////////funcion para deteccion de los bloques solidos
  bloques_solidos();

////////interaccion de los bloques
  funcion_bloques2();

////////funciones para enemigos y peligros
  funcion_objetos();  //funcion para tocar objetos, objetos fuera de la pantalla, y mover los objetos

////////En este caso el teclado es para el control de los menus, no controla el personaje
  //teclado();  // FALTA HACERLO
  if(tecla[KEY_ENTER])  //enter salir presentacion
    {
    ciclo=1;
    }
  if(tecla[KEY_F4])  //Alt+F4 salir
    {
    DesinstalaTeclado();
    closegraph();
    exit (2);
    }
  if(tecla[KEY_CUR_ARRIBA])
    {
    if(selector_pressionado_a==0)
        {
        selector_pressionado_a=1;
        bloque(208,selectory,paisaje[(selectory-(selectory%16))/16][(208-(208%16))/16]);
        selector--;
        }
    }
    else
        {
        selector_pressionado_a=0;
        }
  if(tecla[KEY_CUR_ABAJO])
    {
    if(selector_pressionado_b==0)
        {
        selector_pressionado_b=1;
        bloque(208,selectory,paisaje[(selectory-(selectory%16))/16][(208-(208%16))/16]);
        selector++;
        }
    }
    else
        {
        selector_pressionado_b=0;
        }

  //controla conversion de bloques.
  if(t_moneda==tiempo)
    {
    convertir();
    t_moneda=-88;
    }

////////Aqui se controla el personaje y se sobreescribe todos los enemigos
  if(feof(archivo)==0)
    {
    fscanf(archivo,"%d,%d,%f,%f,%d,%d,%d,",&x,&y,&vx,&vy,&dirx,&estado,&p_disparando);
    if(p_disparando)
      {
      if(estado==4)
        {
        c_disparo();
        }
      }
    while(getc(archivo)!='\r' && feof(archivo)==0)  //lee una 'C' o '\r'
      {
      T=getc(archivo);  //tipo de enemigo
      if(T=='0')
        {
        npc[0]=1;
        fscanf(archivo,",%d,",&n);  //numero de enemigo
        fscanf(archivo,"%d,%d,%d,",&npato[n],&patox[n],&patoy[n]);  //estado y posicion
        }
      if(T=='1')
        {
        npc[1]=1;
        fscanf(archivo,",%d,",&n);
        fscanf(archivo,"%d,%d,%d,",&nseguidor[n],&seguidorx[n],&seguidory[n]);
        }
      if(T=='2')
        {
        npc[2]=1;
        fscanf(archivo,",%d,",&n);
        fscanf(archivo,"%d,%d,%d,",&nsalta[n],&saltax[n],&saltay[n]);
        }
      if(T=='3')
        {
        npc[3]=1;
        fscanf(archivo,",%d,",&n);
        fscanf(archivo,"%d,%d,%d,",&npeligro[n],&peligrox[n],&peligroy[n]);
        }
      if(T=='4')
        {
        npc[4]=1;
        fscanf(archivo,",%d,",&n);
        fscanf(archivo,"%d,%d,%d,",&nmina[n],&minax[n],&minay[n]);
        }
      if(T=='5')
        {
        npc[5]=1;
        fscanf(archivo,",%d,",&n);
        fscanf(archivo,"%d,%d,%d,",&ntortuga[n],&tortugax[n],&tortugay[n]);
        }
      if(T=='6')
        {
        fscanf(archivo,",%d,",&n);
        fscanf(archivo,"%d,%d,%d,",&nbala[n],&balax[n],&balay[n]);
        }
      }
    }
  else
    {
    rewind(archivo);  //repetir animacion
    if(t_moneda>0)
      {
      t_moneda=-88;
      convertir();
      }
    tiempo=400;
    act_fondo(0);  //restaurar el fondo original
    fondo();
    bmp16(140,0,"patito16.bmp",0);
    }

////////operaciones del los bloques, borrando dibujos viejos redibujando el fondo
  refbloques();  //dibujar el fondo sobre el personaje principal
  refrescar_bloques();  //dibujar el fondo para todos los objetos

////////dibujando personajes, enemigos, paneles y marcadores
  verestado();  //verificar el estado del pato y dibujarlo segun el estado, personaje principal
  dibujar_objetos();  //dibujar todos los objetos del escenario
  //texto(220,320,0,13,"Presiona Enter para empezar");
  texto(220,320,0,13,"Comenzar juego");
  texto(220,336,0,13,"Tutorial");
  texto(220,352,0,13,"Editor de niveles");
  texto(220,368,0,13,"Creditos");

  if(selector==0)
    {
    selectory=320;
    }
  else if(selector==1)
    {
    selectory=336;
    }
  else if(selector==2)
    {
    selectory=352;
    }
  else if(selector==3)
    {
    selectory=368;
    }

  if(sec%CPS==0)
    {
    texto(208,selectory,0,1,"");
    }
  else if(sec%10==1)
    {
    texto(208,selectory,0,11,"");
    }
  else if(sec%10==2)
    {
    texto(208,selectory,0,2,"");
    }
  else if(sec%10==3)
    {
    texto(208,selectory,0,10,"");
    }
  else if(sec%10==4)
    {
    texto(208,selectory,0,3,"");
    }
  else if(sec%10==5)
    {
    texto(208,selectory,0,13,"");
    }
  else if(sec%10==6)
    {
    texto(208,selectory,0,4,"");
    }
  else if(sec%10==7)
    {
    texto(208,selectory,0,14,"");
    }
  else if(sec%10==8)
    {
    texto(208,selectory,0,15,"");
    }
  else if(sec%10==9)
    {
    texto(208,selectory,0,8,"");
    }

  segundos();  //realizar un conteo del tiempo del juego

  ajuste_FPS();  //ajustar el retraso para que la imagen sea CPS cuadros por segundo
  delay(retraso);

}
if(fclose(archivo)!=0)
  {
  gotoxy(1,1);
  printf( "Problemas al cerrar el archivo anim.txt\n" );
  }
puntos=0;
vidas=4;
monedas=0;
estado=1;

return(0);
}
