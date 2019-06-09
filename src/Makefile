output: main.o
	g++ main.o -o sudoku -lsfml-graphics -lsfml-window -lsfml-system -ltgui

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o sudoku