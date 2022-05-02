#include "Print.h"
#include "Definitions.h"

std::map<OBJECT_TYPE, std::string> Print::oChar = {{TIP_2 , "1"},
                                            {FLAG, "#"}};
std::map<OBJECT_STATE, Font> Print::oState =  {{REGULAR, {NONE, WHITE, BG_BLACK}},
                                               {PUTFLAG, {BOLD, WHITE, BG_BLACK}},
                                               {CURSOR, {BLINKING, WHITE, BG_BLACK}}};

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