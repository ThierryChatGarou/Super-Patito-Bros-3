#include <stdio.h>
#include <math.h>
#include "graphics.h"


#ifdef GRAPHICS
#include <windows.h>
#include <gl/gl.h>

WNDCLASSEX wcex;
HWND hwnd;
HDC hDC;
HGLRC hRC;
MSG msg;
BOOL bQuit = FALSE;
HINSTANCE hInstance;

int last_Lmouse=0,last_Rmouse=0;
int sec1=0,conteo=0;
int actual_color=15;

#endif

void frameStarted(void)
    {
    sec1++;
    if (sec1==16)
        {
        sec1=0;
        conteo++;
        }

    //mouse_getcoordinates();


    }


void create_scene(void)
    {
#ifdef GRAPHICS
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //Nota: SwapBuffers no se use si SINGLE_GLBUFFER esta definido
    //fondo();
    //SwapBuffers(hDC);
    //fondo();//dibujar lo mismo en ambos lados del buffer
    //SwapBuffers(hDC);
#endif
    }


void render_opengl_windows(void)
    {
#ifndef MSDOS
    static unsigned char hwnd_focus=0;
#ifdef GRAPHICS
    /* check for messages */
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
        /* handle or dispatch messages */
        if (msg.message == WM_QUIT)
            {
            bQuit = TRUE;
            }
        else
            {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            }
        }
    else
        {

        }

//#define PAUSE_IF_NOT_FOCUSED
#ifndef PAUSE_IF_NOT_FOCUSED
//Detect loose of focus
    HWND hwnd_foreground = GetForegroundWindow();
    if(hwnd == hwnd_foreground)
        {
         //printf("Foreground True\r\n");
         IntTeclado();
          if(hwnd_focus==0)  //si la ventana se ha activado entonces es necesario redibujar fondo
               {
               hwnd_focus=1;
               SwapBuffers(hDC);
               SwapBuffers(hDC);
               }
        }
    else
        {
         //printf("Foreground False\r\n");
         hwnd_focus=0;
        }
#else
//Detect loose of focus
    HWND hwnd_foreground = GetForegroundWindow();
    if(hwnd == hwnd_foreground)
        {
         //printf("Foreground True\r\n");
         IntTeclado();
         if(hwnd_focus==0)  //si la ventana se h activado entonces es necesario redibujar fondo
               {
               hwnd_focus=1;
               SwapBuffers(hDC);
               SwapBuffers(hDC);
               }
        }
    else
        {
         //printf("Foreground False\r\n");
         hwnd_focus=0;
         while(hwnd != hwnd_foreground)
            {
            hwnd_foreground = GetForegroundWindow();
            if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                {
                /* handle or dispatch messages */
                if (msg.message == WM_QUIT)
                    {
                    bQuit = TRUE;
                    }
                else
                    {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                    }
                }
            else
                {

                }
            }
        }
#endif  //ifndef PAUSE_IF_NOT_FOCUSED


/* OpenGL animation code goes here */
        frameStarted();
        //fondo();
#ifdef SINGLE_GLBUFFER
        glDrawBuffer(GL_FRONT);
        glFlush();
#else
        SwapBuffers(hDC);
#endif

#endif
#endif
    }


//GetConsoleWindow(); no es soportado en esta version de windows, se hace este workaround
HWND GetConsoleHandle()
    {
	#define BUFFSIZE 768
	HWND hwnd;
	char pszWindowTitle[BUFFSIZE];

	GetConsoleTitle(pszWindowTitle, BUFFSIZE);
	int i = strlen(pszWindowTitle);
	_itoa(GetTickCount(), &pszWindowTitle[i], 16);
	_itoa(GetCurrentProcessId(), &pszWindowTitle[strlen(pszWindowTitle)], 16);
	SetConsoleTitle(pszWindowTitle);
	Sleep(50);
	hwnd = FindWindow(NULL, pszWindowTitle);
	pszWindowTitle[i] = 0;
	SetConsoleTitle(pszWindowTitle);
	return(hwnd);
    }


