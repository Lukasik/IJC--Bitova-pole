/*
* error.h
* IJC-DU1, příklad b), 25.2.2013
* Autor: Lukáš Vokráčko, FIT
* Přeloženo: gcc 4.7.2
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void Error(const char *fmt, ...);
void FatalError(const char *fmt, ...);