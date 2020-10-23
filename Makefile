CC = gcc
CFLAGS = -Os

HEADERS = maze-defs.h
OBJS = maze-allocation.o maze-operations.o main.o

%.o : %.c %(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)
all : walls
walls : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY : clean
clean :
	-rm walls $(OBJS)
