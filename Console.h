#include <string>
#include "Font.h"

class Console{
public:

    static void PrintSymbol(int x, int y, std::string s, Font f);
    static void PrintString(std::string s, Font f);
    static void Flush();
    static void Clear();
    static void Out(const std::string &s);
    static int In();
};