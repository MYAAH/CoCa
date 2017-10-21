#include "3tree.h"

int orderG()
{
	return 2;
}

int sizeG()
{
	return 3;
}

int are_adjacent(int u, int v)
{
	if(u > v)
	{
		int w = v;
		v = u;
		u = w;
	}

	if(u == 0 && v == 2)
		return 0;

	return 1;

}