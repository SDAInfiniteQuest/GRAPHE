#include "sous_ensemble.h"
#include <stdio.h>
#include <stdlib.h>

ens es(graphe g)
{
	ens e=vide();
	int i;
	for(i=0;i<g->taille;i++)
		e->e[i]=1;
	e->taille=g->taille;
	return e;
}

ens epred(graphe g, S x)
{
	ens e=vide();
	int i,n;
	if(x<g->taille)
	{
		n=g->taille;
		for(i=0;i<n;i++)
			if(g->a[i*n+x]>0) e->e[i]=1;
	}
	return e;
}

ens esucc(graphe g, S x )
{
	ens e=vide();
	int i,n;
	if(x<g->taille)
	{
		n=g->taille;
		for(i=0;i<n;i++)
			if(g->a[x*n+i]>0) e->e[i]=1;
	}
	return e;
}

