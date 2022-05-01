//#include <string>
#include "Console.h"
//#include "Font.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include "Objects.h"

class Print{

    
public:
    static std::map<OBJECT_TYPE, char> oChar;
    static std::map<OBJECT_STATE, Font> oState;
    static void PrintObjectInPlace(int x, int y, OBJECT_TYPE object_type, OBJECT_STATE object_state);


    //class Console;
    // this is stub
    /*
    static const int n = 20, m = 20, per = 0;
    int c = n*m;

    static const std::vector<std::vector<int>> table;
    static const std::vector<std::vector<int>> used;
    static const std::vector<std::vector<int>> visiualtable; 
    // end of stub


	static void printcur(int i, int j, Font f);
	static void print();
	static void printstr(int x, int y, std::string s);
    */
};