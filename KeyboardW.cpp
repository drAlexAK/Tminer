#include "Keyboard.h"
#include <conio.h>

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80
#define KEY_ENTER 13

int Keyboard::GetKey(){
    int c, ex;
    c = getch();
    if (c && c != 224) {
        if (c == KEY_ENTER)
            return KEYS::ENTER; // replace bloody windows 13 code for Enter key to regular code 10
        else
            return c;
    }
    else {
        switch(ex = getch())
        {
            case KEY_UP:
                return KEYS::ARROW_UP;
            case KEY_DOWN:
                return KEYS::ARROW_DOWN;
            case KEY_LEFT:
                return KEYS::ARROW_LEFT;
            case KEY_RIGHT:
                return KEYS::ARROW_RIGHT;
            default:
                return KEYS::UNKNOW;
        }
    }
}
