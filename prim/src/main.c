#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"
#include "sous_ensemble.h"
#include "graphe.h"
#include "aretes.h"
#include "listeAretes.h"
#include "prim.h"

Nat tab[]={	4, 7, 3, 3, 4, 3, 0, 1, 3, 4, 5, 6, 5, 8, 7, 9, 3, 1, 4, 6,
3, 2, 0, 3, 0, 3, 2, 9, 7, 7, 9, 7, 6, 2, 3,	5, 8, 6, 5, 8, 1, 0, 3, 3,
1, 6, 2, 7, 4, 3, 0, 7, 8, 1, 9, 0, 3, 4, 4, 1, 2, 9, 5, 7, 0, 8, 1, 1,
5, 4, 4,	5,	7, 0, 1, 0, 2, 1, 8, 8, 2, 8, 8, 5, 5, 0, 8, 3, 9, 0, 6, 7,
1, 0, 0, 9, 9, 7, 2, 2 };

int 
main () 
{	
	srand(time(NULL));
	graphe g=grnouv();
	int i;
	/*for(i=0;i<MAX_SOMMET*MAX_SOMMET;i++)
	{
		g->a[i]=tab[i];
	}*/
	fillg(g,1);
	printg(g);
	foret f=prim(g,0);
	printg(f);

	return 0;
}
		

