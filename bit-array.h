/*
* bit-array.h
* IJC-DU1, příklad a), 25.2.2013
* Autor: Lukáš Vokráčko, FIT
* Přeloženo: gcc 4.7.2
*/

#include "error.h"
#include <strings.h>

typedef unsigned long * BitArray_t;

#define LONGLENGTH (sizeof(unsigned long)*8)

#define BitArray(jmeno_pole, velikost) \
	unsigned long jmeno_pole[velikost/LONGLENGTH+2] = {velikost}

#define DU1_GET_BIT_(p, i) \
	(((p) | (1UL << ((i) % (sizeof(p)*8)))) == (p))

#define DU1_SET_BIT_(p, i, b) \
	(((b) == 0) \
			? ((p) &= ~(1UL<<((i) % (sizeof(p)*8))))\
			: ((p) |= (1UL<<((i) % (sizeof(p)*8))))\
	)

	// bzero(jmeno_pole, (velikost)/LONGLENGTH + 1);

#ifndef USE_INLINE

	#define BitArraySize(jmeno_pole) \
		jmeno_pole[0]

	#define SetBit(jmeno_pole, index, vyraz) \
		((BitArraySize(jmeno_pole) > (index)) \
			? DU1_SET_BIT_(jmeno_pole[((index) / LONGLENGTH)+1], index, (vyraz)) \
			: (FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long) BitArraySize(jmeno_pole)-1), -1)\
		)

	#define GetBit(jmeno_pole, index) \
		((BitArraySize(jmeno_pole) > (index)) \
			? DU1_GET_BIT_(jmeno_pole[((index) / LONGLENGTH)+1], index) \
			: (FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long) BitArraySize(jmeno_pole)-1), -1)\
		)

#else

	inline void SetBit(jmeno_pole, index, vyraz)
	{
		unsigned long size = BitArraySize(jmeno_pole);
		if(size > index)
		{
			DU1_SET_BIT_(jmeno_pole[((index) / LONGLENGTH)+1], index, (vyraz));
		}
		else
		{
			FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long) size-1), -1;
		}
	}

	inline void GetBit(jmeno_pole, index, vyraz)
	{
		unsigned long size = BitArraySize(jmeno_pole);
		if(size > index)
		{
			DU1_GET_BIT_(jmeno_pole[((index) / LONGLENGTH)+1], index);
		}
		else
		{
			FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long) size-1), -1;
		}
	}

	inline unsigned long BitArraySize(BitArray_t jmeno_pole[])
	{
		return jmeno_pole[0];
	}

#endif