#include "Keyboard.h"
#include "Definitions.h"

class Controller{
public:
    enum MOVEMENT{
        UP = 1,
        DOWN,
        RIGHT,
        LEFT,
        FLAGPUT,
        DIG,
        QUITE,
        WRONGINPUT
    };
    static int GetCommand();
};
