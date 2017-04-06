default: main

main.o: main.cpp
	g++ -Wall -g -ILib -c main.cpp -o main.o -O3

main: main.o
	g++ -LLib main.o -o bin/debug/TCC -lBox2D

clean:
	-rm -f main.o