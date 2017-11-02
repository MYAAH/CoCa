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
	if (maxHeight == -1)
	{
		printf("Fichier invalide ! On quitte...\n");
		return 1;
	}

	int heightOfVertices[orderG()];
	getVertices(heightOfVertices);

	printTree(heightOfVertices);

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
		}
		fscanf (file_in, "%d", &fileValue);
	}
}

void printTree(int *vertices)
{
	printf("Hauteur début : 0(racine).\n");
	for (int i = 1 ; i <= maxHeight ; i++)
	{
		for (int j = 0 ; j < orderG() ; j++)
		{
			if (vertices[j] == i)
			{
				for (int k = 0 ; k < orderG() ; k++)
				{
					if (vertices[k] == i-1 && are_adjacent(j, k))
					{
	fprintf(file_out, "%d -> %d\n", k, j);
	break;
					}
				}
			}
		}
	}
	printf("Hauteur Maximale : %d.\n", maxHeight);
}
