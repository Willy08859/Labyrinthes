
#include "labyrinthe.h"

int resoudre(char grille[MAX_TAILLE][MAX_TAILLE], int largeur,
	int hauteur, int ligne, int col)
{
	static const int dl[4] = {-1, 1, 0, 0};
	static const int dc[4] = {0, 0, -1, 1};
	int i;
	int nl;
	int nc;
	char case_depart;

	if (ligne < 0 || ligne >= hauteur || col < 0 || col >= largeur)
		return (0);
	if (grille[ligne][col] == '#' || grille[ligne][col] == 'v')
		return (0);
	if (grille[ligne][col] == 'S')
		return (1);
	case_depart = grille[ligne][col];
	grille[ligne][col] = 'v';
	i = 0;
	while (i < 4)
	{
		nl = ligne + dl[i];
		nc = col + dc[i];
		if (resoudre(grille, largeur, hauteur, nl, nc))
		{
			if (case_depart == '.')
				grille[ligne][col] = '*';
			else
				grille[ligne][col] = case_depart;
			return (1);
		}
		i++;
	}
	if (case_depart == 'E')
		grille[ligne][col] = 'E';
	else
		grille[ligne][col] = '.';
	return (0);
}
