#include "Controller.h"

int Controller::GetCommand(){

    //std::cout << (int)cmd << "\n";

    switch (Keyboard::GetKey()) {
        case KEYS::ARROW_DOWN:
            return MOVEMENT::DOWN;
        case KEYS::ARROW_LEFT:
            return MOVEMENT::LEFT;
        case KEYS::ARROW_UP:
            return MOVEMENT::UP;
        case KEYS::ARROW_RIGHT:
            return MOVEMENT::RIGHT;
        case KEYS::ENTER:
            return MOVEMENT::FLAGPUT;
        case KEYS::SPACE:
            return MOVEMENT::DIG;
        case KEYS::q:
            return MOVEMENT::QUITE;
        case KEYS::c:
            return MOVEMENT::QUITE;
        default:
            return MOVEMENT::WRONGINPUT;
    }
}
