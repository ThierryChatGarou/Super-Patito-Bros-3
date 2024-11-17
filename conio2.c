/*
Autores:
Salvador Pozo Coronado <salvador@conclase.net>
Arthur Christopher Watkins
Hongli Lai <hongli@telekabel.nl>
tkorrovi <tkorrovi@altavista.net> on 2002/02/26.
Andrew Westcott <ajwestco@users.sourceforge.net>
Michal Molhanec <michal@molhanec.net>

                    GNU GENERAL PUBLIC LICENSE
                     Version 3, 29 June 2007

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
*/



#ifndef __CONIO2_H__
#define __CONIO2_H__

#ifdef __WIN32__
#include <windows.h>
//#include "conio.h"
#include <stdio.h>
#include "conio2.h"
#else
#include <stdio.h>
#include "conio2.h"
#include <ncurses.h>
#endif

#define gettext _gettext

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

//variable global
static struct text_info __text_info = {
    1, 1,                      //winleft,wintop
    80, 25,                    //winright,winbottom
    LIGHTGRAY + (BLACK << 4),  //attribute
    LIGHTGRAY + (BLACK << 4),  //normattr
    C80,                       //currmode
    25, 80,                    //screenheight,screenwidth
    1, 1                       //x-coordinate, y-coordinate
    };

static int __CONIO_TOP = 0;
static int __CONIO_LEFT = 0;


static void __fill_text_info(void)
    {
#ifdef __WIN32__
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
    __CONIO_LEFT = csbiInfo.srWindow.Left;
    __CONIO_TOP = csbiInfo.srWindow.Top;
    __text_info.curx = csbiInfo.dwCursorPosition.X - __CONIO_LEFT + 1;
    __text_info.cury = csbiInfo.dwCursorPosition.Y - __CONIO_TOP  + 1;
    __text_info.attribute = csbiInfo.wAttributes;
    __text_info.screenwidth  = csbiInfo.srWindow.Right - csbiInfo.srWindow.Left + 1;
    __text_info.screenheight = csbiInfo.srWindow.Bottom - csbiInfo.srWindow.Top + 1;
#else
    __text_info.attribute = __FOREGROUND + (__BACKGROUND << 4);
#warning funcion __fill_text_info incompleta
#endif
    }

#ifdef __WIN32__




/** <pre><code>
 ▄▄▄▄▄▄▄▄
 ▌clreol▐                           <CONIO.H>
 ▀▀▀▀▀▀▀▀
 Clears to end of line in text window

 Declaration:  void clreol(void);

 Remarks:
clreol clears all characters from the cursor position to the end of the line
within the current text window, without moving the cursor.

 Return Value:  None

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  clrscr    delline   window

 Example:

 #include <conio.h>

 int main(void)
 {
    clrscr();
    cprintf("The function CLREOL clears all characters from the\r\n");
    cprintf("cursor position to the end of the line within the\r\n");
    cprintf("current text window, without moving the cursor.\r\n");
    cprintf("Press any key to continue . . .");
    gotoxy(14, 4);
    getch();

    clreol();
    getch();

    return 0;
 }
</code></pre> **/
void clreol (void)
    {
    COORD coord;
    DWORD written;

    __fill_text_info();
    coord.X = __CONIO_LEFT + __text_info.curx - 1;
    coord.Y = __CONIO_TOP  + __text_info.cury - 1;

    FillConsoleOutputAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                                __FOREGROUND + (__BACKGROUND << 4),
                                __text_info.screenwidth - __text_info.curx + 1, coord, &written);
    FillConsoleOutputCharacter (GetStdHandle (STD_OUTPUT_HANDLE),
                                ' ', __text_info.screenwidth - __text_info.curx + 1, coord, &written);
    gotoxy (__text_info.curx, __text_info.cury);
    }




/** <pre><code>
 ▄▄▄▄▄▄▄▄
 ▌clrscr▐                           <CONIO.H>
 ▀▀▀▀▀▀▀▀
 Clears text mode window

 Declaration:  void clrscr(void);

 Remarks:
clrscr clears the current text window and places the cursor in the upper
left-hand corner (at position 1,1).

 Return Value:  None

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  clreol    delline   window

 Example:

 #include <conio.h>

 int main(void)
 {
    int i;

    clrscr();
    for (i = 0; i < 20; i++)
       cprintf("%d\r\n", i);
    cprintf("\r\nPress any key to clear screen");
    getch();

    clrscr();
    cprintf("The screen has been cleared!");
    getch();

    return 0;
 }
</code></pre> **/
void clrscr()
    {
    COORD pos;
    COORD cs = { 0, 0 };
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    pos.X = 0;
    pos.Y = 0;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbiInfo);
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),' ',csbiInfo.dwSize.X*csbiInfo.dwSize.Y,cs,&written);
    gotoxy(1,1);
    }

/*  //original, aunque no se la diferencia entre los dos
void clrscr (void)
    {
    DWORD written;
    int i;

    __fill_text_info();
    for (i = __CONIO_TOP; i < __CONIO_TOP + __text_info.screenheight; i++)
    {
        FillConsoleOutputAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
__FOREGROUND + (__BACKGROUND << 4), __text_info.screenwidth,
        (COORD) {__CONIO_LEFT, i},&written);
        FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
         __text_info.screenwidth,(COORD) {__CONIO_LEFT, i},&written);
        }
    gotoxy (1, 1);
    }
*/




/** <pre><code>
 ▄▄▄▄▄▄▄▄
 ▌gotoxy▐                           <CONIO.H>
 ▀▀▀▀▀▀▀▀
 Positions cursor in text window

 Declaration:  void gotoxy(int x, int y);

 Remarks:
gotoxy moves the cursor to the given position in the current text window.

If the coordinates are invalid, the call to gotoxy is ignored.

Example of invalid coordinates:
  gotoxy(40,30);  // (35,25) = window's bottom right position

 Return Value:  None

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  wherex/wherey   window

 Example:

 #include <conio.h>

 int main(void)
 {
    clrscr();
    gotoxy(35, 12);
    cprintf("Hello world");
    getch();
    return 0;
 }

</code></pre>
@remarks gotoxy(1,1); is the top left corner of the console
**/
void gotoxy(int x, int y)
    {
    COORD c;
    __fill_text_info();
    if (x < 1 || x > __text_info.screenwidth ||
            y < 1 || y > __text_info.screenheight) return;

    c.X = __CONIO_LEFT + x - 1;
    c.Y = __CONIO_TOP  + y - 1;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
    }




///@{
/** <pre><code>
 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
 ▌wherex, wherey▐                   <CONIO.H>
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
  ■ wherex gives current horizontal cursor position
  ■ wherey gives current vertical cursor position

 Declaration:
  ■ int wherex(void);
  ■ int wherey(void);

 Remarks:
■ wherex returns the x-coordinate of the current cursor position (within the
current text window).

■ wherey returns the y-coordinate of the current cursor position (within the
current text window).

 Return Value:
  ■ wherex returns an integer in the range 1 to 80.
  ■ wherey returns an integer in the range 1 to 25,
    1 to 43, or 1 to 50.

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  gettextinfo   gotoxy

 Example:

 #include <conio.h>

 int main(void)
 {
    clrscr();
    gotoxy(10,10);
    cprintf("Current location is X: %d  Y: %d\r\n", wherex(), wherey());
    getch();

    return 0;
 }
</code></pre> **/
int wherex(void)
    {
    __fill_text_info();
    return __text_info.curx;
    }
