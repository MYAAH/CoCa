#include <stdlib.h>
#include <stdio.h>

#include "get_tree.h"
#include "all.h"

FILE* file_in = NULL;
FILE* file_out = NULL;


int main(int argc, char *argv[]) 
{	
	files_open(argc, argv);

	//get_vertices();

	//rewind(file);
	// When we are finished, close files
	files_close();
}

void files_open(int argc, char *argv[])
{
	if (argc == 1)
	{
		file_in  = fopen("glucose_out.txt", "w");
		file_out = stdout;
	} else if (argc == 2) {
		file_in  = fopen(argv[1], "w");
		file_out = stdout;
	} else {
		file_in  = fopen(argv[1], "w");
		file_out = fopen(argv[2], "w");
	}
	// If errors, quit
	if (file_in == NULL || file_out == NULL)
	{
		exit(1);
	}
}

void files_close()
{
	fclose(file_in);
	if (file_out != stdout)
	{
		fclose(file_out);
	}
}

void printClause(int *clause, int nblit)
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
}

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
