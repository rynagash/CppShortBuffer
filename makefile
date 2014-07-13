main: main.cpp
	g++ main.cpp -o main

clean:
	rm -f *.o
	rm -f main

run:
	./main