//Bloquea el programa y espera a que se selccione la ventana.
void wait_foreground()
    {
#ifndef MSDOS
    //HWND hwnd_console = GetConsoleHandle();
    //ShowWindow(hwnd_console, 0);  //Hide console window and wait for the opengl window to show
    HWND hwnd_foreground = GetForegroundWindow();
    while(hwnd != hwnd_foreground)
        {
        hwnd_foreground = GetForegroundWindow();
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
            {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
                {
                bQuit = TRUE;
                }
            else
                {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
                }
            }
        else
            {

            }
        }
        //No se porque pero es necesario para evitar que se quede la pantalla negra si se selecciona la ventana muy rapidamente.
        glDrawBuffer(GL_FRONT);
        //glFlush();
#endif
    }

/**
Inicializa una ventana de Opengl de dimensiones especificadas
por las constantes CLIENTWIDTH y CLIENTHEIGHT.
@return Retorna 0 en ‚xito y 1 si falla la inicializaci¢n.
**/
int init_opengl_windows()
    {
#ifdef GRAPHICS
#define CLIENTWIDTH 640
#define CLIENTHEIGHT 480
    SetConsoleTitle("Super Patito Bros 3 - Console");

    RECT Rect,RectAct;
    hInstance = GetModuleHandle(NULL);

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
        return 1;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "Super Patito Bros 3 - OpenGL Graphics",
                          WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU,
                          360,//CW_USEDEFAULT,
                          160,//CW_USEDEFAULT,
                          CLIENTWIDTH,
                          CLIENTHEIGHT,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, 1);

    //Retrieves the dimensions of the bounding rectangle of the specified window.
    GetWindowRect(hwnd, &RectAct);
    //Retrieves the coordinates of a window's client area.
    GetClientRect(hwnd, &Rect);
    Rect.right=CLIENTWIDTH-Rect.right+RectAct.right-RectAct.left;
    Rect.bottom=CLIENTHEIGHT-Rect.bottom+RectAct.bottom-RectAct.top;

    MoveWindow(
        hwnd,
        RectAct.left,  //X
        RectAct.top,   //Y
        Rect.right,  //nWidth
        Rect.bottom,  //nHeight
        TRUE
    );

    //enable OpenGL for the window
    EnableOpenGL(hwnd, &hDC, &hRC);

    const int GL_XSize = CLIENTWIDTH, GL_YSize = CLIENTHEIGHT;
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (0, GL_XSize, GL_YSize, 0, 0, 1);
    glMatrixMode (GL_MODELVIEW);
    glDisable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0,0,GL_XSize, GL_YSize);
    glTranslatef(0.375, 0.375, 0.0);  //truco para que los pixeles este alineados
    create_scene();
#endif
    return 0;
    }


/**
Cierra la ventana de OpenGL
**/
void destroy_opengl_windows(void)
    {
#ifdef GRAPHICS
    /* shutdown OpenGL */
    printf("Apagando OpenGL\r\n");
    DisableOpenGL(hwnd, hDC, hRC);
    printf("Destruyendo ventana\r\n");
    /* destroy the window explicitly */
    DestroyWindow(hwnd);
#endif
    }

#ifdef GRAPHICS
/**
Interpreta los comandos recibidos por la ventana de OpenGL y realiza acciones.
Termina el programa el presionar el bot¢n de cerrar
Esta funci¢n es un CALLBACK y es llamada por el sistema operativo.
@param hwnd: Handle a la ventana a la que se escucha los comandos.
@param uMsg: Mensaje de windows
@param wParam: WParam de MS Windows
@param lParam: LParam de MS Windows
**/
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
    switch (uMsg)
        {
        case WM_CLOSE:
            PostQuitMessage(0);
            exit(0);
            break;

        case WM_DESTROY:
            return 0;

        case WM_PAINT:
            //fondo();
            //printf("Fondo redibujado\n");
            break;


        case WM_KEYDOWN:
                {
                switch (wParam)
                    {
                    /*case VK_ESCAPE:
                        PostQuitMessage(0);
                        exit(0);
                        break;*/
                    }
                }
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }

    return 0;
    }
#endif


