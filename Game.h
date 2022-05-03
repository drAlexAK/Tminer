#include "Print.h"
#include "controller.h"
#include <vector>
#include <random>
#include <set>


class Game{
    // height and width of the map
    static int n, m;
    // count of mines on the map
    static int minesCount;
    static int curPosX, curPosY;

    static std::vector<std::vector<int>> table;
    static void Dfs(int x, int y);
    static void InitMap(int x, int y);
    static void PrintPos(int x, int y);
    static void PrintMap();
    static OBJECT_TYPE GetTypePos(int x, int y);
public:
    static void movementControl();
    static void InitGame(int _n, int _m, int _minesCount, int x, int y);
    static void OpenCell(int x, int y);
};