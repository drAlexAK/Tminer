#include "ConsoleW.h"
#include <iostream>


static DWORD originalConsoleMode;;
static HANDLE stdoutHandle;

int Console::Init() {

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

    SetConsoleOutputCP(CP_UTF8);
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
void Console::Flush(){
    std::fflush(stdout);
}

void Console::PrintSymbol(int x, int y, const std::string s, Font f) {
    std::string cmd = f.ToString();
    printf("\033[%d;%dH\x1b[%sm%s\x1b[0m", x+1, y+1, cmd.c_str(), s.c_str());
    Flush();
}
