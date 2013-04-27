/*
* steg-decode.c
* IJC-DU1, příklad b), 26.2.2013
* Autor: Lukáš Vokráčko, FIT
* Přeloženo: gcc 4.7.2
*/

#include "ppm.h"
#include <ctype.h>

int main(int argc, char* argv[])
{
	char* fileName = NULL;
	if(argc != 2)
	{
		FatalError("Program musí být spuštěn s jedním parametrem - jménem souboru\n");
	}
	else
	{
		fileName = argv[1];
	}

	ppm* ppmStruct = ppm_read(fileName);
	int times = 0;
	int end = 0;
	char LSB;
	char secretChar = '\0';

	if(ppmStruct == NULL)
	{
		FatalError("Soubor se nepodařilo přečíst\n");
	}

	int size = ppmStruct->ysize*ppmStruct->xsize*3;

	//implementacní limit, nepodarilo se mi implementovat makro tak, aby pracovalo s počtem prvků jako proměnnou
	BitArray(bArray, 1000*1000*3);
	Eratosthenes(bArray);

	for(int i = 2; i < size; ++i)
	{
		if(GetBit(bArray, i) == 0)
		{
			LSB = ppmStruct->data[i] & 1;
			DU1_SET_BIT_(secretChar, times, LSB);
			++times;

			if(times % 8 == 0)
			{
				if(secretChar == '\0')
				{
					end = 1;
					break;
				}
				else if(!isprint(secretChar))
				{
					ppmFree(ppmStruct);
					FatalError("Obsahuje netisknutelné znaky\n");
				}
				times = 0;
				printf("%c", secretChar);
				secretChar = '\0';
				continue;
			}
		}
	}

	if(end == 0)
	{
		ppmFree(ppmStruct);
		FatalError("Řetězec neobsahuje ukončovací nulu\n");
	}

	return 0;
}