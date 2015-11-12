all: Chapter1.o main.o
	g++ -std=c++11 -o test.x Chapter1.o main.o
Chapter1.o: Chapter1.cpp Chapter1.h
	g++ -std=c++11 -c Chapter1.cpp
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
clean:
	rm *.o test.x
