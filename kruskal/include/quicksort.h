/**
 * \file			quicksort.h
 * \author		Pallamidessi Joseph
 * \version		1.0
 * \date			09/12/2012
 * \brief			header quicksort.h
 *
 * \details		Tri rapide et fonctions associees
*/
#include"table.h"
#ifndef _QUICKSORT_H
#define _QUICKSORT_H

/**
* /brief		Echange les valeur d'indice i et j d'un tableau d'arete
*	/details	
*
*	@param	tab un tableau d'arete
*	@param	i l'indice de l'element du tableau a echanger
*	@param	j l'indice de l'element du tableau a echanger
**/
void echanger(arete* tab,int i,int j);


/**
* /brief		Echange les valeur d'indice i et j d'un tableau d'entier
*	/details	On l'utilisera sur des tableSommet
*
*	@param	tab Un tableau d'int
*	@param	i l'indice de l'element du tableau a echanger
*	@param	j l'indice de l'element du tableau a echanger
**/
void echangerSommet(int* tab,int i,int j);

/**
* /brief		Quicksort in place sur un tableau d'arete
*	/details	Le tri ce fait sur le champ poids des aretes (arcs)
*
*	@param	tab le tableau d'arete a trier
*	@param	debut l'indice du debut du tri
*	@param	fin  l'indice de fin du tri
**/

void quicksort(arete* tab,int debut,int fin);
/**
* /brief		Quicksort in place sur un tableau d'entier
*	/details
*
*	@param	tab le tableau d'int a trier
*	@param	debut l'indice du debut du tri
*	@param	fin  l'indice de fin du tri
**/
void quicksortSommet(int* tab,int debut,int fin);

#endif

