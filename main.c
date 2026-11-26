#include <stdio.h>
#include "labyrinthe.h"

int main(int argc, char **argv)
{
	char grille[MAX_TAILLE][MAX_TAILLE];
	int largeur;
	int hauteur;
	int entree_l;
	int entree_c;
	int ligne;
	int colonne;

	if (argc != 2)
	{
		fprintf(stderr, "Usage : %s fichier_labyrinthe\n", argv[0]);
		return (1);
	}
	if (parse_labyrinthe(argv[1], grille, &largeur, &hauteur,
        &entree_l, &entree_c) != 0)
	{
		fprintf(stderr, "Impossible de lire %s\n", argv[1]);
		return (1);
	}
	if (!resoudre(grille, largeur, hauteur, entree_l, entree_c))
	{
		printf("Aucune sortie trouvee.\n");
		return (1);
	}
	ligne = 0;
	while (ligne < hauteur)
	{
		colonne = 0;
		while (colonne < largeur)
		{
			putchar(grille[ligne][colonne]);
			colonne++;
		}
		putchar('\n');
		ligne++;
	}
	return (0);
}
