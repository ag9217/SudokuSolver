#include <iostream>
#include <fstream>
using namespace std;

//function prototypes
int checkColumn(int col, int board[][9], int tempSol);
int checkRow(int row, int board[][9], int tempSol);
int checkSquare(int row, int col, int board[][9], int tempSol);
int isValid(int row, int col, int board[][9], int tempSol);
void printS(int board[][9]);


int main()
{
    //delcaring variables
    bool solved = 0;
    int tempSolution = 1;
    int backtracked = 0; //checking if a backtrack has been done
    int backtracks = 0; //counting number of backtracks

    int board[9][9];
    int refBoard[9][9];

    // -----CONFIGURATING BOARD-----
    ifstream sconfig("../config/config.txt");

    //temp variables
    int itemp;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            sconfig >> itemp; //reading numbers from config file
            board[i][j] = itemp;
            if(itemp == 0);              
        }
    }

    // -----COPYING BOARD TO REFBOARD-----
    //This is a board to check whether a number is meant to be altered or not
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] > 0)
            {
                refBoard[i][j] = 1;
            }
            else
            {
                refBoard[i][j] = 0;
            }
            
        }
    }

    // -----PRINTING BOARD-----
    printS(board);

    // -----SOLVING BOARD-----
    while(!solved)
    {
        int i = 0;
        int j = 0;

        for(i = 0; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
            {
                if(refBoard[i][j] == 1 && backtracked)
                {
                    backtracks++; //incrementing number of backtracks
                    if(j == 0) //Situation where program is at left most number on board
                    {
                        i--;
                        j = 7; // this value will be added with 1
                        tempSolution = board[i][8] + 1;
                    }
                    else
                    {
                        j = j - 2;
                        tempSolution = board[i][j+1] + 1;
                    }
                }
                else if(refBoard[i][j] == 1)
                {
                    continue;
                }
                else if(tempSolution == 10) //backtracking
                {
                    backtracked = 1;
                    backtracks++;
                    if(j == 0) //Situation where program is at left most number on board
                    {
                        board[i][j] = 0;
                        i--;
                        j = 7; // this value will be added with 1
                        tempSolution = board[i][8] + 1;
                    }
                    else
                    {
                        board[i][j] = 0;
                        j = j - 2;
                        tempSolution = board[i][j+1] + 1;
                    }
                    
                }
                else if(isValid(i,j,board,tempSolution)) //If the guess/temporary solution is valid
                {
                    board[i][j] = tempSolution;
                    tempSolution = 1;
                    backtracked = 0;
                }
                else //if guess is not valid
                {
                    tempSolution++;
                    backtracked = 0;
                    j--;
                }
                
            }
        }

        solved = 1;
        // -----PRINTING SOLVED BOARD-----
        cout << "-------------------" << endl;
        printS(board);
        cout << "Backtracks: " << backtracks << endl;

         do 
        {
            cout << '\n' << "Press enter to exit...";
        } while (cin.get() != '\n');

        return 0;
    }
}

int checkColumn(int col, int board[][9], int tempSol)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[i][col] == tempSol)
        {
            //cout << "same number in column" << endl;
            return 0; //check failed
        }
    }
    return 1; //what will be return if there are no numbers the same as tempSol
}

int checkRow(int row, int board[][9], int tempSol)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[row][i] == tempSol)
        {
            //cout << "same number in row" << endl;
            return 0; //check failed
        }
    }
    return 1; //what will be return if there are no numbers the same as tempSol
}

int checkSquare(int row, int col, int board[][9], int tempSol)
{
    int squareTopY = 3*(row/3);
    int squareTopX = 3*(col/3);

    for(int i = squareTopY; i < squareTopY + 3; i++)
    {
        for(int j = squareTopX; j < squareTopX + 3; j++)
        {
            if(board[i][j] == tempSol)
            {
                //cout << "same number in square" << endl;
                return 0; //check failed
            }
        }
    }
    return 1;
}

int isValid(int row, int col, int board[][9], int tempSol)
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

void printS(int board[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
}