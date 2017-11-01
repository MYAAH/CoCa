/*
La variable x(v, h) est représentée par le nombre v*k + h + 1
*/

// Ouvre les fichiers file_in et file_out, respectivement à lire et à écrire
void filesOpen(int argc, char *argv[]);

// Ferme les fichiers file_in et file_out
void filesClose();

// Obtient la Hauteur maximale atteinte dans l'arbre
// NB : Le nombre d'entiers de file_in = orderG()*Hauteur
void getHeight();

// Obtient le tableau de sommets tel que vertices[i] = Hauteur(i)
void getVertices(int *vertices);

//Crée une nouvelle clause dans le fichiers de sortie
//void printClause(int *litteraux, int nblit);

//Calcule le numéro de la variable correspondant à x(v,h)
//int var(int v, int h);

/*Renvoie la liste des voisins de v dans un tableau
contenant le nombre de voisin suivit des voisins*/
int* voisinage(int v);
