tictactoe.out: tictactoe.o tinyboard.o board.o bigboard.o
	g++ -g -Wall -o tictactoe.out tictactoe.o tinyboard.o board.o bigboard.o

tictactoe.o: tictactoe.cpp tictactoe.h tinyboard.h board.h bigboard.h
	g++ -g -Wall -c tictactoe.cpp

board.o: board.cpp board.h
	g++ -g -Wall -c board.cpp

tinyboard.o: tinyboard.cpp tinyboard.h board.h
	g++ -g -Wall -c tinyboard.cpp

bigboard.o: bigboard.cpp bigboard.h board.h
	g++ -g -Wall -c bigboard.cpp

clean:
	rm -f tictactoe.out tictactoe.o tinyboard.o board.o bigboard.o
