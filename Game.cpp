#include <random>
#include <set>
#include "Game.h"

int Game::n = 0;
int Game::m = 0;
int Game::minesCount = 0;
std::vector<std::vector<int>> Game::table;

std::mt19937 rnd(time(0));

#define mines 16
#define flag 32
#define used 64

// n - height, m - width
// x, y - initial point

void Game::InitMap(int x, int y) {

// the cort more for 2 columns and rows
    Game::table.resize(Game::n + 2, std::vector<int>(Game::m + 2, mines));

// fill all cells zero
    for (int i = 1; i <= Game::n; i++)
        for (int j = 1; j <= Game::m; j++)
            Game::table[i][j] = 0;

    std::set <std::pair<int, int>> st;

// randomly fills field with mines

    for (int i = 0; (int) st.size() < minesCount; i++) {
        int xx = rnd() % Game::n + 1;
        int yy = rnd() % Game::m + 1;
        if (st.count({xx, yy}) != 0 || (abs(xx - x) <= 1 && abs(yy - y) <= 1)) continue;
        st.insert({xx, yy});
        Game::table[xx][yy] |= mines;
    }

// counts mines around each cell

    for (int i = 1; i <= Game::n; i++) {
        for (int j = 1; j <= Game::m; j++) {
            if (Game::table[i][j] == mines) continue;
            for (int k = std::max(i - 1, 1); k <= std::min(i + 1, Game::n); k++) {
                for (int l = std::max(j - 1, 1); l <= std::min(j + 1, Game::m); l++) {
                    if (Game::table[k][l] == mines) Game::table[i][j]++;
                }
            }
        }
    }
}

// prints position on coord [x, y]
void Game::PrintPos(int x, int y){
    if ((Game::table[x][y] & flag) != 0) {
        Print::PutFlag(x, y);
        return;
    }

    if ((Game::table[x][y] & used) == 0) {
        Print::PutHidden(x, y);
        return;
    }

    switch((Game::table[x][y] % mines)) {
        case 0:
            Print::PutTip(x, y, TIP_0);
            return;
        case 1:
            Print::PutTip(x, y, TIP_1);
            return;
        case 2:
            Print::PutTip(x, y, TIP_2);
            return;
        case 3:
            Print::PutTip(x, y, TIP_3);
            return;
        case 4:
            Print::PutTip(x, y, TIP_4);
            return;
        case 5:
            Print::PutTip(x, y, TIP_5);
            return;
        case 6:
            Print::PutTip(x, y, TIP_6);
            return;
        case 7:
            Print::PutTip(x, y, TIP_7);
            return;
        case 8:
            Print::PutTip(x, y, TIP_8);
            return;
    }
}

// dfs - for spreading after strike
void Game::Dfs(int x, int y) {
    if((Game::table[x][y] & used) != 0 || ((Game::table[x][y] & mines) != 0)) return;

    Game::table[x][y] |= used;

    if((Game::table[x][y] % mines) != 0) return;

    Dfs(x - 1, y);
    Dfs(x + 1, y);
    Dfs(x, y + 1);
    Dfs(x, y - 1);
    Dfs(x - 1, y + 1);
    Dfs(x - 1, y - 1);
    Dfs(x + 1, y + 1);
    Dfs(x + 1, y - 1);
}

// prints map after strike
void Game::PrintMap() {
    for(int i = 1; i <= Game::n; i++){
        for(int j = 1; j <= Game::m; j++){
            Game::PrintPos(i, j);
        }
    }
}

// handle strikes
void Game::OpenCell(int x, int y) {
    Game::Dfs(x, y);
    PrintMap();
}

// x, y - coord of the first strike
void Game::InitGame(int _n, int _m, int _minesCount, int x, int y) {
    Game::n = _n;
    Game::m = _m;
    Game::minesCount = _minesCount;
    Game::InitMap(x, y);
    Game::OpenCell(x, y);
}

