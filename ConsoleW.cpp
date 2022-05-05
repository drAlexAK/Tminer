#include "Console.h"
#include <windows.h>
#include <iostream>

static DWORD originalConsoleMode;;
static HANDLE stdoutHandle;

int Console::Init() {

    SetConsoleOutputCP(CP_UTF8);

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
    printf("\x1b[0m");

    // Set original console mode
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

void Console::PrintSymbol(int x, int y, const std::string s, Font f) {
    std::string cmd = f.ToString();
    printf("\033[%d;%dH\x1b[%sm%s\x1b[0m", x+1, y+1, cmd.c_str(), s.c_str());
    Console::Flush();
}

void Console::PrintString(const std::string s, Font f){
    std::string cmd = f.ToString();
    for(int i = 0; i < (int)s.size(); i++){
        std::string ch = s.substr(i, 1);
        printf("\x1b[%sm%s\x1b[0m", cmd.c_str(), ch.c_str());
    }
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
