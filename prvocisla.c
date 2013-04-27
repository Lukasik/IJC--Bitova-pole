/*
* prvocisla.c
* IJC-DU1, příklad a), 25.2.2013
* Autor: Lukáš Vokráčko, FIT
* Přeloženo: gcc 4.7.2
*/

#include "eratosthenes.h"

#define BITSIZE 89000000

int main(void)
{
	int i, times = 0;

	BitArray(e, BITSIZE);
	Eratosthenes(e);

	for(i = BitArraySize(e)-1; i > 2 && times < 10; --i)
	{
		if(GetBit(e, i) == 0) ++times;
	}

	for(i = i; i < BitArraySize(e) && times >= 0; ++i)
	{
		if(GetBit(e, i) == 0)
		{
			--times;
			printf("%d\n", i);
		}
	}

	return 0;
}