#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>

graphe grnouv()
{
	graphe g=(graphe) malloc(sizeof(strGraphe));
	g->taille=MAX_SOMMET;
	g->a=(Nat*) calloc(MAX_SOMMET*MAX_SOMMET,sizeof(Nat));
	return g;
}

graphe adja(graphe g, S x, S y, Nat l)
{
	g->a[x*g->taille+y]=l;
	return g;
}

graphe supa(graphe g, S x, S y)
{
	g->a[x*g->taille+y]=0;
	return g;
}

Bool exs(graphe g, S x)
{
	if(g->taille>x) return 1;
	else return 0;
}

Nat vala(graphe g, S x, S y)
{ 
	return g->a[x*g->taille+y];
}

Bool exa(graphe g, S x,S y)
{
	if(vala(g,x,y)>0) return 1;
	else return 0;
}

Nat di(graphe g, S x)
{
	int i,r,n;
	n=g->taille;
	for(i=0,r=0;i<n;i++)
		if(exa(g,i,x)) r++;
	return r;
}

Nat de(graphe g, S x)
{
	int i,r,n;
	n=g->taille;
	for(i=0,r=0;i<n;i++)
		if(exa(g,x,i)) r++;
	return r;
}
