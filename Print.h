#include "Console.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include "Objects.h"

class Print{
    static void PrintObjectInPlace(int x, int y, OBJECT_TYPE object_type, OBJECT_STATE object_state);
public:
    static std::map<OBJECT_TYPE, std::string> oChar;
    static std::map<OBJECT_STATE, Font> oState;

    static void PutFlag(int x, int y);
    static void PutHidden(int x, int y);
    static void PutTip(int x, int y, OBJECT_TYPE type);

    static void RemoveFlag(int x, int y, OBJECT_TYPE type, OBJECT_STATE state);
    static void PrintCursor(int x, int y, OBJECT_TYPE type);
    static void removeCursor(int x, int y, OBJECT_TYPE type);
};