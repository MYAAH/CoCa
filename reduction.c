#include <stdlib.h>
#include <stdio.h>

#include "reduction.h"
#include "all.h"

int K = 5;

int nbvar = 0;
int nbclauses = 0;
FILE* file = NULL;


int main(int argc, char *argv[]) 
{	
	nbvar = var(orderG()-1, K);

	if (argc > 1)
		K = atoi(argv[1]);
	if (argc > 2)
		file = fopen(argv[2], "w");
	else
		file = fopen("out.txt", "w");
	// If errors, exit
	if (file == NULL)
	{
		exit(1);
	}
	fprintf(file, "p cnf                \n");

	contrainte1();
	contrainte2();
	contrainte3();
	contrainte4();
	
	rewind(file);
	fprintf(file, "p cnf %d %d", nbvar, nbclauses);

	fclose(file);
}

void contrainte1()
{
	//maximum une profondeur par sommet
	for(int v = 0; v < orderG(); v++)
	{
		for(int i = 0; i < K; i++)
		{
			for(int j = i + 1; j <= K; j++)
			{
				int clause[2] = {-var(v, i), -var(v,j)};
				printClause(clause, 2);
			}
		}
	}
	//minimum une profondeur par sommet
	for(int v = 0; v < orderG(); v++)
	{
		int clause[K+1];
		for(int i = 0; i <= K; i++)
		{
			clause[i] = var(v, i);
		}
		printClause(clause, K+1);
	}
}

void contrainte2()
{
	//maximum une racine
	for(int i = 0; i < orderG()-1; i++)
	{
		for(int j = i + 1; j < orderG(); j++)
		{
			int clause[2] = {-var(i, 0), -var(j, 0)};
			printClause(clause, 2);
		}
	}

	//minimum une racine
	int clause[orderG()];
	for(int v = 0; v < orderG(); v++)
	{
		clause[v] = var(v, 0);
	}
	printClause(clause, orderG());
}

void contrainte3()
{
	//il existe un sommet de profondeur K
	int clause[orderG()];
	for(int v = 0; v < orderG(); v++)
	{
		clause[v] = var(v, K);
	}
	printClause(clause, orderG());
}

void contrainte4()
{
	/*soit il existe un sommet voisin de profondeur h-1
	  soit le sommet n'a pas la profondeur h*/
	for(int v = 0; v < orderG(); v++)
	{
		int *voisins = voisinage(v);
		for(int i = 1; i <= K; i++)
		{
			int clause[voisins[0] + 1];
			clause[0] = -var(v, i);
			for(int j = 1; j <= voisins[0]; j++)
			{
				clause[j] = var(voisins[j], i - 1);
			}
			printClause(clause, voisins[0] + 1);
		}
		free(voisins);
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
