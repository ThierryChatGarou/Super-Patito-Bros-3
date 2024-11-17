#include<windows.h>

inline int keypressed(int k);

#ifdef MSDOS

// SCAN-CODES MSDOS
#define KEY_ESC             0x01
#define KEY_1               0x02
#define KEY_2               0x03
#define KEY_3               0x04
#define KEY_4               0x05
#define KEY_5               0x06
#define KEY_6               0x07
#define KEY_7               0x08
#define KEY_8               0x09
#define KEY_9               0x0A
#define KEY_0               0x0B
#define KEY_APOSTROFE       0x0C
#define KEY_EXCLAMACION     0x0D
#define KEY_BACKSPACE       0x0E
#define KEY_TABULADOR       0x0F
#define KEY_Q               0x10
#define KEY_W               0x11
#define KEY_E               0x12
#define KEY_R               0x13
#define KEY_T               0x14
#define KEY_Y               0x15
#define KEY_U               0x16
#define KEY_I               0x17
#define KEY_O               0x18
#define KEY_P               0x19
#define KEY_GORRO           0x1A
#define KEY_PLUS            0x1B
#define KEY_ENTER           0x1C
#define KEY_CONTROL         0x1D
#define KEY_A               0x1E
#define KEY_S               0x1F
#define KEY_D               0x20
#define KEY_F               0x21
#define KEY_G               0x22
#define KEY_H               0x23
#define KEY_J               0x24
#define KEY_K               0x25
#define KEY_L               0x26
#define KEY_ENIE            0x27
#define KEY_ACENTO          0x28
#define KEY_GRADOS          0x29
#define KEY_SHIFT_LEFT      0x2A
#define KEY_CEDILLA         0x2B
#define KEY_Z               0x2C
#define KEY_X               0x2D
#define KEY_C               0x2E
#define KEY_V               0x2F
#define KEY_B               0x30
#define KEY_N               0x31
#define KEY_M               0x32
#define KEY_COMA            0x33
#define KEY_PUNTO           0x34
#define KEY_GUION           0x35
#define KEY_SHIFT_RIGHT     0x36
#define KEY_PRINT_SCREEN    0x37
#define KEY_ALT             0x38
#define KEY_ESPACIO         0x39
#define KEY_CAPS            0x3A
#define KEY_F1              0x3B
#define KEY_F2              0x3C
#define KEY_F3              0x3D
#define KEY_F4              0x3E
#define KEY_F5              0x3F
#define KEY_F6              0x40
#define KEY_F7              0x41
#define KEY_F8              0x42
#define KEY_F9              0x43
#define KEY_F10             0x44
#define KEY_NUM_LOCK        0x45
#define KEY_SCROLL_LOCK     0x46
#define KEY_CUR_HOME        0x47
#define KEY_CUR_ARRIBA      0x48
#define KEY_CUR_PG_UP       0x49
#define KEY_NUM_MINUS       0x4A
#define KEY_CUR_ATRAS       0x4B
#define KEY_NUM_5           0x4C
#define KEY_CUR_ADELANTE    0x4D
#define KEY_NUM_MAS         0x4E
#define KEY_NUM_MENOS	    0x4A
#define KEY_CUR_END         0x4F
#define KEY_CUR_ABAJO       0x50
#define KEY_CUR_PG_DOWN     0x51
#define KEY_INSERT          0x52
#define KEY_DELETE          0x53
#define KEY_SYS_REQUEST     0x54
#define KEY_F11             0x57
#define KEY_F12             0x58


#define RSHIFT       1           // pulsada la tecla derecha de SHIFT
#define LSHIFT       2           // pulsada la tecla izquierda de SHIFT
#define CTRL         4           // pulsada la tecla CTRL
#define ALT          8           // pulsada la tecla ALT
#define SYSREQ    1024           // Tecla Pet Sis (s¢lo teclado AT)
#define BREAK     4096           // pulsada la tecla Pausa
#define NUM       8192           // pulsada la tecla Bloq Num
#define CAPS     16384           // pulsada la tecla Bloq May£s
#define INSERT   32768           // pulsada la tecla INSERT



#else  //Windows


