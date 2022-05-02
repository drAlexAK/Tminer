#include <iostream>
//#include "Font.h"
//#include "Console.h"
#include "Print.h"

using namespace std;

int main() {

    Print::PutFlag(2, 2);
    int a;
    cin >> a;
    Print::PrintCursor(2, 2, FLAG);
    cin >> a;
    Print::RemoveFlag(2, 2, TIP_2, REGULAR);

    return 0;
}
 
