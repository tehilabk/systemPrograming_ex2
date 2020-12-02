CC = gcc
FLAGS = -Wall -g
AR=ar

all: libmyBank.a mains 

main.o: main.c myBank.c myBank.h
	$(CC) $(FLAGS) -c main.c

mains: main.o libmyBank.a
	$(CC) $(FLAGS) -o mains main.o libmyBank.a

libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c				


.PHONY: clean all

clean:
	rm -f mains *.a *.o