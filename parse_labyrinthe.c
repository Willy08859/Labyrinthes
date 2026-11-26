
#include "labyrinthe.h"
#include <stdio.h>

int parse_labyrinthe(const char *chemin,
	char grille[MAX_TAILLE][MAX_TAILLE], int *largeur, int *hauteur,
	int *entree_l, int *entree_c)
{
	FILE	*fichier;
	int		c;
	int		ligne;
	int		col;
	int		w;
	int		entrees;
	int		sorties;

	fichier = fopen(chemin, "r");
	if (!fichier)
		return (-1);
	ligne = 0;
	w = -1;
	entrees = 0;
	sorties = 0;
	col = 0;
	while ((c = fgetc(fichier)) != EOF)
	{
		if (c == '\r')
			continue;
		if (c == '\n')
		{
			if (col == 0 || (w != -1 && col != w) || ligne >= MAX_TAILLE)
				return (fclose(fichier), -1);
			if (w == -1)
				w = col;
			ligne++;
			col = 0;
			continue;
		}
		if (ligne >= MAX_TAILLE || col >= MAX_TAILLE)
			return (fclose(fichier), -1);
		if (c != '#' && c != '.' && c != 'E' && c != 'S')
			return (fclose(fichier), -1);
		grille[ligne][col] = (char)c;
		if (c == 'E')
		{
			entrees++;
			*entree_l = ligne;
			*entree_c = col;
		}
		if (c == 'S')
			sorties++;
		col++;
	}
	if (col > 0)
	{
		if ((w != -1 && col != w) || ligne >= MAX_TAILLE)
			return (fclose(fichier), -1);
		if (w == -1)
			w = col;
		ligne++;
	}
	fclose(fichier);
	if (ligne == 0 || w <= 0 || entrees != 1 || sorties != 1)
		return (-1);
	*largeur = w;
	*hauteur = ligne;
	return (0);
}
