#include <iostream>
#include <fstream>
#include "..\include\sNumber.h" //sudoku number class
#include "..\include\board.h" //sudoku board class
using namespace std;

//function prototypes
void configinput();

int main()
{
    bool solved = 0;

    Board myboard;
    myboard.draw();

    while (!solved)
    {
        return 0;
    }
}

void configiniput()
{
    //delcaring variables
    ifstream sudokuc;

    sudokuc.open("config.txt");
}