flags = -O2 -std=c99 -Wall -pedantic

all: clean steg-decode prvocisla

error.o: error.c
	gcc error.c -c $(flags)

ppm.o: ppm.c
	gcc ppm.c -c $(flags)

eratosthenes.o: eratosthenes.c
	gcc eratosthenes.c -c $(flags)

prvocisla.o: prvocisla.c
	gcc prvocisla.c -c $(flags)

steg-decode.o: steg-decode.c
	gcc steg-decode.c -c $(flags)

steg-decode: ppm.o error.o steg-decode.o eratosthenes.o bit-array.h
	gcc error.o ppm.o steg-decode.o eratosthenes.o $(flags) -o steg-decode -lm

prvocisla: prvocisla.o error.o eratosthenes.o bit-array.h
	gcc prvocisla.o error.o eratosthenes.o $(flags) -pg -lm -o prvocisla
	gcc -DUSE_INLINE prvocisla.o error.o eratosthenes.o $(flags) -lm -o prvocisla-inline

clean:
	rm -f prvocisla prvocisla-inline steg-decode helper *.o

