edit:Sudoku.o giveQuestion transform solve
Sudoku.o:Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

giveQuestion:giveQuestion.o Sudoku.o
	g++ -o giveQuestion giveQuestion.o Sudoku.o

transform:transform.o Sudoku.o
	g++ -o transform transform.o Sudoku.o

solve:solve.o Sudoku.o
	g++ -o solve solve.o Sudoku.o
