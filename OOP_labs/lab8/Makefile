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

human.o: Human.cpp
	g++ -Wall -c -o human.o Human.cpp

student.o: Student.cpp
	g++ -Wall -c -o student.o Student.cpp

complex.o: Complex.cpp
	g++ -Wall -c -o complex.o Complex.cpp

car.o: Car.cpp
	g++ -Wall -c -o car.o Car.cpp

build: human.o student.o complex.o car.o main.o
	mkdir -p bin
	g++ -Wall -o bin/run human.o student.o complex.o car.o main.o