int wherey (void)
    {
    __fill_text_info();
    return __text_info.cury;
    }
///@}




///@{
/** <pre><code>
 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
 ▌getch and getche▐                 <CONIO.H>
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
  ■ getch gets a character from console but does not echo to the screen
  ■ getche gets a character from console, and echoes to the screen

 Declaration:
  ■ int getch(void);
  ■ int getche(void);

 Remarks:
getch reads a single character directly from the keyboard, without echoing
to the screen.

getche reads a single character from the keyboard and echoes it to the
current text window, using direct video or BIOS.

 Return Value:
Both functions return the character read from the keyboard.

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  cgets     cscanf    fgetc     getc      getchar   getpass   kbhit
  putch     ungetch

 getch Example:
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

#include <conio.h>
#include <stdio.h>

int main(void)
    {
  int c;
  int extended = 0;
  c = getch();
  if (!c)
    extended = getch();
  if (extended)
    printf("The character is extended\n");
  else
    printf("The character isn't extended\n");

  return 0;
    }

 getche example:
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

#include <stdio.h>
#include <conio.h>

int main(void)
    {
   char ch;

   printf("Input a character:");
   ch = getche();
   printf("\nYou input a '%c'\n", ch);
   return 0;
    }
</code></pre> **/
int getch(void)
    {
    int car;
    DWORD leidos, modo;

    GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &modo);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo & !ENABLE_ECHO_INPUT & !ENABLE_PROCESSED_INPUT);
    ReadConsole(GetStdHandle(STD_INPUT_HANDLE), &car, 1, &leidos, NULL);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo);
    return car;
    }
int getche(void)
    {
    int car;
    DWORD leidos, modo;

    GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &modo);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo & !ENABLE_ECHO_INPUT & !ENABLE_PROCESSED_INPUT);
    ReadConsole(GetStdHandle(STD_INPUT_HANDLE), &car, 1, &leidos, NULL);
    putch(car);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo);
    return car;
    }
///@}




/** <pre><code>
 ▄▄▄▄▄▄▄
 ▌kbhit▐                            <CONIO.H>
 ▀▀▀▀▀▀▀
 Checks for currently available keystrokes

 Declaration:  int kbhit(void);

 Remarks:
kbhit checks to see if a keystroke is currently available.

Any available keystrokes can be retrieved with getch or getche.

 Return Value:
  ■ On success (if a keystroke is available),
    returns a non-zero integer
  ■ If a keystroke is not available, returns 0.

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 Example:

 #include <conio.h>

 int main(void)
 {
    cprintf("Press any key to continue:");
    while (!kbhit());  //do nothing
    cprintf("\r\nA key was pressed...\r\n");
    return 0;
 }
</code></pre> **/
int kbhit(void)
    {
    DWORD nEventos;
    INPUT_RECORD *eventos;
    DWORD leidos;
    int retval = 0;
    int i;

    GetNumberOfConsoleInputEvents(GetStdHandle(STD_INPUT_HANDLE),
                                  &nEventos);
    // eventos = new INPUT_RECORD[nEventos];
    eventos = (INPUT_RECORD *)malloc(nEventos*sizeof(INPUT_RECORD));
    PeekConsoleInput(GetStdHandle(STD_INPUT_HANDLE),
                     eventos, nEventos, &leidos);
    for (i = 0; !retval && i < nEventos; i++)
        if (eventos[i].EventType == KEY_EVENT) retval = 1;
    // delete[] eventos;
    free( eventos );
    return retval;
    }




/** <pre><code>
 ▄▄▄▄▄▄▄
 ▌putch▐                            <CONIO.H>
 ▀▀▀▀▀▀▀
 Oututs character to the text window on the screen

 Declaration:  int putch(int ch);

 Remarks:
putch outputs the character c to the current text window. It is a text-mode
function that performs direct video output to the console.

putch does not translate linefeed characters (\n) into
carriage-return/linefeed pairs.

The string is written either directly to screen memory or by way of a BIOS
call, depending on the value of directvideo.

 Return Value
  ■ On success, putch returns the character printed, c.
  ■ On error, it returns EOF.

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │  Yes │   Yes  │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  cprintf   cputs     getch     getche    putc      putchar

 Example:

 #include <stdio.h>
 #include <conio.h>

 int main(void)
 {
    char ch = 0;

    printf("Input a string:");
    while ((ch != '\r'))
    {
       ch = getch();
       putch(ch);
    }
    return 0;
 }
</code></pre> **/
int putch(int c)
    {
    DWORD escritos;
    __fill_text_info();
    gotoxy(__text_info.curx, __text_info.cury);
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), (char*)&c, 1, &escritos,NULL);
    __text_info.curx++;
    if (__text_info.curx > __text_info.screenwidth) {
        __text_info.curx -= __text_info.screenwidth;
        __text_info.cury++;
        if (__text_info.cury > __text_info.screenheight) {
            __text_info.cury--;
            movetext(1, 2, __text_info.screenwidth, __text_info.screenheight, 1, 1);
            }
        }
    return 0;
    }

/*
Cannot be implemented on windows
int          inp( unsigned __portid );
unsigned     inpw( unsigned __portid );
int          outp( unsigned __portid, int __value );
unsigned     outpw( unsigned __portid, unsigned __value );
unsigned char  inportb( int __portid );
void         outportb( int __portid, unsigned char __value );
int          inport( int __portid );
void         outport( int __portid, int __value );
*/




/** <pre><code>
 ▄▄▄▄▄▄▄▄▄
 ▌delline▐                          <CONIO.H>
 ▀▀▀▀▀▀▀▀▀
 (Text mode): Deletes line in text window

 Declaration:  void delline(void);

 Remarks:
delline deletes the line containing the cursor and moves all lines below it
one line up.

delline operates within the currently active text window.

 Return Value:  None

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  clreol    clrscr    insline   window

 Example:

 #include <conio.h>

 int main(void)
 {
    clrscr();
    cprintf("The function DELLINE deletes the line containing the\r\n");
    cprintf("cursor and moves all lines below it one line up.\r\n");
    cprintf("DELLINE operates within the currently active text\r\n");
    cprintf("window.  Press any key to continue . . .");
    gotoxy(1,2);  //  Move the cursor to the second line and first column
    getch();

    delline();
    getch();

    return 0;
 }
</code></pre> **/
void delline (void)
    {
    COORD coord;
    SMALL_RECT rect;
    CHAR_INFO fillchar;

    __fill_text_info();
    coord.X = __CONIO_LEFT;
    coord.Y = __CONIO_TOP + __text_info.cury - 1;
    rect.Left = __CONIO_LEFT;
    rect.Top = __CONIO_TOP + __text_info.cury;
    rect.Right = __CONIO_LEFT + __text_info.screenwidth - 1;
    rect.Bottom = __CONIO_TOP + __text_info.screenheight - 1;
    fillchar.Attributes = __FOREGROUND + (__BACKGROUND << 4);
#ifdef UNICODE
    fillchar.Char.UnicodeChar = L' ';
    ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE),
                                &rect, NULL, coord, &fillchar);
#else
    fillchar.Char.AsciiChar = ' ';
    ScrollConsoleScreenBufferA (GetStdHandle (STD_OUTPUT_HANDLE),
                                &rect, NULL, coord, &fillchar);
#endif
    gotoxy (__text_info.curx, __text_info.cury);
    }




