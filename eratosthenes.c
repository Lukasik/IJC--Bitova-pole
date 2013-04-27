/*
* eratosthenes.c
* IJC-DU1, příklad a), 25.2.2013
* Autor: Lukáš Vokráčko, FIT
* Přeloženo: gcc 4.7.2
*/

#include "eratosthenes.h"

void Eratosthenes(BitArray_t pole)
{
	double upToSqrt = sqrt(BitArraySize(pole));

	for(int j = 2; j < upToSqrt; ++j)
	{
		if(GetBit(pole, j) == 0)
		{
			for(int i = j*2; i < BitArraySize(pole); i += j)
			{
				SetBit(pole, i, 1);
			}
		}
	}
}