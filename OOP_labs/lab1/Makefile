.PHONY: all build rebuild clean run

all: build run


clean:
	rm -f bin/complex
	find . -name "*.o"   -type f -delete
	find . -name "*.out" -type f -delete
	find . -name "*.swp" -type f -delete

rebuild: clean build

run:
	bin/complex

Complex.o: Complex.cpp
	g++ -Wall -c -o Complex.o Complex.cpp

main.o: main.cpp
	g++ -Wall -c -o main.o main.cpp

build: Complex.o main.o
	g++ -Wall -o bin/complex Complex.o  main.o
