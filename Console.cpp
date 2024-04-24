#include "Console.h"
#include <iostream>

int Console::Init(){Console::SetCursor(false);return 0;}
int Console::Restore(){
    printf("\033[m");
    SetCursor(true);
    return 0;
}

std::map<Console::CONVERTER, std::string> mp = {{Console::FIG1, "1"},
                                                {Console::FIG2, "2"},
                                                {Console::FIG3, "3"},
                                                {Console::FIG4, "4"},
                                                {Console::FIG5, "5"},
                                                {Console::FIG6, "6"},
                                                {Console::FIG7, "7"},
                                                {Console::FIG8, "8"},
                                                {Console::MINE, "*"},
                                                {Console::SHARP, "#"},
                                                {Console::POINT, "."},
                                                {Console::CELL, "░"},
                                                {Console::NONECH, ""},
                                                {Console::CIRCUITFLOOR, "━"},
                                                {Console::CIRCUITFWALLS, "┃"},
                                                {Console::CIRCUITFCEIL, "━"},
                                                {Console::CIRCUITUPLEFT, "┏"},
                                                {Console::CIRCUITDOWNLEFT, "┗"},
                                                {Console::CIRCUITDOWNRIGHT, "┛"},
                                                {Console::CIRCUITUPRIGHT,  "┓"}};

void Console::Flush(){
    std::fflush(stdout);
}

void Console::Pause(){
    system("PAUSE");
}

void Console::PrintSymbol(int x, int y, CONVERTER symbol, Font f){
    std::string s = mp[symbol];
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

void Console::SetCursor(bool enable){
    (enable ? std::cout << "\033[?25h" :  std::cout << "\033[?25l");
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
