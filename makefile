files = main.cpp GameLogic.cpp GameLogic.h
settings = g++ -lncurses

main: $(files)
	$(settings) $(files)
	./a.out

