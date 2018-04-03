.PHONY: all build rebuild clean run

all: build run


clean:
	rm -f bin/*
	find . -name "*.o"   -type f -delete
	find . -name "*.out" -type f -delete
	find . -name "*.swp" -type f -delete

rebuild: clean build

run:
	bin/animals

main.o: main.cpp
	g++ -Wall -c -o main.o main.cpp

animal.o: animal.cpp
	g++ -Wall -c -o animal.o animal.cpp

cat.o: cat.cpp
	g++ -Wall -c -o cat.o cat.cpp

dog.o: dog.cpp
	g++ -Wall -c -o dog.o dog.cpp

build: main.o animal.o cat.o dog.o
	mkdir -p bin
	g++ -Wall -o bin/animals main.o animal.o cat.o dog.o