///@{
/** <pre><code>
 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
 ▌gettext, puttext▐                 <CONIO.H>
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
  ■ gettext copies text from text-mode screen to memory
  ■ puttext copies text from memory to text-mode screen

 Declaration:
  ■ int gettext(int left, int top, int right, int bottom, void*destin);
  ■ int puttext(int left, int top, int right, int bottom, void*source);

 Remarks:
■ gettext stores the contents of an onscreen text rectangle defined by
(left, top) and (right, bottom) into the area of memory *destin.

■ puttext writes the contents of the memory area *source out to the onscreen
rectangle defined by (left, top) and (right, bottom). puttext is a text-mode
function performing direct video output.

gettext reads the rectangle's contents into memory (and puttext puts the
stored contents into the rectangle) SEQUENTIALLY from left to right and top
to bottom.

All coordinates are absolute screen coordinates, not window-relative. The
upper left corner is (1,1).

Each position onscreen takes 2 bytes of memory.
 ■ The first byte is the character in the cell.
 ■ The second byte is the cell's video attribute.

The space required for a rectangle w columns wide by h rows high is

   bytes = (h rows) x (w columns) x 2

 Return Value:
  ■ On success,
     ■ gettext returns 1
     ■ puttext returns a non-zero value
  ■ On error, both functions return 0 (for
    example, if you gave coordinates outside
    the range of the current screen mode)

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  movetext   window

Examples:
 gettext example:
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

#include <conio.h>

char buffer[4096];

int main(void)
    {
   int i;

   clrscr();
   for (i = 0; i <= 20; i++)
      cprintf("Line #%d\r\n", i);
   gettext(1, 1, 80, 25, buffer);

   gotoxy(1, 25);
   cprintf("Press any key to clear screen...");
   getch();
   clrscr();
   gotoxy(1, 25);
   cprintf("Press any key to restore screen...");
   getch();
   puttext(1, 1, 80, 25, buffer);
   gotoxy(1, 25);
   cprintf("Press any key to quit...");
   getch();

   return 0;
    }


 puttext example:
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

#include <conio.h>

int main(void)
    {
   char buffer[512];

   //  put some text to the console
   clrscr();
   gotoxy(20, 12);
   cprintf("This is a test.  Press any key to continue ...");
   getch();

   //  grab screen contents
   gettext(20, 12, 36, 21,buffer);
   clrscr();

   //  put selected characters back to the screen
   gotoxy(20, 12);
   puttext(20, 12, 36, 21, buffer);
   getch();

   return 0;
    }
</code></pre> **/
int _gettext(int left, int top, int right, int bottom, void *destin)
    {
    PCHAR_INFO buffer;
    char *pantalla = (char *)destin;
    int retval,i;
    __fill_text_info();

    COORD cSize = {1+right-left, 1+bottom-top};
    COORD cDest = {0,0};
    SMALL_RECT rect = {__text_info.winleft+left-1, __text_info.wintop+top-1,
                       __text_info.winleft+right-1, __text_info.wintop+bottom-1
                      };
    // buffer = new CHAR_INFO[cSize.X * cSize.Y];
    buffer = (PCHAR_INFO)malloc(cSize.X*cSize.Y*sizeof(CHAR_INFO));

    retval = ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),
                               buffer, cSize, cDest, &rect);
    for ( i = 0; i < cSize.X * cSize.Y; i++)
        {
        pantalla[2*i] = buffer[i].Char.AsciiChar;
        pantalla[2*i + 1] = buffer[i].Attributes & 0xff;
        }
    // delete[] buffer;
    free( buffer );
    return retval;
    }

int puttext(int left, int top, int right, int bottom, void *source)
    {
    PCHAR_INFO buffer;
    char *pantalla = (char *)source;
    int retval,i;
    __fill_text_info();

    COORD cSize = {1+right-left, 1+bottom-top};
    COORD cDest = {0,0};
    SMALL_RECT rect = {__text_info.winleft+left-1, __text_info.wintop+top-1,
                       __text_info.winleft+right-1, __text_info.wintop+bottom-1
                      };
    // buffer = new CHAR_INFO[cSize.X * cSize.Y];
    buffer = (PCHAR_INFO)malloc(sizeof(CHAR_INFO)*cSize.X * cSize.Y);

    for ( i = 0; i < cSize.X * cSize.Y; i++) {
        buffer[i].Char.AsciiChar = pantalla[2*i];
        buffer[i].Attributes = (WORD)pantalla[2*i + 1];
        }

    retval = WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),
                                buffer, cSize, cDest, &rect);
    // delete[] buffer;
    free(buffer);
    return retval;
    }
///@}




/** <pre><code>
 ▄▄▄▄▄▄▄▄▄▄▄▄▄
 ▌gettextinfo▐                      <CONIO.H>
 ▀▀▀▀▀▀▀▀▀▀▀▀▀
 Gets text-mode video information

 Declaration:  void gettextinfo(struct text_info *r);

 Remarks:
gettextinfo fills in a structure with the current text video information.

 Arg│ What It Is/Does
 ═══╪════════════════════════════════════════
  r │ Points to the text_info structure that
    │ gettextinfo fills in

 Return Value:
gettextinfo does not return. The results are returned in the structure *r.

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  textattr         textbackground   textcolor        textmode
  wherex           wherey           window

 Example:

 #include <conio.h>

 int main(void)
 {
    struct text_info ti;
    gettextinfo(&ti);
    cprintf("window left      %2d\r\n",ti.winleft);
    cprintf("window top       %2d\r\n",ti.wintop);
    cprintf("window right     %2d\r\n",ti.winright);
    cprintf("window bottom    %2d\r\n",ti.winbottom);
    cprintf("attribute        %2d\r\n",ti.attribute);
    cprintf("normal attribute %2d\r\n",ti.normattr);
    cprintf("current mode     %2d\r\n",ti.currmode);
    cprintf("screen height    %2d\r\n",ti.screenheight);
    cprintf("screen width     %2d\r\n",ti.screenwidth);
    cprintf("current x        %2d\r\n",ti.curx);
    cprintf("current y        %2d\r\n",ti.cury);
    return 0;
 }
</code></pre> **/
void gettextinfo (struct text_info * info)
    {
    __fill_text_info();
    *info = __text_info;
    }




///@{
/** <pre><code>
 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
 ▌highvideo, lowvideo, normvideo▐   <CONIO.H>
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
  ■ highvideo selects high-intensity text characters
  ■ lowvideo selects low-intensity text characters
  ■ normvideo selects normal-intensity text characters

 Declaration:
  ■ void highvideo(void);
  ■ void lowvideo(void);
  ■ void normvideo(void);

 Remarks:
■ highvideo selects high-intensity characters by setting the high-intensity
bit of the currently selected foreground color.

■ lowvideo selects low-intensity characters by clearing the high-intensity
bit of the currently selected foreground color.

■ normvideo selects normal characters by returning the text attribute
(foreground and background) to the value it had when the program started.

These functions do not affect any characters currently on the screen.

They only affect characters displayed by functions that perform text-mode,
direct console output AFTER these ...video functions are called (such as
cprintf).

 Return Value:  None

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  cprintf       cputs         gettextinfo   textattr      textcolor

 Example (for all three functions):

 #include <conio.h>

 int main(void)
 {
    normvideo();
    cprintf("NORMAL Intensity Text\r\n");
    return 0;
 }
</code></pre> **/
void highvideo (void)
    {
    if (__FOREGROUND < DARKGRAY) textcolor(__FOREGROUND + 8);
    }
void lowvideo (void)
    {
    if (__FOREGROUND > LIGHTGRAY) textcolor(__FOREGROUND - 8);
    }
void normvideo (void)
    {
    textattr (__text_info.normattr);
    }
