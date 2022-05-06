# tMiner
terminal miner game
## How to build
### for linux
`` g++ -o tMiner ./main.cpp ./Game.cpp ./Print.cpp ./Console.cpp ./Font.cpp ./Controller.cpp ./Keyboard.cpp ``
### for windows 
`` i686-w64-mingw32-g++ -o tMiner ./main.cpp ./Game.cpp ./Print.cpp ./ConsoleW.cpp ./Font.cpp ./Controller.cpp ./KeyboardW.cpp -static-libgcc -static-libstdc++ ``
## How to play
* specify map demention and quantity of mines
* use ``arrows`` to navigate
* ``Enter`` to set up flag
* ``Space`` to reveal field 
