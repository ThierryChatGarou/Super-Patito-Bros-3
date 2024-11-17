#define GRAPHICS  //comentar para desabilitar graficos
#define SINGLE_GLBUFFER

#ifdef __linux__  //no usar graficos en linux
#undef GRAPHICS
#endif

#ifdef GRAPHICS
#include <gl/gl.h>
#include<windows.h>
#endif

#define MIWICOLUMN 0
#define INPUTCOLUMN 4
#define OUTPUTCOLUMN 22

#define MAXCOLORS 16

typedef struct palettetype {
  unsigned char  size;
  signed   char  colors[MAXCOLORS+1];
};


int init_opengl_windows();
void destroy_opengl_windows(void);
void render_opengl_windows(void);
#ifdef GRAPHICS
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);
void create_scene();
void frameStarted(void);
void mouse_getcoordinates(void);

int detectgraph(int *gdriver, int *gmode);
int graphresult();
char *grapherrormsg(int errorcode);
int initgraph(int *gdriver, int *gmode, char *a);
int closegraph();
#define grOk 0
#define DETECT 0

void bmp24(int i, int j, char *nombrearchivo);  //ejemplo: bmp24(0,0,"Dibujo.bmp");
//void bmp16(int i, int j, char *nombrearchivo);  //ejemplo: bmp16(0,0,"Dibujo.bmp");
inline void GLpoint(short x, short y, unsigned short radius, unsigned char r, unsigned char g, unsigned char b);
inline void GLcircle(short x, short y, unsigned short radius, unsigned char r, unsigned char g, unsigned char b);
inline void bar(short x, short y, short x2, short y2);
inline void setfillstyle(unsigned char style, unsigned char color);
inline void GLbar(short x, short y, short x2, short y2, unsigned char r, unsigned char g, unsigned char b);
inline void GLrectangle(short x, short y, short x2, short y2, unsigned char r, unsigned char g, unsigned char b);
inline void GLline(short x, short y, short x2, short y2, unsigned char r, unsigned char g, unsigned char b);
inline void putpixel(short x, short y, unsigned char color);
inline void GLpixel(short x, short y, unsigned char r, unsigned char g, unsigned char b);

void setcolor(int a);
getpalette(struct palettetype *p);
setrgbpalette(int a, int b, int c, int d);
void line(int a, int b, int x, int y);



#endif