#define KEY_ESC             VK_ESCAPE
#define KEY_F1              VK_F1
#define KEY_F2              VK_F2
#define KEY_F3              VK_F3
#define KEY_F4              VK_F4
#define KEY_F5              VK_F5
#define KEY_F6              VK_F6
#define KEY_F7              VK_F7
#define KEY_F8              VK_F8
#define KEY_F9              VK_F9
#define KEY_F10             VK_F10
#define KEY_F11             VK_F11
#define KEY_F12             VK_F12
#define KEY_GRADOS          0xDC
#define KEY_1               0x31
#define KEY_2               0x32
#define KEY_3               0x33
#define KEY_4               0x34
#define KEY_5               0x35
#define KEY_6               0x36
#define KEY_7               0x37
#define KEY_8               0x38
#define KEY_9               0x39
#define KEY_0               0x30
#define KEY_APOSTROFE       0xDB
#define KEY_EXCLAMACION     0xDD
#define KEY_BACKSPACE       VK_BACK
#define KEY_TABULADOR       VK_TAB
#define KEY_A               0x41
#define KEY_B               0x42
#define KEY_C               0x43
#define KEY_D               0x44
#define KEY_E               0x45
#define KEY_F               0x46
#define KEY_G               0x47
#define KEY_H               0x48
#define KEY_I               0x49
#define KEY_J               0x4A
#define KEY_K               0x4B
#define KEY_L               0x4C
#define KEY_M               0x4D
#define KEY_N               0x4E
#define KEY_O               0x4F
#define KEY_P               0x50
#define KEY_Q               0x51
#define KEY_R               0x52
#define KEY_S               0x53
#define KEY_T               0x54
#define KEY_U               0x55
#define KEY_V               0x56
#define KEY_W               0x57
#define KEY_X               0x58
#define KEY_Y               0x59
#define KEY_Z               0x5A
#define KEY_COMA            0xBC
#define KEY_PUNTO           0xBE
#define KEY_GUION           0xBD
#define KEY_MAYOR           0xE2
#define KEY_ENTER           VK_RETURN
#define KEY_CONTROL         VK_CONTROL
#define KEY_ESPACIO         VK_SPACE
#define KEY_SHIFT_LEFT      0xA0
#define KEY_SHIFT_RIGHT     0xA1
#define KEY_CUR_HOME        VK_HOME
#define KEY_CUR_ARRIBA      VK_UP
#define KEY_CUR_PG_UP       VK_PRIOR
#define KEY_CUR_ATRAS       VK_LEFT
#define KEY_CUR_ADELANTE    VK_RIGHT
#define KEY_CUR_END         VK_END
#define KEY_CUR_ABAJO       VK_DOWN
#define KEY_CUR_PG_DOWN     VK_NEXT
#define KEY_INSERT          VK_INSERT
#define KEY_DELETE          VK_DELETE
#define BOTON_L             VK_LBUTTON
#define BOTON_R             VK_RBUTTON
#define BOTON_M             VK_MBUTTON
#define KEY_NUM_MAS         0x6B
#define KEY_NUM_MENOS	    0x6D
#define KEY_NUM_5           0x65
#define KEY_NUM_DIV         0x6F
#define KEY_NUM_MULT        0x6A
#define KEY_ALT             0xA4
#define KEY_CAPS            0x14
#define KEY_GORRO           0xBA
#define KEY_PLUS            0xBB
#define KEY_ENIE            0xC0
#define KEY_ACENTO          0xDE
#define KEY_CEDILLA         0xBF
#define KEY_PRINT_SCREEN    0x2C
#define KEY_NUM_LOCK        0x90
#define KEY_SCROLL_LOCK     0x91
#define KEY_SYS_REQUEST     0x00 //desconocido




#define RSHIFT       0xA1           // pulsada la tecla derecha de SHIFT
#define LSHIFT       0xA0           // pulsada la tecla izquierda de SHIFT
#define CTRL         VK_CONTROL           // pulsada la tecla CTRL
#define ALT          0xA4           // pulsada la tecla ALT
#define SYSREQ       0          //desconocido // Tecla Pet Sis (s¢lo teclado AT)
#define BREAK        0         //desconocido  // pulsada la tecla Pausa
#define NUM          0         //desconocido  // pulsada la tecla Bloq Num
#define CAPS         0         //desconocido  // pulsada la tecla Bloq May£s
#define INSERT       0         //desconocido  // pulsada la tecla INSERT



#endif

