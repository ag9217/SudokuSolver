#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "..\include\sNumber.h" //sudoku number class
#include "..\include\board.h" //sudoku board class
using namespace std;

//function prototypes
int checkColumn(int col, Board board, int tempSol);
int checkRow(int row, Board board, int tempSol);
int checkSquare(int row, int col, Board board, int tempSol);

int main()
{
    bool solved = 0;
    int tempSolution = 2;

    Board myboard;
    myboard.set();
    myboard.draw();

    checkSquare(5,5, myboard, tempSolution);
    return 0;
}

int checkColumn(int col, Board board, int tempSol)
{
    for(int i = 1; i < 10; i++)
    {
        if((*board.getBoardP(i, col)).getNumber() == tempSol)
        {
            cout << "same number in column" << endl;
            return 0; //check failed
        }
    }
    return 1; //what will be return if there are no numbers the same as tempSol
}

int checkRow(int row, Board board, int tempSol)
{
    for(int i = 1; i < 10; i++)
    {
        if((*board.getBoardP(row, i)).getNumber() == tempSol)
        {
            cout << "same number in row" << endl;
            return 0; //check failed
        }
    }
    return 1; //what will be return if there are no numbers the same as tempSol
}

int checkSquare(int row, int col, Board board, int tempSol)
{
    int squareTopY = 3*((row-1)/3);
    int squareTopX = 3*((col-1)/3);

    for(int i = squareTopY+1; i < squareTopY + 4; i++)
    {
        for(int j = squareTopX+1; j < squareTopX + 4; j++)
        {
            if((*board.getBoardP(i,j)).getNumber() == tempSol)
            {
                cout << "same number in square" << endl;
                return 0; //check failed
            }
        }
    }
}