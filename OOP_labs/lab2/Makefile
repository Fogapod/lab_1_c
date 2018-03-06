.PHONY: all build rebuild clean run

all: build run


clean:
	rm -f bin/*
	find . -name "*.o"   -type f -delete
	find . -name "*.out" -type f -delete
	find . -name "*.swp" -type f -delete

rebuild: clean build

run:
	bin/f_pointers

main.o: main.cpp
	g++ -Wall -c -o main.o main.cpp

build: main.o
	g++ -Wall -o bin/f_pointers main.o
