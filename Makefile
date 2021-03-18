.POSIX:

CC=gcc
CFLAGS=-lX11

st-bg-event: main.c
	$(CC) main.c -o $@ $(CFLAGS)
