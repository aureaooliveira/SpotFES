all: pre-build main

INCLUDEDIR = include/

CC = gcc
CFLAGS = -lm -g -Wno-everything -pthread -I $(INCLUDEDIR)

BUILDDIR = build/
SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=build/%.o)

$(BUILDDIR)%.o : %.c
	$(CC) -c $< -o $@ $(CFLAGS)

main: $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

pre-build:
	- mkdir -p $(BUILDDIR)

clean:
	rm -f main main-debug