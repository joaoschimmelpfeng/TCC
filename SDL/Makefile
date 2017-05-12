default: clean compile link

compile: src/*.cpp
	g++ -Wall src/*.cpp  -c 
	mv *.o build

link:
	 g++ -Wall build/*.o -o bin/debug/out -framework SDL2 -F Lib

rund: 
	./bin/debug/out

clean:
	-rm -f build/*.o
	-rm -f sdlTest.o
	-rm -f bin/debug/out