#include "prim.h"
#include <stdio.h>
#include <stdlib.h>

graphe fillg(graphe g,Nat j)
{
	int i,k;
	for(i=0;i<MAX_SOMMET;i++)
	{
		for(k=i+1;k<MAX_SOMMET;k++)
		{
			if((rand()%j)==0) g->a[i*MAX_SOMMET+k]=rand()%100;
			g->a[k*MAX_SOMMET+i]=g->a[i*MAX_SOMMET+k];
		}
	}
	return g;
}

void printg(graphe g,Nat fin)
{
	int i,j;
	printf("\n");
	for(i=0;i<fin;i++)
	{
		for(j=0;j<fin;j++)
			printf("%3d ",g->a[i*MAX_SOMMET+j]);
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
		printf("(s:%d,d:%d,l:%d) ",a->s,a->d,a->l);
	}
	printf("\n");
}

S sommetSuiv(listeAretes l,foret f,ens e)
{
	arete a;
	S newS;
	a=plusPetit(l);
	f=adja(f,a->s,a->d,a->l);
	if(estDans(a->d,e)) newS=a->d;
	else newS=a->s;
	l=supElt(l,a);
	return newS;
}

listeAretes majl(listeAretes l,ens e,graphe g,S x,S fin)
{
	S i;
	for(i=0;i<l->offset;i++)
	{
		if(!estDans(l->liste[i]->d,e)) l=supElt(l,l->liste[i]);
	}
	for(i=0;i<fin;i++)
	{
		if((g->a[x*MAX_SOMMET+i]>0)&&(estDans(i,e)))
		{
			l=adjElt(l,creerArete(x,i,g->a[x*MAX_SOMMET+i]));
		}
	}
	l=triListe(l);
	//printl(l);
	return l;
}

foret prim(graphe g,S x,S fin)
{
	foret f=grnouv();
	listeAretes l=listeNouv();
	ens e=plein();
	S sommetCourant=x;

	int i=1;
	while(i<fin)
	{
		e=del(e,sommetCourant);
		//printe(e);
		l=majl(l,e,g,sommetCourant,fin);	
		sommetCourant=sommetSuiv(l,f,e);
		i++;
	}

	return f;
}