///@}




/** <pre><code>
 ▄▄▄▄▄▄▄▄▄
 ▌insline▐                          <CONIO.H>
 ▀▀▀▀▀▀▀▀▀
 (Text mode): Inserts blank line in text window at cursor position

 Declaration:  void insline(void);

 Remarks:
insline inserts an empty line in the text window at the cursor position
using the current text background color.

All lines below the empty one move down one line, and the bottom line
scrolls off the bottom of the window.

 Return Value:  None

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  clreol    delline   window

 Example:

 #include <conio.h>

 int main(void)
 {
    clrscr();
    cprintf("INSLINE inserts an empty line in the text window\r\n");
    cprintf("at the cursor position using the current text\r\n");
    cprintf("background color.  All lines below the empty one\r\n");
    cprintf("move down one line and the bottom line scrolls\r\n");
    cprintf("off the bottom of the window.\r\n");
    cprintf("\r\nPress any key to continue:");
    gotoxy(1, 3);
    getch();
    insline();
    getch();
    return 0;
 }
</code></pre> **/
void insline (void)
    {
    COORD coord;
    SMALL_RECT rect;
    CHAR_INFO fillchar;

    __fill_text_info();
    coord.X = __CONIO_LEFT;
    coord.Y = __CONIO_TOP + __text_info.cury;
    rect.Left = __CONIO_LEFT;
    rect.Top = __CONIO_TOP + __text_info.cury - 1;
    rect.Right = __CONIO_LEFT + __text_info.screenwidth - 1;
    rect.Bottom = __CONIO_TOP + __text_info.screenheight - 2;
    fillchar.Attributes = __FOREGROUND + (__BACKGROUND << 4);
#ifdef UNICODE
    fillchar.Char.UnicodeChar = L' ';
    ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE),
                                &rect, NULL, coord, &fillchar);
#else
    fillchar.Char.AsciiChar = ' ';
    ScrollConsoleScreenBufferA (GetStdHandle (STD_OUTPUT_HANDLE),
                                &rect, NULL, coord, &fillchar);
#endif
    gotoxy (__text_info.curx, __text_info.cury);
    }




/** <pre><code>
 ▄▄▄▄▄▄▄▄▄▄
 ▌movetext▐                         <CONIO.H>
 ▀▀▀▀▀▀▀▀▀▀
 Copies text on screen from one rectangle to another

 Declaration:
   int movetext(int left, int top, int right,
     int bottom, int destleft, int desttop);

 Remarks:
movetext copies the contents of the onscreen rectangle defined by left, top,
right, and bottom to a new rectangle of the same dimensions.

The new rectangle's upper left corner is position (destleft, desttop).

All coordinates are absolute screen coordinates. Rectangles that overlap are
moved correctly.

movetext is a text mode function performing direct video output.

 Return Value:
movetext returns non-zero if the operation succeeded.

If the operation failed (for example, if you gave coordinates outside the
range of the current screen mode), movetext returns 0.

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  gettext   puttext

 Example:

 #include <conio.h>
 #include <string.h>

 int main(void)
 {
    char *str = "This is a test string";

    clrscr();
    cputs(str);
    getch();

    movetext(1, 1, strlen(str), 2, 10, 10);
    getch();

    return 0;
 }
</code></pre> **/
int movetext(int left, int top, int right, int bottom, int destleft,
             int desttop)
    {
    COORD coord;
    SMALL_RECT origen;
    CHAR_INFO csbiInfo;

    __fill_text_info();
    origen.Left   = __text_info.winleft+left-1;
    origen.Top    = __text_info.wintop+top-1;
    origen.Right  = __text_info.winleft+right-1;
    origen.Bottom = __text_info.wintop+bottom-1;
    coord.X       = __text_info.winleft+destleft-1;
    coord.Y       = __text_info.wintop+desttop-1;
    csbiInfo.Char.AsciiChar = ' ';
    csbiInfo.Attributes = __text_info.attribute;
    ScrollConsoleScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE),&origen, NULL, coord, &csbiInfo);
    return 0;
    }




///@{
/** <pre><code>
 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
 ▌textattr, textbackground, textcolor▐ <CONIO.H>
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
  ■ textattr sets text attributes for text-window functions
  ■ textbackground selects a new text background color
  ■ textcolor selects a new character color in text mode

 Declaration:
  ■ void textattr(int newattr);
  ■ void textbackground(int newcolor);
  ■ void textcolor(int newcolor);

 Remarks:
These functions work for functions that produce text-mode output directly to
the screen (console output functions).

■ textattr sets both the foreground and background colors in a single call.

(Normally, you set the attributes with textcolor and textbackground.)

■ textbackground selects the background color.

■ textcolor selects the foreground character color.

These functions do not affect any characters currently on the screen. Once
you have called one of these three functions, all subsequent functions using
direct video output (such as cprintf) will use the new attributes or colors.

If you use symbolic color constants, the following limitations apply to the
background colors you select:
  ■ You can only select one of the first eight colors (0--7).
  ■ With textattr, you must shift the selected background color left by
    4 bits to move it into the correct "bbb" bit positions.

■ NOTE: If you use the symbolic color constants, you must include CONIO.H.

 newattr
 ▀▀▀▀▀▀▀
This is how color information is encoded in the newattr argument of
textattr:

   7   6   5   4 ║ 3   2   1   0
 ┌───┬───┬───┬───╫───┬───┬───┬───┐
 │ B │ b │ b │ b ║ f │ f │ f │ f │
 └───┴───┴───┴───╫───┴───┴───┴───┘
                 ║

In this 8-bit newattr parameter,
  ■ ffff = 4-bit foreground color (0 to 15)
  ■ bbb  = 3-bit background color (0 to 7)
  ■ B    = blink-enable bit

 Blinking characters
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
If the blink-enable bit is on, the character blinks. To turn the bit on in a
call to textattr, you add the constant BLINK to the attribute.

To make the characters blink in a call to textcolor, you add 128 to the
foreground color. The predefined constant BLINK exists for this purpose; for
example,

  textcolor(CYAN + BLINK);

 Light colors
 ▀▀▀▀▀▀▀▀▀▀▀▀
Some monitors do not recognize the intensity signal used to create the eight
"light" colors (8-15). On such monitors, the light colors are displayed as
their "dark" equivalents (0-7).

Also, systems that do not display in color can treat these numbers as shades
of one color, special patterns, or special attributes (such as underlined,
bold, italics, etc.).

Exactly what you'll see on such systems depends on your hardware.


 Return Value:  None

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  gettextinfo      highvideo        lowvideo         normvideo


Examples:
 textattr example:
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

#include <conio.h>

int main(void)
    {
   int i;

   clrscr();
   for (i=0; i<9; i++)
   {
       textattr(i + ((i+1) << 4));
       cprintf("This is a test\r\n");
   }

   return 0;
    }

 textbackground and textcolor example:
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

#include <conio.h>

int main(void)
    {
   int i, j;

   clrscr();
   for (i=0; i<9; i++)
   {
       for (j=0; j<80; j++)
          cprintf("C");
       cprintf("\r\n");
       textcolor(i+1);
       textbackground(i);
   }

   return 0;
    } </code></pre>
**/
void textattr (int _attr)
    {
    __FOREGROUND = _attr & 0xF;
    __BACKGROUND = _attr >> 4;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), _attr);
    }
void textbackground (int color)
    {
    __BACKGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             __FOREGROUND + (color << 4));
    }
void textcolor (int color)
    {
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
    }
///@}




