default: main

main.o: main.cpp
	g++ -Wall -g -ILib -c main.cpp -o main.o  -ftree-vectorize -Rpass=loop-vectorize -O2

main: main.o
	g++ -LLib main.o -o bin/debug/TCC -lBox2D -ftree-vectorize -Rpass=loop-vectorize -O2

clean:
	-rm -f main.o