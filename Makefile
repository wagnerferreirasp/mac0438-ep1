CFLAGS= -lm

all: clean EP1

EP1: main.o processo1.o processo2.o processo3.o processo4.o 
	gcc -o EP1 main.o processo1.o processo2.o processo3.o processo4.o $(CFLAGS)

main.o: main.c
	gcc -o main.o -c main.c $(CFLAGS)

processo1.o: processo1.c processo1.h
	gcc -o processo1.o -c processo1.c $(CFLAGS)

processo2.o: processo2.c processo2.h
	gcc -o processo2.o -c processo2.c $(CFLAGS)

processo3.o: processo3.c processo3.h
	gcc -o processo3.o -c processo3.c $(CFLAGS)

processo4.o: processo4.c processo4.h
	gcc -o processo4.o -c processo4.c $(CFLAGS)

clean: 
	rm -f EP1
	rm -f *.o
