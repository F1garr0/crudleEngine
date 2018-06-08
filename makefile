all: main clean

clean:
	rm main.o
	rm gamestate.o
	rm gamestatemachine.o
	rm playingstate.o
	rm mainmenustate.o

main: main.o gamestate.o gamestatemachine.o mainmenustate.o playingstate.o
	g++ main.o gamestate.o gamestatemachine.o mainmenustate.o playingstate.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lboost_system -lboost_filesystem
	
main.o: main.cpp
	g++ -c main.cpp

gamestate.o: gamestate.cpp gamestate.h
	g++ -c gamestate.cpp

gamestatemachine.o: gamestatemachine.cpp gamestatemachine.h
	g++ -c gamestatemachine.cpp

playingstate.o: playingstate.cpp playingstate.h
	g++ -c playingstate.cpp

mainmenustate.o: mainmenustate.cpp mainmenustate.h
	g++ -c mainmenustate.cpp