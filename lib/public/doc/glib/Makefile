CC = c99

programs = hello hash

all : $(programs)

hello: hello.c
	$(CC) -Wall `pkg-config --cflags --libs glib` -o $@ $^

hash: hash.c
	$(CC) -Wall `pkg-config --cflags --libs glib` -o $@ $^

.PHONY : clean
clean :
	rm -f *~ $(programs)
