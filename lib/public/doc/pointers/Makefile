CFLAGS = -Wall -std=c99
LDLIBS = -lm

sources = swap.c str_len.c str_len2.c pfun.c \
  doubles_sort.c sort.c psort.c cdate.c

objects = $(patsubst %.c,%.o,$(sources))

programs = $(patsubst %.c,%,$(sources))

all : $(programs)


.PHONY : clean
clean :
	-rm -f *~ $(programs)
