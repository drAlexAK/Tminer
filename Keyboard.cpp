#include "Keyboard.h"

#define KEY_RIGHT 3067
#define KEY_DOWN 3066
#define KEY_LEFT 3068
#define KEY_UP 3065


int Keyboard::GetKey(){
    int k =Keyboard::getKey();
    switch(k) {
        case KEY_UP:
            return KEYS::ARROW_UP;
        case KEY_DOWN:
            return KEYS::ARROW_DOWN;
        case KEY_LEFT:
            return KEYS::ARROW_LEFT;
        case KEY_RIGHT:
            return KEYS::ARROW_RIGHT;
        default:
            if (k > 126)
                return KEYS::UNKNOW;
            else
                return k;
    }
}

int Keyboard::getKey(){
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    if(ch == 27){ // Esc code needed for splitting Esc + D from -> etc
        ch = getchar();
        if(ch != 91) { // Checking for the second input
            tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
            return ch;
        }
        ch = getchar();
        return ch + additionalchar;
    }
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
