#ifndef _DOS2_H
#define _DOS2_H

#ifdef __linux__

#define sound()
#define nosound()

#else    //windows

void sound(int f);
#define nosound() //nada

#endif


void delayms(int ms);
void delays(int _s);




#endif
