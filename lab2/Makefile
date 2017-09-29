.PHONY: all clean

all: main

clean:
	rm -f bin/main
	find . -name "*.o"   -type f -delete
	find . -name "*.out" -type f -delete
	find . -name "*.swp" -type f -delete

daemon.o: daemon.c
	gcc -Wall -c -o daemon.o   daemon.c

logger.o: logger.c
	gcc -Wall -c -o logger.o   logger.c

main: daemon.o logger.o
	gcc -Wall    -o bin/main daemon.o logger.o
