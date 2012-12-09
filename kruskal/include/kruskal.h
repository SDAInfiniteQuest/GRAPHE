/**
 * \file			kruskal.h
 * \author		Pallamidessi Joseph
 * \version		1.0
 * \date			09/12/2012
 * \brief			header kruskal.h
 *
 * \details		Fonctions auxilliaire de la'lgoritme de kruskal et l'algorithme lui-meme
*/

#ifndef _KRUSKAL_H
#define _KRUSKAL_H
#include"quicksort.h"
#include"matrix.h"
#include"table.h"


/**
* /brief		Creer un tableau d'arete d'apres une matrice d'adjacence
*	/details	Si la matrice est non-oriente (oriente==false),on copie uniquement les arete
*	de la tringulaire superieur prive de la diagonale.Sinon on copie toute les arete de al
*	matrice, prive de la diagonale.
*
*	@param	m la matrice dont ont veut extraire les aretes
*	@param	oriente bool pour savoir si la matrice est oriente ou non
* @return	a le tableau d'arete creer et initialiser
**/
arete* matrixToArete(Matrix m,bool oriente);


/**
* /brief		Creer un tableau de tableSommet, correspondant au ensemble representatif de
* chaque sommet
*	/details	Pour chaque tableSommet, il n'y a qu'un seul element au depart,lui-meme  
*
*	@param	m La matrice dont on veut les ensembles representatifs de tout ses sommets au
*	depart
* @return	f Le tableau de tableSommets initialisees
**/
tableSommet* vertexToTable(Matrix m); 


/**
* /brief		Algorithme de kruskal
*	/details	Ecrit le poids total de l'arbre de poids minimun sur la sortie standard,si
*	boolAffiche=true
*
*	@param	m La matrice d'adjacence dont on veut l'arbre de poids minimal
*	@param	oriente  Booleen pour savoir si le graphe est oriente ou non
*	@param	boolAffiche Booleen pour l'affichage ou non du resulat 
* @return	f La matrice d'adjacence correspondant a l'arbre de poids minimun
**/
Matrix kruskal(Matrix m,bool oriente,bool boolAffiche);



/**
* /brief		Libere la memoire d'un tableau d'arete
*	/details	
*
*	@param	a le tableau d'arete a supprimer
**/
void deleteTabArete(arete* a);
#endif
