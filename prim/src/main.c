#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"
#include "sous_ensemble.h"
#include "graphe.h"
#include "aretes.h"
#include "listeAretes.h"
#include "prim.h"

int 
main (int argc,char *argv[]) 
{	
	int n=atoi(argv[1]);
	srand(time(NULL));
	foret f;
	int i;
	graphe g=grnouv();
	fillg(g,1);
	printg(g,n);
	if(n<MAX_SOMMET) f=prim(g,0,n);
	printg(f,n);

	return 0;
}
		

