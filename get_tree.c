#include <stdlib.h>
#include <stdio.h>

#include "get_tree.h"
#include "all.h"

FILE* file_in = NULL;
FILE* file_out = NULL;
int maxHeight = 0;


int main(int argc, char *argv[]) 
{	
	filesOpen(argc, argv);

	getHeight();
	int heightOfVertices[orderG()];
	getVertices(heightOfVertices);

	//rewind(file);
	// When we are finished, close files
	filesClose();
}

void filesOpen(int argc, char *argv[])
{
	if (argc == 1)
	{
		file_in  = fopen("glucose_out.txt", "r");
		file_out = stdout;
	} else if (argc == 2) {
		file_in  = fopen(argv[1], "r");
		file_out = stdout;
	} else {
		file_in  = fopen(argv[1], "r");
		file_out = fopen(argv[2], "w");
	}
	// If errors, quit
	if (file_in == NULL || file_out == NULL)
	{
		exit(1);
	}
}

void filesClose()
{
	fclose(file_in);
	if (file_out != stdout)
	{
		fclose(file_out);
	}
}

void getHeight()
{
	int fileValue = 0;
	int cpt = 0;

	fscanf (file_in, "%d", &fileValue);
	while (fileValue != 0)
	{
		cpt++;
		fscanf (file_in, "%d", &fileValue);
	}
	maxHeight = (cpt/orderG())-1;

	rewind(file_in);
}

void getVertices(int *vertices)
{
	int fileValue = 0;

	fscanf (file_in, "%d", &fileValue);
	while (fileValue != 0)
	{
		if (fileValue > 0)
		{
			int vIndex = (fileValue - 1) / (maxHeight+1);
			int vHeight = (fileValue - 1) % (maxHeight+1);
			vertices[vIndex] = vHeight;
			printf("I:%d, H:%d.\n", vIndex, vHeight);
		}
		fscanf (file_in, "%d", &fileValue);
	}
}

/*void printClause(int *clause, int nblit)
{
	for(int i = 0; i < nblit; i++)
	{
		fprintf(file, "%d ", clause[i]);
	}
	fprintf(file, "0\n");
	nbclauses++;
}

int var(int v, int h)
{
	return (v*(K+1))+h+1;
}*/

int* voisinage(int v)
{
	int *voisins = malloc(sizeof(int) * orderG());
	voisins[0] = 0;
	for(int w = 0; w < orderG() ; w++)
	{
		if(v != w)
		{
			if(are_adjacent(v, w))
			{
				voisins[voisins[0]+1] = w;
				voisins[0]++;
			}
		}
	}
	return voisins;
}