/**
Habilita OpenGl en la ventana, dispositivo y render seleccionado.
@param hwnd: Ventana que contiene el  rea para dibujar en OpenGL
@param hDC: contexto del dispositivo
@param hRC: contexto del sistema de renderizado.
**/
#ifdef GRAPHICS
void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
    {
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    //get the device context (DC)
    *hDC = GetDC(hwnd);

    // set the pixel format for the DC
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
    }
#endif


#ifdef GRAPHICS

/**
Deshabilita OpenGl y libera los recursos uti¤lizados.
@param hwnd: Ventana que contiene el  rea de dibujo en OpenGL
@param hDC: contexto del dispositivo
@param hRC: contexto del sistema de renderizado.
**/
void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
    {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
    }


/**
Obtiene las coordenadas del rat¢n en la ventana en el espacio cliente
(el espacio de trabajo) y almacena los valores obtenidos en
las variables globales ratonx y raton y
**/
void mouse_getcoordinates(int *ratonx, int *ratony)
    {
    static int lastx=0,lasty=0;
    POINT curpos;
    GetCursorPos(&curpos);
    ScreenToClient( hwnd, &curpos);

    if(curpos.x<0 || curpos.x>=640 || curpos.y<0 || curpos.y>=479)
      {
      *ratonx=lastx;
      *ratony=lasty;
      }
    else
      {
      *ratonx = curpos.x;
      *ratony = curpos.y;
      lastx = curpos.x;
      lasty = curpos.y;
      }



/*

    *ratonx=curpos.x;
    *ratony=curpos.y;

if(ratonx<0)
{
ratonx=0;
}
if()
{
ratonx=639;
}
if(ratony<0)
{
ratony=0;
}
if(ratony>=479)
{
ratony=479;
}*/

    }



/** Sobre escribiendo funciones Graficas MSDOS **/
int detectgraph(int *gdriver, int *gmode)
{
*gdriver=9;
*gmode=2;
return 0;
}

int graphresult()
{
return 0;
}

char *grapherrormsg(int errorcode)
{
char *aux;
aux = (char *) malloc (1);
*aux = '\0';
return aux;
}

int initgraph(int *gdriver, int *gmode, char *a)
{
*gdriver=9;
*gmode=2;
init_opengl_windows();
return 0;
}

getpalette(struct palettetype *p)
{

}

setrgbpalette(int a, int b, int c, int d)
{

}

int closegraph()
{
return 0;
}


/**
* Dibuja un pixel de un color en la pantalla en las coordenadas dadas.
* @param [in] x,y: coordenadas en la pantalla.
* @param [in] r,g,b: Color en formato rgb.
* @return no retorna.
* @remarks metodo ineficiente, ya que usa glBegin() y glEnd() por cada pixel. los colores tienen un valor de 0 a 255
**/
inline void GLpixel(short x, short y, unsigned char r, unsigned char g, unsigned char b)
    {
    glBegin(GL_POINTS);
    glColor3ub(r, g, b);
    glVertex2f(x, y);
    glEnd();
    }


/**
* Dibuja un pixel de un color en la pantalla en las coordenadas dadas, emulando el el sistema BGI
* @param [in] x,y: coordenadas en la pantalla.
* @param [in] color: Color en formato BGI.
* @return no retorna.
* @remarks metodo ineficiente, ya que usa glBegin() y glEnd() por cada pixel. los colores tienen un valor de 0 a 15
**/
inline void putpixel(short x, short y, unsigned char color)
    {
    glBegin(GL_POINTS);
    switch (color%16)
        {
        case 0:
            glColor3ub(0,0,0);
            break;
        case 1:
            glColor3ub(0,0,168);
            break;
        case 2:
            glColor3ub(0,168,0);
            break;
        case 3:
            glColor3ub(0,168,168);
            break;
        case 4:
            glColor3ub(168,0,0);
            break;
        case 5:
            glColor3ub(168,0,160);
            break;
        case 6:
            glColor3ub(168,80,0);
            break;
        case 7:
            glColor3ub(168,168,168);
            break;
        case 8:
            glColor3ub(84,84,84);
            break;
        case 9:
            glColor3ub(84,84,255);
            break;
        case 10:
            glColor3ub(80,255,80);
            break;
        case 11:
            glColor3ub(80,255,255);
            break;
        case 12:
            glColor3ub(255,80,80);
            break;
        case 13:
            glColor3ub(255,80,255);
            break;
        case 14:
            glColor3ub(255,255,80);
            break;
        case 15:
            glColor3ub(255,255,255);
            break;
        }
    glVertex2f(x, y);
    glEnd();
    }


