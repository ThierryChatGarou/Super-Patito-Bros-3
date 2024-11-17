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

#include "dos2.h"
#ifdef __WIN32__
#include <windows.h>
#endif


/**
No support for infinite time beep
**/
#ifdef __WIN32__
void sound(int f)
    {
    Beep( f, 200 );
    }
#endif

#define nosound() //nada

void delayms(int ms)
    {
#ifdef __linux__   //linux
    usleep(1000 * ms);
#else
    Sleep(ms);
#endif
    }

void delays(int _s)
    {
#ifdef __linux__   //linux
    sleep(_s);
#else
    Sleep(1000 * _s);
#endif
    }

void delay(int ms)
    {
#ifdef __linux__   //linux
    usleep(1000 * ms);
#else
    Sleep(ms);
#endif
    }


/**
 ÜÜÜÜÜÜÜ
 ÝdelayÞ                        <DOS.H>
 ฿฿฿฿฿฿฿
 Suspends execution for interval (milliseconds)

 Declaration:  void delay(unsigned milliseconds);

 Remarks:
With a call to delay, the current program is suspended from execution for
the time specified by the argument milliseconds.

It is not necessary to make a calibration call to delay before using it.

delay is accurate to one millisecond.

 Return Value:  None

 Portability:
 ษ DOS ั UNIX ั ANSI C ั C++ Only ป
 บ Yes ณ      ณ        ณ          บ
 ศอออออฯออออออฯออออออออฯออออออออออผ

 See Also:
  nosound   sleep     sound

 Example:

 //  Emits a 440-Hz tone for 500 milliseconds
 #include <dos.h>

 int main(void)
 {
    sound(440);
    delay(500);
    nosound();

    return 0;
 }
**/

//old busy state delay
/*void delay(unsigned long int milisec)
    {
    clock_t start,end,loop;
    start = clock();
    end = (start+milisec);
    do
        {
        loop = clock();
        }
    while (loop<end);
    }
*/



