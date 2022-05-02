#include "Console.h"
#include <iostream>

void Console::Flush(){
    std::fflush(stdout);
}

void Console::PrintSymbol(int x, int y, const std::string s, Font f) {
    std::string cmd = f.ToString();
    printf("\033[%d;%dH\x1b[%sm%s\x1b[0m", x+1, y+1, cmd.c_str(), s.c_str());
    Flush();
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
    system("clear");
}

void Console::Out(const std::string &s){
    std::cout << s;
}

int Console::In(){
    int a;
    std::cin >> a;
    return a;
}