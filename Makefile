OBJS = maze-allocation.o maze-operations.o main.o
DEPS = $(OBJS:.o=.d)

vpath %.c $(dir $(MAKEFILE_LIST))

CFLAGS = -Os
CFLAGS += -MMD -MP

all : walls
walls : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY : clean
clean :
	$(RM) walls $(OBJS) $(DEPS)

-include $(DEPS)