/**
* Dibuja una linea de un color en la pantalla en las coordenadas dadas
* @param [in] x,y: Coordenadas iniciales.
* @param [in] x2,y2: coordenadas finales en la pantalla.
* @param [in] r,g,b: color en formato RGB
* @return no retorna.
* @remarks metodo ineficiente, ya que usa glBegin() y glEnd() por cada linea. los colores tienen un valor de 0 a 255
**/
inline void GLline(short x, short y, short x2, short y2, unsigned char r, unsigned char g, unsigned char b)
    {
    glBegin(GL_LINES);
    glColor3ub(r, g, b );
    glVertex2f(x, y);
    glVertex2f(x2, y2);
    glEnd();
    }


/**
* Dibuja una linea del color actual en la pantalla en las coordenadas dadas emulando el sistema BGI
* @param [in] x,y: Coordenadas iniciales.
* @param [in] x2,y2: coordenadas finales en la pantalla.
* @param [in] r,g,b: color en formato RGB
* @return no retorna.
* @remarks metodo ineficiente, ya que usa glBegin() y glEnd() por cada linea. los colores tienen un valor de 0 a 255
**/
inline void line(int x1, int y1, int x2, int y2)
    {
    glBegin(GL_LINES);
    setcolor(actual_color);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    }



/**
* Dibuja un rect ngulo sin relleno
* @param [in] x,y,x2,y2: Dibuja un rect ngulo desde x,y hasta x2,y2
* @param [in] r,g,b:  color en formato RGB
* @return no retorna.
* @remarks metodo ineficiente, ya que usa glBegin() y glEnd() por cada linea. los colores tienen un valor de 0 a 255
**/
inline void GLrectangle(short x, short y, short x2, short y2, unsigned char r, unsigned char g, unsigned char b)
    {
    glBegin(GL_LINE_LOOP);
    glColor3ub(r, g, b);
    glVertex2f(x, y);
    glVertex2f(x2, y);
    glVertex2f(x2, y2);
    glVertex2f(x, y2);
    glEnd();
    }

/**
* Dibuja un rect ngulo con relleno
* @param [in] x,y,x2,y2: Dibuja un rect ngulo desde x,y hasta x2,y2
* @param [in] r,g,b: color en formato RGB
* @return no retorna.
* @remarks metodo ineficiente, ya que usa glBegin() y glEnd() por cada linea. los colores tienen un valor de 0 a 255
*          Dibuja incluyendo x2,y2 del mismo modo que la clasica librer¡a BGI
**/
inline void GLbar(short x, short y, short x2, short y2, unsigned char r, unsigned char g, unsigned char b)
    {
    glBegin(GL_QUADS);
    glColor3ub(r, g, b);
    glVertex2f(x, y);
    glVertex2f(x2+1, y);
    glVertex2f(x2+1, y2+1);
    glVertex2f(x, y2+1);
    glEnd();
    }


/**
* emula la funcion setfillstyle de BGI
* @param style: cambio de patrones no implementado
* @param color: un color de 0 a 15 en formato BGI
* @return no retorna.
* @remarks metodo ineficiente. los colores tienen un valor de 0 a 15
**/
inline void setfillstyle(unsigned char style, unsigned char color)
    {
    actual_color=color;
    switch (color)
        {
        case 0:
            glColor3ub(0,0,0);
            break;
        case 1:
            glColor3ub(0,0,168);
            break;
        case 2:
            glColor3ub(0,168,0);
            break;
        case 3:
            glColor3ub(0,168,168);
            break;
        case 4:
            glColor3ub(168,0,0);
            break;
        case 5:
            glColor3ub(168,0,160);
            break;
        case 6:
            glColor3ub(168,80,0);
            break;
        case 7:
            glColor3ub(168,168,168);
            break;
        case 8:
            glColor3ub(84,84,84);
            break;
        case 9:
            glColor3ub(84,84,255);
            break;
        case 10:
            glColor3ub(80,255,80);
            break;
        case 11:
            glColor3ub(80,255,255);
            break;
        case 12:
            glColor3ub(255,80,80);
            break;
        case 13:
            glColor3ub(255,80,255);
            break;
        case 14:
            glColor3ub(255,255,80);
            break;
        case 15:
            glColor3ub(255,255,255);
            break;
        }
    }


