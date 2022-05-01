#include "Print.h"
//#include "Definitions.h"

std::map<OBJECT_TYPE, char> Print::oChar = {{TIP_2 , 'A'}};
std::map<OBJECT_STATE, Font> Print::oState =  {{REGULAR, Font(-1,-1,-1)}};

void PrintObjectInPlace(int x, int y, OBJECT_TYPE object_type, OBJECT_STATE object_state){
	Console::PrintChar(x, y, Print::oChar.at(object_type), Print::oState.at(object_state));
}

/*
static void printcur(int i, int j, Font f){
    if(Console::visiualtable[i][j] == -3) {Image::printc(i, j, "#", f); return;}
    if(Console::visiualtable[i][j] > -1 && Console::table[i][j] == 0) Image::printc(i, j, "░", f);
    else if(Console::visiualtable[i][j] > -1) Image::printc(i, j,std::to_string(Console::visiualtable[i][j]), f);
    else Image::printc(i, j, ".", f);
}

static void print(){
		for(int i = 1; i <= Console::m; i++) Image::printc(0, i, "━", {NONE, NONE, NONE});
		for(int i = 1; i <= Console::m; i++) Image::printc(Console::n+1, i, "━", {NONE, NONE, NONE});
		for(int i = 1; i <= Console::n; i++) Image::printc(i, Console::m+1, "┃", {NONE, NONE, NONE});
		for(int i = 1; i <= Console::n; i++) Image::printc(i, 0, "┃", {NONE, NONE, NONE});
		Image::printc(Console::n+1, 0, "┗", {NONE, NONE, NONE});
		Image::printc(0, Console::m+1, "┓", {NONE, NONE, NONE});
		Image::printc(Console::n+1, Console::m+1, "┛", {NONE, NONE, NONE});
		Image::printc(0, 0, "┏", {NONE, NONE, NONE});
		for(int i = 1; i <= Console::n; i++) {for(int j = 1; j <= Console::m; j++) printcur(i, j, {NONE, BLACK, BG_WHITE}); std::cout << "\n";}
	}

static void printstr(int x, int y, std::string s){
		for(int i = 0; i < (int)s.size(); i++){
			Image::printc(x, y+i, s.substr(i, 1), {NONE, NONE, NONE});
		}
	}
*/