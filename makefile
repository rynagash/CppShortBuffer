main: main.o ShortBuffer.o
	g++ main.o ShortBuffer.o -o main
	
main.o: main.cpp
	g++ -c main.cpp -o main.o
	
ShortBuffer.o: ShortBuffer.cpp
	g++ -c ShortBuffer.cpp -o ShortBuffer.o

clean:
	rm -f *.o
	rm -f main

run:
	./main
