CFLAGS=

all: EP1

EP1: util.o main.o 
	gcc -o EP1 util.o main.o

main.o: main.c util.h
	gcc -o main.o -c main.c $(CFLAGS)

util.o:	util.c util.h
	gcc -o util.o -c util.c $(CFLAGS)

clean: 
	rm -f EP1
	rm -f *.o
