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
int isValid(int row, int col, Board board, int tempSol);

int main()
{
    bool solved = 0;
    int tempSolution = 1;

    Board myboard;
    myboard.set();
    myboard.draw();

    while(!solved)
    {
        int i = 0;
        int j = 0;
        for(i = 0; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
            {
                if(tempSolution == 10) //backtrack
                {
                    if(j == 0)
                    {
                        i--;
                        j = 7; // this value will be added with 1
                        tempSolution = 1;
                    }
                    else
                    {
                        j = j - 2;
                        tempSolution = 1;
                    }
                }

                else if(myboard.getBoardN(i,j).getSolved())
                {
                    tempSolution = 1;
                    continue;
                }

                else if(isValid(i,j,myboard,tempSolution))
                {
                    myboard.getBoardN(i,j).setNumber(tempSolution);
                    tempSolution = 1;    
                }
                
                else
                {
                    tempSolution++;
                }
            }
        }
        cout << "-------------------" << endl;
        myboard.draw();
        cout << "solved" << endl;
        solved = 1;
    }
    

    return 0;
}

int checkColumn(int col, Board board, int tempSol)
{
    for(int i = 0; i < 9; i++)
    {
        if(board.getBoardN(i, col).getNumber() == tempSol)
        {
            //cout << "same number in column" << endl;
            return 0; //check failed
        }
    }
    return 1; //what will be return if there are no numbers the same as tempSol
}

int checkRow(int row, Board board, int tempSol)
{
    for(int i = 0; i < 9; i++)
    {
        if(board.getBoardN(row, i).getNumber() == tempSol)
        {
            //cout << "same number in row" << endl;
            return 0; //check failed
        }
    }
    return 1; //what will be return if there are no numbers the same as tempSol
}

int checkSquare(int row, int col, Board board, int tempSol)
{
    int squareTopY = 3*(row/3);
    int squareTopX = 3*(col/3);

    for(int i = squareTopY; i < squareTopY + 3; i++)
    {
        for(int j = squareTopX; j < squareTopX + 3; j++)
        {
            if(board.getBoardN(i,j).getNumber() == tempSol)
            {
                //cout << "same number in square" << endl;
                return 0; //check failed
            }
        }
    }
    return 1;
}

int isValid(int row, int col, Board board, int tempSol)
{
    if(checkColumn(col, board, tempSol) && checkRow(row, board, tempSol) && checkSquare(row,col, board, tempSol))
    {
        return 1;
    }

    else
    {
        return 0;
    }
    
}