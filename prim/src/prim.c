#include "prim.h"
#include <stdio.h>
#include <stdlib.h>

S sommetSuiv(listeAretes l,foret f)
{
	arete a;
	S newS;
	a=plusPetit(l);
	f=adja(f,a->s,a->d,a->l);
	newS=a->d;
	l=supElt(l,a);
	return newS;
}

listeAretes majl(listeAretes l,ens e,graphe g,S x)
{
	S i;
	for(i=0;i<MAX_SOMMET;i++)
	{
		if((g->a[x*MAX_SOMMET+i]>0)&&(estDans(i,e)))
		{
			l=adjElt(l,creerArete(x,i,g->a[x*MAX_SOMMET+i]));
		}
	}
	l=triListe(l);
	return l;
}

foret prim(graphe g,S x)
{
	foret f=grnouv();
	listeAretes l=listeNouv();
	ens e=plein();
	S sommetCourant=x;

	while(!estVide(e))
	{
		e=del(e,sommetCourant);
		l=majl(l,e,g,sommetCourant);	
		sommetCourant=sommetSuiv(l,f);
	}

	return f;
}
