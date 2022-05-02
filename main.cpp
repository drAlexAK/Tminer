#include "Game.h"

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    Game::InitGame(20, 20, 40, a, b);
    while(cin >> a >> b){
        Game::OpenCell(a, b);
    }
    return 0;
}
