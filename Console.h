#include <string>
#include <bits/stdc++.h>
#include "Font.h"

class Console{
public:
    enum CONVERTER{
        FIG1 = 1,
        FIG2,
        FIG3,
        FIG4,
        FIG5,
        FIG6,
        FIG7,
        FIG8,
        SHARP,
        POINT,
        CELL,
        MINE,
        NONECH,
        CIRCUITFLOOR,
        CIRCUITFWALLS,
        CIRCUITFCEIL,
        CIRCUITUPLEFT,
        CIRCUITDOWNLEFT,
        CIRCUITUPRIGHT,
        CIRCUITDOWNRIGHT,
    };
    static int Init();
    static int Restore();

    static void PrintSymbol(int x, int y, CONVERTER symbol, Font f);
    static void PrintString(std::string s, Font f);
    static void Flush();
    static void Clear();
    static void SetCursor(bool enable);
    static void Out(const std::string &s);
    static int In();
    static void Pause();
};
