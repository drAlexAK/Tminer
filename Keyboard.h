#include <iostream>
#include <unistd.h>
#include "Keys.h"

#define additionalchar 3000

class Keyboard{
private:
    static int getKey();
public:
    static int GetKey();
};