/** <pre><code>
 ▄▄▄▄▄▄▄▄▄▄
 ▌textmode▐                         <CONIO.H>
 ▀▀▀▀▀▀▀▀▀▀
 Changes screen mode (in text mode)

 Declaration:  void textmode(int newmode);

 Remarks:
textmode selects a specific text mode.

You can give the text mode (the argument newmode) by using a symbolic
constant from the enumeration type text_modes (defined in CONIO.H).

If you use these constants, you must include CONIO.H.

When textmode is called, the current window is reset to the entire screen,
and the current text attributes are reset to normal, corresponding to a call
to normvideo.

Specifying LASTMODE to textmode causes the most recently selected text mode
to be reselected.

textmode should be used only when the screen is in text mode (presumably to
change to a different text mode).

When the screen is in graphics mode, use restorecrtmode to escape
temporarily to text mode.

 Return Value:  None

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  gettextinfo   window

 Example:

 #include <conio.h>

 int main(void)
 {
    textmode(BW40);
    cprintf("ABC");
    getch();

    textmode(C40);
    cprintf("ABC");
    getch();

    textmode(BW80);
    cprintf("ABC");
    getch();

    textmode(C80);
    cprintf("ABC");
    getch();

    textmode(MONO);
    cprintf("ABC");
    getch();

    return 0;
 }
</code></pre> **/
//Half tested, BW color mode not supported
void textmode(int newmode)
    {
    static unsigned char lastmode = C80,currmode = C80;  //default for no last mode
    SMALL_RECT rect;
    if (newmode == LASTMODE)
        {
        newmode=lastmode;
        }
    lastmode=currmode;
    switch (newmode)
        {
        case BW40:
            rect.Left=0;
            rect.Top=0;
            rect.Right=39;
            rect.Bottom=24;
            currmode=newmode;
            break;
        case C40:
            rect.Left=0;
            rect.Top=0;
            rect.Right=39;
            rect.Bottom=24;
            currmode=newmode;
            break;
        case BW80:
            rect.Left=0;
            rect.Top=0;
            rect.Right=79;
            rect.Bottom=24;
            currmode=newmode;
            break;
        case C80:
            rect.Left=0;
            rect.Top=0;
            rect.Right=79;
            rect.Bottom=24;
            currmode=newmode;
            break;
        case MONO:
            rect.Left=0;
            rect.Top=0;
            rect.Right=79;
            rect.Bottom=24;
            currmode=newmode;
            break;
        case C4350:  //80x50 lineas
            rect.Left=0;
            rect.Top=0;
            rect.Right=79;
            rect.Bottom=49;
            currmode=newmode;
            break;
        default :
            break;
        }
//SetConsoleWindowInfo(  _In_  HANDLE hConsoleOutput,  _In_  BOOL bAbsolute,  _In_  const SMALL_RECT *lpConsoleWindow);
    if (! SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),  TRUE,  &rect))
        {
        printf("GetConsoleScreenBufferInfo (%ld)\n", GetLastError());
        //return 0;
        }
    }




/** <pre><code>
 ▄▄▄▄▄▄▄▄
 ▌window▐                           <CONIO.H>
 ▀▀▀▀▀▀▀▀
 Defines active text-mode window

 Declaration:  void window(int left, int top, int right, int bottom);

The top left corner of the screen is (1,1).

 Remarks:
window defines a text window onscreen. If the coordinates are in any way
invalid, the call to window is ignored.

(left, top) is the (x, y) position of the window's upper left corner.

(right, bottom) is the (x, y) position of the window's lower right corner.

The minimum size of the text window is one column by one line.

The default window is full screen, with these coordinates:
  ■ 80-column mode:  (1, 1, 80, 25)
  ■ 40-column mode:  (1, 1, 40, 25)

 Return Value:  None

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  clreol        clrscr        delline       gettextinfo   gotoxy
  insline       puttext       textmode

 Example:

 #include <conio.h>

 int main(void)
 {

    window(10,10,40,11);
    textcolor(BLACK);
    textbackground(WHITE);
    cprintf("This is a test\r\n");

    return 0;
 }
</code></pre> **/
void window(int left, int top, int right, int bottom)
    {
    __text_info.winleft   = left-1;
    __text_info.wintop    = top-1;
    __text_info.winright  = right-1;
    __text_info.winbottom = bottom-1;
    __text_info.screenheight = 1+bottom-top;
    __text_info.screenwidth  = 1+right-left;
    __text_info.curx = 1;
    __text_info.cury = 1;
    clrscr();
    }




/** <pre><code>
 ▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌
 ▐ _setcursortype ▌                 <CONIO.H>
 ▐▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌

 Selects cursor appearance

 Declaration:  void _setcursortype(int cur_t);

 Remarks:
Sets the cursor type to one of the following:
  ■ _NOCURSOR     (turns off the cursor)
  ■ _SOLIDCURSOR  (solid block cursor)
  ■ _NORMALCURSOR (normal underscore cursor)

 Return Value:  None

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 Example:

  #include <conio.h>

 int main(void)
 {
    //  Display the normal cursor
    cprintf("\n\rNormal Cursor: "); getch();

    //  Turn off the cursor
    _setcursortype(_NOCURSOR);
    cprintf("\n\rNo Cursor    : "); getch();

    //  Switch to a solid cursor
    _setcursortype(_SOLIDCURSOR);
    cprintf("\n\rSolid Cursor : "); getch();

    //  Switch back to the normal cursor
    _setcursortype(_NORMALCURSOR);
    cprintf("\n\rNormal Cursor: "); getch();

    return 0;
 }
</code></pre> **/
void _setcursortype(int ctype)
    {
    CONSOLE_CURSOR_INFO type;
    switch (ctype)
        {
        case _NOCURSOR:
            type.bVisible = 0;
            break;
        case _SOLIDCURSOR:
            type.dwSize = 100;
            type.bVisible = 1;
            break;
        case _NORMALCURSOR:
            type.dwSize = 1;
            type.bVisible = 1;
            break;
        default:
            type.dwSize = 1;
            type.bVisible = 1;
            break;
        }
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&type);
    }




/** <pre><code>
 ▄▄▄▄▄▄▄
 ▌cgets▐                           <CONIO.H>
 ▀▀▀▀▀▀▀
 Reads string from console

 Declaration:  char *cgets(char *str);

 Remarks:
cgets reads a string of characters from the console and stores the string
(and the string length) in the location *str.

Before you call cgets, set str[0] to the maximum length of the string to be
read.

cgets reads characters until it encounters a carriage-return/linefeed
combination (CR/LF), or until the maximum allowable number of characters
have been read.

If cgets reads a CR/LF, it replaces the CR/LF with a \0 (null terminator)
before storing the string.

On return, str[1] is set to the number of characters actually read.

The characters read start at str[2] and end with a null terminator, so str
must be at least (str[0] + 2) bytes long.

 Return Value:
  ■ On success, returns a pointer to str[2].

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  cputs    fgets    getch    getche   gets

 Example:

 #include <stdio.h>
 #include <conio.h>

 int main(void)
 {
    char buffer[83];
    char *p;

    //  There's space for 80 characters plus the NULL terminator
    buffer[0] = 81;

    printf("Input some chars:");
    p = cgets(buffer);
    printf("\ncgets read %d characters: \"%s\"\n", buffer[1], p);
    printf("The returned pointer is %p, buffer[0] is at %p\n", p, &buffer);

    //  Leave room for 5 characters plus the NULL terminator
    buffer[0] = 6;

    printf("Input some chars:");
    p = cgets(buffer);
    printf("\ncgets read %d characters: \"%s\"\n", buffer[1], p);
    printf("The returned pointer is %p, buffer[0] is at %p\n", p, &buffer);
    return 0;
 }
</code></pre> **/
char *cgets(char *str)
    {
    DWORD longitud = 0;
    DWORD leidos, modo;

    GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &modo);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo & !ENABLE_ECHO_INPUT);
    do {
        ReadConsole(GetStdHandle(STD_INPUT_HANDLE), &str[2+longitud], 1,&leidos, NULL);
        if (str[2+longitud] != '\r')
            {
            putch(str[2+longitud++]);
            }
        } while (longitud < str[0] && str[2+longitud] != '\r');
    str[1] = longitud;
    str[2+longitud] = 0;
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo);
    return &str[2];
    }




