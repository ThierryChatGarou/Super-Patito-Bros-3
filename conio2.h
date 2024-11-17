/*
 cgets  OK           clreol OK2         clrscr OK2          cprintf OK
 cputs  OK           cscanf OK           delline OK2         getch  OK
 getche OK           getpass OK          gettext OK            gettextinfo OK2
 gotoxy  OK2       highvideo OK         insline OK2         inp X
 inport  X          inportb  X         inpw  X              kbhit  OK
 lowvideo OK         movetext OK       normvideo OK           outp  X
 outport X          outportb X         outpw  X             putch  OK
 puttext OK          _setcursortype OK   textattr OK       textbackground OK2
 textcolor OK      textmode  OK      ungetch  OK          wherex  OK
 wherey OK         window OK

Constants, data types, and global variables

 BLINK               COLORS          directvideo     _NOCURSOR OK
 _NORMALCURSOR OK   _SOLIDCURSOR OK  text_info       text_modes
 _wscroll

*/

///////////////////////////////BORLAND conio.h code adapted by Thierry
/*  conio.h

    Direct MSDOS console input/output.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef _CONIO2_H
#define _CONIO2_H

#define _NOCURSOR      0
#define _SOLIDCURSOR   1
#define _NORMALCURSOR  2

struct text_info {
   unsigned char winleft;        //left window coordinate
   unsigned char wintop;         //top window coordinate
   unsigned char winright;       //right window coordinate
   unsigned char winbottom;      //bottom window coordinate
   unsigned char attribute;      //text attribute
   unsigned char normattr;       //normal attribute
   unsigned char currmode;       //current video mode BW40, BW80, C40, C80, or C4350
   unsigned char screenheight;   //text screen's height
   unsigned char screenwidth;    //text screen's width
   unsigned char curx;           //x-coordinate in current window
   unsigned char cury;           //y-coordinate in current window
};

enum text_modes { LASTMODE=-1, BW40=0, C40, BW80, C80, MONO=7, C4350=64 };
//LASTMODE -1    //previous text mode
//BW40      0    //Black and white     40 columns
//C40       1    //Color               40 columns
//BW80      2    //Black and white     80 columns
//C80       3    //Color               80 columns
//MONO      7    //Monochrome          80 columns
//C4350    64    //EGA 43 lines or VGA 50 lines


enum COLORS {
    BLACK,          /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

#define BLINK       128 /* blink bit */

extern   int directvideo;
extern   int _wscroll;

#ifdef __cplusplus
extern "C" {
#endif

void         clreol( void );
void         clrscr( void );
void         gotoxy( int x, int y );
int          wherex( void );
int          wherey( void );
int          getch( void );
int          getche( void );
int          kbhit( void );
int          putch( int __c );

#ifndef _PORT_DEFS
int          inp( unsigned __portid );
unsigned     inpw( unsigned __portid );
int          outp( unsigned __portid, int __value );
unsigned     outpw( unsigned __portid, unsigned __value );
unsigned char  inportb( int __portid );
void         outportb( int __portid, unsigned char __value );
#endif  /* !_PORT_DEFS */

int          inport( int __portid );
void         outport( int __portid, int __value );

void         delline( void );
int          _gettext( int __left, int __top,
                            int __right, int __bottom,
                            void *__destin);
int          puttext( int __left, int __top,
                            int __right, int __bottom,
                            void *__source );
void         gettextinfo (struct text_info *__r );
void         highvideo( void );
void         normvideo( void );
void         lowvideo( void );
void         insline( void );
int          movetext( int __left, int __top,
                             int __right, int __bottom,
                             int __destleft, int __desttop );
void         textattr(int newattr);
void         textbackground(int color);
void         textcolor(int color);
void         textmode(int newmode );
void         window( int __left, int __top, int __right, int __bottom);

void         _setcursortype( int __cur_t );
char *  cgets( char *__str );
int          cprintf( const char *__format, ... );
int          cputs( const char *__str );
int          cscanf( const char *__format, ... );
char *  getpass( const char *__prompt );
int          ungetch( int __ch );

#ifndef _PORT_DEFS
#define _PORT_DEFS

    /* These are in-line functions.  These prototypes just clean up
       some syntax checks and code generation.
     */
unsigned char     __inportb__( int __portid );
unsigned int      __inportw__( int __portid );
void              __outportb__( int __portid, unsigned char __value );
void              __outportw__( int __portid, unsigned int __value );

#define inportb         __inportb__
#define inportw         __inportw__
#define outportb        __outportb__
#define outportw        __outportw__

#define inp( portid )      __inportb__( portid )
#define outp( portid,v )  (__outportb__( portid,v ), (int)_AL)
#define inpw( portid )     __inportw__( portid )
#define outpw( portid,v ) (__outportw__( portid,v ), (unsigned)_AX)

#endif  /* _PORT_DEFS */

#ifdef __cplusplus
}
#endif

//non borland
void gotox(int x);
void gotoy(int y);
int align(int align,const char *str);
void         gotoxy( int x, int y );

//non borland linux
void cursor_savepos(void);
void cursor_restorepos(void);

#endif
