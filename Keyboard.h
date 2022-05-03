#include <iostream>
#include <termios.h>
#include <unistd.h>

#define additionalchar 3000

class Keyboard{
public:
    static int GetKey();
};
