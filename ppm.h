/*
* ppm.h
* IJC-DU1, příklad b), 25.2.2013
* Autor: Lukáš Vokráčko, FIT
* Přeloženo: gcc 4.7.2
*/

#include "eratosthenes.h"

typedef struct
{
	unsigned long xsize;
	unsigned long ysize;
	char data[];
} ppm;

void ppmFree(ppm* p);
ppm* ppm_read(const char * filename);
int ppm_write(ppm *p, const char * filename);