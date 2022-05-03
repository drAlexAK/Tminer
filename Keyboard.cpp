#include "Keyboard.h"

int Keyboard::GetKey(){
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