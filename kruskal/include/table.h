/**
 * \file			table.h
 * \author		Pallamidessi Joseph
 * \version		1.0
 * \date			09/12/2012
 * \brief			header table.h
 *
 * \details		Definition de la struct arete et tableSommet, fonctions generatrice et
 * associees (union,insertion)
*/

#ifndef __TABLE_H
#define __TABLE_H
#include<stdio.h>
#include<stdlib.h>
typedef int bool;

#define false 0
#define true 1

/**
*	/struct		str_arete
*	/brief		Une arete (arc),composer d'un sommet de depart,d'un sommet d'arrivee,et d'un
*	poids 
*
**/
typedef struct str_arete{
	int depart;							/*<!	Le sommet de depart, un int	*/
	int arrivee;						/*<!	Le sommet d'arrivee, un int	*/
	int poids;							/*<!	le poids de l'arc, un int*/
}arete;						

/**
*	/struct		str_tableSommet
*	/brief		Une table d'int, pour representer les ensembles de sommet 
*	/details 	Elle doit rester toujours trie
*
**/
typedef struct{
	int* tab;								/*<!	Un tableau d'int	*/
	int nbElements;					/*<!	le nombre d'elements actuelle contenu dans la table	*/
	int tailleMax;					/*<!	La taille maximal de la table(taille allouer en memoire)	*/
	}str_tableSommet,*tableSommet;	/*<!	Pointeur sur la structure	*/

/**
* /brief		Cree et alloue en memoire un table de taille donnee
*	/details	Initialise la variable tailleMax->Il s'agit de celle donnee en argument
*
*	@param	taille Taille de la table a creer
* @return	t La table nouvellement alloue
**/
tableSommet newTable(int taille);


/**
* /brief		Insere a la fin de la table 
*	/details	Pas de precondition
*
*	@param	t La tableSommet auquelle on veut ajouter des elements
*	@param	sommet Le sommet a ajouter
* @return	f la tableSommet t avec sommet ajouter a la fin 
**/
tableSommet insertFin(tableSommet t,int sommet);


/**
* /brief		Renvoye une nouvelle tableSommet,qui est l'union de deux tableSommet
*	/details	Vu que les tableSommet sont triees, on procede a un interclassement
*
*	@param	t1 Une tableSommet
*	@param	t2 Une tableSommet
* @return	t la tableSommet resultant de l'union de t1 et de t2 
**/
tableSommet unionListeSommet(tableSommet t1,tableSommet t2);


/**
* /brief		Recherche d'un element donne,dans une tableSommet donnee
*	/details	Recherche lineaire, il faudrait faire une recherche dichotomique pour
*	ameliorer grandement le temps de rechcher
*
*	@param	t tableSommet dans laquelle on cherche l'element
*	@param	sommet l'elements qu'on cherche
* @return	b un booleen, vrai si ona trouver l'element, non sinon 
**/
bool estDans(tableSommet t,int sommet);


/**
* /brief		Test l'egalite entre deux tableSommet
*	/details
*
*	@param	t1 Une tableSommet
*	@param	t2 Une tableSommet
* @return	b Un booleen vrai si les tableSommet sont egales, sinon faux  
**/
bool egauxListeSommet(tableSommet t1, tableSommet t2);


/**
* /brief		Libere la memoire occupee par une tableSommet
*	/details
*
*	@param	t La tableSommet a detruire
**/
void deleteTable(tableSommet t);


/**
* /brief		Creer une copie en memoire du tableSommet
*	/details
*
*	@param	t La tableSommet a copier
* @return	f La nouvelle tableSommet creer
**/
tableSommet copieTable(tableSommet t);
#endif
