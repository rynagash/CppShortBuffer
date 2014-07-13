main: main.o ShortBuffer.o ShortBufferContainer.o
	g++ main.o ShortBuffer.o ShortBufferContainer.o -o main
	
main.o: main.cpp
	g++ -c main.cpp -o main.o
	
ShortBufferContainer.o: ShortBufferContainer.cpp
	g++ -c ShortBufferContainer.cpp -o ShortBufferContainer.o
	
ShortBuffer.o: ShortBuffer.cpp
	g++ -c ShortBuffer.cpp -o ShortBuffer.o

clean:
	rm -f *.o
	rm -f main

run:
	./main
