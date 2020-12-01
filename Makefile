CC = gcc
FLAGS = -Wall -g
AR=ar

all: libmyBank.so libmyBank.a mains maind

main.o: main.c myBank.c myBank.h
	$(CC) $(FLAGS) -c main.c

mains: main.o libmyBank.a
	$(CC) $(FLAGS) -o mains main.o libmyBank.a

maind: main.o 
	$(CC) $(FLAGS) -o maind main.o ./libmyBank.so

libmyMath.a: myBank.o
	$(AR) -rcs libmyMath.a myBank.o

libmyMath.so: myBank.o
	$(CC) -shared -o libmyBank.so myBank.o

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c				


.PHONY: clean all

clean:
	rm -f mains maind *.a *.so *.o