/** <pre><code>
 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
 ▌...printf functions▐     <CONIO.H, STDIO.H>
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

  ■ cprintf  sends formatted output to the text window on the screen
  ■ fprintf  sends formatted output to a stream
  ■ printf   sends formatted output to stdin
  ■ sprintf  sends formatted output to a string
  ■ vfprintf sends formatted output to a stream, using an argument list
  ■ vprintf  sends formatted output to stdin, using an argument list
  ■ vsprintf sends formatted output to a string, using an argument list

 Declaration:
  ■ int cprintf (              const char *format [, argument, ...]);
  ■ int fprintf (FILE *stream, const char *format [, argument, ...]);
  ■ int printf  (              const char *format [, argument, ...]);
  ■ int sprintf (char *buffer, const char *format [, argument, ...]);
  ■ int vfprintf(FILE *stream, const char *format, va_list arglist);
  ■ int vprintf (              const char *format, va_list arglist);
  ■ int vsprintf(char *buffer, const char *format, va_list arglist);

 Remarks:
All these functions are declared in STDIO.H, except cprintf, which is
declared in CONIO.H.

The ...printf functions do the following:
  ■ Accept a series of arguments
  ■ Apply to each argument a format specifier
    contained in the format string *format
  ■ Output the formatted data (to the screen,
    a stream, stdin, or a string)

These functions apply the first format specifier to the first argument, the
second specifier to the second argument, the third to the third, etc., to
the end of the format.

 ┌────────────────────────────────────────┐
 │                  NOTE                  │
 ├────────────────────────────────────────┤
 │ There must be enough arguments for the │
 │ format.                                │
 │                                        │
 │ If there are not, the results will be  │
 │ unpredictable and likely disastrous.   │
 │                                        │
 │ Excess arguments (more than required   │
 │ by the format) are merely ignored.     │
 └────────────────────────────────────────┘

  Argument│ Functions │ What Argument Is/Does
 ═════════╪═══════════╪══════════════════════
  arglist │ v...printf│ Pointer to a list of
          │           │ arguments
  argument│ cprintf,  │ One of a series of
          │ fprintf,  │ arguments to which
          │ printf,   │ the functions apply
          │ sprintf   │ a format specifier
          │           │ contained in *format
  buffer  │ sprintf,  │ Buffer where function
          │ vsprintf  │ writes the string
  format  │ (all)     │ Format string
  stream  │ fprintf,  │ Stream where the
          │ vfprintf  │ functions output the
          │           │ formatted data


 cprintf
 ▀▀▀▀▀▀▀
With cprintf, the string is written either directly to screen memory or by
way of a BIOS call, depending on the value of directvideo.

cprintf does not translate linefeed characters (\n) into
carriage-return/linefeed character pairs (\r\n).


 The v...printf functions
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
The v...printf functions are known as alternate entry points for the
...printf functions.

They behave exactly like their ...printf counterparts, except they accept a
pointer to a list of arguments (va_list arglist) instead of accepting an
actual list of arguments ([, address, ...]).

■ NOTE: When you use the SS!=DS flag, vprintf assumes that the address being
passed is in the SS segment.

 Return Value:
  ■ On success, the ...printf functions return the number of bytes output
     ■ cprintf returns the number of characters output
     ■ sprintf does not include the terminating null byte in the count
  ■ On error, these functions return EOF

 Portability:
          ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 cprintf  ║ Yes │      │        │          ║
 fprintf  ║ Yes │  Yes │  Yes   │          ║
 printf   ║ Yes │  Yes │  Yes   │          ║
 sprintf  ║ Yes │  Yes │  Yes   │          ║
 vfprintf ║ Yes │  Yes │  Yes   │          ║
 vprintf  ║ Yes │  Yes │  Yes   │          ║
 vsprintf ║ Yes │  Yes │  Yes   │          ║
          ╚═════╧══════╧════════╧══════════╝

 See Also:
  atof       fscanf     getc       getche     putc       putch      va_arg
  va_end     va_start

 More ...printf topics
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
  Format String                  Format Specifiers
  Format Specifier Conventions   Flag Characters
  Input-size Modifiers           Precision Specifiers
  Type Characters                Width Specifiers

 Examples:
 cprintf example
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

#include <conio.h>

int main(void)
    {
   //  clear the screen
   clrscr();

   //  create a text window
   window(10, 10, 80, 25);

   //  output some text in the window
   cprintf("Hello world\r\n");

   //  wait for a key
   getch();
   return 0;
    }
</code></pre> **/
///@bug '\n' is automatically translated to "\r\n" by vfprintf
int cprintf(const char *format, ...)
    {
    va_list p;
    int n;
    va_start(p, format);
    n = vfprintf(stdout, format, p);
    va_end (p);
    return n;
    }




/** <pre><code>
 ▄▄▄▄▄▄▄
 ▌cputs▐                            <CONIO.H>
 ▀▀▀▀▀▀▀
 Writes a string to the text window on the screen

 Declaration:  int cputs(const char *str);

 Remarks:
cputs writes the null-terminated string str to the current text window. It
does not append a newline character.

The string is written either directly to screen memory or by way of a BIOS
call, depending on the value of directvideo.

cputs does not translate linefeed characters (\n) into
carriage-return/linefeed character pairs (\r\n).

 Return Value:
Returns the last character printed.

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │      │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  cgets   fputs   putch   puts

 Example:

 #include <conio.h>

 int main(void)
 {
    //  clear the screen
    clrscr();

    //  create a text window
    window(10, 10, 80, 25);

    //  output some text in the window
    cputs("This is within the window\r\n");

    // wait for a key
    getch();
    return 0;
 }
</code></pre> **/
int cputs(const char *str) // nececita verificación
    {
    DWORD escritos;
    int n = 0;
    int resto;
    __fill_text_info();
    resto = __text_info.screenwidth-__text_info.curx+1;
    do {
        if (strlen(&str[n]) < resto)
            {
            resto = strlen(&str[n]);
            }
        gotoxy(__text_info.curx, __text_info.cury);
        WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), &str[n], resto, &escritos,
                     NULL);
        n+=resto;
        __text_info.curx+=resto;
        if (__text_info.curx > __text_info.screenwidth)
            {
            __text_info.curx -= __text_info.screenwidth;
            resto = __text_info.screenwidth-__text_info.curx+1;
            __text_info.cury++;
            resto = __text_info.screenwidth;
            if (__text_info.cury > __text_info.screenheight)
                {
                __text_info.cury--;
                movetext(1, 2, __text_info.screenwidth, __text_info.screenheight, 1, 1);
                }
            }
        } while (str[n]);
    return strlen(str);
    }




