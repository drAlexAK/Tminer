#include "Print.h"
#include "Definitions.h"

int Print::xBeginCoor = 1;
int Print::yBeginCoor = 1;

std::map<OBJECT_TYPE, Console::CONVERTER> Print::oChar =   {{TIP_1, Console::FIG1},
                                                     {TIP_2, Console::FIG2},
                                                     {TIP_3, Console::FIG3},
                                                     {TIP_4, Console::FIG4},
                                                     {TIP_5, Console::FIG5},
                                                     {TIP_6, Console::FIG6},
                                                     {TIP_7, Console::FIG7},
                                                     {TIP_8, Console::FIG8},
                                                     {FLAG, Console::SHARP},
                                                     {HIDDEN, Console::POINT},
                                                     {TIP_0, Console::CELL},
                                                     {MINE, Console::MINE}};

std::map<OBJECT_STATE, Font> Print::oState = {{REGULAR, Font(NONE, BLACK, BG_WHITE)},
                                               {PUTFLAG, {NONE, BLACK, BG_WHITE}},
                                               {MINEGREEN, {NONE, GREEN, BG_WHITE}},
                                               {MINERED, {NONE, RED, BG_WHITE}},
                                               {CURSOR, {NONE, WHITE, BG_BLACK}}};

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

void Print::RemoveCursor(int x, int y, OBJECT_TYPE type){
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

void Print::PrintString(std::string s) {
    Console::PrintString(s, {-1, WHITE, -1});
}

void Print::PrintLose(int x, int y, OBJECT_STATE state) {
    Print::PrintObjectInPlace(x, y, MINE, state);
}

void Print::PrintDead(){
    Console::Clear();
    Console::Out ("\n________________________________________________________\n"
                  "/                                                      \\\n"
                  "|                 Ha ha, you're dead                   |\n"
                  "\\_________              _______________________________/\n"
                  "          \\_         __/    ___---------__              \n"
                  "            \\      _/      /              \\_            \n"
                  "             \\    /       /                 \\           \n"
                  "              |  /       | _    _ \\          \\          \n"
                  "              | |       / / \\ / \\ |           \\         \n"
                  "              | |       ||   ||   | |           |        \n"
                  "              | |       | \\_//\\_/ |           |        \n"
                  "              | |       |_| (||)    |_______|   |       \n"
                  "              | |         |  ||     | _  / /    |        \n"
                  "               \\ \\        |_________|| \\/ /   /         \n"
                  "                \\ \\_       |_|_|_|_|/|  _/___/          \n"
                  "                 \\__>       _ _/_ _ /  |                \n"
                  "                          .|_|_|_|_|   |                \n"
                  "                          |           /                 \n"
                  "                          |__________/      ");//, Print::oState.at(OBJECT_STATE::REGULAR));*/
}

void Print::PrintLogo(){
    Console::Clear();
    Console::Out(" _    __  __  _ \n"
                 "| |_ |  \\/  |(_) _ __    ___  _ __\n"
                 "| __|| |\\/| || || '_ \\  / _ \\| '__|\n"
                 "| |_ | |  | || || | | ||  __/| |\n"
                 " \\__||_|  |_||_||_| |_| \\___||_|\n");
}

void Print::PrintControl(){
    Console::Clear();
    Console::Out("Settings\nUse arrows to navigate\nPress Space to reveal field\nPress Enter to set up flag\nPress q to exit\n\nPress any key to continue\n");
}

void Print::PrintWin() {
    Console::Clear();
    Console::Out("__   __   ___    _   _        __      __   ___    _  _ \n"
                 "\\ \\ / /  / _ \\  | | | |       \\ \\    / /  / _ \\  | \\| |\n"
                 " \\ V /  | (_) | | |_| |        \\ \\/\\/ /  | (_) | | .` |\n"
                 "  |_|    \\___/   \\___/          \\_/\\_/    \\___/  |_|\\_|\n");
}

void Print::PrintChar(int x, int y, Console::CONVERTER symbol){
    Console::PrintSymbol(x + xBeginCoor, y + yBeginCoor, symbol, {NONE, NONE, NONE});
}
