#include "Print.h"
#include "Controller.h"
#include <vector>
#include <random>
#include <set>
#include <chrono>

class Game{
    // height and width of the map
    static int n, m;
    // count of mines on the map
    static int minesCount;
    static int curPosX, curPosY;
    static int wasFirstMove;
    static int cellsTillVictory;

    static std::vector<std::vector<int>> table;
    static void dfs(int x, int y);
    static void initMap(int x, int y);
    static void printPos(int x, int y);
    static void printMap();
    static OBJECT_TYPE getTypePos(int x, int y);
    static void openCell(int x, int y);
    static void initGame(int _n, int _m, int _minesCount, int x, int y);
    static int movementControl();
    static void losePrintCurCell(int x, int y);
    static void losePrint();
    static void printCircuit();
public:
    static void Play();
};