/** <pre><code>
 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
 ▌...scanf functions▐
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
  Function│ Header  │ Scans and formats input from...
 ═════════╪═════════╪═══════════════════════════════════
  cscanf  │ CONIO.H │ The console
  fscanf  │ STDIO.H │ A stream
  scanf   │ STDIO.H │ stdin
  sscanf  │ STDIO.H │ A string
  vfscanf │ STDIO.H │ A stream, using an argument list
  vscanf  │ STDIO.H │ stdin, using an argument list
  vsscanf │ STDIO.H │ A string, using an argument list

 Declaration:
  ■ int cscanf (                          char *format [, address, ...]);
  ■ int fscanf (FILE *stream,       const char *format [, address, ...]);
  ■ int scanf  (                    const char *format [, address, ...]);
  ■ int sscanf (const char *buffer, const char *format [, address, ...]);
  ■ int vfscanf(FILE *stream,       const char *format, va_list arglist);
  ■ int vscanf (                    const char *format, va_list arglist);
  ■ int vsscanf(const char *buffer, const char *format, va_list arglist);

 Remarks:
The ...scanf functions do the following:
  ■ Scan a series of input fields one character at a time
  ■ Format each field according to a corresponding format specifier passed
   in the format string *format.
  ■ Store the formatted input at an address passed as an argument following
   *format (cscanf also echoes the input directly to the screen)

  Argument│ In Function(s) │ What It Is/Does
 ═════════╪════════════════╪═══════════════════════════════════════════════════
  address │ cscanf, fscanf │
          │ scanf, sscanf  │
  arglist │ v...scanf      │ Pointer to a list of arguments
  buffer  │ sscanf, vsscanf│
  format  │ (all)          │ Format string
  stream  │ fscanf,vfscanf │

The v...scanf functions are known as alternate entry points for the ...scanf
functions.

They behave exactly like their ...scanf counterparts, except they accept a
pointer to a list of arguments (va_list arglist) instead of a list of
arguments ([, address, ...]).

There must be one format specifier and address for each input field.

A ...scanf function might stop scanning a particular field before it reaches
the normal end-of-field (whitespace) character, or it might terminate
entirely.

For details about why this might happen, see
When ...scanf Functions Stop Scanning.

■ WARNING: scanf often leads to unexpected results if you diverge from an
expected pattern. You must teach scanf how to synchronize at the end of a
line.

The combination of gets or fgets followed by sscanf is safe and easy, and
therefore recommended over scanf.


 Return Value:
  ■ On success, ...scanf functions return the number of input fields
    successfully scanned, converted, and stored.
    The return value does not include scanned fields that were not stored.
  ■ Return value = 0 if no fields were stored.
  ■ Return value = EOF if
     ■ cscanf, fscanf, scanf, vfscanf, or vscanf attempts to read at
       end-of-file, or
     ■ sscanf or vsscanf attempts to read at end-of-string

 Portability:
         ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 cscanf  ║ Yes │      │        │          ║
 fscanf  ║ Yes │  Yes │  Yes   │          ║
 scanf   ║ Yes │  Yes │  Yes   │          ║
 sscanf  ║ Yes │  Yes │  Yes   │          ║
 vfscanf ║ Yes │  Yes │        │          ║
 vscanf  ║ Yes │  Yes │        │          ║
 vsscanf ║ Yes │  Yes │        │          ║
         ╚═════╧══════╧════════╧══════════╝

 See Also:
  atof       fprintf    getc       getche     printf     va_arg     va_end
  va_start

 More ...scanf Topics
 ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
  Argument-type Modifiers        Assignment Suppression
  Format Specifiers              Format Specifier Conventions
  Format String                  Input Fields
  Pointer-size Modifiers         Type Characters
  Width Specifiers               When ...scanf Functions Stop Scanning

 Examples:
 cscanf example
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

#include <conio.h>

int main(void)
    {
   char string[80];

   //  clear the screen
   clrscr();

   //  Prompt the user for input
   cprintf("Enter a string with no spaces:");

   //  read the input
   cscanf("%s", string);

   //  display what was read
   cprintf("\r\nThe string entered is: %s", string);
   return 0;
    }
</code></pre> **/
//Función no probada
int cscanf(const char *format, ...)
    {
    char *buffer;
    va_list p;
    int n;

    //buffer = new char[260];
    buffer = malloc(sizeof(char)*260);
    buffer[0] = 255;
    cgets(buffer);
    va_start(p, format);
    printf("#%s#%s#\n", &buffer[2], format);
    n = sscanf(&buffer[2], format, p);
    //delete[] buffer;
    free(buffer);
    return n;
    }




/** <pre><code>
 ▄▄▄▄▄▄▄▄▄
 ▌getpass▐                          <CONIO.H>
 ▀▀▀▀▀▀▀▀▀
 Reads a password

 Declaration:  char *getpass(const char *prompt);

 Remarks:
getpass reads a password from the system console, after prompting with the
null-terminated string prompt and disabling the echo.

It returns a pointer to a null-terminated string of up to eight characters
(not counting the null terminator).

 Return Value:
Returns a pointer to a static string that is overwritten with each call.

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │  Yes │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  getch

 Example:

 #include <conio.h>

 int main(void)
 {
    char *password;

    password = getpass("Input a password:");
    cprintf("The password is: %s\r\n", password);
    return 0;
 }
</code></pre> **/
char *getpass(const char *prompt)
    {
    static char pass[9];
    DWORD longitud = 0;
    DWORD leidos, modo;

    cputs(prompt);
    GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &modo);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo & !ENABLE_ECHO_INPUT);
    do {
        ReadConsole(GetStdHandle(STD_INPUT_HANDLE), &pass[longitud], 1, &leidos,
                    NULL);
        if (pass[longitud] != '\r')
            {
            longitud++;
            }
        } while (longitud < 8 && pass[longitud] != '\r');
    pass[longitud] = 0;
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo);
    return pass;
    }




/** <pre><code>
 ▄▄▄▄▄▄▄▄▄
 ▌ungetch▐                          <CONIO.H>
 ▀▀▀▀▀▀▀▀▀
 Pushes a character back to the keyboard

 Declaration:  int ungetch(int ch);

 Remarks:
ungetch pushes the character ch back to the console, causing ch to be the
next character read.

ungetch fails if it is called more than once before the next read.

 Return Value:
  ■ On success, returns the character ch.
  ■ On error, returns EOF.

 Portability:
 ╔ DOS ╤ UNIX ╤ ANSI C ╤ C++ Only ╗
 ║ Yes │  Yes │        │          ║
 ╚═════╧══════╧════════╧══════════╝

 See Also:
  getch    getche

 Example:

 #include <stdio.h>
 #include <ctype.h>
 #include <conio.h>

 int main( void )
 {
    int i=0;
    char ch;

    puts("Input an integer followed by a char:");

    //  read chars until non digit or EOF
    while((ch = getche()) != EOF && isdigit(ch))
       i = 10 * i + ch - 48; //  convert ASCII into int value

    //  if non digit char was read, push it back into input buffer
    if (ch != EOF)
       ungetch(ch);

    printf("\n\ni = %d, next char in buffer = %c\n", i, getch());
    return 0;
 }
</code></pre> **/
int ungetch(int ch)
    {
    INPUT_RECORD ir[2];
    DWORD escritos;

    ir[0].EventType = KEY_EVENT;
    ir[0].Event.KeyEvent.bKeyDown = TRUE;
    ir[0].Event.KeyEvent.wRepeatCount = 1;
    ir[0].Event.KeyEvent.wVirtualKeyCode = 0;
    ir[0].Event.KeyEvent.wVirtualScanCode = 0;
    ir[0].Event.KeyEvent.uChar.AsciiChar = ch;
    ir[0].Event.KeyEvent.dwControlKeyState = 0;
    ir[1].EventType = KEY_EVENT;
    ir[1].Event.KeyEvent.bKeyDown = FALSE;
    ir[1].Event.KeyEvent.wRepeatCount = 1;
    ir[1].Event.KeyEvent.wVirtualKeyCode = 0;
    ir[1].Event.KeyEvent.wVirtualScanCode = 0;
    ir[1].Event.KeyEvent.uChar.AsciiChar = ch;
    ir[1].Event.KeyEvent.dwControlKeyState = 0;
    if (WriteConsoleInput(GetStdHandle(STD_INPUT_HANDLE),ir, 2, &escritos))
        {
        return ch;
        }
    return EOF;
    }




