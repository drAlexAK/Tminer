#ifdef __unix__
#include "Keyboard.h"
#else
#include "KeyboardW.h"
#endif


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