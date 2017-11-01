/*
La variable x(v, h) est représentée par le nombre v*k + h + 1
*/

//Crée des clauses pour que n'avoir qu'une seule profondeur par sommet
void contrainte1();

//Crée des clauses pour n'avoir qu'une seule racine
void contrainte2();

//Crée des clauses pour que l'arbre soit suffisament profond
void contrainte3();

//Crée des clauses pour que tous les sommets aient un parent
void contrainte4();

//Crée une nouvelle clause dans le fichiers de sortie
void printClause(int *litteraux, int nblit);

//Calcule le numéro de la variable correspondant à x(v,h)
int var(int v, int h);

/*Renvoie la liste des voisins de v dans un tableau
contenant le nombre de voisin suivit des voisins*/
int* voisinage(int v);