////////////////////////////END OF FILE CONIO.C


////////////////////////////////////////////////////////////////////////////////
//           Funciones que no son de borland, evitar usarlas
////////////////////////////////////////////////////////////////////////////////


//Non Borland
int getscreenx()
    {
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    // Get the current screen buffer size and window position.
    if (! GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo))
        {
        printf("GetConsoleScreenBufferInfo (%ld)\n", GetLastError());
        //return 0;
        }
    return (csbiInfo.srWindow.Right-csbiInfo.srWindow.Left+1);
    }

//Non Borland
int getscreeny()
    {
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    // Get the current screen buffer size and window position.
    if (! GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo))
        {
        printf("GetConsoleScreenBufferInfo (%ld)\n", GetLastError());
        //return 0;
        }
    return (csbiInfo.srWindow.Bottom-csbiInfo.srWindow.Top+1);
    }

//Non Borland
void gotox(int x)
    {
    COORD pos;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    // Get the current screen buffer size and window position.
    if (! GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo))
        {
        printf("GetConsoleScreenBufferInfo (%ld)\n", GetLastError());
        //return 0;
        }
    pos.X = x + csbiInfo.srWindow.Left;
    pos.Y = csbiInfo.dwCursorPosition.Y;  //(csbiInfo.dwCursorPosition.Y - csbiInfo.srWindow.Top) + csbiInfo.srWindow.Top;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }

//Non Borland
void gotoy(int y)
    {
    COORD pos;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    // Get the current screen buffer size and window position.
    if (! GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo))
        {
        printf("GetConsoleScreenBufferInfo (%ld)\n", GetLastError());
        //return 0;
        }
    pos.X = csbiInfo.dwCursorPosition.X; //(csbiInfo.dwCursorPosition.X - csbiInfo.srWindow.Left) + csbiInfo.srWindow.Left;
    pos.Y = y + csbiInfo.srWindow.Top;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }


//non borland
int align(int align,const char *str)
    {
    int x;
    switch (align)
        {
        case 0:
            x = (0);
            break;
        case 1:
            x = (40-(strlen(str)/2));
            break;
        case 2:
            x = (80-(strlen(str)));
            break;
        default:
            return 1;
            break;
        }
    if (strlen(str) > 79)
        {
        }
    else
        {
        gotoxy(x,wherey());  //DEBUG
        printf("%s",str);
        }
    return 0;
    }

//non borland
int _cp_x,_cp_y;
void cursor_savepos(void)
{
//Save cursor position:
    _cp_x = wherex();
    _cp_y = wherey();
}

//non borland
void cursor_restorepos(void)
{
gotoxy(_cp_x,_cp_y);
}

////////////////////////////////////////////////////////////////////////////////
//                         Definiciones en LINUX
////////////////////////////////////////////////////////////////////////////////

#else  //linux

//static int __BACKGROUND = BLACK;
//static int __FOREGROUND = LIGHTGRAY;

void gettextinfo (struct text_info * info)
    {
    __fill_text_info();
    *info = __text_info;
    }

void textcolor(int color)
{
__FOREGROUND=color;
   switch(color)
   {
       case BLACK:
       printf("\x1B[22;30m");
       break;
    case BLUE:
       printf("\x1B[22;34m");
       break;
    case GREEN:
       printf("\x1B[22;32m");
       break;
    case CYAN:
       printf("\x1B[22;36m");
       break;
    case RED:
       printf("\x1B[22;31m");
       break;
    case MAGENTA:
       printf("\x1B[22;35m");
       break;
    case BROWN:
       printf("\x1B[22;33m");
       break;
    case LIGHTGRAY:
       printf("\x1B[22;37m");
       break;
    case DARKGRAY:
       printf("\x1B[2;37m");
       break;
    case LIGHTBLUE:
       printf("\x1B[1;34m");
       break;
    case LIGHTGREEN:
       printf("\x1B[1;32m");
       break;
    case LIGHTCYAN:
       printf("\x1B[1;36m");
       break;
    case LIGHTRED:
       printf("\x1B[1;31m");
       break;
    case LIGHTMAGENTA:
       printf("\x1B[1;35m");
       break;
    case YELLOW:
       printf("\x1B[1;33m");
       break;
    case WHITE:
       printf("\x1B[1;37m");
       break;
   }
fflush(stdout);
}

void gotoxy( int x, int y )
    {
    __text_info.curx = x;
    __text_info.cury = y;
    printf("\x1B[%d;%dH",y,x);
    }

int          wherex( void ){}
int          wherey( void ){}

void clrscr(void)
    {
    printf("\x1B[2J");
    printf("\x1B[1;1H");
    }

//non borland
void cursor_savepos(void)
{
//Save cursor position:
  printf("\033[s");
}

//non borland
void cursor_restorepos(void)
{
//Restore cursor position:
  printf("\033[u");
}

#endif
#endif

//Old linux stuff with ncurses
/*

void         textcolor(int color)
{
    __FOREGROUND=color;
   switch(color)
   {
       case BLACK:
       attron (COLOR_PAIR (1));
       break;
       case BLUE:
       case LIGHTBLUE:
       attron (COLOR_PAIR (2));
       break;
       case GREEN:
       case LIGHTGREEN:
       attron (COLOR_PAIR (3));
       break;
       case CYAN:
       case LIGHTCYAN:
       attron (COLOR_PAIR (4));
       break;
       case RED:
       case LIGHTRED:
       attron (COLOR_PAIR (5));
       break;
       case MAGENTA:
       case LIGHTMAGENTA:
       attron (COLOR_PAIR (6));
       break;
       case BROWN:
       case YELLOW:
       attron (COLOR_PAIR (7));
       break;
       case LIGHTGRAY:
       case DARKGRAY:
       attron (COLOR_PAIR (8)|A_UNDERLINE);
       break;
       case WHITE:
       attron (COLOR_PAIR (8));
       break;
   }
}

void gotoxy( int x, int y )
    {
    move (y,x);
    }

int          wherex( void ){}
int          wherey( void ){}
void         gettextinfo (struct text_info *__r ){}
void clrscr(void)
    {
    erase ();
    }

void init_conio(void)
{
    initscr();
    savetty();
    start_color();
    init_pair(1,COLOR_BLACK,COLOR_BLACK);
    init_pair(2,COLOR_BLUE,COLOR_BLACK);
    init_pair(3,COLOR_GREEN,COLOR_BLACK);
    init_pair(4,COLOR_CYAN,COLOR_BLACK);
    init_pair(5,COLOR_RED,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(7,COLOR_YELLOW,COLOR_BLACK);
    init_pair(8,COLOR_WHITE,COLOR_BLACK);
}

*/

