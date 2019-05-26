#include <iostream>
#include "..\include\sNumber.h"
using namespace std;

//function prototypes
void printboard(sNumber *board[11][11]);

int main()
{
    cout << "Hello" << endl;
    bool solved = 0;

    sNumber *board[11][11];

    //filling board with zeroes and border with 0's
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if(i == 0 || i == 10 || j == 0 || j == 10) //creating special case for border
            {
                board[i][j] = new sNumber(0);
                continue;
            }
            board[i][j] = new sNumber(1);
        }
    }

    printboard(board);

    while (!solved)
    {
        return 0;
    }
}

void printboard(sNumber *board[11][11]) //IMPLEMENT INTO CLASS
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cout << "|" << (*board[i][j]).getNumber();
        }
        cout << "|" << endl;
    }
}