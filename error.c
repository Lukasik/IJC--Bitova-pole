/*
* error.c
* IJC-DU1, příklad b), 25.2.2013
* Autor: Lukáš Vokráčko, FIT
* Přeloženo: gcc 4.7.2
*/

#include "error.h"

void Error(const char *fmt, ...)
{
	fprintf(stderr, "CHYBA: ");
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
}

void FatalError(const char *fmt, ...)
{
	fprintf(stderr, "CHYBA: ");
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	exit(1);
}