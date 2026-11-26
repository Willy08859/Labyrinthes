
#ifndef LABYRINTHE_H
# define LABYRINTHE_H

# define MAX_TAILLE 32

int parse_labyrinthe(const char *chemin,
	char grille[MAX_TAILLE][MAX_TAILLE], int *largeur, int *hauteur,
	int *entree_l, int *entree_c);
int resoudre(char grille[MAX_TAILLE][MAX_TAILLE], int largeur,
	int hauteur, int ligne, int col);

#endif
