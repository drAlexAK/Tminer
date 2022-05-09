#include "Console.h"
#include <windows.h>
#include <iostream>

static DWORD originalConsoleMode;;
static HANDLE stdoutHandle;

int cpDefaultMod = 0;

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

std::map<Console::CONVERTER, char> mp = {{Console::FIG1, '1'},
                                                {Console::FIG2, '2'},
                                                {Console::FIG3, '3'},
                                                {Console::FIG4, '4'},
                                                {Console::FIG5, '5'},
                                                {Console::FIG6, '6'},
                                                {Console::FIG7, '7'},
                                                {Console::FIG8, '8'},
                                                {Console::MINE, '*'},
                                                {Console::SHARP, '#'},
                                                {Console::POINT, '.'},
                                                {Console::CELL, (char) 176}, //░
                                                {Console::NONECH, ' '},
                                                {Console::CIRCUITFLOOR, (char) 196},
                                                {Console::CIRCUITFWALLS, (char) 179},
                                                {Console::CIRCUITFCEIL, (char) 196},
                                                {Console::CIRCUITUPLEFT, (char)218},
                                                {Console::CIRCUITDOWNLEFT, (char)192},
                                                {Console::CIRCUITDOWNRIGHT, (char)217},
                                                {Console::CIRCUITUPRIGHT,  (char)191}};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void color(Font f){
    int a;
    switch(f.color){
        case 31: //red
            a = 4;
            break;
        default:
            a = f.color - 30;
    }
    Color(16 * (f.bg_color - 40) + a);
}

int Console::Init() {

    //SetConsoleOutputCP(CP_UTF8);
    SetConsoleOutputCP(437);
    cpDefaultMod = GetConsoleOutputCP();

    DWORD currentConsoleMode = 0;

    stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if(stdoutHandle == INVALID_HANDLE_VALUE) {
        return(GetLastError());
    }

    if(!GetConsoleMode(stdoutHandle, &currentConsoleMode)) {
        return(GetLastError());
    }

    originalConsoleMode = currentConsoleMode;

    // Set ANSI escape codes
    currentConsoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if(!SetConsoleMode(stdoutHandle, currentConsoleMode)) {
        return(GetLastError());
    }
}

int Console::Restore() {
    // Reset colors
    //printf("\x1b[0m");

    // Set original console mode

    SetConsoleOutputCP(cpDefaultMod);

    if(!SetConsoleMode(stdoutHandle, originalConsoleMode)) {
        return(GetLastError());
    }
}

void Console::Pause(){
    system("pause");
}

void Console::SetCursor(bool enable){
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(handle, &cci);
    cci.bVisible = enable; // show/hide cursor
    SetConsoleCursorInfo(handle, &cci);
}

void Console::Flush(){
    std::fflush(stdout);
}

void Console::PrintSymbol(int x, int y, Console::CONVERTER symbol, Font f) {
    gotoxy(y, x);
    color(f);
    char s = mp[symbol];
    printf("%c", s);
    Console::Flush();
}

void Console::PrintString(const std::string s, Font f){
    color({-1, 37, 40});
    printf("%s", s.c_str());
    Flush();
}

void Console::Clear(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;

    COORD homeCoords = { 0, 0 };

    stdoutHandle = GetStdHandle( STD_OUTPUT_HANDLE );
    if (stdoutHandle == INVALID_HANDLE_VALUE) return;

    // Get the number of cells in the current buffer
    if (!GetConsoleScreenBufferInfo( stdoutHandle, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    // Fill the entire buffer with spaces
    if (!FillConsoleOutputCharacter(stdoutHandle, (TCHAR) ' ', cellCount, homeCoords, &count)) return;

    // Fill the entire buffer with the current colors and attributes
    if (!FillConsoleOutputAttribute( stdoutHandle, csbi.wAttributes, cellCount, homeCoords, &count)) return;

    // Move the cursor top-left corner
    SetConsoleCursorPosition( stdoutHandle, homeCoords );

}

void Console::Out(const std::string &s){
    std::cout << s;
}

int Console::In(){
    int a;
    std::cin >> a;
    return a;
}