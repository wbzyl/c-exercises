CFLAGS = -Wall -std=c11
CC = gccx

sources = stack.h stack2.c stack1.c stack.c rpn-simulation.c
programs = rpn2 rpn1 rpn

all : rpn rpn1 rpn2

stack2.o : stack2.c stack.h
stack1.o : stack1.c stack.h
stack.o : stack.c stack.h
rpn-simulation.o : rpn-simulation.c

rpn2 : rpn-simulation.o stack2.o
	$(CC) -o $@ $^
rpn1 : rpn-simulation.o stack1.o
	$(CC) -o $@ $^
rpn : rpn-simulation.o stack.o
	$(CC) -o $@ $^


.PHONY : clean

clean:
	rm -f core *.o *~ \#* $(programs)
