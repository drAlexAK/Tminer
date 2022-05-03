#include "controller.h"

int Controller::GetCommand(){
    auto cmd = Keyboard::GetKey();
    if(cmd == enter){
        return MOVEMENT::FLAGPUT;
    }

    if(cmd == space){
        return MOVEMENT::DIG;
    }

    if(cmd < additionalchar){
        return MOVEMENT::WRONGINPUT;
    }

    return cmd - additionalchar - 64;
}
