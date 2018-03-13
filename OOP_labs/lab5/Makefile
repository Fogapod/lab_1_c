.PHONY: all build rebuild clean run

all: build run


clean:
	rm -f bin/*
	find . -name "*.o"   -type f -delete
	find . -name "*.out" -type f -delete
	find . -name "*.swp" -type f -delete

rebuild: clean build

run:
	bin/vector

main.o: main.cpp
	g++ -Wall -c -o main.o main.cpp

vector.o: vector.cpp
	g++ -Wall -c -o vector.o vector.cpp

build: main.o vector.o
	mkdir -p bin
	g++ -Wall -o bin/vector main.o vector.o
