#include "Print.h"
#include "Definitions.h"

int Print::xBeginCoor = 1;
int Print::yBeginCoor = 1;

std::map<OBJECT_TYPE, std::string> Print::oChar =   {{TIP_1, "1"},
                                                     {TIP_2, "2"},
                                                     {TIP_3, "3"},
                                                     {TIP_4, "4"},
                                                     {TIP_5, "5"},
                                                     {TIP_6, "6"},
                                                     {TIP_7, "7"},
                                                     {TIP_8, "8"},
                                                     {FLAG, "#"},
                                                     {HIDDEN, "."},
                                                     {TIP_0, "░"},
                                                     {MINE, "*"}};

std::map<OBJECT_STATE, Font> Print::oState =  {{REGULAR, Font(NONE, BLACK, BG_WHITE)},
                                               {PUTFLAG, {NONE, BLACK, BG_WHITE}},
                                               {MINEGREEN, {BLINKING, GREEN, BG_WHITE}},
                                               {MINERED, {BLINKING, RED, BG_WHITE}},
                                               {CURSOR, {BLINKING, WHITE, BG_BLACK}}};

void Print::PrintObjectInPlace(int x, int y, OBJECT_TYPE object_type, OBJECT_STATE object_state){
    Console::PrintSymbol(x + xBeginCoor, y + yBeginCoor, Print::oChar.at(object_type), Print::oState.at(object_state));
}

void Print::PutFlag(int x, int y){
    Print::PrintObjectInPlace(x, y, FLAG, PUTFLAG);
}

void Print::RemoveFlag(int x, int y, OBJECT_TYPE type, OBJECT_STATE state){
    Print::PrintObjectInPlace(x, y, type, state);
}

void Print::PrintCursor(int x, int y, OBJECT_TYPE type){
    Print::PrintObjectInPlace(x, y, type, CURSOR);
}

void Print::removeCursor(int x, int y, OBJECT_TYPE type){
    Print::PrintObjectInPlace(x, y, type, REGULAR);
}

void Print::PutHidden(int x, int y){
    Print::PrintObjectInPlace(x, y, HIDDEN, REGULAR);
}

void Print::PutTip(int x, int y, OBJECT_TYPE type){
    Print::PrintObjectInPlace(x, y, type, REGULAR);
}

void Print::MoveCursor(int x, int y, OBJECT_TYPE type1, int x2, int y2, OBJECT_TYPE type2) {
    Print::PrintObjectInPlace(x, y, type1, REGULAR);
    Print::PrintObjectInPlace(x2, y2, type2, CURSOR);
}

void Print::removeConsoleCursor() {
    std::cout << "\033[?25l";
}

void Print::addConsoleCursor() {
    std::cout << "\033[?25h";
}

void Print::PrintString(std::string s) {
    Console::PrintString(s, Print::oState.at(OBJECT_STATE::REGULAR));
}

void Print::PrintLose(int x, int y, OBJECT_STATE state) {
    Print::PrintObjectInPlace(x, y, MINE, state);
}

void Print::PrintWin() {
    Console::Clear();
    Console::Out("__   __   ___    _   _        __      __   ___    _  _ \n"
                 "\\ \\ / /  / _ \\  | | | |       \\ \\    / /  / _ \\  | \\| |\n"
                 " \\ V /  | (_) | | |_| |        \\ \\/\\/ /  | (_) | | .` |\n"
                 "  |_|    \\___/   \\___/          \\_/\\_/    \\___/  |_|\\_|\n");
    Print::addConsoleCursor();
}

void Print::PrintChar(int x, int y, std::string s){
    Console::PrintSymbol(x + xBeginCoor, y + yBeginCoor, s, {NONE, NONE, NONE});
}
