#include <string>
#include "Font.h"

class Console{
	public:

    static void PrintChar(int x, int y, const char c, Font &f);
    static void PrintString(const std::string &s, Font &f);
    static void Flush();
    static void Clear();
    static void Out(const std::string &s);
    static int In();
};