/**
* emula la funcion setcolor de BGI
* @param color: un color de 0 a 15 en formato BGI
* @return no retorna.
* @remarks metodo ineficiente. los colores tienen un valor de 0 a 15
**/
inline void setcolor(int color)
    {
    actual_color=color;
    switch (color)
        {
        case 0:
            glColor3ub(0,0,0);
            break;
        case 1:
            glColor3ub(0,0,168);
            break;
        case 2:
            glColor3ub(0,168,0);
            break;
        case 3:
            glColor3ub(0,168,168);
            break;
        case 4:
            glColor3ub(168,0,0);
            break;
        case 5:
            glColor3ub(168,0,160);
            break;
        case 6:
            glColor3ub(168,80,0);
            break;
        case 7:
            glColor3ub(168,168,168);
            break;
        case 8:
            glColor3ub(84,84,84);
            break;
        case 9:
            glColor3ub(84,84,255);
            break;
        case 10:
            glColor3ub(80,255,80);
            break;
        case 11:
            glColor3ub(80,255,255);
            break;
        case 12:
            glColor3ub(255,80,80);
            break;
        case 13:
            glColor3ub(255,80,255);
            break;
        case 14:
            glColor3ub(255,255,80);
            break;
        case 15:
            glColor3ub(255,255,255);
            break;
        }
    }


/**
* emula la funcion bar de BGI
* @param x,y,x2,y2: Dibuja un rect ngulo desde x,y hasta x2,y2
* @return no retorna.
* @remarks metodo ineficiente.
**/
inline void bar(short x, short y, short x2, short y2)
    {
    glBegin(GL_QUADS);
    setcolor(actual_color);
    glVertex2f(x, y);
    glVertex2f(x2+1, y);
    glVertex2f(x2+1, y2+1);
    glVertex2f(x, y2+1);
    glEnd();
    }

/**
* Dibuja un circulo con lineas
* @param x,y: posici¢n x,y del centro del circulo
* @param radius: radio del circulo
* @param r,g,b: color en formato RGB
* @return no retorna.
* @remarks metodo ineficiente. los colores tienen un valor de 0 a 255
**/
inline void GLcircle(short x, short y, unsigned short radius, unsigned char r, unsigned char g, unsigned char b)
    {
    unsigned short angle;
    glBegin(GL_LINE_LOOP);
    glColor3ub(r, g, b);
    if (radius<10)
        {
        for (angle = 0 ; angle< 360; angle+=36)
            {
            glVertex2f(x + sin(angle*2*3.1415926537/(float)360) * radius, y + cos(angle*2*3.1415926537/(float)360) * radius);
            }
        }
    else if (radius<50)
        {
        for (angle = 0 ; angle< 360; angle+=10)
            {
            glVertex2f(x + sin(angle*2*3.1415926537/(float)360) * radius, y + cos(angle*2*3.1415926537/(float)360) * radius);
            }
        }
    else if (radius<400)
        {
        for (angle = 0 ; angle< 360; angle+=5)
            {
            glVertex2f(x + sin(angle*2*3.1415926537/(float)360) * radius, y + cos(angle*2*3.1415926537/(float)360) * radius);
            }
        }
    else
        {
        for (angle = 0 ; angle< 360; angle+=2)
            {
            glVertex2f(x + sin(angle*2*3.1415926537/(float)360) * radius, y + cos(angle*2*3.1415926537/(float)360) * radius);
            }
        }
    glEnd();
    }


