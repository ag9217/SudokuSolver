# SudokuSolver
Graphical Sudoku Solver written in C++ with SFML/TGUI. The solver uses a bruteforce algorithm to solve Sudoku puzzles.

# Usage
In order to run the the solver, [SFML](https://www.sfml-dev.org/) and [TGUI](https://tgui.eu/) need be installed. In order to install the libraries on Linux, run the following commands:

To install SFML
```
sudo apt-get install libsfml-dev
```
To Install TGUI (you need to add a PPA to your system)
```
sudo add-apt-repository ppa:texus/tgui-0.8
sudo apt-get update
sudo apt-get install libtgui-dev
```

To compile the program, simply run the Makefile in the src directory or to compile with g++ (in src directory):
```
g++ -std=c++14 main.cpp -ltgui -lsfml-graphics -lsfml-window -lsfml-system -o sudoku
```

To run the program:
```
./sudoku
```
