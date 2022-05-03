#include "Game.h"

using namespace std;

int main() {
    Print::removeConsoleCursor();
    Game::InitGame(20, 20, 50, 1, 1);
    while(1){
        Game::movementControl();
    }
    Print::addConsoleCursor();
    return 0;
}
