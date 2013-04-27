/*
* ppm.c
* IJC-DU1, příklad b), 25.2.2013
* Autor: Lukáš Vokráčko, FIT
* Přeloženo: gcc 4.7.2
*/

#include "ppm.h"

void ppmFree(ppm* p)
{
	free(p->data);
	free(p);
}

ppm* ppm_read(const char * filename)
{
	FILE* ppmFile;
	ppm* ppmStruct;
	int scannedChar;
	int variablesRead, i = 0;
	unsigned long xsize, ysize;

	ppmFile = fopen(filename, "rb");
	if(ppmFile == NULL)
	{
		Error("Soubor nelze otevřít\n");
		return NULL;
	}

	variablesRead = fscanf(ppmFile, "P6 %lu %lu 255 ", &xsize, &ysize);
	if(variablesRead == 2 && ysize > 0 && xsize > 0)
	{
		ppmStruct = (ppm*) malloc(sizeof(ppm) + sizeof(char) * xsize * ysize * 3);

		if(ppmStruct != NULL)
		{
			ppmStruct->ysize = ysize;
			ppmStruct->xsize = xsize;

			while((scannedChar = fgetc(ppmFile)) != EOF)
			{
				ppmStruct->data[i++] = (char) scannedChar;
			}
		}
		else
		{
			fclose(ppmFile);
			ppmFree(ppmStruct);
			Error("Nedostatek paměti\n");
			return NULL;
		}
	}
	else
	{
		Error("Chybný formát\n");
		return NULL;
	}

	fclose(ppmFile);
	return ppmStruct;

}

int ppm_write(ppm *p, const char * filename)
{
	if(p == NULL)
	{
		Error("Není co zapsat\n");
		return -1;
	}
	FILE* ppmFile;
	int size = p->xsize * p->ysize * 3;

	ppmFile = fopen(filename, "wb");
	if(ppmFile == NULL)
	{
		Error("Soubor nelze vytvořit\n");
		return -1;
	}

	fprintf(ppmFile, "P6\n%lu %lu\n255\n", p->xsize, p->ysize);

	for(int i = 0; i < size; ++i)
	{
		fputc(p->data[i], ppmFile);
	}

	fclose(ppmFile);
	return 0;
}