/**
* Dibuja un circulo relleno con triangulos
* @param x,y: posici¢n x,y del centro del circulo
* @param radius: radio del circulo
* @param r,g,b: color en formato RGB
* @return no retorna.
* @remarks metodo ineficiente. los colores tienen un valor de 0 a 255
**/
inline void GLpoint(short x, short y, unsigned short radius, unsigned char r, unsigned char g, unsigned char b)
    {
    unsigned short angle;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r, g, b);
    glVertex2f(x, y);
    if (radius<10)
        {
        for (angle = 0 ; angle<= 360; angle+=36)
            {
            glVertex2f(x + sin(angle*2*3.1415926537/(float)360) * radius, y + cos(angle*2*3.1415926537/(float)360) * radius);
            }
        }
    else if (radius<50)
        {
        for (angle = 0 ; angle<= 360; angle+=10)
            {
            glVertex2f(x + sin(angle*2*3.1415926537/(float)360) * radius, y + cos(angle*2*3.1415926537/(float)360) * radius);
            }
        }
    else if (radius<400)
        {
        for (angle = 0 ; angle<= 360; angle+=5)
            {
            glVertex2f(x + sin(angle*2*3.1415926537/(float)360) * radius, y + cos(angle*2*3.1415926537/(float)360) * radius);
            }
        }
    else
        {
        for (angle = 0 ; angle<= 360; angle+=2)
            {
            glVertex2f(x + sin(angle*2*3.1415926537/(float)360) * radius, y + cos(angle*2*3.1415926537/(float)360) * radius);
            }
        }
    glEnd();
    }


/**
* Dibuja una imagen BMP16
* @param [in] i,j: posici¢n x,y de la imagen
* @param [in] nombrearchivo: nombre del archivo BMP
* @return no retorna.
* @remarks nececita eficientar, la imagenes deben ser multiplo de 4 en X debido a problemas con el formato BMP
**/
/*void bmp16(int i, int j, char *nombrearchivo)  //ejemplo: bmp16(0,0,"Dibujo.bmp");
    {
    FILE *archivo;
    int n,m,bmp_largo,bmp_ancho;
    unsigned char dato,a,b;
    archivo = fopen(nombrearchivo,"rb");
    if (archivo!=NULL)
        {
        for (n=0;n<18;n++) //omitir 18 bytes
            {
            (void) getc(archivo);
            }
//los siguientes 4 bytes son el largo de la imagen siendo:
//  LSB               MSB        en este orden
// 0-255 0-255 0-255 0-255
//como el orden esta invertido uso esta forma de leer los primeros 16 bits (2 bytes), del tamano.
        bmp_largo=getc(archivo);
        bmp_largo= bmp_largo + 0x100 * (getc(archivo));
        (void) getc(archivo);  //omitir 2 bytes
        (void) getc(archivo);
        bmp_ancho=getc(archivo);
        bmp_ancho=bmp_ancho + 0x100 *(getc(archivo));
        (void) getc(archivo);
        (void) getc(archivo);
        for (n=0;n<28;n++) //omitir 28 bytes
            {
            (void) getc(archivo);
            }
        for (n=0;n<64;n++) //omitir 64 bytes de paleta
            {
            (void) getc(archivo);
            }
        for (m=bmp_ancho-1;m>=0;m--)
            {
            for (n=0;n<(bmp_largo/2);n++)
                {
                dato=getc(archivo);
                a=dato & 0xf0;
                a=dato>>4;  //11110000
                b=dato &0x0f;  //00001111
                switch (a)
                    {
                    case 0:
                        putpixel(i+n*2,j+m,0);
                        break;
                    case 4:
                        putpixel(i+n*2,j+m,1);
                        break;
                    case 2:
                        putpixel(i+n*2,j+m,2);
                        break;
                    case 6:
                        putpixel(i+n*2,j+m,3);
                        break;
                    case 1:
                        putpixel(i+n*2,j+m,4);
                        break;
                    case 5:
                        putpixel(i+n*2,j+m,5);
                        break;
                    case 3:
                        putpixel(i+n*2,j+m,6);
                        break;
                    case 7:
                        putpixel(i+n*2,j+m,7);
                        break;
                    case 8:
                        putpixel(i+n*2,j+m,8);
                        break;
                    case 12:
                        putpixel(i+n*2,j+m,9);
                        break;
                    case 10:
                        putpixel(i+n*2,j+m,10);
                        break;
                    case 14:
                        putpixel(i+n*2,j+m,11);
                        break;
                    case 9:
                        putpixel(i+n*2,j+m,12);
                        break;
                    case 13:
                        putpixel(i+n*2,j+m,13);
                        break;
                    case 11:
                        putpixel(i+n*2,j+m,14);
                        break;
                    case 15:
                        putpixel(i+n*2,j+m,15);
                        break;
                    }
                switch (b)
                    {
                    case 0:
                        putpixel(i+n*2+1,j+m,0);
                        break;
                    case 4:
                        putpixel(i+n*2+1,j+m,1);
                        break;
                    case 2:
                        putpixel(i+n*2+1,j+m,2);
                        break;
                    case 6:
                        putpixel(i+n*2+1,j+m,3);
                        break;
                    case 1:
                        putpixel(i+n*2+1,j+m,4);
                        break;
                    case 5:
                        putpixel(i+n*2+1,j+m,5);
                        break;
                    case 3:
                        putpixel(i+n*2+1,j+m,6);
                        break;
                    case 7:
                        putpixel(i+n*2+1,j+m,7);
                        break;
                    case 8:
                        putpixel(i+n*2+1,j+m,8);
                        break;
                    case 12:
                        putpixel(i+n*2+1,j+m,9);
                        break;
                    case 10:
                        putpixel(i+n*2+1,j+m,10);
                        break;
                    case 14:
                        putpixel(i+n*2+1,j+m,11);
                        break;
                    case 9:
                        putpixel(i+n*2+1,j+m,12);
                        break;
                    case 13:
                        putpixel(i+n*2+1,j+m,13);
                        break;
                    case 11:
                        putpixel(i+n*2+1,j+m,14);
                        break;
                    case 15:
                        putpixel(i+n*2+1,j+m,15);
                        break;
                    }
                }
            }
        if (fclose(archivo)!=0)
            {
            printf( "Problemas al cerrar el archivo BMP\r\n" );
            }
        }
    }*/


