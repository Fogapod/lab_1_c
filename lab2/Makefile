.PHONY: all rebuild clean

all: main

clean:
	rm -rf bin/*
	find . -name "*.o"   -type f -delete
	find . -name "*.out" -type f -delete
	find . -name "*.swp" -type f -delete
	find . -name "*.log" -type f -delete

rebuild: clean all


logger.o: logger.c
	gcc -Wall -c -o logger.o logger.c

daemon.o: daemon.c
	gcc -Wall -c -o daemon.o daemon.c

main.o: main.c
	gcc -Wall -c -o main.o main.c

main: logger.o  daemon.o main.o
	gcc -Wall -o bin/main logger.o daemon.o main.o
