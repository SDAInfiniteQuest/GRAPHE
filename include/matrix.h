/**
 * \file			matrix.h
 * \author		Pallamidessi Joseph
 * \version		1.0
 * \date			09/12/2012
 * \brief			header matrix.h
 *
 * \details		Definition de la struct matrix, et fonction de generation de graphe
*/

#ifndef __MATRIX_H
#define __MATRIX_H
#include<stdio.h>
#include<stdlib.h>
#include"table.h"

/**
*	/struct		str_matrix
*	/brief		Une structure contenant la taille de la matrice et une matrice
*	/details 	Il s'agit d'une matrice d'int,et on defini un pointeur sur la structure
*
**/

typedef struct matrix {
	int **mat;						/*<!	mat: La matrice d'int	*/
	int taille; 					/*<!	taille: la taille code dans un int	*/
}str_matrix,*Matrix;		/*<!	Pointeur sur la structure	*/

/**
* /brief		Alloue en memoire une matrice carre de taille donne
*	/details	Initialise aussi la taille de la nouvelle matrice cree
*
*	@param	taille Taille de la matrice carre a creer
* @return	m la matrice nouvellement alloue
**/
Matrix newMatrix(int taille);

/**
* /brief		Alloue en memoire une matrice carre de taille donne,et la remplie de facon a
* satisfaire que le graphe representer soit complet
*	/details	Alloue la nouvelle matrice , et la remplie grace a remplirComplet()
*
*	@param	taille Taille de la matrice carre a creer
*	@param	oriente Pour savoir si le graphe est oriente
* @return	m la matrice nouvellement alloue et remplie
**/

Matrix grapheComplet(int taille,bool oriente);


/**
* /brief		Alloue en memoire une matrice carre de taille donne,et la remplie de facon a
* satisfaireque le graphe representer soit partiel
*	/details	Alloue la nouvelle matrice cree,et la remplie grace a remplirPartiel()
*
*	@param	taille Taille de la matrice carre a creer
*	@param	oriente Pour savoir si le graphe est oriente
* @return	m la matrice nouvellement alloue
**/
Matrix graphePartiel(int taille,bool oriente);

/**
* /brief		Remplie une matrice en satisfaisant le fait que le graphe ainsi
* representer soit complet
*	/details	On determine si le graphe representer par une matrice d'adjacence doit etre
*	oriente ou non. S'il est oriente, on remplira toute les case de la matrice(n^2 choix
*	d'element),sinon on choisira unique des poids d'arc dans sa triangulaire superieur,et on
*	copira ces choix dans la matrice triangulaire inferieur
*
*	@param	m La matrice a remplir  
* @param	oriente Un bool,determinant si le graphe a creer doit etres oriente ou pas
*	@return m La matrice ainsi cree
**/
Matrix remplirComplet(Matrix m,bool oriente);


/**
* /brief		Remplie une matrice en satisfaisant le fait que le graphe ainsi
* representer soit partielle
*	/details	On determine si le graphe representer par une matrice d'adjacence doit etre
*	oriente ou non. S'il est oriente, on remplira toute les case de la matrice(n^2 choix
*	d'element),sinon on choisira unique des poids d'arc dans sa triangulaire superieure,et on
*	copira ces choix dans la triangulaire inferieure. On verifira que toute les arcs crees
*	ont un sommet dans un ensemble de sommet,et on ajoute l'autre sommet s'il n'est pas deja
*	dans l'ensemble. On choisi un sommet au depart et on le rajoute a
*	l'ensemble. Tant que tout les sommets ne sont pas dans l'ensemble on continue
*	de creer et de rajouter des arcs.
*
*	@param	m La matrice a remplir 
* @param	oriente Un bool,determinant si le graphe a creer doit etres oriente ou pas
*	@return f La matrice ainsi cree
**/
Matrix remplirPartiel(Matrix m,bool oriente);


/**
* /brief		Libere la memoire d'une matrice d'adjacence
*	/details
*
*	@param	m la matrice a free
**/
void deleteMatrix(Matrix m);


/**
* /brief		Affiche sur la sortie standard une matrice
*	/details
*
*	@param	m La mtrice a afficher
**/
void affichage(Matrix m);
#endif