/**
* Dibuja una imagen BMP de 24 bits 8B 8G 8R
* @param i,j: posici¢n x,y de la imagen
* @param nombrearchivo: nombre del archivo BMP
* @return no retorna.
* @remarks la imagenes deben ser multiplo de 4 en X debido a problemas con el formato BMP
**/
void bmp24(int i, int j, char *nombrearchivo)  //ejemplo: bmp24(0,0,"Dibujo.bmp");
    {
    FILE *archivo;
    int n,m,bmp_largo,bmp_ancho;
    unsigned char datoR,datoG,datoB;
    archivo = fopen(nombrearchivo,"rb");
    if (archivo!=NULL)
        {
        for (n=0;n<18;n++) //omitir 18 bytes
            {
            (void) getc(archivo);
            }
//los siguientes 4 bytes son el largo de la imagen siendo:
//  LSB               MSB        en este orden
// 0-255 0-255 0-255 0-255
//como el orden esta invertido uso esta forma de leer los primeros 16 bits (2 bytes), del tamano.
        bmp_largo=getc(archivo);
        bmp_largo= bmp_largo + 0x100 * (getc(archivo));
        (void) getc(archivo);  //omitir 2 bytes
        (void) getc(archivo);
        bmp_ancho=getc(archivo);
        bmp_ancho=bmp_ancho + 0x100 *(getc(archivo));
        (void) getc(archivo);
        (void) getc(archivo);
        for (n=0;n<28;n++) //omitir 28 bytes
            {
            (void) getc(archivo);
            }
        //colores en formato BGR
        glBegin(GL_POINTS);
        for (m=bmp_ancho-1;m>=0;m--)
            {
            for (n=0;n<bmp_largo;n++)
                {
                datoB=getc(archivo);
                datoG=getc(archivo);
                datoR=getc(archivo);
                glColor3ub(datoR, datoG, datoB);
                glVertex2f(i+n, j+m);
                }
            }
        glEnd();
        if (fclose(archivo)!=0)
            {
            printf( "Problemas al cerrar el archivo BMP\r\n" );
            }
        }
    }



#endif

