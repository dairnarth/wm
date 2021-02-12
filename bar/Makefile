PREFIX?=/usr/X11R6
CFLAGS?=-Os -pedantic -Wall

all:
	$(CC) $(CFLAGS) -I$(PREFIX)/include bar.c -L$(PREFIX)/lib -lX11 -o bar

clean:
	rm -f bar

