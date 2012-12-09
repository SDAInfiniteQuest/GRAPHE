#ifndef __graphe_h_
#define	__graphe_h_

#include "base.h"

typedef struct
{
	Nat taille;
	Nat *a;
} *graphe, strGraphe, strForet, *foret;

graphe grnouv();
graphe adja(graphe, S x, S y, Nat l);
graphe supa(graphe, S x, S y);
Bool exs(graphe, S);
Nat vala(graphe, S, S);
Bool exa(graphe, S, S);
Nat di(graphe, S);
Nat de(graphe, S);

#endif
