PREFIX?=/usr/X11R6
CFLAGS?=-Os -pedantic -Wall

all:
	$(CC) $(CFLAGS) -I$(PREFIX)/include tiling.c -L$(PREFIX)/lib -lX11 -o tiling

clean:
	rm -f tiling

