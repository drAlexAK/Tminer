#include "Print.h"
#include "Definitions.h"

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
                                               {PUTFLAG, {BOLD, BLACK, BG_WHITE}},
                                               {CURSOR, {BLINKING, BLACK, BG_WHITE}}};

void Print::PrintObjectInPlace(int x, int y, OBJECT_TYPE object_type, OBJECT_STATE object_state){
    Console::PrintSymbol(x, y, Print::oChar.at(object_type), Print::oState.at(object_state));
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