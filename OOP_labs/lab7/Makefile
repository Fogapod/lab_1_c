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

boss.o: Boss.cpp
	g++ -Wall -c -o boss.o Boss.cpp

build: main.o human.o student.o boss.o
	mkdir -p bin
	g++ -Wall -o bin/run main.o human.o student.o boss.o
