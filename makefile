all: main clean

install: main

clean:
	rm *.o

main: obj
	g++ main.o gamestate.o gamestatemachine.o mainmenustate.o playingstate.o menubutton.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lboost_system -lboost_filesystem
	
obj:
	g++ -c *.cpp -Wno-enum-compare -Wno-deprecated-declarations