#include <iostream>
#include <fstream>
#include <string>
#include <TGUI/TGUI.hpp>
using namespace std;

//function prototypes
int checkColumn(int col, int board[][9], int tempSol);
int checkRow(int row, int board[][9], int tempSol);
int checkSquare(int row, int col, int board[][9], int tempSol);
int isValid(int row, int col, int board[][9], int tempSol);
void printS(int board[][9]);
void solveSignal(tgui::EditBox::Ptr editBoxes[9][9]);
int solveBoard(int board[9][9], tgui::EditBox::Ptr editBoxes[9][9]);

int main()
{
    //------------------GUI-------------------
    sf::RenderWindow window{{270, 375}, "SudokuSolver", sf::Style::Titlebar | sf::Style::Close};
    tgui::Gui gui{window}; // Create the gui and attach it to the window

    //Solve Button
    tgui::Button::Ptr solveButton = tgui::Button::create();
    solveButton->setPosition(0,270);
    solveButton->setSize(270,105);
    solveButton->setText("Solve");
    gui.add(solveButton, "solvebutton");

    tgui::EditBox::Ptr editBoxes[9][9]; //textbox 2D-array
    for(unsigned int i = 0; i < 9; i++) //textboxes
    {
        for(unsigned int j = 0; j < 9; j++)
        {
            editBoxes[i][j] = tgui::EditBox::create();
            editBoxes[i][j]->setSize(30,30);
            editBoxes[i][j]->setMaximumCharacters(1);
            editBoxes[i][j]->setAlignment(tgui::EditBox::Alignment::Center);
            editBoxes[i][j]->setPosition(0 + 30 * i, 0 + 30 * j);

            std::string si = std::to_string(i);
            std::string sj = std::to_string(j);

            gui.add(editBoxes[i][j], si + sj);
        }
    }

    solveButton->connect("pressed", solveSignal, std::ref(editBoxes));

    // -----CONFIGURATING BOARD-----
    ifstream sconfig("../config/config.txt");

    //temp variables
    int itemp;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            sconfig >> itemp; //reading numbers from config file
            editBoxes[j][i]->setText(std::to_string(itemp));
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            gui.handleEvent(event); // Pass the event to the widgets
        }

        window.clear();
        gui.draw(); // Draw all widgets
        window.display();
    }
}

int checkColumn(int col, int board[][9], int tempSol)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[i][col] == tempSol)
        {
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
            std::cout << "|" << board[i][j];
        }
        std::cout << "|" << endl;
    }
}

void solveSignal(tgui::EditBox::Ptr editBoxes[9][9])
{
    std::string temp;
    std::string temp1;
    int itemp;
    int board[9][9];

    //resetting board
    for(unsigned int i = 0; i < 9; i++)
    {
        for(unsigned int j = 0; j < 9; j++)
        {
            board[i][j] = 0;
        }
    }

    for(unsigned int i = 0; i < 9; i++)
    {
        for(unsigned int j = 0; j < 9; j++)
        {
            temp = editBoxes[j][i]->getText(); //board is flipped when putting in data from gui
            itemp = stoi(temp);

            board[i][j] = itemp;
        }
    }
    solveBoard(board, editBoxes);
}

int solveBoard(int board[9][9],tgui::EditBox::Ptr editBoxes[9][9])
{
    //------------------SOLVING SUDOKU-------------------
    //delcaring variables
    bool solved = 0;
    int tempSolution = 1;
    int backtracked = 0; //checking if a backtrack has been done
    int backtracks = 0; //counting number of backtracks
    int refBoard[9][9];

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
        std::cout << "-------------------" << endl;
        printS(board);
        std::cout << "Backtracks: " << backtracks << endl;

        for(unsigned int i = 0; i < 9; i++)
        {
            for(unsigned int j = 0; j < 9; j++)
            {
                editBoxes[i][j]->setText(std::to_string(board[j][i])); //editBoxes is flipped
            }
        }
        return 1;
    }

    return 0;
}