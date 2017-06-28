files = main.cpp GameLogic.cpp GameLogic.h UserInput.cpp UserInput.h enums.h
settings = clang++ -std=c++11 -lncurses

main: $(files)
	$(settings) $(files)
	./a.out

