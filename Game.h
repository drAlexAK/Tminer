#include "Print.h"
#include <vector>

class Game{
    // height and width of the map
    static int n, m;
    // count of mines on the map
    static int minesCount;

    static std::vector<std::vector<int>> table;
    static void Dfs(int x, int y);
    static void InitMap(int x, int y);
    static void PrintPos(int x, int y);
    static void PrintMap();
public:
    static void InitGame(int _n, int _m, int _minesCount, int x, int y);
    static void OpenCell(int x, int y);
};