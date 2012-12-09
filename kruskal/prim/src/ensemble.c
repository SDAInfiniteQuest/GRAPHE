#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"

ens vide()
{
	ens e=(ens) malloc(sizeof(ens));
	e->taille=0;
	e->e=(Bool*) calloc(MAX_SOMMET,sizeof(Bool));
	return e;
}

ens plein()
{
	int i;
	ens e=vide();
	e->taille=MAX_SOMMET;
	for(i=0;i<MAX_SOMMET;i++) e->e[i]=1;
	return e;
}

ens ins(ens e,S x)
{
	if(e==NULL) e=vide();
	if(e->e[x]==0)
	{
		e->e[x]=1;
		e->taille++;
	}
	return e;
}

ens	del(ens e,S x)
{
	if(e==NULL) e=vide();
	if(e->e[x]==1)
	{
		e->e[x]=0;
		e->taille--;
	}
	return e;
}

Bool estDans(S x, ens e)
{
	return e->e[x];
}

Bool estVide(ens e)
{
	if(e->taille==0) return 1;
	else return 0;
}

Nat card(ens e)
{
	return e->taille;
}

ens uni(ens e1,ens e2)
{
	int i; 
	ens e3=vide();
	for(i=0;i<MAX_SOMMET;i++)
	{
		if((e3->e[i]=e1->e[i]||e2->e[i])==1) e3->taille++;
	}
	return e3;
}

ens inter(ens e1,ens e2)
{
	int i; 
	ens e3=vide();
	for(i=0;i<MAX_SOMMET;i++)
	{
		if((e3->e[i]=e1->e[i]&&e2->e[i])==1) e3->taille++;
	}
	return e3;
}

ens supe(ens e)
{
	free(e->e);
	free(e);
	return NULL;
}
