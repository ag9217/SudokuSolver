#include <iostream>
#include <fstream>
#include <string>
#include "..\include\sNumber.h" //sudoku number class
#include "..\include\board.h" //sudoku board class
using namespace std;

int main()
{
    bool solved = 0;

    Board myboard;
    myboard.set();
    myboard.draw(); //drawing board

    sNumber a(5);
    cout << (a.getNumber()) << endl;

    return 0;
}