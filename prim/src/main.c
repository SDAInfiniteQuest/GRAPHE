#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"
#include "sous_ensemble.h"
#include "graphe.h"
#include "aretes.h"
#include "listeAretes.h"
#include "prim.h"

graphe fillg(graphe g,Nat k)
{
	int i;
	for(i=0;i<100;i++)
	{
		if((rand()%k)==0) g->a[i]=rand()%10;
	}
	return g;
}

void printg(graphe g)
{
	int i,j;
	printf("\n");
	for(i=0;i<MAX_SOMMET;i++)
	{
		for(j=0;j<MAX_SOMMET;j++)
			printf("%d ",g->a[i*g->taille+j]);
		printf("\n");
	}
	printf("\n");
}

void printe(ens e)
{
	int i;
	printf("\n");
	for(i=0;i<MAX_SOMMET;i++)
	{
		printf("%d ",e->e[i]);
	}
	printf("\n");
}

void printl(listeAretes l)
{
	printf("\n%d\n",l->offset);
	int i;
	for(i=0;i<l->offset;i++)
	{
		arete a=l->liste[i];
		printf("\t%d\n",a->l);
	}
}

int 
main () 
{	
	srand(time(NULL));
	graphe g=grnouv();
	fillg(g,1);
	printg(g);
	foret f=prim(g,0);
	printg(f);

	return 0;
}
		

