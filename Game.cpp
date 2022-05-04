#include "Game.h"

int Game::n = 0;
int Game::m = 0;
int Game::minesCount = 0;
std::vector<std::vector<int>> Game::table;
int Game::curPosX = 1;
int Game::curPosY = 1;
int Game::wasFirstMove = 0;
int Game::cellsTillVictory = 0;

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
    cellsTillVictory--;

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
    Print::PrintCursor(x, y, Game::GetTypePos(x, y));
}

// x, y - coord of the first strike
void Game::InitGame(int _n, int _m, int _minesCount, int x, int y) {
    Game::n = _n;
    Game::m = _m;
    Game::minesCount = _minesCount;
    Game::cellsTillVictory = n*m - minesCount;
    Game::InitMap(x, y);
    Game::OpenCell(x, y);
}

OBJECT_TYPE Game::GetTypePos(int x, int y) {
    if ((Game::table[x][y] & flag) != 0) {
        return OBJECT_TYPE::FLAG;
    }

    if ((Game::table[x][y] & used) == 0) {
        return OBJECT_TYPE::HIDDEN;
    }

    switch((Game::table[x][y] % mines)) {
        case 0:
            return TIP_0;
        case 1:
            return TIP_1;
        case 2:
            return TIP_2;
        case 3:
            return TIP_3;
        case 4:
            return TIP_4;
        case 5:
            return TIP_5;
        case 6:
            return TIP_6;
        case 7:
            return TIP_7;
        case 8:
            return TIP_8;
    }
}

void Game::movementControl() {
    //std::cout << "\n\n\n\n\n\n\n" << curPosX << " " << curPosY << "\n";
    auto cmd = Controller::GetCommand();
    auto type = Game::GetTypePos(curPosX, curPosY);
    OBJECT_TYPE type2 = type;
    switch (cmd) {
        case Controller::MOVEMENT::LEFT:
            type2 = Game::GetTypePos(curPosX, std::max(1, curPosY-1));
            Print::MoveCursor(curPosX, curPosY, type, curPosX, std::max(1, curPosY-1), type2);
            curPosY = std::max(1, curPosY-1);
            return;
        case Controller::MOVEMENT::RIGHT:
            type2 = Game::GetTypePos(curPosX, std::min(m, curPosY+1));
            Print::MoveCursor(curPosX, curPosY, type, curPosX, std::min(m, curPosY+1), type2);
            curPosY = std::min(m, curPosY+1);
            return;
        case Controller::MOVEMENT::UP:
            type2 = Game::GetTypePos(std::max(curPosX-1, 1), curPosY);
            Print::MoveCursor(curPosX, curPosY, type, std::max(1, curPosX-1), curPosY, type2);
            curPosX = std::max(1, curPosX-1);
            return;
        case Controller::MOVEMENT::DOWN:
            type2 = Game::GetTypePos(std::min(curPosX+1, n), curPosY);
            Print::MoveCursor(curPosX, curPosY, type, std::min(n, curPosX+1), curPosY, type2);
            curPosX = std::min(n, curPosX+1);
            return;
        case Controller::MOVEMENT::DIG:
            wasFirstMove = 1;
            if((table[curPosX][curPosY] & mines) != 0)
                Game::LosePrint();

            Game::OpenCell(curPosX, curPosY);
            return;
        case Controller::MOVEMENT::FLAGPUT:
            if((table[curPosX][curPosY] & used) != 0) return;
            if((table[curPosX][curPosY] & flag) != 0){
                table[curPosX][curPosY] ^= flag;
                Print::RemoveFlag(curPosX, curPosY, Game::GetTypePos(curPosX, curPosY), REGULAR);
                Print::MoveCursor(curPosX, curPosY, type, curPosX, curPosY, OBJECT_TYPE::HIDDEN);
            }else {
                table[curPosX][curPosY] |= flag;
                Print::PutFlag(curPosX, curPosY);
                Print::MoveCursor(curPosX, curPosY, type, curPosX, curPosY, OBJECT_TYPE::FLAG);
            }
            return;
        default:
            return;
    }
}

void Game::Play() {
    Console::Clear();
    Print::PrintString("Please enter n, m, count of mines\n");
    Game::n = Console::In();
    Game::m = Console::In();
    Game::minesCount = Console::In();
    Keyboard::GetKey();
    Console::Clear();

    Print::removeConsoleCursor();
    Game::InitMap(n, m);
    Game::PrintMap();
    Game::PrintCircuit();
    Print::PrintCursor(curPosX, curPosY, HIDDEN);

    while(!Game::wasFirstMove){
        Game::movementControl();
    }

    Game::InitGame(n, m, minesCount, curPosX, curPosY);
    while(cellsTillVictory > 0){
        Game::movementControl();
    }

    Print::PrintWin();
    Keyboard::GetKey();
    Print::addConsoleCursor();
    Console::Clear();
}

void Game::LosePrint() {
    Console::Clear();
    Game::PrintCircuit();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            Game::LosePrintCurCell(i, j);
        }
    }
    Print::addConsoleCursor();
    Keyboard::GetKey();
    exit(0);
}

void Game::LosePrintCurCell(int x, int y) {
    if((table[x][y] & mines) != 0){
        if((table[x][y] & flag) != 0)
            Print::PrintLose(x, y, MINEGREEN);
        else
            Print::PrintLose(x, y, MINERED);
    }else {
        Game::PrintPos(x, y);
    }
}

void Game::PrintCircuit(){
    for(int i = 1; i <= m; i++) Print::PrintChar(0, i, "━");
    for(int i = 1; i <= m; i++) Print::PrintChar(n+1, i, "━");
    for(int i = 1; i <= n; i++) Print::PrintChar(i, m+1, "┃");
    for(int i = 1; i <= n; i++) Print::PrintChar(i, 0, "┃");
    Print::PrintChar(n+1, 0, "┗");
    Print::PrintChar(0, m+1, "┓");
    Print::PrintChar(n+1, m+1, "┛");
    Print::PrintChar(0, 0, "┏");
}