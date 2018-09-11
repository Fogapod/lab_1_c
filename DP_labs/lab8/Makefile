.PHONY: all build rebuild clean run

all: build run


clean:
	rm -f bin/*
	find . -name "*.o"   -type f -delete
	find . -name "*.out" -type f -delete
	find . -name "*.swp" -type f -delete

rebuild: clean build

run:
	bin/run

main.o: main.cpp
	g++ -Wall -c -o main.o main.cpp

build: main.o
	mkdir -p bin
	g++ -Wall -o bin/run main.o
