#Makefile for roman numeral calculator
C=gcc

LIBS = `pkg-config --cflags --libs check`

CFLAGS=-c -Wall 

all : romancal


test : romancal-tests
	./romancal-tests

romancal-tests: romancal.o romancal.h romancal-tests.o
	$(C) -g romancal-tests.o romancal.o romancal.h -o romancal-tests $(LIBS)

romancal : romancal.c romancal.h test
	$(C) $(CFLAGS) romancal.c


rtests.o: romancal-tests.c
	$(C) $(CFLAGS) romancal-tests.c 

clean:
	rm -rf *o romancal-tests
